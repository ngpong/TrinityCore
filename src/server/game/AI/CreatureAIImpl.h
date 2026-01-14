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
#ifndef CREATUREAIIMPL_H
#define CREATUREAIIMPL_H

#include "Random.h"
#include <type_traits>
#include <functional>

class WorldObject;

template<typename First, typename Second, typename... Rest>
inline First const& RAND(First const& first, Second const& second, Rest const&... rest)
{
    std::reference_wrapper<typename std::add_const<First>::type> const pack[] = { first, second, rest... };
    return pack[urand(0, sizeof...(rest) + 1)].get();
}

enum AITarget
{
    AITARGET_SELF,    // 目标 = 自己（施放自保技能、给自己上 Buff、解控、自疗等）
    AITARGET_VICTIM,  // 目标 = 当前仇恨目标/攻击目标（通常是 AI 正在打的那个人；用于单体输出/控制）
    AITARGET_ENEMY,   // 目标 = 敌对单位（不一定是当前 victim；可表示“从敌方集合中选一个”用于换目标/找最近/找最低血等）
    AITARGET_ALLY,    // 目标 = 友方单位（从同阵营/同队伍/同召唤阵营中选择；用于治疗/驱散/救援）
    AITARGET_BUFF,    // 目标 = 需要上 Buff 的单位（通常是：友方集合里“缺少某个 Buff/光环”的那个；偏“按状态选目标”）
    AITARGET_DEBUFF   // 目标 = 需要挂 Debuff 的单位（通常是：敌方集合里“没有某个 Debuff/可叠层/可刷新”的那个；偏“按状态选目标”）
};

enum AICondition
{
    AICOND_AGGRO,     // 条件 = 仇恨建立/进入警戒（首次拉到仇恨、开始对玩家产生敌对行为的瞬间；常用于开怪喊话/开场技能）
    AICOND_COMBAT,    // 条件 = 战斗中（已进入战斗状态的阶段性条件；常用于循环施法/按冷却与血量阈值执行）
    AICOND_DIE        // 条件 = 死亡（单位死亡事件触发；常用于死亡台词、召唤增援、掉落触发、事件推进）
};

#define AI_DEFAULT_COOLDOWN 5000

struct AISpellInfoType
{
    AISpellInfoType() : target(AITARGET_SELF), condition(AICOND_COMBAT)
        , cooldown(AI_DEFAULT_COOLDOWN), realCooldown(0), maxRange(0.0f){ }
    AITarget target;
    AICondition condition;
    uint32 cooldown;
    uint32 realCooldown;
    float maxRange;
};

AISpellInfoType* GetAISpellInfo(uint32 i);

TC_GAME_API bool InstanceHasScript(WorldObject const* obj, char const* scriptName);

template <class AI, class T>
AI* GetInstanceAI(T* obj, char const* scriptName)
{
    if (InstanceHasScript(obj, scriptName))
        return new AI(obj);

    return nullptr;
}

#endif
