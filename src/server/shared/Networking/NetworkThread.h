/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITYCORE_NETWORK_THREAD_H
#define TRINITYCORE_NETWORK_THREAD_H

#include "Containers.h"
#include "DeadlineTimer.h"
#include "Define.h"
#include "Errors.h"
#include "IoContext.h"
#include "Log.h"
#include "Socket.h"
#include "Timer.h"
#include <boost/asio/ip/tcp.hpp>
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>
#include <set>
#include <thread>

namespace Trinity::Net
{
template<class SocketType>
class NetworkThread
{
public:
    NetworkThread() : _connections(0), _stopped(false), _thread(nullptr), _ioContext(1),
        _acceptSocket(_ioContext), _updateTimer(_ioContext)
    {
    }

    NetworkThread(NetworkThread const&) = delete;
    NetworkThread(NetworkThread&&) = delete;
    NetworkThread& operator=(NetworkThread const&) = delete;
    NetworkThread& operator=(NetworkThread&&) = delete;

    virtual ~NetworkThread()
    {
        Stop();
        if (_thread)
            Wait();
    }

    void Stop()
    {
        _stopped = true;
        _ioContext.stop();
    }

    bool Start()
    {
        if (_thread)
            return false;

        // 开启一个线程处理
        _thread = std::make_unique<std::thread>(&NetworkThread::Run, this);
        return true;
    }

    void Wait()
    {
        ASSERT(_thread);

        _thread->join();
        _thread = nullptr;
    }

    int32 GetConnectionCount() const
    {
        return _connections;
    }

    virtual void AddSocket(std::shared_ptr<SocketType> sock)
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        ++_connections;
        SocketAdded(_newSockets.emplace_back(std::move(sock)));
    }

    Trinity::Net::IoContextTcpSocket* GetSocketForAccept() { return &_acceptSocket; }

protected:
    virtual void SocketAdded(std::shared_ptr<SocketType> const& /*sock*/) { }
    virtual void SocketRemoved(std::shared_ptr<SocketType> const& /*sock*/) { }

    void AddNewSockets()
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        if (_newSockets.empty())
            return;

        for (std::shared_ptr<SocketType>& sock : _newSockets)
        {
            if (!sock->IsOpen())
            {
                SocketRemoved(sock);
                --_connections;
            }
            else
                _sockets.emplace_back(std::move(sock));
        }

        _newSockets.clear();
    }

    void Run()
    {
        TC_LOG_DEBUG("misc", "Network Thread Starting");

        // 每 1ms 触发一次异步回调
        _updateTimer.expires_after(1ms);
        _updateTimer.async_wait([this](boost::system::error_code const&) { Update(); });
        _ioContext.run();

        TC_LOG_DEBUG("misc", "Network Thread exits");
        _newSockets.clear();
        _sockets.clear();
    }

    void Update()
    {
        if (_stopped)
            return;

        // 延续异步调用，还是 1ms 逻辑
        _updateTimer.expires_after(1ms);
        _updateTimer.async_wait([this](boost::system::error_code const&) { Update(); });

        // 处理新加(accept)进来的连接(放在预备队列_newSockets里面)，并将它们接受进处理队列 _sockets 中
        AddNewSockets();

        // 轮询所有 _sockets，调用其 Update 函数
        Trinity::Containers::EraseIf(_sockets, [this](std::shared_ptr<SocketType> const& sock)
        {
            // <name>Session 更新失败，则就将其从处理队列中移除(return true)
            if (!sock->Update())
            {
                if (sock->IsOpen())
                    sock->CloseSocket();

                this->SocketRemoved(sock);

                --this->_connections;
                return true;
            }

            return false;
        });
    }

private:
    typedef std::vector<std::shared_ptr<SocketType>> SocketContainer;

    std::atomic<int32> _connections;
    std::atomic<bool> _stopped;

    std::unique_ptr<std::thread> _thread;

    SocketContainer _sockets;

    std::mutex _newSocketsLock;
    SocketContainer _newSockets;

    Trinity::Asio::IoContext _ioContext;
    Trinity::Net::IoContextTcpSocket _acceptSocket;
    Trinity::Asio::DeadlineTimer _updateTimer;
};
}

#endif // TRINITYCORE_NETWORK_THREAD_H
