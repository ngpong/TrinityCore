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

#include "AIException.h"
#include "Creature.h"
#include "CreatureAISelector.h"
#include "CreatureAIFactory.h"

#include "MovementGenerator.h"

#include "GameObject.h"
#include "GameObjectAIFactory.h"

#include "Log.h"
#include "ScriptMgr.h"

namespace FactorySelector
{
    template <class T, class Value>
    inline int32 GetPermitFor(T const* obj, Value const& value)
    {
        Permissible<T> const* const p = ASSERT_NOTNULL(dynamic_cast<Permissible<T> const*>(value.second.get()));
        return p->Permit(obj);
    }

    template <class T>
    struct PermissibleOrderPred
    {
        public:
            PermissibleOrderPred(T const* obj) : _obj(obj) { }

            template <class Value>
            bool operator()(Value const& left, Value const& right) const
            {
                return GetPermitFor(_obj, left) < GetPermitFor(_obj, right);
            }

        private:
            T const* const _obj;
    };

    template <class AI, class T>
    inline FactoryHolder<AI, T> const* SelectFactory(T* obj)
    {
        static_assert(std::is_same<AI, CreatureAI>::value || std::is_same<AI, GameObjectAI>::value, "Invalid template parameter");
        static_assert(std::is_same<AI, CreatureAI>::value == std::is_same<T, Creature>::value, "Incompatible AI for type");
        static_assert(std::is_same<AI, GameObjectAI>::value == std::is_same<T, GameObject>::value, "Incompatible AI for type");

        using AIRegistry = typename FactoryHolder<AI, T>::FactoryHolderRegistry;

        // 如果 DB/对象指定了 AIName，优先使用
        // AIName in db
        std::string const& aiName = obj->GetAIName();
        if (!aiName.empty())
            return AIRegistry::instance()->GetRegistryItem(aiName);

        // 否则根据 Permit 分值自动选择
        // select by permit check
        //
        // 此处先获取 ObjectRegistry<FactoryHolder<AI, T, std::string>, std::string> 下的 _registeredObjects
        typename AIRegistry::RegistryMapType const& items = AIRegistry::instance()->GetRegisteredItems();
        // 此处的计算逻辑依赖于 AI 实现的 Permissible 静态函数；该函数会给出一个分值；
        // 取分值最高的那个 factory；只有分值 >= 0 才算可用，负数表示拒绝；
        auto itr = std::max_element(items.begin(), items.end(), PermissibleOrderPred<T>(obj));
        if (itr != items.end() && GetPermitFor(obj, *itr) >= 0)
            return itr->second.get();

        // should _never_ happen, Null AI types defined as PERMIT_BASE_IDLE, it must've been found
        ABORT();
        return nullptr;
    }

    CreatureAI* SelectAI(Creature* creature)
    {
        // special pet case, if a tamed creature uses AIName (example SmartAI) we need to override it
        if (creature->IsPet())
            return ASSERT_NOTNULL(sCreatureAIRegistry->GetRegistryItem("PetAI"))->Create(creature);

        // scriptname in db
        try
        {
            // 此处要求 Creature 在 DB 中配置了脚本 ID；
            // 且对应脚本 ID 的脚本已经完成了注册；
            // 且对应脚本类中实现了 GetAI 函数；
            if (CreatureAI* scriptedAI = sScriptMgr->GetCreatureAI(creature))
                return scriptedAI;
        }
        catch (InvalidAIException const& e)
        {
            TC_LOG_ERROR("entities.unit", "Exception trying to assign script '{}' to Creature (Entry: {}), this Creature will have a default AI. Exception message: {}",
                creature->GetScriptName(), creature->GetEntry(), e.what());
        }

        // 从 AI 工厂里面选择一个最合适的 AI；
        return SelectFactory<CreatureAI>(creature)->Create(creature);
    }

    MovementGenerator* SelectMovementGenerator(Unit* unit)
    {
        MovementGeneratorType type = unit->GetDefaultMovementType();
        // 如果是 Creature 且不被玩家控制；那么就使用 Creatue 指定的默认移动类型
        if (Creature* creature = unit->ToCreature())
            // 这里指的是，这个单位可能是被玩家魅惑了或者本身就是玩家对象；
            if (!creature->GetCharmerOrSelfPlayer())
                type = creature->GetDefaultMovementType();

        MovementGeneratorCreator const* mv_factory = sMovementGeneratorRegistry->GetRegistryItem(type);
        // static IdleMovementGenerator 
        // new RandomMovementGenerator<Creature>();
        // new WaypointMovementGenerator<Creature>();
        return ASSERT_NOTNULL(mv_factory)->Create(unit);
    }

    GameObjectAI* SelectGameObjectAI(GameObject* go)
    {
        // scriptname in db
        if (GameObjectAI* scriptedAI = sScriptMgr->GetGameObjectAI(go))
            return scriptedAI;

        return SelectFactory<GameObjectAI>(go)->Create(go);
    }
}
