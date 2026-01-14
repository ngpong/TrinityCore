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

#ifndef _SPELLINFO_H
#define _SPELLINFO_H

#include "SharedDefines.h"
#include "Util.h"
#include "DBCStructure.h"
#include "Object.h"
#include "SpellAuraDefines.h"

class AuraEffect;
class Item;
class Player;
class Spell;
class SpellMgr;
class SpellInfo;
class Unit;
class WorldObject;
struct Condition;
struct SpellChainNode;
struct SpellModifier;
enum WeaponAttackType : uint8;

enum SpellTargetSelectionCategories
{
    TARGET_SELECT_CATEGORY_NYI,
    TARGET_SELECT_CATEGORY_DEFAULT,
    TARGET_SELECT_CATEGORY_CHANNEL,
    TARGET_SELECT_CATEGORY_NEARBY,
    TARGET_SELECT_CATEGORY_CONE,
    TARGET_SELECT_CATEGORY_AREA,
    TARGET_SELECT_CATEGORY_TRAJ
};

enum SpellTargetReferenceTypes
{
    TARGET_REFERENCE_TYPE_NONE,
    TARGET_REFERENCE_TYPE_CASTER,
    TARGET_REFERENCE_TYPE_TARGET,
    TARGET_REFERENCE_TYPE_LAST,
    TARGET_REFERENCE_TYPE_SRC,
    TARGET_REFERENCE_TYPE_DEST
};

enum SpellTargetObjectTypes : uint8
{
    TARGET_OBJECT_TYPE_NONE = 0,
    TARGET_OBJECT_TYPE_SRC,
    TARGET_OBJECT_TYPE_DEST,
    TARGET_OBJECT_TYPE_UNIT,
    TARGET_OBJECT_TYPE_UNIT_AND_DEST,
    TARGET_OBJECT_TYPE_GOBJ,
    TARGET_OBJECT_TYPE_GOBJ_ITEM,
    TARGET_OBJECT_TYPE_ITEM,
    TARGET_OBJECT_TYPE_CORPSE,
    // only for effect target type
    TARGET_OBJECT_TYPE_CORPSE_ENEMY,
    TARGET_OBJECT_TYPE_CORPSE_ALLY
};

enum SpellTargetCheckTypes : uint8
{
    TARGET_CHECK_DEFAULT,
    TARGET_CHECK_ENTRY,
    TARGET_CHECK_ENEMY,
    TARGET_CHECK_ALLY,
    TARGET_CHECK_PARTY,
    TARGET_CHECK_RAID,
    TARGET_CHECK_RAID_CLASS,
    TARGET_CHECK_PASSENGER
};

enum SpellTargetDirectionTypes
{
    TARGET_DIR_NONE,
    TARGET_DIR_FRONT,
    TARGET_DIR_BACK,
    TARGET_DIR_RIGHT,
    TARGET_DIR_LEFT,
    TARGET_DIR_FRONT_RIGHT,
    TARGET_DIR_BACK_RIGHT,
    TARGET_DIR_BACK_LEFT,
    TARGET_DIR_FRONT_LEFT,
    TARGET_DIR_RANDOM,
    TARGET_DIR_ENTRY
};

enum SpellEffectImplicitTargetTypes
{
    EFFECT_IMPLICIT_TARGET_NONE = 0,
    EFFECT_IMPLICIT_TARGET_EXPLICIT,
    EFFECT_IMPLICIT_TARGET_CASTER
};

// Spell clasification
enum SpellSpecificType
{
    SPELL_SPECIFIC_NORMAL                        = 0,
    SPELL_SPECIFIC_SEAL                          = 1,
    SPELL_SPECIFIC_AURA                          = 3,
    SPELL_SPECIFIC_STING                         = 4,
    SPELL_SPECIFIC_CURSE                         = 5,
    SPELL_SPECIFIC_ASPECT                        = 6,
    SPELL_SPECIFIC_TRACKER                       = 7,
    SPELL_SPECIFIC_WARLOCK_ARMOR                 = 8,
    SPELL_SPECIFIC_MAGE_ARMOR                    = 9,
    SPELL_SPECIFIC_ELEMENTAL_SHIELD              = 10,
    SPELL_SPECIFIC_MAGE_POLYMORPH                = 11,
    SPELL_SPECIFIC_JUDGEMENT                     = 13,
    SPELL_SPECIFIC_WARLOCK_CORRUPTION            = 17,
    SPELL_SPECIFIC_FOOD                          = 19,
    SPELL_SPECIFIC_DRINK                         = 20,
    SPELL_SPECIFIC_FOOD_AND_DRINK                = 21,
    SPELL_SPECIFIC_PRESENCE                      = 22,
    SPELL_SPECIFIC_CHARM                         = 23,
    SPELL_SPECIFIC_SCROLL                        = 24,
    SPELL_SPECIFIC_MAGE_ARCANE_BRILLANCE         = 25,
    SPELL_SPECIFIC_WARRIOR_ENRAGE                = 26,
    SPELL_SPECIFIC_PRIEST_DIVINE_SPIRIT          = 27,
    SPELL_SPECIFIC_HAND                          = 28
};

enum SpellCustomAttributes
{
    SPELL_ATTR0_CU_ENCHANT_PROC                  = 0x00000001,
    SPELL_ATTR0_CU_CONE_BACK                     = 0x00000002,
    SPELL_ATTR0_CU_CONE_LINE                     = 0x00000004,
    SPELL_ATTR0_CU_SHARE_DAMAGE                  = 0x00000008,
    SPELL_ATTR0_CU_NO_INITIAL_THREAT             = 0x00000010,
    SPELL_ATTR0_CU_AURA_CC                       = 0x00000020,
    SPELL_ATTR0_CU_DONT_BREAK_STEALTH            = 0x00000040,
    SPELL_ATTR0_CU_CAN_CRIT                      = 0x00000080,
    SPELL_ATTR0_CU_DIRECT_DAMAGE                 = 0x00000100,
    SPELL_ATTR0_CU_CHARGE                        = 0x00000200,
    SPELL_ATTR0_CU_PICKPOCKET                    = 0x00000400,
    SPELL_ATTR0_CU_ROLLING_PERIODIC              = 0x00000800,
    SPELL_ATTR0_CU_NEGATIVE_EFF0                 = 0x00001000,
    SPELL_ATTR0_CU_NEGATIVE_EFF1                 = 0x00002000,
    SPELL_ATTR0_CU_NEGATIVE_EFF2                 = 0x00004000,
    SPELL_ATTR0_CU_IGNORE_ARMOR                  = 0x00008000,
    SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER      = 0x00010000,
    SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET      = 0x00020000,
    SPELL_ATTR0_CU_ALLOW_INFLIGHT_TARGET         = 0x00040000,
    SPELL_ATTR0_CU_NEEDS_AMMO_DATA               = 0x00080000,
    SPELL_ATTR0_CU_BINARY_SPELL                  = 0x00100000,
    SPELL_ATTR0_CU_SCHOOLMASK_NORMAL_WITH_MAGIC  = 0x00200000,
    SPELL_ATTR0_CU_DEPRECATED_LIQUID_AURA        = 0x00400000, // DO NOT REUSE
    SPELL_ATTR0_CU_IS_TALENT                     = 0x00800000, // reserved for master branch
    SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED          = 0x01000000,
    SPELL_ATTR0_CU_CAN_TARGET_ANY_PRIVATE_OBJECT = 0x02000000, // reserved for master branch

    SPELL_ATTR0_CU_NEGATIVE                      = SPELL_ATTR0_CU_NEGATIVE_EFF0 | SPELL_ATTR0_CU_NEGATIVE_EFF1 | SPELL_ATTR0_CU_NEGATIVE_EFF2
};

uint32 GetTargetFlagMask(SpellTargetObjectTypes objType);

class TC_GAME_API SpellImplicitTargetInfo
{
private:
    Targets _target;
public:
    SpellImplicitTargetInfo() : _target(Targets(0)) { }
    SpellImplicitTargetInfo(uint32 target);

    bool IsArea() const;
    SpellTargetSelectionCategories GetSelectionCategory() const;
    SpellTargetReferenceTypes GetReferenceType() const;
    SpellTargetObjectTypes GetObjectType() const;
    SpellTargetCheckTypes GetCheckType() const;
    SpellTargetDirectionTypes GetDirectionType() const;
    float CalcDirectionAngle() const;

    Targets GetTarget() const;
    uint32 GetExplicitTargetMask(bool& srcSet, bool& dstSet) const;

private:
    struct StaticData
    {
        SpellTargetObjectTypes ObjectType;    // type of object returned by target type
        SpellTargetReferenceTypes ReferenceType; // defines which object is used as a reference when selecting target
        SpellTargetSelectionCategories SelectionCategory;
        SpellTargetCheckTypes SelectionCheckType; // defines selection criteria
        SpellTargetDirectionTypes DirectionType; // direction for cone and dest targets
    };
    static std::array<StaticData, TOTAL_SPELL_TARGETS> _data;
};

class TC_GAME_API SpellEffectInfo
{
    friend class SpellInfo;
    SpellInfo const* _spellInfo;
public:
    SpellEffIndex EffectIndex;
    SpellEffects Effect;
    AuraType  ApplyAuraName;
    uint32    Amplitude;
    int32     DieSides;
    float     RealPointsPerLevel;
    int32     BasePoints;
    float     PointsPerComboPoint;
    float     ValueMultiplier;
    float     DamageMultiplier;
    float     BonusMultiplier;
    int32     MiscValue;
    int32     MiscValueB;
    Mechanics Mechanic;
    SpellImplicitTargetInfo TargetA;
    SpellImplicitTargetInfo TargetB;
    SpellRadiusEntry const* RadiusEntry;
    uint32    ChainTarget;
    uint32    ItemType;
    uint32    TriggerSpell;
    flag96    SpellClassMask;
    std::vector<Condition*>* ImplicitTargetConditions;

    SpellEffectInfo();
    explicit SpellEffectInfo(SpellEntry const* spellEntry, SpellInfo const* spellInfo, uint8 effIndex);
    SpellEffectInfo(SpellEffectInfo const&) = delete;
    SpellEffectInfo(SpellEffectInfo&&) noexcept;
    SpellEffectInfo& operator=(SpellEffectInfo const&) = delete;
    SpellEffectInfo& operator=(SpellEffectInfo&&) noexcept;
    ~SpellEffectInfo();

    bool IsEffect() const;
    bool IsEffect(SpellEffects effectName) const;
    bool IsAura() const;
    bool IsAura(AuraType aura) const;
    bool IsTargetingArea() const;
    bool IsAreaAuraEffect() const;
    bool IsUnitOwnedAuraEffect() const;

    int32 CalcValue(WorldObject const* caster = nullptr, int32 const* basePoints = nullptr) const;
    int32 CalcBaseValue(int32 value) const;
    float CalcValueMultiplier(WorldObject* caster, Spell* spell = nullptr) const;
    float CalcDamageMultiplier(WorldObject* caster, Spell* spell = nullptr) const;

    bool HasRadius() const;
    float CalcRadius(WorldObject* caster = nullptr, Spell* = nullptr) const;

    uint32 GetProvidedTargetMask() const;
    uint32 GetMissingTargetMask(bool srcSet = false, bool destSet = false, uint32 mask = 0) const;

    SpellEffectImplicitTargetTypes GetImplicitTargetType() const;
    SpellTargetObjectTypes GetUsedTargetObjectType() const;

    struct ImmunityInfo;
    ImmunityInfo const* GetImmunityInfo() const { return _immunityInfo.get(); }

private:
    struct StaticData
    {
        SpellEffectImplicitTargetTypes ImplicitTargetType; // defines what target can be added to effect target list if there's no valid target type provided for effect
        SpellTargetObjectTypes UsedTargetObjectType; // defines valid target object type for spell effect
    };
    static std::array<StaticData, TOTAL_SPELL_EFFECTS> _data;

    std::unique_ptr<ImmunityInfo> _immunityInfo;
};

struct TC_GAME_API SpellDiminishInfo
{
    DiminishingGroup DiminishGroup = DIMINISHING_NONE;
    DiminishingReturnsType DiminishReturnType = DRTYPE_NONE;
    DiminishingLevels DiminishMaxLevel = DIMINISHING_LEVEL_IMMUNE;
    int32 DiminishDurationLimit = 0;
};

class TC_GAME_API SpellInfo
{
    friend class SpellMgr;

    public:
        uint32 Id;                                               // 法术 ID（Spell.dbc / SpellEntry 的主键）

        SpellCategoryEntry const* CategoryEntry;                 // 法术分类信息（冷却共享、类别冷却等）

        uint32 Dispel;                                           // 驱散类型（DispelType）（Magic / Curse / Poison / Disease 等）

        uint32 Mechanic;                                         // 法术机制类型（Mechanics）（眩晕、恐惧、定身等）

        uint32 Attributes;                                       // SpellAttr0：法术“基础语义位”。决定最顶层的施放规则与标签化行为：
                                                                 // - 施放者状态约束：可否死亡/坐骑/坐下施放（CASTABLE_WHILE_DEAD/MOUNTED/SITTING）
                                                                 // - 环境约束：室内/室外（INDOORS_ONLY/OUTDOORS_ONLY）
                                                                 // - 形态/潜行约束：变形/潜行限制（NOT_SHAPESHIFT/ONLY_STEALTHED）
                                                                 // - 战斗与可用性：是否禁止战斗中使用（CANT_USED_IN_COMBAT）
                                                                 // - 冷却语义：效果存在期间不可再次使用，且冷却在效果结束后才开始（DISABLED_WHILE_ACTIVE）
                                                                 // - 目标/命中模型：是否不可闪避/招架/格挡（IMPOSSIBLE_DODGE_PARRY_BLOCK）
                                                                 // - 伤害缩放：对非玩家施放时按施法者等级缩放效果与消耗（LEVEL_DAMAGE_CALCULATION）
                                                                 // - 负面/正面强制：强制视为负面法术（NEGATIVE_1），影响光环/驱散/敌对判定
                                                                 // - 免疫穿透：可穿透“无敌类”效果（UNAFFECTED_BY_INVULNERABILITY）【注意对向也需要该位才互穿】
                                                                 // - 心跳抗性复检：周期性重判抗性以提前终止光环（HEARTBEAT_RESIST_CHECK）
                                                                 // - 光环不可取消：玩家不能手动取消（CANT_CANCEL）
                                                                 // 另外：REQ_AMMO/ABILITY/TRADESPELL/PASSIVE 等位决定“它被当作普攻/技能/配方/被动”的大类处理路径。
        
        uint32 AttributesEx;                                     // SpellAttr1：施法/引导/威胁/重定向相关的“战斗语义扩展”：
                                                                 // - 引导语义：标记为引导（CHANNELED_1/CHANNELED_2），决定引导条/打断/每跳逻辑
                                                                 // - 反射/重定向：是否忽略反射（CANT_BE_REFLECTED）或忽略磁吸/吸收类重定向（CANT_BE_REDIRECTED）
                                                                 // - 潜行保持：施放不破潜行（NOT_BREAK_STEALTH）
                                                                 // - 目标约束：目标必须不在战斗（CANT_TARGET_IN_COMBAT）、不能自施（CANT_TARGET_SELF）
                                                                 // - 仇恨语义：不产生仇恨且不拉怪（NO_THREAT）
                                                                 // - 光环重施：重施不刷新持续时间（DONT_REFRESH_DURATION_ON_RECAST）
                                                                 // - 宠物相关：施放会解散宠物（DISMISS_PET）、宠物不能自动施放（UNAUTOCASTABLE_BY_PET）
                                                                 // - 连击点：需要连击点（REQ_COMBO_POINTS1/2）
                                                                 // - 免疫施加副作用：免疫类法术在施加时会清掉其免疫掉的既有光环（DISPEL_AURAS_ON_IMMUNITY）
                                                                 // - 免疫交互：标记为“不会穿透学派免疫/无敌类”（UNAFFECTED_BY_SCHOOL_IMMUNE）用于细分免疫体系
                                                                 // 备注：MELEE_COMBAT_START 为客户端语义（自动开平砍），服务器通常仍会参考以保持一致体验。
        
        uint32 AttributesEx2;                                    // SpellAttr2：目标选择/可见性/自动攻击计时器/特殊系统（驯服、食物、竞技场）：
                                                                 // - 目标合法性：允许目标为尸体/死人（CAN_TARGET_DEAD），允许无视视线（CAN_TARGET_NOT_IN_LOS）
                                                                 // - 归属限制：不能对“别人已标记(tap)”的怪施放（CANT_TARGET_TAPPED）
                                                                 // - 远程自动攻击：标记为远程自动射击（AUTOREPEAT_FLAG）
                                                                 // - 计时器语义：施放不重置普攻摆动计时（NOT_RESET_AUTO_ACTIONS）
                                                                 // - 形态例外：即使有 Stances 限制，也允许“非变形状态”施放（NOT_NEED_SHAPESHIFT）
                                                                 // - 全免疫失败语义：若目标全免疫则施放失败（FAIL_ON_ALL_TARGETS_IMMUNE）并影响战场旗帜等逻辑
                                                                 // - 光环施加免疫穿透：允许在“禁止新光环”类免疫下仍能上光环（UNAFFECTED_BY_AURA_SCHOOL_IMMUNE）
                                                                 // - 暴击语义：禁止暴击（CANT_CRIT）
                                                                 // - 威胁语义：Active Threat（用于某些主动仇恨/拉怪规则）
                                                                 // - 特殊标记：TAME_BEAST / HEALTH_FUNNEL / FOOD_BUFF 等会进入特化逻辑分支。
        
        uint32 AttributesEx3;                                    // SpellAttr3：Proc 链路、命中结果、叠加模型、武器需求与“死亡持久”等：
                                                                 // - Proc 传播：触发法术是否能再触发别的 Proc（NOT_A_PROC / CANT_TRIGGER_PROC / CAN_PROC_FROM_PROCS）
                                                                 // - 命中结果：忽略命中结果（IGNORE_HIT_RESULT）=> 不能 miss/dodge/parry/block（比 Attr0 的“仅物理避免”更广）
                                                                 // - 叠加模型：不同施法者分别叠（STACK_FOR_DIFF_CASTERS）
                                                                 // - 目标过滤：只能选玩家/幽灵（ONLY_TARGET_PLAYERS / ONLY_TARGET_GHOSTS）
                                                                 // - 装备需求：主手/副手/魔杖要求（MAIN_HAND / REQ_OFFHAND / REQ_WAND）
                                                                 // - 仇恨/开怪：无初始仇恨（NO_INITIAL_AGGRO）
                                                                 // - 死亡持久：光环死亡不掉（DEATH_PERSISTENT）
                                                                 // - 伤害修正隔离：造成伤害不吃增伤修正（NO_DONE_BONUS）
                                                                 // - Treat as periodic：把效果当成周期性处理（TREAT_AS_PERIODIC）影响跳数/触发/驱散等路径。
        
        uint32 AttributesEx4;                                    // SpellAttr4：抗性/偷取/并行施法/竞技场/物品触发等“规则修饰层”：
                                                                 // - 抗性体系：不可被抵抗（IGNORE_RESISTANCES）
                                                                 // - 光环可偷取：禁止法术偷取/驱散偷取（NOT_STEALABLE）
                                                                 // - 并行施法：允许在施法过程中施放（CAN_CAST_WHILE_CASTING）=> 打破“正在读条则拒绝”的顶层限制
                                                                 // - 固定伤害：造成固定伤害（FIXED_DAMAGE）通常绕开部分系数计算
                                                                 // - 进入竞技场处理：不移除/强制移除/可用性覆盖（DONT_REMOVE_IN_ARENA / REMOVE_ON_ARENA_ENTER 见 Attr5 / NOT_USABLE_IN_ARENA / USABLE_IN_ARENA）
                                                                 // - 物品触发隔离：不能触发物品法术（CANT_TRIGGER_ITEM_SPELLS）
                                                                 // - 宠物缩放：宠物属性缩放光环（IS_PET_SCALING）
                                                                 // - 地域限制：只在外域/诺森德（CAST_ONLY_IN_OUTLAND）
                                                                 // - 施法条强制显示：FORCE_DISPLAY_CASTBAR
                                                                 // - Damage doesn't break auras：伤害不破隐身/控制等特定光环（DAMAGE_DOESNT_BREAK_AURAS）
        
        uint32 AttributesEx5;                                    // SpellAttr5：控制状态下可施放、周期 tick 行为、持续时间与 LOS 特例：
                                                                 // - 移动引导：可移动引导（CAN_CHANNEL_WHEN_MOVING）
                                                                 // - 控制态施法：可在眩晕/恐惧/混乱时施放（USABLE_WHILE_STUNNED/FEARED/CONFUSED）
                                                                 // - 单目标光环语义：同一施法者对不同目标只能存在一个（SINGLE_TARGET_SPELL）=> “转移目标会移除旧的”
                                                                 // - 周期 tick：上光环立刻跳一次（START_PERIODIC_AT_APPLY）
                                                                 // - 客户端显示：隐藏持续时间（HIDE_DURATION）
                                                                 // - 急速影响持续时间：HASTE_AFFECT_DURATION（改变 tick/总时长计算路径）
                                                                 // - 视线特例：跳过 checkcast LOS（SKIP_CHECKCAST_LOS_CHECK）
                                                                 // - Charm 限制：被魅惑单位不能施放（NOT_USABLE_WHILE_CHARMED）
                                                                 // - 朝向控制：施法时不自动转向（DONT_TURN_DURING_CAST）
        
        uint32 AttributesEx6;                                    // SpellAttr6：冷却显示/施法阻止光环忽略/Proc 消耗/隐身与不可选目标等杂项高影响位：
                                                                 // - 忽略施法者限制光环：IGNORE_CASTER_AURAS（绕过“禁止施法/沉默/变形”等阻止类光环检查的一部分）
                                                                 // - Proc charges：不消耗 proc 层数（DONT_CONSUME_PROC_CHARGES）
                                                                 // - 事件语义（客户端）：USE_SPELL_CAST_EVENT（影响客户端事件流）
                                                                 // - CC 目标过滤：隐式目标不命中被控目标（CANT_TARGET_CROWD_CONTROLLED）=> 链式/范围隐式选目标会跳过 CC
                                                                 // - 场景限制：非团队副本可用性 / 仅竞技场（NOT_IN_RAID_INSTANCE / ONLY_IN_ARENA）
                                                                 // - 载具：在载具上可施放（CASTABLE_WHILE_ON_VEHICLE）
                                                                 // - 目标可见性：可选隐形/不可被选中的单位（CAN_TARGET_INVISIBLE / CAN_TARGET_UNTARGETABLE）
                                                                 // - 摆动计时器：瞬发不重置摆动（NOT_RESET_SWING_IF_INSTANT）
                                                                 // - 限制百分比修正：限制可应用的%治疗/%伤害修正（LIMIT_PCT_HEALING_MODS / LIMIT_PCT_DAMAGE_MODS）
                                                                 // - 冷却修正豁免：忽略分类冷却的修正（IGNORE_CATEGORY_COOLDOWN_MODS）
        
        uint32 AttributesEx7;                                    // SpellAttr7：阵营/作弊/命中三连（不可躲/招/未命中）/复活与“客户端指示器”等尾部扩展：
                                                                 // - 时长修正豁免：IGNORE_DURATION_MODS（不吃天赋/光环对持续时间的改动）
                                                                 // - 死亡时禁用光环：DISABLE_AURA_WHILE_DEAD
                                                                 // - Cheat spell：需要特定 UnitFlag 才能施放（IS_CHEAT_SPELL）
                                                                 // - 阵营限制：HORDE_ONLY / ALLIANCE_ONLY
                                                                 // - 驱散/偷取语义：按 charge 单独移除（DISPEL_CHARGES）
                                                                 // - 打断限制：只打断非玩家施法（INTERRUPT_ONLY_NONPLAYER）
                                                                 // - 次级能量恢复：允许恢复非当前活跃能量条（CAN_RESTORE_SECONDARY_POWER）
                                                                 // - Charge effect：有冲锋类效果（HAS_CHARGE_EFFECT）
                                                                 // - 区域传送：ZONE_TELEPORT
                                                                 // - 命中结果强制：不可躲闪/招架/未命中（CANT_DODGE/CANT_PARRY/CANT_MISS）=> 对命中结算链路影响巨大
                                                                 // - 复活限制绕过：BYPASS_NO_RESURRECT_AURA
                                                                 // - 寒冷飞行限制绕过：IGNORE_COLD_WEATHER_FLYING
                                                                 // - 客户端显示：CONSOLIDATED_RAID_BUFF / CLIENT_INDICATOR 等
                                                                
        uint32 AttributesCu;                                     // SpellCustomAttributes：TC 额外补充的自定义行为位（用于修复 DBC 不足、兼容不同版本差异、
                                                                 // 或给核心逻辑提供更明确的分类/快速路径；不对应客户端 DBC 位，完全由服务器定义与消费）

        uint64 Stances;                                          // 允许施放的姿态（如战士姿态、德鲁伊形态）

        uint64 StancesNot;                                       // 禁止施放的姿态掩码

        uint32 Targets;                                          // 目标选择标志（SpellImplicitTarget）

        uint32 TargetCreatureType;                               // 目标生物类型限制（CreatureTypeMask）（亡灵、恶魔等）

        uint32 RequiresSpellFocus;                               // 施法所需的 Spell Focus（施法物件，图腾/法阵）

        uint32 FacingCasterFlags;                                // 是否要求目标面向施法者

        uint32 CasterAuraState;                                  // 施法者必须具备的 Aura 状态

        uint32 TargetAuraState;                                  // 目标必须具备的 Aura 状态

        uint32 CasterAuraStateNot;                               // 施法者不能具备的 Aura 状态

        uint32 TargetAuraStateNot;                               // 目标不能具备的 Aura 状态

        uint32 CasterAuraSpell;                                  // 施法者必须拥有的特定 Aura 法术

        uint32 TargetAuraSpell;                                  // 目标必须拥有的特定 Aura 法术

        uint32 ExcludeCasterAuraSpell;                           // 施法者不能拥有的 Aura 法术

        uint32 ExcludeTargetAuraSpell;                           // 目标不能拥有的 Aura 法术

        SpellCastTimesEntry const* CastTimeEntry;                // 施法时间配置（CastTime.dbc）

        uint32 RecoveryTime;                                     // 独立冷却时间（法术自身冷却时间）

        uint32 CategoryRecoveryTime;                             // 分类冷却时间（共享 CD）

        uint32 StartRecoveryCategory;                            // 启动冷却的分类

        uint32 StartRecoveryTime;                                // 启动冷却的时间（事件触发型）

        uint32 InterruptFlags;                                   // 施法打断条件（移动、受击等）

        uint32 AuraInterruptFlags;                               // Aura 可被打断的条件

        uint32 ChannelInterruptFlags;                            // 引导法术的打断条件

        uint32 ProcFlags;                                        // 触发条件（被攻击、暴击等）

        uint32 ProcChance;                                       // 触发概率百分比

        uint32 ProcCharges;                                      // 可触发次数

        uint32 MaxLevel;                                         // 法术允许施放的最大目标等级

        uint32 BaseLevel;                                        // 法术基础等级

        uint32 SpellLevel;                                       // 法术等级（用于判定学习 / 命中）

        SpellDurationEntry const* DurationEntry;                 // 法术持续时间配置

        Powers PowerType;                                        // 消耗的能量类型（Mana / Rage / Energy 等）

        uint32 ManaCost;                                         // 固定能量消耗

        uint32 ManaCostPerlevel;                                 // 每等级额外能量消耗

        uint32 ManaPerSecond;                                    // 每秒能量消耗（引导法术）

        uint32 ManaPerSecondPerLevel;                            // 每等级每秒能量消耗

        uint32 ManaCostPercentage;                               // 按百分比能量消耗

        uint32 RuneCostID;                                       // 符文消耗配置（死亡骑士）

        SpellRangeEntry const* RangeEntry;                       // 施法距离配置

        float  Speed;                                            // 飞行速度（飞弹、投射物）

        uint32 StackAmount;                                      // 最大叠加层数

        std::array<uint32, 2> Totem;                             // 施法所需图腾

        std::array<int32, MAX_SPELL_REAGENTS> Reagent;           // 法术所需材料

        std::array<uint32, MAX_SPELL_REAGENTS> ReagentCount;     // 法术所需材料数量

        int32  EquippedItemClass;                                // 装备类型限制

        int32  EquippedItemSubClassMask;                         // 装备子类型掩码

        int32  EquippedItemInventoryTypeMask;                    // 装备槽位掩码

        std::array<uint32, 2> TotemCategory;                     // 图腾分类限制

        std::array<uint32, 2> SpellVisual;                       // 法术视觉效果 ID

        uint32 SpellIconID;                                      // 法术图标 ID

        uint32 ActiveIconID;                                     // 激活状态图标 ID

        uint32 Priority;                                         // 法术优先级（客户端/系统使用）

        std::array<char const*, 16> SpellName;                   // 法术名称（多语言）

        std::array<char const*, 16> Rank;                        // 法术等级描述（多语言）

        uint32 MaxTargetLevel;                                   // 最大可影响目标等级

        uint32 MaxAffectedTargets;                               // 最大可影响目标数量

        uint32 SpellFamilyName;                                  // 法术家族（职业相关）

        flag96 SpellFamilyFlags;                                 // 法术家族标志位（用于天赋/触发）

        uint32 DmgClass;                                         // 伤害类型（近战 / 远程 / 魔法）

        uint32 PreventionType;                                   // 免疫类型（如沉默）

        int32  AreaGroupId;                                      // 区域限制（仅允许在特定区域）

        uint32 SchoolMask;                                       // 法术学派掩码（Fire/Frost/Arcane 等）

        std::array<SpellEffectInfo, MAX_SPELL_EFFECTS> _effects; // 法术效果数组（最多 3 个）

        uint32 ExplicitTargetMask;                               // 显式目标掩码（运行时计算）

        SpellChainNode const* ChainEntry;                        // 法术等级链（Rank 链）

        SpellInfo(SpellEntry const* spellEntry);
        ~SpellInfo();

        uint32 GetCategory() const;
        bool HasEffect(SpellEffects effect) const;
        bool HasAura(AuraType aura) const;
        bool HasAreaAuraEffect() const;
        bool HasOnlyDamageEffects() const;

        inline bool HasAttribute(SpellAttr0 attribute) const { return !!(Attributes & attribute); }
        inline bool HasAttribute(SpellAttr1 attribute) const { return !!(AttributesEx & attribute); }
        inline bool HasAttribute(SpellAttr2 attribute) const { return !!(AttributesEx2 & attribute); }
        inline bool HasAttribute(SpellAttr3 attribute) const { return !!(AttributesEx3 & attribute); }
        inline bool HasAttribute(SpellAttr4 attribute) const { return !!(AttributesEx4 & attribute); }
        inline bool HasAttribute(SpellAttr5 attribute) const { return !!(AttributesEx5 & attribute); }
        inline bool HasAttribute(SpellAttr6 attribute) const { return !!(AttributesEx6 & attribute); }
        inline bool HasAttribute(SpellAttr7 attribute) const { return !!(AttributesEx7 & attribute); }
        inline bool HasAttribute(SpellCustomAttributes customAttribute) const { return !!(AttributesCu & customAttribute); }

        bool IsExplicitDiscovery() const;
        bool IsLootCrafting() const;
        bool IsProfessionOrRiding() const;
        bool IsProfession() const;
        bool IsPrimaryProfession() const;
        bool IsPrimaryProfessionFirstRank() const;
        bool IsAbilityLearnedWithProfession() const;
        bool IsAbilityOfSkillType(uint32 skillType) const;

        bool IsAffectingArea() const;
        bool IsTargetingArea() const;
        bool NeedsExplicitUnitTarget() const;
        bool NeedsToBeTriggeredByCaster(SpellInfo const* triggeringSpell) const;
        bool IsSelfCast() const;

        bool IsPassive() const;
        bool IsAutocastable() const;
        bool IsStackableWithRanks() const;
        bool IsPassiveStackableWithRanks() const;
        bool IsMultiSlotAura() const;
        bool IsStackableOnOneSlotWithDifferentCasters() const;
        bool IsCooldownStartedOnEvent() const;
        bool IsDeathPersistent() const;
        bool IsRequiringDeadTarget() const;
        bool IsAllowingDeadTarget() const;
        bool IsGroupBuff() const;
        bool CanBeUsedInCombat() const;
        bool IsPositive() const;
        bool IsPositiveEffect(uint8 effIndex) const;
        bool IsChanneled() const;
        bool IsMoveAllowedChannel() const;
        bool NeedsComboPoints() const;
        bool IsNextMeleeSwingSpell() const;
        bool IsBreakingStealth() const;
        bool IsRangedWeaponSpell() const;
        bool IsAutoRepeatRangedSpell() const;
        bool HasInitialAggro() const;

        WeaponAttackType GetAttackType() const;

        bool IsItemFitToSpellRequirements(Item const* item) const;

        bool IsAffected(uint32 familyName, flag96 const& familyFlags) const;

        bool IsAffectedBySpellMods() const;
        bool IsAffectedBySpellMod(SpellModifier const* mod) const;

        bool CanPierceImmuneAura(SpellInfo const* auraSpellInfo) const;
        bool CanDispelAura(SpellInfo const* auraSpellInfo) const;

        bool IsSingleTarget() const;
        bool IsAuraExclusiveBySpecificWith(SpellInfo const* spellInfo) const;
        bool IsAuraExclusiveBySpecificPerCasterWith(SpellInfo const* spellInfo) const;

        SpellCastResult CheckShapeshift(uint32 form) const;
        SpellCastResult CheckLocation(uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player = nullptr, bool strict = true) const;
        SpellCastResult CheckTarget(WorldObject const* caster, WorldObject const* target, bool implicit = true) const;
        SpellCastResult CheckExplicitTarget(WorldObject const* caster, WorldObject const* target, Item const* itemTarget = nullptr) const;
        SpellCastResult CheckVehicle(Unit const* caster) const;
        bool CheckTargetCreatureType(Unit const* target) const;

        SpellSchoolMask GetSchoolMask() const;
        uint32 GetAllEffectsMechanicMask() const;
        uint32 GetEffectMechanicMask(SpellEffIndex effIndex) const;
        uint32 GetSpellMechanicMaskByEffectMask(uint32 effectMask) const;
        Mechanics GetEffectMechanic(SpellEffIndex effIndex) const;
        uint32 GetDispelMask() const;
        static uint32 GetDispelMask(DispelType type);
        uint32 GetExplicitTargetMask() const;

        AuraStateType GetAuraState() const;
        SpellSpecificType GetSpellSpecific() const;

        float GetMinRange(bool positive = false) const;
        float GetMaxRange(bool positive = false, WorldObject* caster = nullptr, Spell* spell = nullptr) const;

        int32 GetDuration() const;
        int32 GetMaxDuration() const;

        uint32 GetMaxTicks() const;

        uint32 CalcCastTime(Spell* spell = nullptr) const;
        uint32 GetRecoveryTime() const;

        int32 CalcPowerCost(WorldObject const* caster, SpellSchoolMask schoolMask, Spell* spell = nullptr) const;

        bool IsRanked() const;
        uint8 GetRank() const;
        SpellInfo const* GetFirstRankSpell() const;
        SpellInfo const* GetLastRankSpell() const;
        SpellInfo const* GetNextRankSpell() const;
        SpellInfo const* GetPrevRankSpell() const;
        SpellInfo const* GetAuraRankForLevel(uint8 level) const;
        bool IsRankOf(SpellInfo const* spellInfo) const;
        bool IsDifferentRankOf(SpellInfo const* spellInfo) const;
        bool IsHighRankOf(SpellInfo const* spellInfo) const;

        std::array<SpellEffectInfo, MAX_SPELL_EFFECTS> const& GetEffects() const { return _effects; }
        SpellEffectInfo const& GetEffect(SpellEffIndex index) const { ASSERT(index < _effects.size()); return _effects[index]; }

        // spell diminishing returns
        DiminishingGroup GetDiminishingReturnsGroupForSpell(bool triggered) const;
        DiminishingReturnsType GetDiminishingReturnsGroupType(bool triggered) const;
        DiminishingLevels GetDiminishingReturnsMaxLevel(bool triggered) const;
        int32 GetDiminishingReturnsLimitDuration(bool triggered) const;

        // spell immunities
        void ApplyAllSpellImmunitiesTo(Unit* target, SpellEffectInfo const& spellEffectInfo, bool apply) const;
        bool CanSpellProvideImmunityAgainstAura(SpellInfo const* auraSpellInfo) const;
        bool SpellCancelsAuraEffect(AuraEffect const* aurEff) const;

        uint32 GetAllowedMechanicMask() const;

        uint32 GetMechanicImmunityMask(Unit* caster) const;

    private:
        // loading helpers
        void _InitializeExplicitTargetMask();
        void _InitializeSpellPositivity();
        void _LoadSpellSpecific();
        void _LoadAuraState();
        void _LoadSpellDiminishInfo();
        void _LoadImmunityInfo();

        std::array<SpellEffectInfo, MAX_SPELL_EFFECTS>& _GetEffects() { return _effects; }
        SpellEffectInfo& _GetEffect(SpellEffIndex index) { ASSERT(index < _effects.size()); return _effects[index]; }

        // unloading helpers
        void _UnloadImplicitTargetConditionLists();

        SpellSpecificType _spellSpecific;
        AuraStateType _auraState;

        SpellDiminishInfo _diminishInfoNonTriggered;
        SpellDiminishInfo _diminishInfoTriggered;

        uint32 _allowedMechanicMask;
};

#endif // _SPELLINFO_H
