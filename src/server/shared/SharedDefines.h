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

#ifndef TRINITY_SHAREDDEFINES_H
#define TRINITY_SHAREDDEFINES_H

#include "DBCEnums.h"
#include "Define.h"
#include "EnumFlag.h"
#include "SmartEnum.h"

float const GROUND_HEIGHT_TOLERANCE = 0.05f; // Extra tolerance to z position to check if it is in air or on ground.
constexpr float Z_OFFSET_FIND_HEIGHT = 1.5f;

enum SpellEffIndex : uint8
{
    EFFECT_0 = 0,
    EFFECT_1 = 1,
    EFFECT_2 = 2
};

// used in script definitions
#define EFFECT_FIRST_FOUND 254
#define EFFECT_ALL 255

// loot modes for creatures and gameobjects, bitmask!
enum LootModes
{
    LOOT_MODE_DEFAULT                  = 0x1,
    LOOT_MODE_HARD_MODE_1              = 0x2,
    LOOT_MODE_HARD_MODE_2              = 0x4,
    LOOT_MODE_HARD_MODE_3              = 0x8,
    LOOT_MODE_HARD_MODE_4              = 0x10,
    LOOT_MODE_JUNK_FISH                = 0x8000
};

enum Expansions
{
    EXPANSION_CLASSIC                  = 0,
    EXPANSION_THE_BURNING_CRUSADE      = 1,
    EXPANSION_WRATH_OF_THE_LICH_KING   = 2,
    MAX_EXPANSIONS                     = 3
};

inline uint32 GetMaxLevelForExpansion(uint32 expansion)
{
    switch (expansion)
    {
        case EXPANSION_CLASSIC:
            return 60;
        case EXPANSION_THE_BURNING_CRUSADE:
            return 70;
        case EXPANSION_WRATH_OF_THE_LICH_KING:
            return 80;
        default:
            break;
    }
    return DEFAULT_MAX_LEVEL;
}

enum Gender
{
    GENDER_MALE                        = 0,
    GENDER_FEMALE                      = 1,
    GENDER_NONE                        = 2
};

// Race value is index in ChrRaces.dbc
// EnumUtils: DESCRIBE THIS
enum Races
{
    RACE_NONE               = 0,  // SKIP
    RACE_HUMAN              = 1,  // TITLE Human
    RACE_ORC                = 2,  // TITLE Orc
    RACE_DWARF              = 3,  // TITLE Dwarf
    RACE_NIGHTELF           = 4,  // TITLE Night Elf
    RACE_UNDEAD_PLAYER      = 5,  // TITLE Undead
    RACE_TAUREN             = 6,  // TITLE Tauren
    RACE_GNOME              = 7,  // TITLE Gnome
    RACE_TROLL              = 8,  // TITLE Troll
    //RACE_GOBLIN             = 9,
    RACE_BLOODELF           = 10, // TITLE Blood Elf
    RACE_DRAENEI            = 11 //, TITLE Draenei
    //RACE_FEL_ORC            = 12,
    //RACE_NAGA               = 13,
    //RACE_BROKEN             = 14,
    //RACE_SKELETON           = 15,
    //RACE_VRYKUL             = 16,
    //RACE_TUSKARR            = 17,
    //RACE_FOREST_TROLL       = 18,
    //RACE_TAUNKA             = 19,
    //RACE_NORTHREND_SKELETON = 20,
    //RACE_ICE_TROLL          = 21
};

// max+1 for player race
#define MAX_RACES         12

#define RACEMASK_ALL_PLAYABLE      \
    ((1<<(RACE_HUMAN-1))         | \
     (1<<(RACE_ORC-1))           | \
     (1<<(RACE_DWARF-1))         | \
     (1<<(RACE_NIGHTELF-1))      | \
     (1<<(RACE_UNDEAD_PLAYER-1)) | \
     (1<<(RACE_TAUREN-1))        | \
     (1<<(RACE_GNOME-1))         | \
     (1<<(RACE_TROLL-1))         | \
     (1<<(RACE_BLOODELF-1))      | \
     (1<<(RACE_DRAENEI-1)))

#define RACEMASK_ALLIANCE     \
    ((1<<(RACE_HUMAN-1))    | \
     (1<<(RACE_DWARF-1))    | \
     (1<<(RACE_NIGHTELF-1)) | \
     (1<<(RACE_GNOME-1))    | \
     (1<<(RACE_DRAENEI-1)))

#define RACEMASK_HORDE RACEMASK_ALL_PLAYABLE & ~RACEMASK_ALLIANCE

// Class value is index in ChrClasses.dbc
// EnumUtils: DESCRIBE THIS
enum Classes
{
    CLASS_NONE          = 0, // SKIP
    CLASS_WARRIOR       = 1, // TITLE Warrior
    CLASS_PALADIN       = 2, // TITLE Paladin
    CLASS_HUNTER        = 3, // TITLE Hunter
    CLASS_ROGUE         = 4, // TITLE Rogue
    CLASS_PRIEST        = 5, // TITLE Priest
    CLASS_DEATH_KNIGHT  = 6, // TITLE Death Knight
    CLASS_SHAMAN        = 7, // TITLE Shaman
    CLASS_MAGE          = 8, // TITLE Mage
    CLASS_WARLOCK       = 9, // TITLE Warlock
    //CLASS_UNK           = 10,
    CLASS_DRUID         = 11 // TITLE Druid
};

// max+1 for player class
#define MAX_CLASSES       12

#define CLASSMASK_ALL_PLAYABLE     \
    ((1<<(CLASS_WARRIOR-1))      | \
     (1<<(CLASS_PALADIN-1))      | \
     (1<<(CLASS_HUNTER-1))       | \
     (1<<(CLASS_ROGUE-1))        | \
     (1<<(CLASS_PRIEST-1))       | \
     (1<<(CLASS_DEATH_KNIGHT-1)) | \
     (1<<(CLASS_SHAMAN-1))       | \
     (1<<(CLASS_MAGE-1))         | \
     (1<<(CLASS_WARLOCK-1))      | \
     (1<<(CLASS_DRUID-1)))

#define MAX_TALENT_TREES 3

enum PlayerSpecializations
{
    SPEC_WARRIOR_ARMS = 0,
    SPEC_WARRIOR_FURY = 1,
    SPEC_WARRIOR_PROTECTION = 2,
    SPEC_PALADIN_HOLY = 0,
    SPEC_PALADIN_PROTECTION = 1,
    SPEC_PALADIN_RETRIBUTION = 2,
    SPEC_HUNTER_BEAST_MASTERY = 0,
    SPEC_HUNTER_MARKSMANSHIP = 1,
    SPEC_HUNTER_SURVIVAL = 2,
    SPEC_ROGUE_ASSASSINATION = 0,
    SPEC_ROGUE_COMBAT = 1,
    SPEC_ROGUE_SUBLETY = 2,
    SPEC_PRIEST_DISCIPLINE = 0,
    SPEC_PRIEST_HOLY = 1,
    SPEC_PRIEST_SHADOW = 2,
    SPEC_DEATH_KNIGHT_BLOOD = 0,
    SPEC_DEATH_KNIGHT_FROST = 1,
    SPEC_DEATH_KNIGHT_UNHOLY = 2,
    SPEC_SHAMAN_ELEMENTAL = 0,
    SPEC_SHAMAN_ENHANCEMENT = 1,
    SPEC_SHAMAN_RESTORATION = 2,
    SPEC_MAGE_ARCANE = 0,
    SPEC_MAGE_FIRE = 1,
    SPEC_MAGE_FROST = 2,
    SPEC_WARLOCK_AFFLICTION = 0,
    SPEC_WARLOCK_DEMONOLOGY = 1,
    SPEC_WARLOCK_DESTRUCTION = 2,
    SPEC_DRUID_BALANCE = 0,
    SPEC_DRUID_FERAL = 1,
    SPEC_DRUID_RESTORATION = 2
};

// valid classes for creature_template.unit_class
enum UnitClass
{
    UNIT_CLASS_WARRIOR                  = 1,
    UNIT_CLASS_PALADIN                  = 2,
    UNIT_CLASS_ROGUE                    = 4,
    UNIT_CLASS_MAGE                     = 8
};

#define CLASSMASK_ALL_CREATURES ((1<<(UNIT_CLASS_WARRIOR-1)) | (1<<(UNIT_CLASS_PALADIN-1)) | (1<<(UNIT_CLASS_ROGUE-1)) | (1<<(UNIT_CLASS_MAGE-1)))

#define CLASSMASK_WAND_USERS ((1<<(CLASS_PRIEST-1)) | (1<<(CLASS_MAGE-1)) | (1<<(CLASS_WARLOCK-1)))

#define PLAYER_MAX_BATTLEGROUND_QUEUES 2

enum ReputationRank
{
    REP_HATED       = 0,
    REP_HOSTILE     = 1,
    REP_UNFRIENDLY  = 2,
    REP_NEUTRAL     = 3,
    REP_FRIENDLY    = 4,
    REP_HONORED     = 5,
    REP_REVERED     = 6,
    REP_EXALTED     = 7
};

enum FactionTemplates
{
    FACTION_NONE                        = 0,
    FACTION_CREATURE                    = 7,
    FACTION_ESCORTEE_A_NEUTRAL_PASSIVE  = 10,
    FACTION_MONSTER                     = 14,
    FACTION_MONSTER_2                   = 16,
    FACTION_TROLL_BLOODSCALP            = 28,
    FACTION_PREY                        = 31,
    FACTION_ESCORTEE_H_NEUTRAL_PASSIVE  = 33,
    FACTION_FRIENDLY                    = 35,
    FACTION_TROLL_FROSTMANE             = 37,
    FACTION_OGRE                        = 45,
    FACTION_ORC_DRAGONMAW               = 62,
    FACTION_HORDE_GENERIC               = 83,
    FACTION_ALLIANCE_GENERIC            = 84,
    FACTION_DEMON                       = 90,
    FACTION_ELEMENTAL                   = 91,
    FACTION_DRAGONFLIGHT_BLACK          = 103,
    FACTION_ESCORTEE_N_NEUTRAL_PASSIVE  = 113,
    FACTION_ENEMY                       = 168,
    FACTION_ESCORTEE_A_NEUTRAL_ACTIVE   = 231,
    FACTION_ESCORTEE_H_NEUTRAL_ACTIVE   = 232,
    FACTION_ESCORTEE_N_NEUTRAL_ACTIVE   = 250,
    FACTION_ESCORTEE_N_FRIEND_PASSIVE   = 290,
    FACTION_TITAN                       = 415,
    FACTION_ESCORTEE_N_FRIEND_ACTIVE    = 495,
    FACTION_RATCHET                     = 637,
    FACTION_GOBLIN_DARK_IRON_BAR_PATRON = 736,
    FACTION_DARK_IRON_DWARVES           = 754,
    FACTION_ESCORTEE_A_PASSIVE          = 774,
    FACTION_ESCORTEE_H_PASSIVE          = 775,
    FACTION_UNDEAD_SCOURGE              = 974,
    FACTION_EARTHEN_RING                = 1726,
    FACTION_ALLIANCE_GENERIC_WG         = 1732,
    FACTION_HORDE_GENERIC_WG            = 1735,
    FACTION_ARAKKOA                     = 1738,
    FACTION_ASHTONGUE_DEATHSWORN        = 1820,
    FACTION_FLAYER_HUNTER               = 1840,
    FACTION_MONSTER_SPAR_BUDDY          = 1868,
    FACTION_ESCORTEE_N_ACTIVE           = 1986,
    FACTION_ESCORTEE_H_ACTIVE           = 2046,
    FACTION_UNDEAD_SCOURGE_2            = 2068,
    FACTION_UNDEAD_SCOURGE_3            = 2084,
    FACTION_SCARLET_CRUSADE             = 2089,
    FACTION_SCARLET_CRUSADE_2           = 2096
};

#define MIN_REPUTATION_RANK (REP_HATED)
#define MAX_REPUTATION_RANK 8

#define MAX_SPILLOVER_FACTIONS 4

enum MoneyConstants
{
    COPPER = 1,
    SILVER = COPPER*100,
    GOLD   = SILVER*100
};

enum Stats
{
    STAT_STRENGTH                      = 0,
    STAT_AGILITY                       = 1,
    STAT_STAMINA                       = 2,
    STAT_INTELLECT                     = 3,
    STAT_SPIRIT                        = 4,
    MAX_STATS
};

// EnumUtils: DESCRIBE THIS
enum Powers : int8
{
    POWER_HEALTH                        = -2, // TITLE Health    生命
    POWER_MANA                          = 0,  // TITLE Mana      魔法
    POWER_RAGE                          = 1,  // TITLE Rage      怒气值
    POWER_FOCUS                         = 2,  // TITLE Focus     集中值
    POWER_ENERGY                        = 3,  // TITLE Energy    能量值
    POWER_HAPPINESS                     = 4,  // TITLE Happiness 幸福值
    POWER_RUNE                          = 5,  // TITLE Runes     符文值
    POWER_RUNIC_POWER                   = 6,  // TITLE Runic Power 符文能量值
    MAX_POWERS                          = 7,  // SKIP
    POWER_ALL                           = 127 // SKIP
};

#define MAX_RUNES 6

// EnumUtils: DESCRIBE THIS
enum SpellSchools
{
    SPELL_SCHOOL_NORMAL                 = 0, // TITLE Physical
    SPELL_SCHOOL_HOLY                   = 1, // TITLE Holy
    SPELL_SCHOOL_FIRE                   = 2, // TITLE Fire
    SPELL_SCHOOL_NATURE                 = 3, // TITLE Nature
    SPELL_SCHOOL_FROST                  = 4, // TITLE Frost
    SPELL_SCHOOL_SHADOW                 = 5, // TITLE Shadow
    SPELL_SCHOOL_ARCANE                 = 6, // TITLE Arcane
    MAX_SPELL_SCHOOL                    = 7  // SKIP
};

enum SpellSchoolMask : uint32
{
    SPELL_SCHOOL_MASK_NONE    = 0x00,                       // not exist
    SPELL_SCHOOL_MASK_NORMAL  = (1 << SPELL_SCHOOL_NORMAL), // PHYSICAL (Armor)
    SPELL_SCHOOL_MASK_HOLY    = (1 << SPELL_SCHOOL_HOLY),
    SPELL_SCHOOL_MASK_FIRE    = (1 << SPELL_SCHOOL_FIRE),
    SPELL_SCHOOL_MASK_NATURE  = (1 << SPELL_SCHOOL_NATURE),
    SPELL_SCHOOL_MASK_FROST   = (1 << SPELL_SCHOOL_FROST),
    SPELL_SCHOOL_MASK_SHADOW  = (1 << SPELL_SCHOOL_SHADOW),
    SPELL_SCHOOL_MASK_ARCANE  = (1 << SPELL_SCHOOL_ARCANE),

    // unions

    // 124, not include normal and holy damage
    SPELL_SCHOOL_MASK_SPELL   = (SPELL_SCHOOL_MASK_FIRE   |
                                  SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_FROST  |
                                  SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE),
    // 126
    SPELL_SCHOOL_MASK_MAGIC   = (SPELL_SCHOOL_MASK_HOLY | SPELL_SCHOOL_MASK_SPELL),

    // 127
    SPELL_SCHOOL_MASK_ALL     = (SPELL_SCHOOL_MASK_NORMAL | SPELL_SCHOOL_MASK_MAGIC)
};

constexpr SpellSchoolMask GetMaskForSchool(SpellSchools school)
{
    return SpellSchoolMask(1 << school);
}

inline SpellSchools GetFirstSchoolInMask(SpellSchoolMask mask)
{
    for (SpellSchools school : EnumUtils::Iterate<SpellSchools>())
        if (mask & GetMaskForSchool(school))
            return school;

    return SPELL_SCHOOL_NORMAL;
}

enum ItemQualities
{
    ITEM_QUALITY_POOR                  = 0, // GREY
    ITEM_QUALITY_NORMAL                = 1, // WHITE
    ITEM_QUALITY_UNCOMMON              = 2, // GREEN
    ITEM_QUALITY_RARE                  = 3, // BLUE
    ITEM_QUALITY_EPIC                  = 4, // PURPLE
    ITEM_QUALITY_LEGENDARY             = 5, // ORANGE
    ITEM_QUALITY_ARTIFACT              = 6, // LIGHT YELLOW
    ITEM_QUALITY_HEIRLOOM              = 7,
    MAX_ITEM_QUALITY
};

enum SpellCategory
{
    SPELL_CATEGORY_FOOD             = 11,
    SPELL_CATEGORY_DRINK            = 59
};

enum SpellVisualKit
{
    SPELL_VISUAL_KIT_FOOD           = 406,
    SPELL_VISUAL_KIT_DRINK          = 438
};

uint32 constexpr ItemQualityColors[MAX_ITEM_QUALITY] =
{
    0xff9d9d9d, // GREY
    0xffffffff, // WHITE
    0xff1eff00, // GREEN
    0xff0070dd, // BLUE
    0xffa335ee, // PURPLE
    0xffff8000, // ORANGE
    0xffe6cc80, // LIGHT YELLOW
    0xffe6cc80  // LIGHT YELLOW
};

size_t constexpr MAX_QUEST_DIFFICULTY = 5;
uint32 constexpr QuestDifficultyColors[MAX_QUEST_DIFFICULTY] = {
    0xff40c040,
    0xff808080,
    0xffffff00,
    0xffff8040,
    0xffff2020
};

// ***********************************
// Spell Attributes definitions
// ***********************************

// EnumUtils: DESCRIBE THIS
enum SpellAttr0 : uint32
{
    SPELL_ATTR0_UNK0                             = 0x00000001, // TITLE Unknown attribute 0@Attr0
                                                               // 未知属性位。通常为历史遗留或客户端/服务端尚未完全确认用途的标志位，可能被部分法术错误地设置或仅用于占位。

    SPELL_ATTR0_REQ_AMMO                         = 0x00000002, // TITLE Treat as ranged attack DESCRIPTION Use ammo, ranged attack range modifiers, ranged haste, etc.
                                                               // 将法术视为远程攻击。施放时需要消耗弹药（箭/子弹），并使用远程攻击距离、远程急速、远程命中等规则，而不是普通法术规则。

    SPELL_ATTR0_ON_NEXT_SWING                    = 0x00000004, // TITLE On next melee (type 1) DESCRIPTION Both "on next swing" attributes have identical handling in server & client
                                                               // 下一次近战攻击触发（类型1）。该类技能不会立即造成效果，而是在下一次成功的近战挥击时附带触发。

    SPELL_ATTR0_IS_REPLENISHMENT                 = 0x00000008, // TITLE Replenishment (client only)
                                                               // 回蓝类法术（客户端标记）。主要用于客户端显示和提示，与服务器逻辑基本无关。

    SPELL_ATTR0_ABILITY                          = 0x00000010, // TITLE Treat as ability DESCRIPTION Cannot be reflected, not affected by cast speed modifiers, etc.
                                                               // 将法术视为“技能”而非法术。通常不可被反射、不受施法速度加成影响，常用于瞬发技能或战斗动作。

    SPELL_ATTR0_TRADESPELL                       = 0x00000020, // TITLE Trade skill recipe DESCRIPTION Displayed in recipe list, not affected by cast speed modifiers
                                                               // 专业技能配方法术。会显示在专业配方列表中，不受施法速度影响，一般只用于制造/采集系统。

    SPELL_ATTR0_PASSIVE                          = 0x00000040, // TITLE Passive spell DESCRIPTION Spell is automatically cast on self by core
                                                               // 被动法术。服务器自动给自己施加（学习/登录/光环维持），不需要玩家主动施放，也不会显示施法过程。

    SPELL_ATTR0_HIDDEN_CLIENTSIDE                = 0x00000080, // TITLE Hidden in UI (client only) DESCRIPTION Not visible in spellbook or aura bar
                                                               // 客户端界面隐藏。该法术不会显示在技能书或光环栏中，通常用于内部或辅助效果。

    SPELL_ATTR0_HIDE_IN_COMBAT_LOG               = 0x00000100, // TITLE Hidden in combat log (client only) DESCRIPTION Spell will not appear in combat logs
                                                               // 战斗日志隐藏。该法术的施放或效果不会出现在战斗记录中，减少日志干扰。

    SPELL_ATTR0_TARGET_MAINHAND_ITEM             = 0x00000200, // TITLE Auto-target mainhand item (client only) DESCRIPTION Client will automatically select main-hand item as cast target
                                                               // 自动选中主手武器作为目标。常用于武器附魔、强化等技能，避免玩家手动选择目标。

    SPELL_ATTR0_ON_NEXT_SWING_2                  = 0x00000400, // TITLE On next melee (type 2) DESCRIPTION Both "on next swing" attributes have identical handling in server & client
                                                               // 下一次近战攻击触发（类型2）。与 type1 在逻辑上等价，主要用于数据区分或历史兼容。

    SPELL_ATTR0_UNK11                            = 0x00000800, // TITLE Unknown attribute 11@Attr0
                                                               // 未知属性位。当前尚未明确用途，可能仅被客户端识别或已废弃。

    SPELL_ATTR0_DAYTIME_ONLY                     = 0x00001000, // TITLE Only usable during daytime (unused)
                                                               // 仅白天可用（未使用）。理论上限制技能只能在白天施放，实际版本中通常未启用。

    SPELL_ATTR0_NIGHT_ONLY                       = 0x00002000, // TITLE Only usable during nighttime (unused)
                                                               // 仅夜晚可用（未使用）。与白天标志类似，多为设计遗留。

    SPELL_ATTR0_INDOORS_ONLY                     = 0x00004000, // TITLE Only usable indoors
                                                               // 只能在室内使用。服务器会检查施法者是否处于室内环境。

    SPELL_ATTR0_OUTDOORS_ONLY                    = 0x00008000, // TITLE Only usable outdoors
                                                               // 只能在室外使用。常见于坐骑、召唤类或自然相关技能。

    SPELL_ATTR0_NOT_SHAPESHIFT                   = 0x00010000, // TITLE Not usable while shapeshifted
                                                               // 变形状态下不可用。用于限制德鲁伊等职业在变形时使用特定技能。

    SPELL_ATTR0_ONLY_STEALTHED                   = 0x00020000, // TITLE Only usable in stealth
                                                               // 只能在潜行状态下使用。常见于盗贼的开场技能。

    SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE         = 0x00040000, // TITLE Don't shealthe weapons (client only)
                                                               // 不影响武器收放状态。施法时不会触发客户端的武器拔出或收回动画。

    SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION         = 0x00080000, // TITLE Scale with caster level DESCRIPTION For non-player casts, scale impact and power cost with caster's level
                                                               // 伤害与消耗随施法者等级缩放。多用于 NPC 或怪物技能，保证低高等级表现合理。

    SPELL_ATTR0_STOP_ATTACK_TARGET               = 0x00100000, // TITLE Stop attacking after cast DESCRIPTION After casting this, the current auto-attack will be interrupted
                                                               // 施放后中断自动攻击。技能施放完成后会停止当前普攻循环。

    SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK     = 0x00200000, // TITLE Prevent physical avoidance DESCRIPTION Spell cannot be dodged, parried or blocked
                                                               // 无法被闪避、招架或格挡。用于保证技能必定命中（物理层面）。

    SPELL_ATTR0_CAST_TRACK_TARGET                = 0x00400000, // TITLE Automatically face target during cast (client only)
                                                               // 施法时自动面向目标。客户端辅助功能，避免因朝向错误导致施法失败。

    SPELL_ATTR0_CASTABLE_WHILE_DEAD              = 0x00800000, // TITLE Can be cast while dead DESCRIPTION Spells without this flag cannot be cast by dead units in non-triggered contexts
                                                               // 死亡状态可施放。常用于灵魂状态技能、复活前技能或特殊机制。

    SPELL_ATTR0_CASTABLE_WHILE_MOUNTED           = 0x01000000, // TITLE Can be cast while mounted
                                                               // 骑乘状态下可施放。常见于非战斗技能或坐骑专用技能。

    SPELL_ATTR0_DISABLED_WHILE_ACTIVE            = 0x02000000, // TITLE Cooldown starts on expiry DESCRIPTION Spell is unusable while already active, and cooldown does not begin until the effects have worn off
                                                               // 效果持续期间不可再次使用，冷却在效果结束后才开始计算。

    SPELL_ATTR0_NEGATIVE_1                       = 0x04000000, // TITLE Is negative spell DESCRIPTION Forces the spell to be treated as a negative spell
                                                               // 强制视为负面法术。用于仇恨、驱散、光环判定等逻辑。

    SPELL_ATTR0_CASTABLE_WHILE_SITTING           = 0x08000000, // TITLE Can be cast while sitting
                                                               // 坐下状态可施放。少数技能允许在休息或坐下时使用。

    SPELL_ATTR0_CANT_USED_IN_COMBAT              = 0x10000000, // TITLE Cannot be used in combat
                                                               // 战斗中不可使用。典型用于坐骑、传送、制造类技能。

    SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY    = 0x20000000, // TITLE Pierce invulnerability DESCRIPTION Allows spell to pierce invulnerability, unless the invulnerability spell also has this attribute
                                                               // 穿透无敌效果。可以作用于无敌目标，除非目标的无敌技能同样声明可互相穿透。

    SPELL_ATTR0_HEARTBEAT_RESIST_CHECK           = 0x40000000, // TITLE Periodic resistance checks DESCRIPTION Periodically re-rolls against resistance to potentially expire aura early
                                                               // 周期性抗性判定。光环在持续期间会定期重新判定抗性，可能提前失效。

    SPELL_ATTR0_CANT_CANCEL                      = 0x80000000  // TITLE Aura cannot be cancelled DESCRIPTION Prevents the player from voluntarily canceling a positive aura
                                                               // 光环不可手动取消。玩家无法右键移除该正面效果，常用于剧情或核心机制。
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr1 : uint32
{
    SPELL_ATTR1_DISMISS_PET                      = 0x00000001, // TITLE Dismiss Pet on cast DESCRIPTION Without this attribute, summoning spells will fail if caster already has a pet
                                                               // 施法时解散当前宠物。若召唤类法术没有该标志，当施法者已有宠物时将直接失败。

    SPELL_ATTR1_DRAIN_ALL_POWER                  = 0x00000002, // TITLE Drain all power DESCRIPTION Ignores listed power cost and drains entire pool instead
                                                               // 消耗全部能量资源。忽略技能表中配置的消耗值，直接清空对应能量池（法力/能量/怒气等）。

    SPELL_ATTR1_CHANNELED_1                      = 0x00000004, // TITLE Channeled (type 1) DESCRIPTION Both "channeled" attributes have identical handling in server & client
                                                               // 引导法术（类型1）。施法后进入持续引导状态，效果在引导期间周期性触发。

    SPELL_ATTR1_CANT_BE_REDIRECTED               = 0x00000008, // TITLE Ignore redirection effects DESCRIPTION Spell will not be attracted by SPELL_MAGNET auras (Grounding Totem)
                                                               // 不受重定向影响。法术不会被法术磁铁类效果吸引（如萨满的根基图腾）。

    SPELL_ATTR1_UNK4                             = 0x00000010, // TITLE Unknown attribute 4@Attr1
                                                               // 未知属性位。用途不明确，可能为废弃字段或客户端私有逻辑残留。

    SPELL_ATTR1_NOT_BREAK_STEALTH                = 0x00000020, // TITLE Does not break stealth
                                                               // 施放后不打破潜行状态。常用于盗贼的某些非攻击性或特殊技能。

    SPELL_ATTR1_CHANNELED_2                      = 0x00000040, // TITLE Channeled (type 2) DESCRIPTION Both "channeled" attributes have identical handling in server & client
                                                               // 引导法术（类型2）。与 type1 在逻辑上等价，主要用于数据或版本区分。

    SPELL_ATTR1_CANT_BE_REFLECTED                = 0x00000080, // TITLE Ignore reflection effects DESCRIPTION Spell will pierce through Spell Reflection and similar
                                                               // 无法被反射。法术会无视法术反射类效果，直接作用于目标。

    SPELL_ATTR1_CANT_TARGET_IN_COMBAT            = 0x00000100, // TITLE Target cannot be in combat
                                                               // 目标必须处于非战斗状态。若目标已进入战斗，施法将失败。

    SPELL_ATTR1_MELEE_COMBAT_START               = 0x00000200, // TITLE Starts auto-attack (client only) DESCRIPTION Caster will begin auto-attacking the target on cast
                                                               // 施法后自动开始近战攻击。客户端行为，用于技能释放后自动接入普攻。

    SPELL_ATTR1_NO_THREAT                        = 0x00000400, // TITLE Does not generate threat DESCRIPTION Also does not cause target to engage
                                                               // 不产生仇恨值。施放该法术不会增加仇恨，也不会使目标进入战斗状态。

    SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST  = 0x00000800, // TITLE Aura will not refresh its duration when recast
                                                               // 重复施放不刷新持续时间。光环存在期间再次施放，不会重置剩余时长。

    SPELL_ATTR1_IS_PICKPOCKET                    = 0x00001000, // TITLE Pickpocket (client only)
                                                               // 扒窃技能标记。客户端用于识别盗贼的扒窃行为与相关UI反馈。

    SPELL_ATTR1_FARSIGHT                         = 0x00002000, // TITLE Farsight aura (client only)
                                                               // 远视类光环。客户端用于处理视角转移、摄像机绑定等效果。

    SPELL_ATTR1_CHANNEL_TRACK_TARGET             = 0x00004000, // TITLE Track target while channeling DESCRIPTION While channeling, adjust facing to face target
                                                               // 引导期间持续追踪目标。施法者会在引导过程中自动调整朝向以面对目标。

    SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY         = 0x00008000, // TITLE Immunity cancels preapplied auras DESCRIPTION For immunity spells, cancel all auras that this spell would make you immune to when the spell is applied
                                                               // 获得免疫时驱散已有相关光环。施放免疫技能时，会移除所有该免疫可覆盖的已有效果。

    SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE      = 0x00010000, // TITLE Unaffected by school immunities DESCRIPTION Will not pierce Divine Shield, Ice Block and other full invulnerabilities
                                                               // 不受“学派免疫”影响，但仍受完全无敌影响。可无视抗性或学派免疫，但无法穿透完全无敌状态。

    SPELL_ATTR1_UNAUTOCASTABLE_BY_PET            = 0x00020000, // TITLE Cannot be autocast by pet
                                                               // 宠物无法自动施放。必须由玩家手动控制，防止AI误用。

    SPELL_ATTR1_PREVENTS_ANIM                    = 0x00040000, // TITLE NYI, auras apply UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT
                                                               // 阻止表情动画（未完全实现）。光环会禁止聊天文本触发的表情动作。

    SPELL_ATTR1_CANT_TARGET_SELF                 = 0x00080000, // TITLE Cannot be self-cast
                                                               // 不能以自身为目标。即使满足其他条件，也禁止对自己施放。

    SPELL_ATTR1_REQ_COMBO_POINTS1                = 0x00100000, // TITLE Requires combo points (type 1)
                                                               // 需要连击点数（类型1）。通常用于盗贼/德鲁伊终结技的基础校验。

    SPELL_ATTR1_UNK21                            = 0x00200000, // TITLE Unknown attribute 21@Attr1
                                                               // 未知属性位。用途不明，可能为历史版本残留。

    SPELL_ATTR1_REQ_COMBO_POINTS2                = 0x00400000, // TITLE Requires combo points (type 2)
                                                               // 需要连击点数（类型2）。与 type1 语义接近，多为数据或兼容性区分。

    SPELL_ATTR1_UNK23                            = 0x00800000, // TITLE Unknwon attribute 23@Attr1
                                                               // 未知属性位。当前未发现明确服务器逻辑用途。

    SPELL_ATTR1_IS_FISHING                       = 0x01000000, // TITLE Fishing (client only)
                                                               // 钓鱼技能标记。客户端用于切换钓鱼相关UI、动作与摄像机行为。

    SPELL_ATTR1_UNK25                            = 0x02000000, // TITLE Unknown attribute 25@Attr1
                                                               // 未知属性位。可能仅在特定资料片或客户端逻辑中使用。

    SPELL_ATTR1_REQUIRE_ALL_TARGETS              = 0x04000000, // TITLE Require All Targets
                                                               // 要求所有目标都有效。多目标法术中，若任一目标不满足条件，则整体施法失败。

    SPELL_ATTR1_UNK27                            = 0x08000000, // TITLE Unknown attribute 27@Attr1 DESCRIPTION Melee spell?
                                                               // 疑似近战相关标记。部分数据中与近战技能共现，但用途未完全确认。

    SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR         = 0x10000000, // TITLE Hide in aura bar (client only)
                                                               // 不显示在光环栏中。效果仍然存在，仅对客户端UI隐藏。

    SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME       = 0x20000000, // TITLE Show spell name during channel (client only)
                                                               // 引导期间显示法术名称。用于客户端施法条或UI提示。

    SPELL_ATTR1_ENABLE_AT_DODGE                  = 0x40000000, // TITLE Enable at dodge
                                                               // 在闪避事件时触发或启用。常用于“成功闪避后可使用”的技能机制。

    SPELL_ATTR1_UNK31                            = 0x80000000  // TITLE Unknown attribute 31@Attr1
                                                               // 未知属性位。最高位标记，可能为客户端或未来扩展预留。
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr2 : uint32 
{
    SPELL_ATTR2_CAN_TARGET_DEAD                  = 0x00000001, // TITLE Can target dead players or corpses
                                                               // 可以以死亡单位或尸体为目标。常用于复活、复生、尸体交互类技能。

    SPELL_ATTR2_UNK1                             = 0x00000002, // TITLE Unknown attribute 1@Attr2
                                                               // 未知属性位。用途尚不明确，可能为客户端或早期版本残留。

    SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS            = 0x00000004, // TITLE Ignore Line of Sight
                                                               // 忽略视线检测。施法不受 LOS（Line of Sight）限制，可隔墙或遮挡施放。

    SPELL_ATTR2_ALLOW_LOW_LEVEL_BUFF             = 0x00000008, // TITLE Allow Low Level Buff
                                                               // 允许对低等级目标施放增益。绕过等级差限制，常用于祝福、团队增益等技能。

    SPELL_ATTR2_DISPLAY_IN_STANCE_BAR            = 0x00000010, // TITLE Show in stance bar (client only)
                                                               // 显示在姿态栏中。客户端用于战士/德鲁伊等职业的姿态技能显示。

    SPELL_ATTR2_AUTOREPEAT_FLAG                  = 0x00000020, // TITLE Ranged auto-attack spell
                                                               // 远程自动攻击技能。用于标记射击/投掷等可持续自动重复的攻击行为。

    SPELL_ATTR2_CANT_TARGET_TAPPED               = 0x00000040, // TITLE Cannot target others' tapped units DESCRIPTION Can only target untapped units, or those tapped by caster
                                                               // 不能以他人已占用（tapped）的单位为目标。只能作用于未被占用或由自己占用的目标。

    SPELL_ATTR2_UNK7                             = 0x00000080, // TITLE Unknown attribute 7@Attr2
                                                               // 未知属性位。未发现明确服务器逻辑用途。

    SPELL_ATTR2_UNK8                             = 0x00000100, // TITLE Unknown attribute 8@Attr2
                                                               // 未知属性位。可能仅影响客户端表现或已废弃。

    SPELL_ATTR2_UNK9                             = 0x00000200, // TITLE Unknown attribute 9@Attr2
                                                               // 未知属性位。暂未确认实际作用。

    SPELL_ATTR2_UNK10                            = 0x00000400, // TITLE Unknown attribute 10@Attr2 DESCRIPTION Related to taming?
                                                               // 疑似与驯服机制相关。常与野兽驯服类技能数据同时出现。

    SPELL_ATTR2_HEALTH_FUNNEL                    = 0x00000800, // TITLE Health Funnel
                                                               // 生命通道技能标记。用于术士生命通道，将施法者生命持续转移给宠物。

    SPELL_ATTR2_UNK12                            = 0x00001000, // TITLE Unknown attribute 12@Attr2
                                                               // 未知属性位。用途尚未确认。

    SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA        = 0x00002000, // TITLE Enchant persists when entering arena
                                                               // 进入竞技场时保留附魔效果。防止竞技场规则清除特定临时附魔。

    SPELL_ATTR2_UNK14                            = 0x00004000, // TITLE Unknown attribute 14@Attr2
                                                               // 未知属性位。可能为数据占位。

    SPELL_ATTR2_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr2
                                                               // 未知属性位。尚无明确用途。

    SPELL_ATTR2_TAME_BEAST                       = 0x00010000, // TITLE Tame Beast
                                                               // 驯服野兽技能标记。用于猎人驯服野兽的完整流程控制。

    SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS           = 0x00020000, // TITLE Don't reset swing timer DESCRIPTION Does not reset melee/ranged autoattack timer on cast
                                                               // 施法不重置普攻计时器。允许技能施放与自动攻击节奏并行。

    SPELL_ATTR2_REQ_DEAD_PET                     = 0x00040000, // TITLE Requires dead pet
                                                               // 需要死亡的宠物。常用于复活宠物类技能。

    SPELL_ATTR2_NOT_NEED_SHAPESHIFT              = 0x00080000, // TITLE Also allow outside shapeshift DESCRIPTION Even if Stances are nonzero, allow spell to be cast outside of shapeshift (though not in a different shapeshift)
                                                               // 允许在未变形状态下施放。即使技能限定某姿态，也允许“非变形”状态使用，但不能跨其他姿态。

    SPELL_ATTR2_UNK20                            = 0x00100000, // TITLE Unknown attribute 20@Attr2
                                                               // 未知属性位。可能与特定版本机制有关。

    SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE       = 0x00200000, // TITLE Fail on all targets immune DESCRIPTION Causes BG flags to be dropped if combined with ATTR1_DISPEL_AURAS_ON_IMMUNITY
                                                               // 当所有目标免疫时施法失败。与免疫驱散组合时会触发特殊逻辑（如战场旗帜掉落）。

    SPELL_ATTR2_UNK22                            = 0x00400000, // TITLE Unknown attribute 22@Attr2
                                                               // 未知属性位。用途尚不明确。

    SPELL_ATTR2_IS_ARCANE_CONCENTRATION          = 0x00800000, // TITLE Arcane Concentration
                                                               // 奥术专注标记。用于法师“节能施法/清晰施法”类天赋与触发逻辑。

    SPELL_ATTR2_UNK24                            = 0x01000000, // TITLE Unknown attribute 24@Attr2
                                                               // 未知属性位。未发现明确行为差异。

    SPELL_ATTR2_UNK25                            = 0x02000000, // TITLE Unknown attribute 25@Attr2
                                                               // 未知属性位。可能为客户端保留。

    SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE = 0x04000000, // TITLE Pierce aura application immunities DESCRIPTION Allow aura to be applied despite target being immune to new aura applications
                                                               // 穿透“光环施加免疫”。即使目标无法获得新光环，也强制应用该光环。

    SPELL_ATTR2_UNK27                            = 0x08000000, // TITLE Unknown attribute 27@Attr2
                                                               // 未知属性位。用途不明。

    SPELL_ATTR2_UNK28                            = 0x10000000, // TITLE Unknown attribute 28@Attr2
                                                               // 未知属性位。可能为未来扩展或废弃字段。

    SPELL_ATTR2_CANT_CRIT                        = 0x20000000, // TITLE Cannot critically strike
                                                               // 无法造成暴击。无论暴击率如何，效果都不会产生暴击结果。

    SPELL_ATTR2_ACTIVE_THREAT                    = 0x40000000, // TITLE Active Threat
                                                               // 主动仇恨技能。施放后会立即引发目标仇恨反应，强制进入战斗逻辑。

    SPELL_ATTR2_FOOD_BUFF                        = 0x80000000  // TITLE Food buff (client only)
                                                               // 食物增益标记。客户端用于区分食物/饮料带来的持续增益效果。
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr3 : uint32
{
    SPELL_ATTR3_UNK0                             = 0x00000001, // TITLE Unknown attribute 0@Attr3
                                                               // 未知属性位。用途尚未明确，可能为客户端或旧版本遗留标志。

    SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK        = 0x00000002, //  1 Ignores subclass mask check when checking proc
                                                               // 触发（proc）时忽略子类掩码校验。允许该法术在不匹配子类别条件时仍然触发相关 proc。

    SPELL_ATTR3_UNK2                             = 0x00000004, // TITLE Unknown attribute 2@Attr3
                                                               // 未知属性位。未发现明确的服务器逻辑用途。

    SPELL_ATTR3_COMPLETELY_BLOCKED               = 0x00000008, // TITLE Completely Blocked
                                                               // 完全被格挡。该法术的伤害可被判定为“完全格挡”，通常与盾牌或特殊防御机制相关。

    SPELL_ATTR3_IGNORE_RESURRECTION_TIMER        = 0x00000010, // TITLE Ignore resurrection timer
                                                               // 忽略复活冷却时间。允许目标在未到复活等待时间时被复活。

    SPELL_ATTR3_UNK5                             = 0x00000020, // TITLE Unknown attribute 5@Attr3
                                                               // 未知属性位。可能为占位或已废弃功能。

    SPELL_ATTR3_UNK6                             = 0x00000040, // TITLE Unknown attribute 6@Attr3
                                                               // 未知属性位。当前未确认实际作用。

    SPELL_ATTR3_STACK_FOR_DIFF_CASTERS           = 0x00000080, // TITLE Stack separately for each caster
                                                               // 不同施法者分别叠加。同一光环来自不同施法者时不会互相覆盖，而是各自独立存在。

    SPELL_ATTR3_ONLY_TARGET_PLAYERS              = 0x00000100, // TITLE Can only target players
                                                               // 只能以玩家为目标。无法对 NPC、怪物或召唤物施放。

    SPELL_ATTR3_NOT_A_PROC                       = 0x00000200, // TITLE Not a Proc DESCRIPTION Without this attribute, any triggered spell will be unable to trigger other auras' procs
                                                               // 该技能本身不被视为一次 proc。若没有此标志，触发型法术将无法再次触发其他光环的 proc 效果。

    SPELL_ATTR3_MAIN_HAND                        = 0x00000400, // TITLE Require main hand weapon
                                                               // 需要主手武器。施法前会校验主手是否装备有效武器。

    SPELL_ATTR3_BATTLEGROUND                     = 0x00000800, // TITLE Can only be cast in battleground
                                                               // 只能在战场中施放。离开战场环境后该技能不可用。

    SPELL_ATTR3_ONLY_TARGET_GHOSTS               = 0x00001000, // TITLE Can only target ghost players
                                                               // 只能以幽灵状态玩家为目标。常用于复活、复生或墓地相关技能。

    SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR         = 0x00002000, // TITLE Do not display channel bar (client only)
                                                               // 不显示引导进度条。客户端隐藏该技能的引导条UI。

    SPELL_ATTR3_IS_HONORLESS_TARGET              = 0x00004000, // TITLE Honorless Target
                                                               // 荣誉无效目标。用于 PvP 中标记不会产生荣誉收益的目标。

    SPELL_ATTR3_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr3 DESCRIPTION Auto Shoot, Shoot, Throw - ranged normal attack attribute?
                                                               // 疑似远程普通攻击相关标志。常与自动射击、投掷等技能共现。

    SPELL_ATTR3_CANT_TRIGGER_PROC                = 0x00010000, // TITLE Cannot trigger procs
                                                               // 不能触发任何 proc 效果。该技能的命中或效果不会触发天赋或光环的触发逻辑。

    SPELL_ATTR3_NO_INITIAL_AGGRO                 = 0x00020000, // TITLE No initial aggro
                                                               // 不会产生初始仇恨。首次作用不会立即引发目标进入攻击状态。

    SPELL_ATTR3_IGNORE_HIT_RESULT                = 0x00040000, // TITLE Ignore hit result DESCRIPTION Spell cannot miss, or be dodged/parried/blocked
                                                               // 忽略命中判定结果。该法术不会出现未命中、闪避、招架或格挡等结果。

    SPELL_ATTR3_DISABLE_PROC                     = 0x00080000, // TITLE Cannot trigger spells during aura proc
                                                               // 在光环 proc 期间禁止再次触发技能。用于防止递归或连锁触发。

    SPELL_ATTR3_DEATH_PERSISTENT                 = 0x00100000, // TITLE Persists through death
                                                               // 死亡后仍然保留。角色死亡不会移除该光环或效果。

    SPELL_ATTR3_UNK21                            = 0x00200000, // TITLE Unknown attribute 21@Attr3
                                                               // 未知属性位。未确认实际用途。

    SPELL_ATTR3_REQ_WAND                         = 0x00400000, // TITLE Requires equipped Wand
                                                               // 需要装备魔杖。常用于法师/术士的魔杖射击类技能。

    SPELL_ATTR3_UNK23                            = 0x00800000, // TITLE Unknown attribute 23@Attr3
                                                               // 未知属性位。可能与特定客户端行为相关。

    SPELL_ATTR3_REQ_OFFHAND                      = 0x01000000, // TITLE Requires offhand weapon
                                                               // 需要副手武器。施法前必须在副手槽装备有效武器。

    SPELL_ATTR3_TREAT_AS_PERIODIC                = 0x02000000, // TITLE Treat as periodic effect
                                                               // 按周期性效果处理。即使不是传统 DOT，也会按周期效果逻辑结算。

    SPELL_ATTR3_CAN_PROC_FROM_PROCS              = 0x04000000, // TITLE Can Proc From Procs
                                                               // 允许由 proc 再次触发 proc。打破默认“proc 不触发 proc”的限制。

    SPELL_ATTR3_DRAIN_SOUL                       = 0x08000000, // TITLE Drain Soul
                                                               // 灵魂吸取技能标记。用于术士灵魂碎片生成及相关特殊结算逻辑。

    SPELL_ATTR3_UNK28                            = 0x10000000, // TITLE Unknown attribute 28@Attr3
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR3_NO_DONE_BONUS                    = 0x20000000, // TITLE Damage dealt is unaffected by modifiers
                                                               // 伤害不受加成修正。不会受到伤害提高、易伤等系数影响。

    SPELL_ATTR3_DONT_DISPLAY_RANGE               = 0x40000000, // TITLE Do not show range in tooltip (client only)
                                                               // 技能提示中不显示距离。客户端 UI 纯显示控制。

    SPELL_ATTR3_UNK31                            = 0x80000000  // TITLE Unknown attribute 31@Attr3
                                                               // 未知属性位。最高位标志，可能为扩展或保留用途。
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr4 : uint32
{
    SPELL_ATTR4_IGNORE_RESISTANCES               = 0x00000001, // TITLE Cannot be resisted
                                                               // 无视抗性判定。该法术不会被目标的魔法抗性所抵抗，结算时直接命中生效。

    SPELL_ATTR4_PROC_ONLY_ON_CASTER              = 0x00000002, // TITLE Only proc on self-cast
                                                               // 仅在自身施法时才触发 proc。由他人或其他来源触发时不会激活相关触发效果。

    SPELL_ATTR4_FADES_WHILE_LOGGED_OUT           = 0x00000004, // TITLE Buff expires while offline DESCRIPTION Debuffs (except Resurrection Sickness) will automatically do this
                                                               // 离线期间持续时间仍然流逝。玩家下线后该增益会继续倒计时，重新上线可能已经过期。

    SPELL_ATTR4_UNK3                             = 0x00000008, // TITLE Unknown attribute 3@Attr4
                                                               // 未知属性位。用途不明，可能为历史版本遗留或客户端内部逻辑。

    SPELL_ATTR4_UNK4                             = 0x00000010, // TITLE Treat as delayed spell
                                                               // 按延迟型法术处理。可能用于延迟结算、延迟触发效果的特殊技能。

    SPELL_ATTR4_UNK5                             = 0x00000020, // TITLE Unknown attribute 5@Attr4
                                                               // 未知属性位。当前未发现明确服务器行为关联。

    SPELL_ATTR4_NOT_STEALABLE                    = 0x00000040, // TITLE Aura cannot be stolen
                                                               // 光环不可被偷取。无法被法术偷取类技能（如法术吸取、法术偷取）移除或转移。

    SPELL_ATTR4_CAN_CAST_WHILE_CASTING           = 0x00000080, // TITLE Can be cast while casting DESCRIPTION Ignores already in-progress cast and still casts
                                                               // 可在施法过程中施放。不会打断或受当前正在进行的施法影响，常用于瞬发技能。

    SPELL_ATTR4_FIXED_DAMAGE                     = 0x00000100, // TITLE Deals fixed damage
                                                               // 固定伤害。伤害数值不随攻击强度、法术强度或其他系数缩放。

    SPELL_ATTR4_TRIGGER_ACTIVATE                 = 0x00000200, // TITLE Spell is initially disabled (client only)
                                                               // 初始为禁用状态（客户端）。通常需要通过触发条件或事件激活后才能使用。

    SPELL_ATTR4_SPELL_VS_EXTEND_COST             = 0x00000400, // TITLE Attack speed modifies cost DESCRIPTION Adds 10 to power cost for each 1s of weapon speed
                                                               // 消耗随武器速度变化。武器速度越慢，技能消耗的能量/怒气等越高。

    SPELL_ATTR4_UNK11                            = 0x00000800, // TITLE Unknown attribute 11@Attr4
                                                               // 未知属性位。尚未发现具体用途。

    SPELL_ATTR4_UNK12                            = 0x00001000, // TITLE Unknown attribute 12@Attr4
                                                               // 未知属性位。可能仅影响客户端表现。

    SPELL_ATTR4_UNK13                            = 0x00002000, // TITLE Unknown attribute 13@Attr4
                                                               // 未知属性位。用途未确认。

    SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS        = 0x00004000, // TITLE Damage does not break auras
                                                               // 造成伤害不会打断光环。即使受到伤害，某些易碎或需保持的光环仍然保留。

    SPELL_ATTR4_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr4
                                                               // 未知属性位。未发现明确逻辑关联。

    SPELL_ATTR4_NOT_USABLE_IN_ARENA              = 0x00010000, // TITLE Not usable in arena DESCRIPTION Makes spell unusable despite CD <= 10min
                                                               // 竞技场中不可使用。即使冷却时间满足竞技场规则，也强制禁用。

    SPELL_ATTR4_USABLE_IN_ARENA                  = 0x00020000, // TITLE Usable in arena DESCRIPTION Makes spell usable despite CD > 10min
                                                               // 竞技场中允许使用。即使冷却时间超过竞技场默认限制，仍可施放。

    SPELL_ATTR4_AREA_TARGET_CHAIN                = 0x00040000, // TITLE Chain area targets DESCRIPTION [NYI] Hits area targets over time instead of all at once
                                                               // 区域目标链式命中（未实现）。设计上用于区域目标分批或链式命中。

    SPELL_ATTR4_UNK19                            = 0x00080000, // TITLE Unknown attribute 19@Attr4
                                                               // 未知属性位。用途尚未明确。

    SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER         = 0x00100000, // TITLE Allow self-cast to override stronger aura (client only)
                                                               // 自施放时不检查能量与光环强度。允许用自身施法覆盖更强的同类光环（客户端逻辑）。

    SPELL_ATTR4_DONT_REMOVE_IN_ARENA             = 0x00200000, // TITLE Keep when entering arena
                                                               // 进入竞技场时不移除。通常用于允许部分增益在竞技场中保留。

    SPELL_ATTR4_UNK22                            = 0x00400000, // TITLE Unknown attribute 22@Attr4
                                                               // 未知属性位。当前无明确用途说明。

    SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS         = 0x00800000, // TITLE Cannot trigger item spells
                                                               // 不能触发物品法术。该技能不会触发装备或物品附带的法术效果。

    SPELL_ATTR4_UNK24                            = 0x01000000, // TITLE Unknown attribute 24@Attr4 DESCRIPTION Shoot-type spell?
                                                               // 疑似射击类法术相关标志。常与远程普通攻击技能数据共现。

    SPELL_ATTR4_IS_PET_SCALING                   = 0x02000000, // TITLE Pet Scaling aura
                                                               // 宠物属性缩放光环。用于根据主人属性动态调整宠物属性。

    SPELL_ATTR4_CAST_ONLY_IN_OUTLAND             = 0x04000000, // TITLE Only in Outland/Northrend
                                                               // 仅能在外域或诺森德施放。用于限制技能在特定资料片区域使用。

    SPELL_ATTR4_FORCE_DISPLAY_CASTBAR            = 0x08000000, // TITLE Force Display Castbar
                                                               // 强制显示施法条。即使是瞬发或特殊技能，也会显示施法进度条。

    SPELL_ATTR4_UNK28                            = 0x10000000, // TITLE Unknown attribute 28@Attr4
                                                               // 未知属性位。用途未确认。

    SPELL_ATTR4_UNK29                            = 0x20000000, // TITLE Unknown attribute 29@Attr4
                                                               // 未知属性位。可能为客户端或未来扩展预留。

    SPELL_ATTR4_UNK30                            = 0x40000000, // TITLE Unknown attribute 30@Attr4
                                                               // 未知属性位。尚无明确行为定义。

    SPELL_ATTR4_UNK31                            = 0x80000000  // TITLE Unknown attribute 31@Attr4
                                                               // 未知属性位。最高位标志，通常为保留或内部用途。
};

// EnumUtils: DESCRIBE THIS

enum SpellAttr5 : uint32
{
    SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING          = 0x00000001, // TITLE Can be channeled while moving
                                                               // 引导期间允许移动。通常引导法术会因移动而中断，此标志允许边走边保持引导。

    SPELL_ATTR5_NO_REAGENT_WHILE_PREP            = 0x00000002, // TITLE No reagents during arena preparation
                                                               // 竞技场准备阶段不消耗材料。用于竞技场开场倒计时阶段的施法测试/预上 buff。

    SPELL_ATTR5_REMOVE_ON_ARENA_ENTER            = 0x00000004, // TITLE Remove when entering arena DESCRIPTION Force this aura to be removed on entering arena, regardless of other properties
                                                               // 进入竞技场时强制移除该光环。无视“可在竞技场保留”等其他规则，进场即清除。

    SPELL_ATTR5_USABLE_WHILE_STUNNED             = 0x00000008, // TITLE Usable while stunned
                                                               // 眩晕状态可用。绕过“眩晕禁止施法”的通用限制，常用于饰品解控或特殊反制技能。

    SPELL_ATTR5_UNK4                             = 0x00000010, // TITLE Unknown attribute 4@Attr5
                                                               // 未知属性位。用途尚未确认，可能为客户端或旧机制残留。

    SPELL_ATTR5_SINGLE_TARGET_SPELL              = 0x00000020, // TITLE Single-target aura DESCRIPTION Remove previous application to another unit if applied
                                                               // 单目标光环（唯一目标）。同一施法者把该光环转移给新目标时，会自动移除旧目标上的同类光环（类似“只能维持一个目标”的持续效果）。

    SPELL_ATTR5_UNK6                             = 0x00000040, // TITLE Unknown attribute 6@Attr5
                                                               // 未知属性位。当前未发现明确行为差异。

    SPELL_ATTR5_UNK7                             = 0x00000080, // TITLE Unknown attribute 7@Attr5
                                                               // 未知属性位。可能只对特定法术数据生效或已废弃。

    SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED    = 0x00000100, // TITLE Cannot target player controlled units but can target players
                                                               // 不能选中“玩家控制的单位”，但可以选中玩家本体。比如不能对被玩家操控的宠物/载具/魅惑单位生效。

    SPELL_ATTR5_START_PERIODIC_AT_APPLY          = 0x00000200, // TITLE Immediately do periodic tick on apply
                                                               // 应用时立刻触发一次周期跳（tick）。用于 DOT/HOT 在刚挂上时马上结算一跳，而不是等到下一个周期点。

    SPELL_ATTR5_HIDE_DURATION                    = 0x00000400, // TITLE Do not send aura duration to client
                                                               // 不向客户端同步光环持续时间。客户端可能显示为“无时间/未知时间”，常用于隐藏机制或动态时长效果。

    SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET = 0x00000800, // TITLE Auto-target target of target (client only)
                                                               // 自动以“目标的目标”为施法目标（客户端）。例如你选中友方坦克时，技能自动指向坦克当前仇恨的敌人。

    SPELL_ATTR5_UNK12                            = 0x00001000, // TITLE Unknown attribute 12@Attr5 DESCRIPTION Cleave related?
                                                               // 未知属性位，疑似与顺劈/劈砍类多目标命中逻辑有关（数据上可能与 cleave 类技能共现）。

    SPELL_ATTR5_HASTE_AFFECT_DURATION            = 0x00002000, // TITLE Duration scales with Haste Rating
                                                               // 持续时间受急速影响。急速属性会改变该光环/效果的总持续时长（区别于“急速改变跳频”那种机制）。

    SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED         = 0x00004000, // TITLE Charmed units cannot cast this spell
                                                               // 被魅惑/控制时不可用。即使处于可施法状态，也禁止在被控期间释放该技能（防止反制或逃脱）。

    SPELL_ATTR5_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr5 DESCRIPTION Related to multi-target spells?
                                                               // 未知属性位，疑似与多目标法术的目标选择/命中规则相关（如链式/溅射/多重目标校验）。

    SPELL_ATTR5_UNK16                            = 0x00010000, // TITLE Unknown attribute 16@Attr5
                                                               // 未知属性位。用途不明。

    SPELL_ATTR5_USABLE_WHILE_FEARED              = 0x00020000, // TITLE Usable while feared
                                                               // 恐惧状态可用。允许在恐惧中施放，通常用于解控、保命或极少数特殊技能。

    SPELL_ATTR5_USABLE_WHILE_CONFUSED            = 0x00040000, // TITLE Usable while confused
                                                               // 混乱状态可用。允许在混乱（方向错乱/不可控移动）时施放的例外技能。

    SPELL_ATTR5_DONT_TURN_DURING_CAST            = 0x00080000, // TITLE Do not auto-turn while casting
                                                               // 施法时不自动转向。即使目标移动或朝向不足，也不触发自动面向行为（常用于固定朝向/定向读条技能）。

    SPELL_ATTR5_UNK20                            = 0x00100000, // TITLE Unknown attribute 20@Attr5
                                                               // 未知属性位。暂未确认用途。

    SPELL_ATTR5_UNK21                            = 0x00200000, // TITLE Unknown attribute 21@Attr5
                                                               // 未知属性位。可能与某些条件施法限制相关。

    SPELL_ATTR5_UNK22                            = 0x00400000, // TITLE Unknown attribute 22@Attr5
                                                               // 未知属性位。当前无明确行为定义。

    SPELL_ATTR5_UNK23                            = 0x00800000, // TITLE Unknown attribute 23@Attr5
                                                               // 未知属性位。可能仅对客户端提示或内部状态有意义。

    SPELL_ATTR5_UNK24                            = 0x01000000, // TITLE Unknown attribute 24@Attr5
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR5_UNK25                            = 0x02000000, // TITLE Unknown attribute 25@Attr5
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK         = 0x04000000, // TITLE Ignore line of sight checks
                                                               // 跳过 CheckCast 阶段的视线检测。与 Attr2 的“忽略 LOS”类似，但更偏向“施法前校验”层面的绕过（常用于脚本/触发型技能）。

    SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST      = 0x08000000, // TITLE Don't show aura if self-cast (client only)
                                                               // 若由自己施放，则不显示该光环（客户端）。效果仍存在，仅隐藏 UI 显示以减少干扰或避免暴露机制。

    SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST  = 0x10000000, // TITLE Don't show aura unless self-cast (client only)
                                                               // 仅在自己施放时才显示光环（客户端）。他人施放在你身上时 UI 不显示，但服务器效果仍生效。

    SPELL_ATTR5_UNK29                            = 0x20000000, // TITLE Unknown attribute 29@Attr5
                                                               // 未知属性位。用途不明。

    SPELL_ATTR5_UNK30                            = 0x40000000, // TITLE Unknown attribute 30@Attr5
                                                               // 未知属性位。用途不明。

    SPELL_ATTR5_UNK31                            = 0x80000000  // TITLE Unknown attribute 31@Attr5 DESCRIPTION Forces nearby enemies to attack caster?
                                                               // 未知属性位，疑似带有“嘲讽/强制周围敌人攻击施法者”的语义（从描述推测），可能与脚本或特殊仇恨机制相关。
};


// EnumUtils: DESCRIBE THIS

enum SpellAttr6 : uint32
{
    SPELL_ATTR6_DONT_DISPLAY_COOLDOWN            = 0x00000001, // TITLE Don't display cooldown (client only)
                                                               // 不在客户端显示冷却时间。技能仍然有冷却，只是 UI 上不显示，用于隐藏机制或被动/触发型技能。

    SPELL_ATTR6_ONLY_IN_ARENA                    = 0x00000002, // TITLE Only usable in arena
                                                               // 只能在竞技场中使用。离开竞技场环境后该技能不可施放。

    SPELL_ATTR6_IGNORE_CASTER_AURAS              = 0x00000004, // TITLE Ignore all preventing caster auras
                                                               // 忽略施法者身上的“禁止施法”类光环。即使存在沉默、限制施法的光环，仍允许施放该技能。

    SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG        = 0x00000008, // TITLE Ignore immunity flags when assisting
                                                               // 协助型施法时忽略免疫标志。用于治疗/辅助技能在目标标记为免疫时仍可正常作用。

    SPELL_ATTR6_UNK4                             = 0x00000010, // TITLE Unknown attribute 4@Attr6
                                                               // 未知属性位。用途尚未明确。

    SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES        = 0x00000020, // TITLE Don't consume proc charges
                                                               // 触发时不消耗 proc 次数。该技能触发相关光环效果，但不会减少其剩余触发层数/次数。

    SPELL_ATTR6_USE_SPELL_CAST_EVENT             = 0x00000040, // TITLE Generate spell_cast event instead of aura_start (client only)
                                                               // 使用 spell_cast 事件而非 aura_start（客户端）。影响客户端事件流与 UI 表现。

    SPELL_ATTR6_UNK7                             = 0x00000080, // TITLE Unknown attribute 7@Attr6
                                                               // 未知属性位。可能为客户端或历史机制残留。

    SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED     = 0x00000100, // TITLE Do not implicitly target in CC DESCRIPTION Implicit targeting (chaining and area targeting) will not impact crowd controlled targets
                                                               // 隐式目标选择时跳过被控制目标。链式/范围技能不会自动命中被恐惧、变形、昏迷等 CC 状态的单位。

    SPELL_ATTR6_UNK9                             = 0x00000200, // TITLE Unknown attribute 9@Attr6
                                                               // 未知属性位。用途未确认。

    SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS     = 0x00000400, // TITLE Can target possessed friends DESCRIPTION [NYI]
                                                               // 可以选中被附身/控制的友方单位。当前标注为未实现（NYI），逻辑可能尚未完整接入。

    SPELL_ATTR6_NOT_IN_RAID_INSTANCE             = 0x00000800, // TITLE Unusable in raid instances
                                                               // 在团队副本中不可使用。进入 raid instance 后该技能被禁用。

    SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE        = 0x00001000, // TITLE Castable while caster is on vehicle
                                                               // 乘坐载具时可施放。绕过“上载具禁止施法”的默认限制。

    SPELL_ATTR6_CAN_TARGET_INVISIBLE             = 0x00002000, // TITLE Can target invisible units
                                                               // 可以选中隐形单位。忽略目标的隐形状态，用于反隐、侦测或特殊机制技能。

    SPELL_ATTR6_UNK14                            = 0x00004000, // TITLE Unknown attribute 14@Attr6
                                                               // 未知属性位。用途尚不明确。

    SPELL_ATTR6_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr6
                                                               // 未知属性位。可能与特殊施法条件有关。

    SPELL_ATTR6_UNK16                            = 0x00010000, // TITLE Unknown attribute 16@Attr6
                                                               // 未知属性位。当前无明确行为。

    SPELL_ATTR6_UNK17                            = 0x00020000, // TITLE Unknown attribute 17@Attr6 DESCRIPTION Mount related?
                                                               // 疑似与坐骑相关的属性标志。可能用于限制或放行某些骑乘状态下的技能。

    SPELL_ATTR6_CAST_BY_CHARMER                  = 0x00040000, // TITLE Spell is cast by charmer DESCRIPTION Client will prevent casting if not possessed, charmer will be caster for all intents and purposes
                                                               // 由控制者（魅惑者）施放。客户端仅在被控制状态下允许施法，且所有归属（仇恨、日志等）视为控制者。

    SPELL_ATTR6_UNK19                            = 0x00080000, // TITLE Unknown attribute 19@Attr6
                                                               // 未知属性位。用途不明。

    SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER           = 0x00100000, // TITLE Only visible to caster (client only)
                                                               // 仅对施法者可见。客户端中其他玩家无法看到该技能或光环的显示效果。

    SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS         = 0x00200000, // TITLE Client UI target effects (client only)
                                                               // 客户端目标 UI 特效标志。用于显示特殊指示、边框或选中效果。

    SPELL_ATTR6_UNK22                            = 0x00400000, // TITLE Unknown attribute 22@Attr6
                                                               // 未知属性位。尚未确认用途。

    SPELL_ATTR6_UNK23                            = 0x00800000, // TITLE Unknown attribute 23@Attr6
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR6_CAN_TARGET_UNTARGETABLE          = 0x01000000, // TITLE Can target untargetable units
                                                               // 可以选中“不可选中”的单位。绕过常规 targetable 检查（如剧情单位、特殊状态单位）。

    SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT       = 0x02000000, // TITLE Do not reset swing timer if cast time is instant
                                                               // 瞬发施法不重置普攻计时器。避免技能打断近战/远程自动攻击节奏。

    SPELL_ATTR6_UNK26                            = 0x04000000, // TITLE Unknown attribute 26@Attr6 DESCRIPTION Player castable buff?
                                                               // 未知属性位，疑似与“玩家可施放的增益类法术”相关（根据数据共现推测）。

    SPELL_ATTR6_LIMIT_PCT_HEALING_MODS           = 0x08000000, // TITLE Limit applicable %healing modifiers DESCRIPTION This prevents certain healing modifiers from applying - see implementation if you really care about details
                                                               // 限制百分比治疗加成。部分治疗增益/减益系数不会作用于该技能，防止数值被过度放大。

    SPELL_ATTR6_UNK28                            = 0x10000000, // TITLE Unknown attribute 28@Attr6 DESCRIPTION Death grip?
                                                               // 未知属性位，疑似与“死亡之握”等强制位移/牵引类技能有关（推测）。

    SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS            = 0x20000000, // TITLE Limit applicable %damage modifiers DESCRIPTION This prevents certain damage modifiers from applying - see implementation if you really care about details
                                                               // 限制百分比伤害加成。部分伤害增益/减益不会作用于该技能，用于精确控制数值结算。

    SPELL_ATTR6_UNK30                            = 0x40000000, // TITLE Unknown attribute 30@Attr6
                                                               // 未知属性位。用途尚未明确。

    SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS    = 0x80000000  // TITLE Ignore cooldown modifiers for category cooldown
                                                               // 忽略技能类别冷却修正。天赋或光环对“分类冷却”的缩短/延长不会影响该技能。
};


// EnumUtils: DESCRIBE THIS

enum SpellAttr7 : uint32
{
    SPELL_ATTR7_UNK0                             = 0x00000001, // TITLE Unknown attribute 0@Attr7
                                                               // 未知属性位。用途尚未明确，可能为内部或历史遗留标志。

    SPELL_ATTR7_IGNORE_DURATION_MODS             = 0x00000002, // TITLE Ignore duration modifiers
                                                               // 忽略持续时间修正。急速、天赋、光环等对持续时间的增减不会影响该法术。

    SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD          = 0x00000004, // TITLE Disable Aura While Dead
                                                               // 死亡状态下禁用光环。角色死亡后该光环不生效（可能不移除，但不参与结算）。

    SPELL_ATTR7_IS_CHEAT_SPELL                   = 0x00000008, // TITLE Is cheat spell DESCRIPTION Cannot cast if caster doesn't have UnitFlag2 & UNIT_FLAG2_ALLOW_CHEAT_SPELLS
                                                               // 作弊/GM 法术标记。只有具备允许作弊施法标志的单位（如 GM）才能施放。

    SPELL_ATTR7_UNK4                             = 0x00000010, // TITLE Unknown attribute 4@Attr7 DESCRIPTION Soulstone related?
                                                               // 未知属性位，疑似与灵魂石或死亡后触发类机制相关（推测）。

    SPELL_ATTR7_SUMMON_PLAYER_TOTEM              = 0x00000020, // TITLE Summons player-owned totem
                                                               // 召唤玩家所属的图腾。图腾的归属、仇恨与控制权视为施法玩家。

    SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE            = 0x00000040, // TITLE Damage dealt by this does not cause spell pushback
                                                               // 该技能造成的伤害不会引起施法回退。被命中的目标在读条时不会因这次伤害而延长施法时间。

    SPELL_ATTR7_UNK7                             = 0x00000080, // TITLE Unknown attribute 7@Attr7
                                                               // 未知属性位。用途尚未确认。

    SPELL_ATTR7_HORDE_ONLY                       = 0x00000100, // TITLE Horde only
                                                               // 部落专用技能。联盟角色无法施放或使用。

    SPELL_ATTR7_ALLIANCE_ONLY                    = 0x00000200, // TITLE Alliance only
                                                               // 联盟专用技能。部落角色无法施放或使用。

    SPELL_ATTR7_DISPEL_CHARGES                   = 0x00000400, // TITLE Dispel/Spellsteal remove individual charges
                                                               // 驱散/偷取时按“单层”处理。每次只移除一个充能层，而不是整个光环。

    SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER         = 0x00000800, // TITLE Only interrupt non-player casting
                                                               // 仅能打断非玩家单位的施法。对玩家施法不会产生打断效果。

    SPELL_ATTR7_UNK12                            = 0x00001000, // TITLE Unknown attribute 12@Attr7
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR7_UNK13                            = 0x00002000, // TITLE Unknown attribute 13@Attr7
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR7_UNK14                            = 0x00004000, // TITLE Unknown attribute 14@Attr7
                                                               // 未知属性位。可能为特定技能数据占位。

    SPELL_ATTR7_UNK15                            = 0x00008000, // TITLE Unknown attribute 15@Attr7 DESCRIPTION Exorcism - guaranteed crit vs families?
                                                               // 未知属性位，疑似与“对特定生物家族必定暴击”相关（如驱邪术历史行为，推测）。

    SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER      = 0x00010000, // TITLE Can restore secondary power DESCRIPTION Only spells with this attribute can replenish a non-active power type
                                                               // 可以恢复次要能量类型。允许回复当前未激活的能量资源（如非主资源的能量/怒气/法力）。

    SPELL_ATTR7_UNK17                            = 0x00020000, // TITLE Unknown attribute 17@Attr7
                                                               // 未知属性位。用途尚未确认。

    SPELL_ATTR7_HAS_CHARGE_EFFECT                = 0x00040000, // TITLE Has charge effect
                                                               // 具有冲锋/位移效果。通常伴随快速位移到目标位置或目标身边的行为。

    SPELL_ATTR7_ZONE_TELEPORT                    = 0x00080000, // TITLE Is zone teleport
                                                               // 区域/地图传送技能。用于跨区域或副本切换的传送法术。

    SPELL_ATTR7_UNK20                            = 0x00100000, // TITLE Unknown attribute 20@Attr7 DESCRIPTION Invulnerability related?
                                                               // 未知属性位，疑似与无敌或免疫类机制相关（推测）。

    SPELL_ATTR7_UNK21                            = 0x00200000, // TITLE Unknown attribute 21@Attr7
                                                               // 未知属性位。用途不明。

    SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING       = 0x00400000, // TITLE Ignore cold weather flying restriction DESCRIPTION Set for loaner mounts, allows them to be used despite lacking required flight skill
                                                               // 忽略寒冷天气飞行限制。常用于临时坐骑，即使角色未学习寒冷飞行也可使用。

    SPELL_ATTR7_CANT_DODGE                       = 0x00800000, // TITLE Spell cannot be dodged
                                                               // 该法术无法被闪避。命中判定中跳过“闪避”结果。

    SPELL_ATTR7_CANT_PARRY                       = 0x01000000, // TITLE Spell cannot be parried
                                                               // 该法术无法被招架。命中判定中跳过“招架”结果。

    SPELL_ATTR7_CANT_MISS                        = 0x02000000, // TITLE Spell cannot be missed
                                                               // 该法术不会未命中。直接视为命中目标（仍可能受其他规则影响）。

    SPELL_ATTR7_UNK26                            = 0x04000000, // TITLE Unknown attribute 26@Attr7
                                                               // 未知属性位。用途未明确。

    SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA         = 0x08000000, // TITLE Bypasses the prevent resurrection aura
                                                               // 绕过“禁止复活”光环。即使目标身上存在禁止复活的状态，也允许复活成功。

    SPELL_ATTR7_CONSOLIDATED_RAID_BUFF           = 0x10000000, // TITLE Consolidate in raid buff frame (client only)
                                                               // 在团队增益框中合并显示。客户端 UI 用于将多个同类团队 Buff 折叠显示。

    SPELL_ATTR7_UNK29                            = 0x20000000, // TITLE Unknown attribute 29@Attr7
                                                               // 未知属性位。用途不明。

    SPELL_ATTR7_UNK30                            = 0x40000000, // TITLE Unknown attribute 30@Attr7
                                                               // 未知属性位。用途不明。

    SPELL_ATTR7_CLIENT_INDICATOR                 = 0x80000000  // TITLE Client indicator (client only)
                                                               // 客户端指示器标记。用于显示特殊 UI 提示、光效或指向性指示，不影响服务器逻辑。
};


#define MIN_TALENT_SPEC         0
#define MAX_TALENT_SPEC         1
#define MIN_TALENT_SPECS        1
#define MAX_TALENT_SPECS        2
#define MAX_GLYPH_SLOT_INDEX    6

// Custom values
enum SpellClickUserTypes
{
    SPELL_CLICK_USER_ANY    = 0,
    SPELL_CLICK_USER_FRIEND = 1,
    SPELL_CLICK_USER_RAID   = 2,
    SPELL_CLICK_USER_PARTY  = 3,
    SPELL_CLICK_USER_MAX    = 4
};

enum SpellClickCastFlags
{
    NPC_CLICK_CAST_CASTER_CLICKER       = 0x01,
    NPC_CLICK_CAST_TARGET_CLICKER       = 0x02,
    NPC_CLICK_CAST_ORIG_CASTER_OWNER    = 0x04
};

enum SheathTypes
{
    SHEATHETYPE_NONE                   = 0,
    SHEATHETYPE_MAINHAND               = 1,
    SHEATHETYPE_OFFHAND                = 2,
    SHEATHETYPE_LARGEWEAPONLEFT        = 3,
    SHEATHETYPE_LARGEWEAPONRIGHT       = 4,
    SHEATHETYPE_HIPWEAPONLEFT          = 5,
    SHEATHETYPE_HIPWEAPONRIGHT         = 6,
    SHEATHETYPE_SHIELD                 = 7
};

#define MAX_SHEATHETYPE                  8

enum CharacterFlags
{
    CHARACTER_FLAG_NONE                 = 0x00000000,
    CHARACTER_FLAG_UNK1                 = 0x00000001,
    CHARACTER_FLAG_UNK2                 = 0x00000002,
    CHARACTER_LOCKED_FOR_TRANSFER       = 0x00000004,
    CHARACTER_FLAG_UNK4                 = 0x00000008,
    CHARACTER_FLAG_UNK5                 = 0x00000010,
    CHARACTER_FLAG_UNK6                 = 0x00000020,
    CHARACTER_FLAG_UNK7                 = 0x00000040,
    CHARACTER_FLAG_UNK8                 = 0x00000080,
    CHARACTER_FLAG_UNK9                 = 0x00000100,
    CHARACTER_FLAG_UNK10                = 0x00000200,
    CHARACTER_FLAG_HIDE_HELM            = 0x00000400,
    CHARACTER_FLAG_HIDE_CLOAK           = 0x00000800,
    CHARACTER_FLAG_UNK13                = 0x00001000,
    CHARACTER_FLAG_GHOST                = 0x00002000,
    CHARACTER_FLAG_RENAME               = 0x00004000,
    CHARACTER_FLAG_UNK16                = 0x00008000,
    CHARACTER_FLAG_UNK17                = 0x00010000,
    CHARACTER_FLAG_UNK18                = 0x00020000,
    CHARACTER_FLAG_UNK19                = 0x00040000,
    CHARACTER_FLAG_UNK20                = 0x00080000,
    CHARACTER_FLAG_UNK21                = 0x00100000,
    CHARACTER_FLAG_UNK22                = 0x00200000,
    CHARACTER_FLAG_UNK23                = 0x00400000,
    CHARACTER_FLAG_UNK24                = 0x00800000,
    CHARACTER_FLAG_LOCKED_BY_BILLING    = 0x01000000,
    CHARACTER_FLAG_DECLINED             = 0x02000000,
    CHARACTER_FLAG_UNK27                = 0x04000000,
    CHARACTER_FLAG_UNK28                = 0x08000000,
    CHARACTER_FLAG_UNK29                = 0x10000000,
    CHARACTER_FLAG_UNK30                = 0x20000000,
    CHARACTER_FLAG_UNK31                = 0x40000000,
    CHARACTER_FLAG_UNK32                = 0x80000000
};

enum CharacterCustomizeFlags
{
    CHAR_CUSTOMIZE_FLAG_NONE            = 0x00000000,
    CHAR_CUSTOMIZE_FLAG_CUSTOMIZE       = 0x00000001, // name, gender, etc...
    CHAR_CUSTOMIZE_FLAG_FACTION         = 0x00010000, // name, gender, faction, etc...
    CHAR_CUSTOMIZE_FLAG_RACE            = 0x00100000  // name, gender, race, etc...
};

enum CharacterSlot
{
    SLOT_HEAD                          = 0,
    SLOT_NECK                          = 1,
    SLOT_SHOULDERS                     = 2,
    SLOT_SHIRT                         = 3,
    SLOT_CHEST                         = 4,
    SLOT_WAIST                         = 5,
    SLOT_LEGS                          = 6,
    SLOT_FEET                          = 7,
    SLOT_WRISTS                        = 8,
    SLOT_HANDS                         = 9,
    SLOT_FINGER1                       = 10,
    SLOT_FINGER2                       = 11,
    SLOT_TRINKET1                      = 12,
    SLOT_TRINKET2                      = 13,
    SLOT_BACK                          = 14,
    SLOT_MAIN_HAND                     = 15,
    SLOT_OFF_HAND                      = 16,
    SLOT_RANGED                        = 17,
    SLOT_TABARD                        = 18,
    SLOT_EMPTY                         = 19
};

enum Language
{
    LANG_UNIVERSAL         = 0,
    LANG_ORCISH            = 1,
    LANG_DARNASSIAN        = 2,
    LANG_TAURAHE           = 3,
    LANG_DWARVISH          = 6,
    LANG_COMMON            = 7,
    LANG_DEMONIC           = 8,
    LANG_TITAN             = 9,
    LANG_THALASSIAN        = 10,
    LANG_DRACONIC          = 11,
    LANG_KALIMAG           = 12,
    LANG_GNOMISH           = 13,
    LANG_TROLL             = 14,
    LANG_GUTTERSPEAK       = 33,
    LANG_DRAENEI           = 35,
    LANG_ZOMBIE            = 36,
    LANG_GNOMISH_BINARY    = 37,
    LANG_GOBLIN_BINARY     = 38,
    LANG_ADDON             = 0xFFFFFFFF // used by addons, in 2.4.0 not exist, replaced by messagetype?
};

#define LANGUAGES_COUNT   19

enum TeamId
{
    TEAM_ALLIANCE = 0,
    TEAM_HORDE,
    TEAM_NEUTRAL
};

enum Team
{
    HORDE               = 67,
    ALLIANCE            = 469,
    //TEAM_STEAMWHEEDLE_CARTEL = 169,                       // not used in code
    //TEAM_ALLIANCE_FORCES     = 891,
    //TEAM_HORDE_FORCES        = 892,
    //TEAM_SANCTUARY           = 936,
    //TEAM_OUTLAND             = 980,
    TEAM_OTHER               = 0                            // if ReputationListId > 0 && Flags != FACTION_FLAG_TEAM_HEADER
};

enum SpellEffects
{
    SPELL_EFFECT_NONE                               = 0,
    SPELL_EFFECT_INSTAKILL                          = 1,
    SPELL_EFFECT_SCHOOL_DAMAGE                      = 2,
    SPELL_EFFECT_DUMMY                              = 3,
    SPELL_EFFECT_PORTAL_TELEPORT                    = 4,
    SPELL_EFFECT_TELEPORT_UNITS                     = 5,
    SPELL_EFFECT_APPLY_AURA                         = 6,
    SPELL_EFFECT_ENVIRONMENTAL_DAMAGE               = 7,
    SPELL_EFFECT_POWER_DRAIN                        = 8,
    SPELL_EFFECT_HEALTH_LEECH                       = 9,
    SPELL_EFFECT_HEAL                               = 10,
    SPELL_EFFECT_BIND                               = 11,
    SPELL_EFFECT_PORTAL                             = 12,
    SPELL_EFFECT_RITUAL_BASE                        = 13,
    SPELL_EFFECT_RITUAL_SPECIALIZE                  = 14,
    SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL             = 15,
    SPELL_EFFECT_QUEST_COMPLETE                     = 16,
    SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL             = 17,
    SPELL_EFFECT_RESURRECT                          = 18,
    SPELL_EFFECT_ADD_EXTRA_ATTACKS                  = 19,
    SPELL_EFFECT_DODGE                              = 20,
    SPELL_EFFECT_EVADE                              = 21,
    SPELL_EFFECT_PARRY                              = 22,
    SPELL_EFFECT_BLOCK                              = 23,
    SPELL_EFFECT_CREATE_ITEM                        = 24,
    SPELL_EFFECT_WEAPON                             = 25,
    SPELL_EFFECT_DEFENSE                            = 26,
    SPELL_EFFECT_PERSISTENT_AREA_AURA               = 27,
    SPELL_EFFECT_SUMMON                             = 28,
    SPELL_EFFECT_LEAP                               = 29,
    SPELL_EFFECT_ENERGIZE                           = 30,
    SPELL_EFFECT_WEAPON_PERCENT_DAMAGE              = 31,
    SPELL_EFFECT_TRIGGER_MISSILE                    = 32,
    SPELL_EFFECT_OPEN_LOCK                          = 33,
    SPELL_EFFECT_SUMMON_CHANGE_ITEM                 = 34,
    SPELL_EFFECT_APPLY_AREA_AURA_PARTY              = 35,
    SPELL_EFFECT_LEARN_SPELL                        = 36,
    SPELL_EFFECT_SPELL_DEFENSE                      = 37,
    SPELL_EFFECT_DISPEL                             = 38,
    SPELL_EFFECT_LANGUAGE                           = 39,
    SPELL_EFFECT_DUAL_WIELD                         = 40,
    SPELL_EFFECT_JUMP                               = 41,
    SPELL_EFFECT_JUMP_DEST                          = 42,
    SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER         = 43,
    SPELL_EFFECT_SKILL_STEP                         = 44,
    SPELL_EFFECT_ADD_HONOR                          = 45,
    SPELL_EFFECT_SPAWN                              = 46,
    SPELL_EFFECT_TRADE_SKILL                        = 47,
    SPELL_EFFECT_STEALTH                            = 48,
    SPELL_EFFECT_DETECT                             = 49,
    SPELL_EFFECT_TRANS_DOOR                         = 50,
    SPELL_EFFECT_FORCE_CRITICAL_HIT                 = 51,
    SPELL_EFFECT_GUARANTEE_HIT                      = 52,
    SPELL_EFFECT_ENCHANT_ITEM                       = 53,
    SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY             = 54,
    SPELL_EFFECT_TAMECREATURE                       = 55,
    SPELL_EFFECT_SUMMON_PET                         = 56,
    SPELL_EFFECT_LEARN_PET_SPELL                    = 57,
    SPELL_EFFECT_WEAPON_DAMAGE                      = 58,
    SPELL_EFFECT_CREATE_RANDOM_ITEM                 = 59,
    SPELL_EFFECT_PROFICIENCY                        = 60,
    SPELL_EFFECT_SEND_EVENT                         = 61,
    SPELL_EFFECT_POWER_BURN                         = 62,
    SPELL_EFFECT_THREAT                             = 63,
    SPELL_EFFECT_TRIGGER_SPELL                      = 64,
    SPELL_EFFECT_APPLY_AREA_AURA_RAID               = 65,
    SPELL_EFFECT_CREATE_MANA_GEM                    = 66,
    SPELL_EFFECT_HEAL_MAX_HEALTH                    = 67,
    SPELL_EFFECT_INTERRUPT_CAST                     = 68,
    SPELL_EFFECT_DISTRACT                           = 69,
    SPELL_EFFECT_PULL                               = 70,
    SPELL_EFFECT_PICKPOCKET                         = 71,
    SPELL_EFFECT_ADD_FARSIGHT                       = 72,
    SPELL_EFFECT_UNTRAIN_TALENTS                    = 73,
    SPELL_EFFECT_APPLY_GLYPH                        = 74,
    SPELL_EFFECT_HEAL_MECHANICAL                    = 75,
    SPELL_EFFECT_SUMMON_OBJECT_WILD                 = 76,
    SPELL_EFFECT_SCRIPT_EFFECT                      = 77,
    SPELL_EFFECT_ATTACK                             = 78,
    SPELL_EFFECT_SANCTUARY                          = 79,
    SPELL_EFFECT_ADD_COMBO_POINTS                   = 80,
    SPELL_EFFECT_CREATE_HOUSE                       = 81,
    SPELL_EFFECT_BIND_SIGHT                         = 82,
    SPELL_EFFECT_DUEL                               = 83,
    SPELL_EFFECT_STUCK                              = 84,
    SPELL_EFFECT_SUMMON_PLAYER                      = 85,
    SPELL_EFFECT_ACTIVATE_OBJECT                    = 86,
    SPELL_EFFECT_GAMEOBJECT_DAMAGE                  = 87,
    SPELL_EFFECT_GAMEOBJECT_REPAIR                  = 88,
    SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE   = 89,
    SPELL_EFFECT_KILL_CREDIT                        = 90,
    SPELL_EFFECT_THREAT_ALL                         = 91,
    SPELL_EFFECT_ENCHANT_HELD_ITEM                  = 92,
    SPELL_EFFECT_FORCE_DESELECT                     = 93,
    SPELL_EFFECT_SELF_RESURRECT                     = 94,
    SPELL_EFFECT_SKINNING                           = 95,
    SPELL_EFFECT_CHARGE                             = 96,
    SPELL_EFFECT_CAST_BUTTON                        = 97,
    SPELL_EFFECT_KNOCK_BACK                         = 98,
    SPELL_EFFECT_DISENCHANT                         = 99,
    SPELL_EFFECT_INEBRIATE                          = 100,
    SPELL_EFFECT_FEED_PET                           = 101,
    SPELL_EFFECT_DISMISS_PET                        = 102,
    SPELL_EFFECT_REPUTATION                         = 103,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT1                = 104,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT2                = 105,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT3                = 106,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT4                = 107,
    SPELL_EFFECT_DISPEL_MECHANIC                    = 108,
    SPELL_EFFECT_RESURRECT_PET                      = 109,
    SPELL_EFFECT_DESTROY_ALL_TOTEMS                 = 110,
    SPELL_EFFECT_DURABILITY_DAMAGE                  = 111,
    SPELL_EFFECT_112                                = 112,
    SPELL_EFFECT_RESURRECT_NEW                      = 113,
    SPELL_EFFECT_ATTACK_ME                          = 114,
    SPELL_EFFECT_DURABILITY_DAMAGE_PCT              = 115,
    SPELL_EFFECT_SKIN_PLAYER_CORPSE                 = 116,
    SPELL_EFFECT_SPIRIT_HEAL                        = 117,
    SPELL_EFFECT_SKILL                              = 118,
    SPELL_EFFECT_APPLY_AREA_AURA_PET                = 119,
    SPELL_EFFECT_TELEPORT_GRAVEYARD                 = 120,
    SPELL_EFFECT_NORMALIZED_WEAPON_DMG              = 121,
    SPELL_EFFECT_122                                = 122,
    SPELL_EFFECT_SEND_TAXI                          = 123,
    SPELL_EFFECT_PULL_TOWARDS                       = 124,
    SPELL_EFFECT_MODIFY_THREAT_PERCENT              = 125,
    SPELL_EFFECT_STEAL_BENEFICIAL_BUFF              = 126,
    SPELL_EFFECT_PROSPECTING                        = 127,
    SPELL_EFFECT_APPLY_AREA_AURA_FRIEND             = 128,
    SPELL_EFFECT_APPLY_AREA_AURA_ENEMY              = 129,
    SPELL_EFFECT_REDIRECT_THREAT                    = 130,
    SPELL_EFFECT_PLAY_SOUND                         = 131,
    SPELL_EFFECT_PLAY_MUSIC                         = 132,
    SPELL_EFFECT_UNLEARN_SPECIALIZATION             = 133,
    SPELL_EFFECT_KILL_CREDIT2                       = 134,
    SPELL_EFFECT_CALL_PET                           = 135,
    SPELL_EFFECT_HEAL_PCT                           = 136,
    SPELL_EFFECT_ENERGIZE_PCT                       = 137,
    SPELL_EFFECT_LEAP_BACK                          = 138,
    SPELL_EFFECT_CLEAR_QUEST                        = 139,
    SPELL_EFFECT_FORCE_CAST                         = 140,
    SPELL_EFFECT_FORCE_CAST_WITH_VALUE              = 141,
    SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE           = 142,
    SPELL_EFFECT_APPLY_AREA_AURA_OWNER              = 143,
    SPELL_EFFECT_KNOCK_BACK_DEST                    = 144,
    SPELL_EFFECT_PULL_TOWARDS_DEST                  = 145,
    SPELL_EFFECT_ACTIVATE_RUNE                      = 146,
    SPELL_EFFECT_QUEST_FAIL                         = 147,
    SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE   = 148,
    SPELL_EFFECT_CHARGE_DEST                        = 149,
    SPELL_EFFECT_QUEST_START                        = 150,
    SPELL_EFFECT_TRIGGER_SPELL_2                    = 151,
    SPELL_EFFECT_SUMMON_RAF_FRIEND                  = 152,
    SPELL_EFFECT_CREATE_TAMED_PET                   = 153,
    SPELL_EFFECT_DISCOVER_TAXI                      = 154,
    SPELL_EFFECT_TITAN_GRIP                         = 155,
    SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC             = 156,
    SPELL_EFFECT_CREATE_ITEM_2                      = 157,
    SPELL_EFFECT_MILLING                            = 158,
    SPELL_EFFECT_ALLOW_RENAME_PET                   = 159,
    SPELL_EFFECT_FORCE_CAST_2                       = 160,
    SPELL_EFFECT_TALENT_SPEC_COUNT                  = 161,
    SPELL_EFFECT_TALENT_SPEC_SELECT                 = 162,
    SPELL_EFFECT_163                                = 163,
    SPELL_EFFECT_REMOVE_AURA                        = 164,
    TOTAL_SPELL_EFFECTS                             = 165
};

// EnumUtils: DESCRIBE THIS
enum SpellCastResult : uint8
{
    SPELL_FAILED_SUCCESS = 0,
    SPELL_FAILED_AFFECTING_COMBAT = 1,
    SPELL_FAILED_ALREADY_AT_FULL_HEALTH = 2,
    SPELL_FAILED_ALREADY_AT_FULL_MANA = 3,
    SPELL_FAILED_ALREADY_AT_FULL_POWER = 4,
    SPELL_FAILED_ALREADY_BEING_TAMED = 5,
    SPELL_FAILED_ALREADY_HAVE_CHARM = 6,
    SPELL_FAILED_ALREADY_HAVE_SUMMON = 7,
    SPELL_FAILED_ALREADY_OPEN = 8,
    SPELL_FAILED_AURA_BOUNCED = 9,
    SPELL_FAILED_AUTOTRACK_INTERRUPTED = 10,
    SPELL_FAILED_BAD_IMPLICIT_TARGETS = 11,
    SPELL_FAILED_BAD_TARGETS = 12,
    SPELL_FAILED_CANT_BE_CHARMED = 13,
    SPELL_FAILED_CANT_BE_DISENCHANTED = 14,
    SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL = 15,
    SPELL_FAILED_CANT_BE_MILLED = 16,
    SPELL_FAILED_CANT_BE_PROSPECTED = 17,
    SPELL_FAILED_CANT_CAST_ON_TAPPED = 18,
    SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE = 19,
    SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED = 20,
    SPELL_FAILED_CANT_STEALTH = 21,
    SPELL_FAILED_CASTER_AURASTATE = 22,
    SPELL_FAILED_CASTER_DEAD = 23,
    SPELL_FAILED_CHARMED = 24,
    SPELL_FAILED_CHEST_IN_USE = 25,
    SPELL_FAILED_CONFUSED = 26,
    SPELL_FAILED_DONT_REPORT = 27,
    SPELL_FAILED_EQUIPPED_ITEM = 28,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS = 29,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND = 30,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND = 31,
    SPELL_FAILED_ERROR = 32,
    SPELL_FAILED_FIZZLE = 33,
    SPELL_FAILED_FLEEING = 34,
    SPELL_FAILED_FOOD_LOWLEVEL = 35,
    SPELL_FAILED_HIGHLEVEL = 36,
    SPELL_FAILED_HUNGER_SATIATED = 37,
    SPELL_FAILED_IMMUNE = 38,
    SPELL_FAILED_INCORRECT_AREA = 39,
    SPELL_FAILED_INTERRUPTED = 40,
    SPELL_FAILED_INTERRUPTED_COMBAT = 41,
    SPELL_FAILED_ITEM_ALREADY_ENCHANTED = 42,
    SPELL_FAILED_ITEM_GONE = 43,
    SPELL_FAILED_ITEM_NOT_FOUND = 44,
    SPELL_FAILED_ITEM_NOT_READY = 45,
    SPELL_FAILED_LEVEL_REQUIREMENT = 46,
    SPELL_FAILED_LINE_OF_SIGHT = 47,
    SPELL_FAILED_LOWLEVEL = 48,
    SPELL_FAILED_LOW_CASTLEVEL = 49,
    SPELL_FAILED_MAINHAND_EMPTY = 50,
    SPELL_FAILED_MOVING = 51,
    SPELL_FAILED_NEED_AMMO = 52,
    SPELL_FAILED_NEED_AMMO_POUCH = 53,
    SPELL_FAILED_NEED_EXOTIC_AMMO = 54,
    SPELL_FAILED_NEED_MORE_ITEMS = 55,
    SPELL_FAILED_NOPATH = 56,
    SPELL_FAILED_NOT_BEHIND = 57,
    SPELL_FAILED_NOT_FISHABLE = 58,
    SPELL_FAILED_NOT_FLYING = 59,
    SPELL_FAILED_NOT_HERE = 60,
    SPELL_FAILED_NOT_INFRONT = 61,
    SPELL_FAILED_NOT_IN_CONTROL = 62,
    SPELL_FAILED_NOT_KNOWN = 63,
    SPELL_FAILED_NOT_MOUNTED = 64,
    SPELL_FAILED_NOT_ON_TAXI = 65,
    SPELL_FAILED_NOT_ON_TRANSPORT = 66,
    SPELL_FAILED_NOT_READY = 67,
    SPELL_FAILED_NOT_SHAPESHIFT = 68,
    SPELL_FAILED_NOT_STANDING = 69,
    SPELL_FAILED_NOT_TRADEABLE = 70,
    SPELL_FAILED_NOT_TRADING = 71,
    SPELL_FAILED_NOT_UNSHEATHED = 72,
    SPELL_FAILED_NOT_WHILE_GHOST = 73,
    SPELL_FAILED_NOT_WHILE_LOOTING = 74,
    SPELL_FAILED_NO_AMMO = 75,
    SPELL_FAILED_NO_CHARGES_REMAIN = 76,
    SPELL_FAILED_NO_CHAMPION = 77,
    SPELL_FAILED_NO_COMBO_POINTS = 78,
    SPELL_FAILED_NO_DUELING = 79,
    SPELL_FAILED_NO_ENDURANCE = 80,
    SPELL_FAILED_NO_FISH = 81,
    SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED = 82,
    SPELL_FAILED_NO_MOUNTS_ALLOWED = 83,
    SPELL_FAILED_NO_PET = 84,
    SPELL_FAILED_NO_POWER = 85,
    SPELL_FAILED_NOTHING_TO_DISPEL = 86,
    SPELL_FAILED_NOTHING_TO_STEAL = 87,
    SPELL_FAILED_ONLY_ABOVEWATER = 88,
    SPELL_FAILED_ONLY_DAYTIME = 89,
    SPELL_FAILED_ONLY_INDOORS = 90,
    SPELL_FAILED_ONLY_MOUNTED = 91,
    SPELL_FAILED_ONLY_NIGHTTIME = 92,
    SPELL_FAILED_ONLY_OUTDOORS = 93,
    SPELL_FAILED_ONLY_SHAPESHIFT = 94,
    SPELL_FAILED_ONLY_STEALTHED = 95,
    SPELL_FAILED_ONLY_UNDERWATER = 96,
    SPELL_FAILED_OUT_OF_RANGE = 97,
    SPELL_FAILED_PACIFIED = 98,
    SPELL_FAILED_POSSESSED = 99,
    SPELL_FAILED_REAGENTS = 100,
    SPELL_FAILED_REQUIRES_AREA = 101,
    SPELL_FAILED_REQUIRES_SPELL_FOCUS = 102,
    SPELL_FAILED_ROOTED = 103,
    SPELL_FAILED_SILENCED = 104,
    SPELL_FAILED_SPELL_IN_PROGRESS = 105,
    SPELL_FAILED_SPELL_LEARNED = 106,
    SPELL_FAILED_SPELL_UNAVAILABLE = 107,
    SPELL_FAILED_STUNNED = 108,
    SPELL_FAILED_TARGETS_DEAD = 109,
    SPELL_FAILED_TARGET_AFFECTING_COMBAT = 110,
    SPELL_FAILED_TARGET_AURASTATE = 111,
    SPELL_FAILED_TARGET_DUELING = 112,
    SPELL_FAILED_TARGET_ENEMY = 113,
    SPELL_FAILED_TARGET_ENRAGED = 114,
    SPELL_FAILED_TARGET_FRIENDLY = 115,
    SPELL_FAILED_TARGET_IN_COMBAT = 116,
    SPELL_FAILED_TARGET_IS_PLAYER = 117,
    SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED = 118,
    SPELL_FAILED_TARGET_NOT_DEAD = 119,
    SPELL_FAILED_TARGET_NOT_IN_PARTY = 120,
    SPELL_FAILED_TARGET_NOT_LOOTED = 121,
    SPELL_FAILED_TARGET_NOT_PLAYER = 122,
    SPELL_FAILED_TARGET_NO_POCKETS = 123,
    SPELL_FAILED_TARGET_NO_WEAPONS = 124,
    SPELL_FAILED_TARGET_NO_RANGED_WEAPONS = 125,
    SPELL_FAILED_TARGET_UNSKINNABLE = 126,
    SPELL_FAILED_THIRST_SATIATED = 127,
    SPELL_FAILED_TOO_CLOSE = 128,
    SPELL_FAILED_TOO_MANY_OF_ITEM = 129,
    SPELL_FAILED_TOTEM_CATEGORY = 130,
    SPELL_FAILED_TOTEMS = 131,
    SPELL_FAILED_TRY_AGAIN = 132,
    SPELL_FAILED_UNIT_NOT_BEHIND = 133,
    SPELL_FAILED_UNIT_NOT_INFRONT = 134,
    SPELL_FAILED_WRONG_PET_FOOD = 135,
    SPELL_FAILED_NOT_WHILE_FATIGUED = 136,
    SPELL_FAILED_TARGET_NOT_IN_INSTANCE = 137,
    SPELL_FAILED_NOT_WHILE_TRADING = 138,
    SPELL_FAILED_TARGET_NOT_IN_RAID = 139,
    SPELL_FAILED_TARGET_FREEFORALL = 140,
    SPELL_FAILED_NO_EDIBLE_CORPSES = 141,
    SPELL_FAILED_ONLY_BATTLEGROUNDS = 142,
    SPELL_FAILED_TARGET_NOT_GHOST = 143,
    SPELL_FAILED_TRANSFORM_UNUSABLE = 144,
    SPELL_FAILED_WRONG_WEATHER = 145,
    SPELL_FAILED_DAMAGE_IMMUNE = 146,
    SPELL_FAILED_PREVENTED_BY_MECHANIC = 147,
    SPELL_FAILED_PLAY_TIME = 148,
    SPELL_FAILED_REPUTATION = 149,
    SPELL_FAILED_MIN_SKILL = 150,
    SPELL_FAILED_NOT_IN_ARENA = 151,
    SPELL_FAILED_NOT_ON_SHAPESHIFT = 152,
    SPELL_FAILED_NOT_ON_STEALTHED = 153,
    SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE = 154,
    SPELL_FAILED_NOT_ON_MOUNTED = 155,
    SPELL_FAILED_TOO_SHALLOW = 156,
    SPELL_FAILED_TARGET_NOT_IN_SANCTUARY = 157,
    SPELL_FAILED_TARGET_IS_TRIVIAL = 158,
    SPELL_FAILED_BM_OR_INVISGOD = 159,
    SPELL_FAILED_EXPERT_RIDING_REQUIREMENT = 160,
    SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT = 161,
    SPELL_FAILED_NOT_IDLE = 162,
    SPELL_FAILED_NOT_INACTIVE = 163,
    SPELL_FAILED_PARTIAL_PLAYTIME = 164,
    SPELL_FAILED_NO_PLAYTIME = 165,
    SPELL_FAILED_NOT_IN_BATTLEGROUND = 166,
    SPELL_FAILED_NOT_IN_RAID_INSTANCE = 167,
    SPELL_FAILED_ONLY_IN_ARENA = 168,
    SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE = 169,
    SPELL_FAILED_ON_USE_ENCHANT = 170,
    SPELL_FAILED_NOT_ON_GROUND = 171,
    SPELL_FAILED_CUSTOM_ERROR = 172,
    SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW = 173,
    SPELL_FAILED_TOO_MANY_SOCKETS = 174,
    SPELL_FAILED_INVALID_GLYPH = 175,
    SPELL_FAILED_UNIQUE_GLYPH = 176,
    SPELL_FAILED_GLYPH_SOCKET_LOCKED = 177,
    SPELL_FAILED_NO_VALID_TARGETS = 178,
    SPELL_FAILED_ITEM_AT_MAX_CHARGES = 179,
    SPELL_FAILED_NOT_IN_BARBERSHOP = 180,
    SPELL_FAILED_FISHING_TOO_LOW = 181,
    SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW = 182,
    SPELL_FAILED_SUMMON_PENDING = 183,
    SPELL_FAILED_MAX_SOCKETS = 184,
    SPELL_FAILED_PET_CAN_RENAME = 185,
    SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED = 186,
    SPELL_FAILED_UNKNOWN = 187, // actually doesn't exist in client

    SPELL_CAST_OK = 255 // custom value, must not be sent to client
};

enum SpellCustomErrors
{
    SPELL_CUSTOM_ERROR_NONE                             =  0,
    SPELL_CUSTOM_ERROR_CUSTOM_MSG                       =  1, // Something bad happened, and we want to display a custom message!
    SPELL_CUSTOM_ERROR_ALEX_BROKE_QUEST                 =  2, // Alex broke your quest! Thank him later!
    SPELL_CUSTOM_ERROR_NEED_HELPLESS_VILLAGER           =  3, // This spell may only be used on Helpless Wintergarde Villagers that have not been rescued.
    SPELL_CUSTOM_ERROR_NEED_WARSONG_DISGUISE            =  4, // Requires that you be wearing the Warsong Orc Disguise.
    SPELL_CUSTOM_ERROR_REQUIRES_PLAGUE_WAGON            =  5, // You must be closer to a plague wagon in order to drop off your 7th Legion Siege Engineer.
    SPELL_CUSTOM_ERROR_CANT_TARGET_FRIENDLY_NONPARTY    =  6, // You cannot target friendly units outside your party.
    SPELL_CUSTOM_ERROR_NEED_CHILL_NYMPH                 =  7, // You must target a weakened chill nymph.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_ENKILAH               =  8, // The Imbued Scourge Shroud will only work when equipped in the Temple City of En'kilah.
    SPELL_CUSTOM_ERROR_REQUIRES_CORPSE_DUST             =  9, // Requires Corpse Dust
    SPELL_CUSTOM_ERROR_CANT_SUMMON_GARGOYLE             = 10, // You cannot summon another gargoyle yet.
    SPELL_CUSTOM_ERROR_NEED_CORPSE_DUST_IF_NO_TARGET    = 11, // Requires Corpse Dust if the target is not dead and humanoid.
    SPELL_CUSTOM_ERROR_MUST_BE_AT_SHATTERHORN           = 12, // Can only be placed near Shatterhorn
    SPELL_CUSTOM_ERROR_MUST_TARGET_PROTO_DRAKE_EGG      = 13, // You must first select a Proto-Drake Egg.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_TREE            = 14, // You must be close to a marked tree.
    SPELL_CUSTOM_ERROR_MUST_TARGET_TURKEY               = 15, // You must target a Fjord Turkey.
    SPELL_CUSTOM_ERROR_MUST_TARGET_HAWK                 = 16, // You must target a Fjord Hawk.
    SPELL_CUSTOM_ERROR_TOO_FAR_FROM_BOUY                = 17, // You are too far from the bouy.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_OIL_SLICK       = 18, // Must be used near an oil slick.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_BOUY            = 19, // You must be closer to the buoy!
    SPELL_CUSTOM_ERROR_WYRMREST_VANQUISHER              = 20, // You may only call for the aid of a Wyrmrest Vanquisher in Wyrmrest Temple, The Dragon Wastes, Galakrond's Rest or The Wicked Coil.
    SPELL_CUSTOM_ERROR_MUST_TARGET_ICE_HEART_JORMUNGAR  = 21, // That can only be used on a Ice Heart Jormungar Spawn.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_SINKHOLE        = 22, // You must be closer to a sinkhole to use your map.
    SPELL_CUSTOM_ERROR_REQUIRES_HAROLD_LANE             = 23, // You may only call down a stampede on Harold Lane.
    SPELL_CUSTOM_ERROR_REQUIRES_GAMMOTH_MAGNATAUR       = 24, // You may only use the Pouch of Crushed Bloodspore on Gammothra or other magnataur in the Bloodspore Plains and Gammoth.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_RESURRECTION_CHAMBER  = 25, // Requires the magmawyrm resurrection chamber in the back of the Maw of Neltharion.
    SPELL_CUSTOM_ERROR_CANT_CALL_WINTERGARDE_HERE       = 26, // You may only call down a Wintergarde Gryphon in Wintergarde Keep or the Carrion Fields.
    SPELL_CUSTOM_ERROR_MUST_TARGET_WILHELM              = 27, // What are you doing? Only aim that thing at Wilhelm!
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_HEALTH                = 28, // Not enough health!
    SPELL_CUSTOM_ERROR_NO_NEARBY_CORPSES                = 29, // There are no nearby corpses to use
    SPELL_CUSTOM_ERROR_TOO_MANY_GHOULS                  = 30, // You've created enough ghouls. Return to Gothik the Harvester at Death's Breach.
    SPELL_CUSTOM_ERROR_GO_FURTHER_FROM_SUNDERED_SHARD   = 31, // Your companion does not want to come here.  Go further from the Sundered Shard.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_CAT_FORM              = 32, // Must be in Cat Form
    SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT             = 33, // Only Death Knights may enter Ebon Hold.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_FERAL_FORM            = 34, // Must be in Cat Form, Bear Form, or Dire Bear Form
    SPELL_CUSTOM_ERROR_MUST_BE_NEAR_HELPLESS_VILLAGER   = 35, // You must be within range of a Helpless Wintergarde Villager.
    SPELL_CUSTOM_ERROR_CANT_TARGET_ELEMENTAL_MECHANICAL = 36, // You cannot target an elemental or mechanical corpse.
    SPELL_CUSTOM_ERROR_MUST_HAVE_USED_DALARAN_CRYSTAL   = 37, // This teleport crystal cannot be used until the teleport crystal in Dalaran has been used at least once.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HOLD_SOMETHING       = 38, // You are already holding something in your hand. You must throw the creature in your hand before picking up another.
    SPELL_CUSTOM_ERROR_YOU_DONT_HOLD_ANYTHING           = 39, // You don't have anything to throw! Find a Vargul and use Gymer Grab to pick one up!
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_VALDURAN        = 40, // Bouldercrag's War Horn can only be used within 10 yards of Valduran the Stormborn.
    SPELL_CUSTOM_ERROR_NO_PASSENGER                     = 41, // You are not carrying a passenger. There is nobody to drop off.
    SPELL_CUSTOM_ERROR_CANT_BUILD_MORE_VEHICLES         = 42, // You cannot build any more siege vehicles.
    SPELL_CUSTOM_ERROR_ALREADY_CARRYING_CRUSADER        = 43, // You are already carrying a captured Argent Crusader. You must return to the Argent Vanguard infirmary and drop off your passenger before you may pick up another.
    SPELL_CUSTOM_ERROR_CANT_DO_WHILE_ROOTED             = 44, // You can't do that while rooted.
    SPELL_CUSTOM_ERROR_REQUIRES_NEARBY_TARGET           = 45, // Requires a nearby target.
    SPELL_CUSTOM_ERROR_NOTHING_TO_DISCOVER              = 46, // Nothing left to discover.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_TARGETS               = 47, // No targets close enough to bluff.
    SPELL_CUSTOM_ERROR_CONSTRUCT_TOO_FAR                = 48, // Your Iron Rune Construct is out of range.
    SPELL_CUSTOM_ERROR_REQUIRES_GRAND_MASTER_ENGINEER   = 49, // Requires Grand Master Engineer
    SPELL_CUSTOM_ERROR_CANT_USE_THAT_MOUNT              = 50, // You can't use that mount.
    SPELL_CUSTOM_ERROR_NOONE_TO_EJECT                   = 51, // There is nobody to eject!
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_BOUND             = 52, // The target must be bound to you.
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_UNDEAD            = 53, // Target must be undead.
    SPELL_CUSTOM_ERROR_TARGET_TOO_FAR                   = 54, // You have no target or your target is too far away.
    SPELL_CUSTOM_ERROR_MISSING_DARK_MATTER              = 55, // Missing Reagents: Dark Matter
    SPELL_CUSTOM_ERROR_CANT_USE_THAT_ITEM               = 56, // You can't use that item
    SPELL_CUSTOM_ERROR_CANT_DO_WHILE_CYCYLONED          = 57, // You can't do that while Cycloned
    SPELL_CUSTOM_ERROR_TARGET_HAS_SCROLL                = 58, // Target is already affected by a scroll
    SPELL_CUSTOM_ERROR_POISON_TOO_STRONG                = 59, // That anti-venom is not strong enough to dispel that poison
    SPELL_CUSTOM_ERROR_MUST_HAVE_LANCE_EQUIPPED         = 60, // You must have a lance equipped.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_MAIDEN          = 61, // You must be near the Maiden of Winter's Breath Lake.
    SPELL_CUSTOM_ERROR_LEARNED_EVERYTHING               = 62, // You have learned everything from that book
    SPELL_CUSTOM_ERROR_PET_IS_DEAD                      = 63, // Your pet is dead
    SPELL_CUSTOM_ERROR_NO_VALID_TARGETS                 = 64, // There are no valid targets within range.
    SPELL_CUSTOM_ERROR_GM_ONLY                          = 65, // Only GMs may use that. Your account has been reported for investigation.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_58                = 66, // You must reach level 58 to use this portal.
    SPELL_CUSTOM_ERROR_AT_HONOR_CAP                     = 67, // You already have the maximum amount of honor.
    SPELL_CUSTOM_ERROR_68                               = 68, // ""
    SPELL_CUSTOM_ERROR_69                               = 69, // ""
    SPELL_CUSTOM_ERROR_70                               = 70, // ""
    SPELL_CUSTOM_ERROR_71                               = 71, // ""
    SPELL_CUSTOM_ERROR_72                               = 72, // ""
    SPELL_CUSTOM_ERROR_73                               = 73, // ""
    SPELL_CUSTOM_ERROR_74                               = 74, // ""
    SPELL_CUSTOM_ERROR_MUST_HAVE_DEMONIC_CIRCLE         = 75, // You must have a demonic circle active.
    SPELL_CUSTOM_ERROR_AT_MAX_RAGE                      = 76, // You already have maximum rage
    SPELL_CUSTOM_ERROR_REQUIRES_350_ENGINEERING         = 77, // Requires Engineering (350)
    SPELL_CUSTOM_ERROR_SOUL_BELONGS_TO_LICH_KING        = 78, // Your soul belongs to the Lich King
    SPELL_CUSTOM_ERROR_ATTENDANT_HAS_PONY               = 79, // Your attendant already has an Argent Pony
    SPELL_CUSTOM_ERROR_80                               = 80, // ""
    SPELL_CUSTOM_ERROR_81                               = 81, // ""
    SPELL_CUSTOM_ERROR_82                               = 82, // ""
    SPELL_CUSTOM_ERROR_MUST_HAVE_FIRE_TOTEM             = 83, // You must have a Fire Totem active.
    SPELL_CUSTOM_ERROR_CANT_TARGET_VAMPIRES             = 84, // You may not bite other vampires.
    SPELL_CUSTOM_ERROR_PET_ALREADY_AT_YOUR_LEVEL        = 85, // Your pet is already at your level.
    SPELL_CUSTOM_ERROR_MISSING_ITEM_REQUIREMENS         = 86, // You do not meet the level requirements for this item.
    SPELL_CUSTOM_ERROR_TOO_MANY_ABOMINATIONS            = 87, // There are too many Mutated Abominations.
    SPELL_CUSTOM_ERROR_ALL_POTIONS_USED                 = 88, // The potions have all been depleted by Professor Putricide.
    SPELL_CUSTOM_ERROR_89                               = 89, // ""
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_65                = 90, // Requires level 65
    SPELL_CUSTOM_ERROR_91                               = 91, // ""
    SPELL_CUSTOM_ERROR_92                               = 92, // ""
    SPELL_CUSTOM_ERROR_93                               = 93, // ""
    SPELL_CUSTOM_ERROR_94                               = 94, // ""
    SPELL_CUSTOM_ERROR_95                               = 95, // ""
    SPELL_CUSTOM_ERROR_MAX_NUMBER_OF_RECRUITS           = 96, // You already have the max number of recruits.
    SPELL_CUSTOM_ERROR_MAX_NUMBER_OF_VOLUNTEERS         = 97, // You already have the max number of volunteers.
    SPELL_CUSTOM_ERROR_FROSTMOURNE_RENDERED_RESURRECT   = 98, // Frostmourne has rendered you unable to resurrect.
    SPELL_CUSTOM_ERROR_CANT_MOUNT_WITH_SHAPESHIFT       = 99  // You can't mount while affected by that shapeshift.
};

enum StealthType
{
    STEALTH_GENERAL     = 0,
    STEALTH_TRAP        = 1,

    TOTAL_STEALTH_TYPES = 2
};

enum InvisibilityType
{
    INVISIBILITY_GENERAL     =  0,
    INVISIBILITY_UNK1        =  1,
    INVISIBILITY_UNK2        =  2,
    INVISIBILITY_TRAP        =  3,
    INVISIBILITY_UNK4        =  4,
    INVISIBILITY_UNK5        =  5,
    INVISIBILITY_DRUNK       =  6,
    INVISIBILITY_UNK7        =  7,
    INVISIBILITY_UNK8        =  8,
    INVISIBILITY_UNK9        =  9,
    INVISIBILITY_UNK10       = 10,
    INVISIBILITY_UNK11       = 11,

    TOTAL_INVISIBILITY_TYPES = 12
};

enum ServerSideVisibilityType
{
    SERVERSIDE_VISIBILITY_GM          = 0,
    SERVERSIDE_VISIBILITY_GHOST       = 1,

    TOTAL_SERVERSIDE_VISIBILITY_TYPES = 2
};

enum GhostVisibilityType
{
    GHOST_VISIBILITY_ALIVE = 0x1,
    GHOST_VISIBILITY_GHOST = 0x2
};

// Spell aura states
// EnumUtils: DESCRIBE THIS
enum AuraStateType
{   // (C) used in caster aura state     (T) used in target aura state
    // (c) used in caster aura state-not (t) used in target aura state-not
    AURA_STATE_NONE                         = 0,            // C   |
    AURA_STATE_DEFENSE                      = 1,            // C   |
    AURA_STATE_HEALTHLESS_20_PERCENT        = 2,            // CcT |
    AURA_STATE_BERSERKING                   = 3,            // C T |
    AURA_STATE_FROZEN                       = 4,            //  c t| frozen target
    AURA_STATE_JUDGEMENT                    = 5,            // C   |
    //AURA_STATE_UNKNOWN6                   = 6,            //     | not used
    AURA_STATE_HUNTER_PARRY                 = 7,            // C   |
    //AURA_STATE_UNKNOWN7                   = 7,            //  c  | creature cheap shot / focused bursts spells
    //AURA_STATE_UNKNOWN8                   = 8,            //    t| test spells
    //AURA_STATE_UNKNOWN9                   = 9,            //     |
    AURA_STATE_WARRIOR_VICTORY_RUSH         = 10,           // C   | warrior victory rush
    //AURA_STATE_UNKNOWN11                  = 11,           // C  t| 60348 - Maelstrom Ready!, test spells
    AURA_STATE_FAERIE_FIRE                  = 12,           //  c t|
    AURA_STATE_HEALTHLESS_35_PERCENT        = 13,           // C T |
    AURA_STATE_CONFLAGRATE                  = 14,           //   T |
    AURA_STATE_SWIFTMEND                    = 15,           //   T |
    AURA_STATE_DEADLY_POISON                = 16,           //   T |
    AURA_STATE_ENRAGE                       = 17,           // C   |
    AURA_STATE_BLEEDING                     = 18,           //    T|
    AURA_STATE_UNKNOWN19                    = 19,           //     |
    //AURA_STATE_UNKNOWN20                  = 20,           //  c  | only (45317 Suicide)
    //AURA_STATE_UNKNOWN21                  = 21,           //     | not used
    AURA_STATE_UNKNOWN22                    = 22,           // C  t| varius spells (63884, 50240)
    AURA_STATE_HEALTH_ABOVE_75_PERCENT      = 23            // C   |
};

#define PER_CASTER_AURA_STATE_MASK (\
    (1<<(AURA_STATE_CONFLAGRATE-1))|(1<<(AURA_STATE_DEADLY_POISON-1)))

// Spell mechanics
// EnumUtils: DESCRIBE THIS
enum Mechanics : uint32
{
    MECHANIC_NONE             = 0,
    MECHANIC_CHARM            = 1,
    MECHANIC_DISORIENTED      = 2,
    MECHANIC_DISARM           = 3,
    MECHANIC_DISTRACT         = 4,
    MECHANIC_FEAR             = 5,
    MECHANIC_GRIP             = 6,
    MECHANIC_ROOT             = 7,
    MECHANIC_SLOW_ATTACK      = 8,
    MECHANIC_SILENCE          = 9,
    MECHANIC_SLEEP            = 10,
    MECHANIC_SNARE            = 11,
    MECHANIC_STUN             = 12,
    MECHANIC_FREEZE           = 13,
    MECHANIC_KNOCKOUT         = 14,
    MECHANIC_BLEED            = 15,
    MECHANIC_BANDAGE          = 16,
    MECHANIC_POLYMORPH        = 17,
    MECHANIC_BANISH           = 18,
    MECHANIC_SHIELD           = 19,
    MECHANIC_SHACKLE          = 20,
    MECHANIC_MOUNT            = 21,
    MECHANIC_INFECTED         = 22,
    MECHANIC_TURN             = 23,
    MECHANIC_HORROR           = 24,
    MECHANIC_INVULNERABILITY  = 25,
    MECHANIC_INTERRUPT        = 26,
    MECHANIC_DAZE             = 27,
    MECHANIC_DISCOVERY        = 28,
    MECHANIC_IMMUNE_SHIELD    = 29, // Divine (Blessing) Shield/Protection and Ice Block
    MECHANIC_SAPPED           = 30,
    MECHANIC_ENRAGED          = 31,
    MAX_MECHANIC              = 32 // SKIP
};

// Used for spell 42292 Immune Movement Impairment and Loss of Control (0x49967ca6)
#define IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK (\
    (1<<MECHANIC_CHARM)|(1<<MECHANIC_DISORIENTED)|(1<<MECHANIC_FEAR)| \
    (1<<MECHANIC_ROOT)|(1<<MECHANIC_SLEEP)|(1<<MECHANIC_SNARE)| \
    (1<<MECHANIC_STUN)|(1<<MECHANIC_FREEZE)|(1<<MECHANIC_KNOCKOUT)| \
    (1<<MECHANIC_POLYMORPH)|(1<<MECHANIC_BANISH)|(1<<MECHANIC_SHACKLE)| \
    (1<<MECHANIC_TURN)|(1<<MECHANIC_HORROR)|(1<<MECHANIC_DAZE)| \
    (1<<MECHANIC_SAPPED))

// Spell dispel type
enum DispelType
{
    DISPEL_NONE         = 0,
    DISPEL_MAGIC        = 1,
    DISPEL_CURSE        = 2,
    DISPEL_DISEASE      = 3,
    DISPEL_POISON       = 4,
    DISPEL_STEALTH      = 5,
    DISPEL_INVISIBILITY = 6,
    DISPEL_ALL          = 7,
    DISPEL_SPE_NPC_ONLY = 8,
    DISPEL_ENRAGE       = 9,
    DISPEL_ZG_TICKET    = 10,
    DESPEL_OLD_UNUSED   = 11
};

#define DISPEL_ALL_MASK ((1<<DISPEL_MAGIC) | (1<<DISPEL_CURSE) | (1<<DISPEL_DISEASE) | (1<<DISPEL_POISON))

//To all Immune system, if target has immunes,
//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
//some aura(related to Mechanics or ImmuneToState<aura>) can't apply to it.
enum SpellImmunity
{
    IMMUNITY_EFFECT                = 0,                     // enum SpellEffects
    IMMUNITY_STATE                 = 1,                     // enum AuraType
    IMMUNITY_SCHOOL                = 2,                     // enum SpellSchoolMask
    IMMUNITY_DAMAGE                = 3,                     // enum SpellSchoolMask
    IMMUNITY_DISPEL                = 4,                     // enum DispelType
    IMMUNITY_MECHANIC              = 5,                     // enum Mechanics
    IMMUNITY_ID                    = 6,

    MAX_SPELL_IMMUNITY
};

// target enum name consist of:
// TARGET_[OBJECT_TYPE]_[REFERENCE_TYPE(skipped for caster)]_[SELECTION_TYPE(skipped for default)]_[additional specifiers(friendly, BACK_LEFT, etc.]
enum Targets
{
    TARGET_UNIT_CASTER                 = 1,
    TARGET_UNIT_NEARBY_ENEMY           = 2,
    TARGET_UNIT_NEARBY_ALLY            = 3,
    TARGET_UNIT_NEARBY_PARTY           = 4,
    TARGET_UNIT_PET                    = 5,
    TARGET_UNIT_TARGET_ENEMY           = 6,
    TARGET_UNIT_SRC_AREA_ENTRY         = 7,
    TARGET_UNIT_DEST_AREA_ENTRY        = 8,
    TARGET_DEST_HOME                   = 9,
    TARGET_UNIT_SRC_AREA_UNK_11        = 11,
    TARGET_UNIT_SRC_AREA_ENEMY         = 15,
    TARGET_UNIT_DEST_AREA_ENEMY        = 16,
    TARGET_DEST_DB                     = 17,
    TARGET_DEST_CASTER                 = 18,
    TARGET_UNIT_CASTER_AREA_PARTY      = 20,
    TARGET_UNIT_TARGET_ALLY            = 21,
    TARGET_SRC_CASTER                  = 22,
    TARGET_GAMEOBJECT_TARGET           = 23,
    TARGET_UNIT_CONE_ENEMY_24          = 24,
    TARGET_UNIT_TARGET_ANY             = 25,
    TARGET_GAMEOBJECT_ITEM_TARGET      = 26,
    TARGET_UNIT_MASTER                 = 27,
    TARGET_DEST_DYNOBJ_ENEMY           = 28,
    TARGET_DEST_DYNOBJ_ALLY            = 29,
    TARGET_UNIT_SRC_AREA_ALLY          = 30,
    TARGET_UNIT_DEST_AREA_ALLY         = 31,
    TARGET_DEST_CASTER_SUMMON          = 32, // front left, doesn't use radius
    TARGET_UNIT_SRC_AREA_PARTY         = 33,
    TARGET_UNIT_DEST_AREA_PARTY        = 34,
    TARGET_UNIT_TARGET_PARTY           = 35,
    TARGET_DEST_CASTER_UNK_36          = 36,
    TARGET_UNIT_LASTTARGET_AREA_PARTY  = 37,
    TARGET_UNIT_NEARBY_ENTRY           = 38,
    TARGET_DEST_CASTER_FISHING         = 39,
    TARGET_GAMEOBJECT_NEARBY_ENTRY     = 40,
    TARGET_DEST_CASTER_FRONT_RIGHT     = 41,
    TARGET_DEST_CASTER_BACK_RIGHT      = 42,
    TARGET_DEST_CASTER_BACK_LEFT       = 43,
    TARGET_DEST_CASTER_FRONT_LEFT      = 44,
    TARGET_UNIT_TARGET_CHAINHEAL_ALLY  = 45,
    TARGET_DEST_NEARBY_ENTRY           = 46,
    TARGET_DEST_CASTER_FRONT           = 47,
    TARGET_DEST_CASTER_BACK            = 48,
    TARGET_DEST_CASTER_RIGHT           = 49,
    TARGET_DEST_CASTER_LEFT            = 50,
    TARGET_GAMEOBJECT_SRC_AREA         = 51,
    TARGET_GAMEOBJECT_DEST_AREA        = 52,
    TARGET_DEST_TARGET_ENEMY           = 53,
    TARGET_UNIT_CONE_ENEMY_54          = 54,
    TARGET_DEST_CASTER_FRONT_LEAP      = 55, // for a leap spell
    TARGET_UNIT_CASTER_AREA_RAID       = 56,
    TARGET_UNIT_TARGET_RAID            = 57,
    TARGET_UNIT_NEARBY_RAID            = 58,
    TARGET_UNIT_CONE_ALLY              = 59,
    TARGET_UNIT_CONE_ENTRY             = 60,
    TARGET_UNIT_TARGET_AREA_RAID_CLASS = 61,
    TARGET_UNK_62                      = 62,
    TARGET_DEST_TARGET_ANY             = 63,
    TARGET_DEST_TARGET_FRONT           = 64,
    TARGET_DEST_TARGET_BACK            = 65,
    TARGET_DEST_TARGET_RIGHT           = 66,
    TARGET_DEST_TARGET_LEFT            = 67,
    TARGET_DEST_TARGET_FRONT_RIGHT     = 68,
    TARGET_DEST_TARGET_BACK_RIGHT      = 69,
    TARGET_DEST_TARGET_BACK_LEFT       = 70,
    TARGET_DEST_TARGET_FRONT_LEFT      = 71,
    TARGET_DEST_CASTER_RANDOM          = 72,
    TARGET_DEST_CASTER_RADIUS          = 73,
    TARGET_DEST_TARGET_RANDOM          = 74,
    TARGET_DEST_TARGET_RADIUS          = 75,
    TARGET_DEST_CHANNEL_TARGET         = 76,
    TARGET_UNIT_CHANNEL_TARGET         = 77,
    TARGET_DEST_DEST_FRONT             = 78,
    TARGET_DEST_DEST_BACK              = 79,
    TARGET_DEST_DEST_RIGHT             = 80,
    TARGET_DEST_DEST_LEFT              = 81,
    TARGET_DEST_DEST_FRONT_RIGHT       = 82,
    TARGET_DEST_DEST_BACK_RIGHT        = 83,
    TARGET_DEST_DEST_BACK_LEFT         = 84,
    TARGET_DEST_DEST_FRONT_LEFT        = 85,
    TARGET_DEST_DEST_RANDOM            = 86,
    TARGET_DEST_DEST                   = 87,
    TARGET_DEST_DYNOBJ_NONE            = 88,
    TARGET_DEST_TRAJ                   = 89,
    TARGET_UNIT_TARGET_MINIPET         = 90,
    TARGET_DEST_DEST_RADIUS            = 91,
    TARGET_UNIT_SUMMONER               = 92,
    TARGET_CORPSE_SRC_AREA_ENEMY       = 93, // NYI
    TARGET_UNIT_VEHICLE                = 94,
    TARGET_UNIT_TARGET_PASSENGER       = 95,
    TARGET_UNIT_PASSENGER_0            = 96,
    TARGET_UNIT_PASSENGER_1            = 97,
    TARGET_UNIT_PASSENGER_2            = 98,
    TARGET_UNIT_PASSENGER_3            = 99,
    TARGET_UNIT_PASSENGER_4            = 100,
    TARGET_UNIT_PASSENGER_5            = 101,
    TARGET_UNIT_PASSENGER_6            = 102,
    TARGET_UNIT_PASSENGER_7            = 103,
    TARGET_UNIT_CONE_ENEMY_104         = 104,
    TARGET_UNIT_UNK_105                = 105, // 1 spell
    TARGET_DEST_CHANNEL_CASTER         = 106,
    TARGET_UNK_DEST_AREA_UNK_107       = 107, // not enough info - only generic spells avalible
    TARGET_GAMEOBJECT_CONE             = 108,
    TARGET_UNIT_CONE_ENTRY_110         = 110, // 1 spell
    TOTAL_SPELL_TARGETS
};

enum SpellMissInfo
{
    SPELL_MISS_NONE                    = 0,
    SPELL_MISS_MISS                    = 1,
    SPELL_MISS_RESIST                  = 2,
    SPELL_MISS_DODGE                   = 3,
    SPELL_MISS_PARRY                   = 4,
    SPELL_MISS_BLOCK                   = 5,
    SPELL_MISS_EVADE                   = 6,
    SPELL_MISS_IMMUNE                  = 7,
    SPELL_MISS_IMMUNE2                 = 8, // one of these 2 is MISS_TEMPIMMUNE
    SPELL_MISS_DEFLECT                 = 9,
    SPELL_MISS_ABSORB                  = 10,
    SPELL_MISS_REFLECT                 = 11
};

enum SpellHitType
{
    SPELL_HIT_TYPE_CRIT_DEBUG           = 0x01,
    SPELL_HIT_TYPE_CRIT                 = 0x02,
    SPELL_HIT_TYPE_HIT_DEBUG            = 0x04,
    SPELL_HIT_TYPE_SPLIT                = 0x08,
    SPELL_HIT_TYPE_VICTIM_IS_ATTACKER   = 0x10,
    SPELL_HIT_TYPE_ATTACK_TABLE_DEBUG   = 0x20
};

// EnumUtils: DESCRIBE THIS
enum SpellDmgClass
{
    SPELL_DAMAGE_CLASS_NONE     = 0, // TITLE None
    SPELL_DAMAGE_CLASS_MAGIC    = 1, // TITLE Magic
    SPELL_DAMAGE_CLASS_MELEE    = 2, // TITLE Melee
    SPELL_DAMAGE_CLASS_RANGED   = 3  // TITLE Ranged
};

// EnumUtils: DESCRIBE THIS
enum SpellPreventionType
{
    SPELL_PREVENTION_TYPE_NONE      = 0, // TITLE None
    SPELL_PREVENTION_TYPE_SILENCE   = 1, // TITLE Silence
    SPELL_PREVENTION_TYPE_PACIFY    = 2  // TITLE Pacify
};

enum GameobjectTypes
{
    GAMEOBJECT_TYPE_DOOR                        = 0,
    GAMEOBJECT_TYPE_BUTTON                      = 1,
    GAMEOBJECT_TYPE_QUESTGIVER                  = 2,
    GAMEOBJECT_TYPE_CHEST                       = 3,
    GAMEOBJECT_TYPE_BINDER                      = 4,
    GAMEOBJECT_TYPE_GENERIC                     = 5,
    GAMEOBJECT_TYPE_TRAP                        = 6,
    GAMEOBJECT_TYPE_CHAIR                       = 7,
    GAMEOBJECT_TYPE_SPELL_FOCUS                 = 8,
    GAMEOBJECT_TYPE_TEXT                        = 9,
    GAMEOBJECT_TYPE_GOOBER                      = 10,
    GAMEOBJECT_TYPE_TRANSPORT                   = 11,
    GAMEOBJECT_TYPE_AREADAMAGE                  = 12,
    GAMEOBJECT_TYPE_CAMERA                      = 13,
    GAMEOBJECT_TYPE_MAP_OBJECT                  = 14,
    GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT           = 15,
    GAMEOBJECT_TYPE_DUEL_ARBITER                = 16,
    GAMEOBJECT_TYPE_FISHINGNODE                 = 17,
    GAMEOBJECT_TYPE_RITUAL                      = 18,
    GAMEOBJECT_TYPE_MAILBOX                     = 19,
    GAMEOBJECT_TYPE_DO_NOT_USE                  = 20,
    GAMEOBJECT_TYPE_GUARDPOST                   = 21,
    GAMEOBJECT_TYPE_SPELLCASTER                 = 22,
    GAMEOBJECT_TYPE_MEETINGSTONE                = 23,
    GAMEOBJECT_TYPE_FLAGSTAND                   = 24,
    GAMEOBJECT_TYPE_FISHINGHOLE                 = 25,
    GAMEOBJECT_TYPE_FLAGDROP                    = 26,
    GAMEOBJECT_TYPE_MINI_GAME                   = 27,
    GAMEOBJECT_TYPE_DO_NOT_USE_2                = 28,
    GAMEOBJECT_TYPE_CAPTURE_POINT               = 29,
    GAMEOBJECT_TYPE_AURA_GENERATOR              = 30,
    GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY          = 31,
    GAMEOBJECT_TYPE_BARBER_CHAIR                = 32,
    GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING       = 33,
    GAMEOBJECT_TYPE_GUILD_BANK                  = 34,
    GAMEOBJECT_TYPE_TRAPDOOR                    = 35,
};

#define MAX_GAMEOBJECT_TYPE                  36             // sending to client this or greater value can crash client.
#define MAX_GAMEOBJECT_DATA                  24             // Max number of uint32 vars in gameobject_template data field

enum GameObjectFlags
{
    GO_FLAG_IN_USE          = 0x00000001,                   // disables interaction while animated
    GO_FLAG_LOCKED          = 0x00000002,                   // require key, spell, event, etc to be opened. Makes "Locked" appear in tooltip
    GO_FLAG_INTERACT_COND   = 0x00000004,                   // cannot interact (condition to interact - requires GO_DYNFLAG_LO_ACTIVATE to enable interaction clientside)
    GO_FLAG_TRANSPORT       = 0x00000008,                   // any kind of transport? Object can transport (elevator, boat, car)
    GO_FLAG_NOT_SELECTABLE  = 0x00000010,                   // not selectable even in GM mode
    GO_FLAG_NODESPAWN       = 0x00000020,                   // never despawn, typically for doors, they just change state
    GO_FLAG_AI_OBSTACLE     = 0x00000040,                   // makes the client register the object in something called AIObstacleMgr, unknown what it does
    GO_FLAG_FREEZE_ANIMATION = 0x00000080,
    GO_FLAG_DAMAGED         = 0x00000200,
    GO_FLAG_DESTROYED       = 0x00000400
};

DEFINE_ENUM_FLAG(GameObjectFlags);

enum GameObjectDynamicLowFlags
{
    GO_DYNFLAG_LO_ACTIVATE          = 0x01,                 // enables interaction with GO
    GO_DYNFLAG_LO_ANIMATE           = 0x02,                 // possibly more distinct animation of GO
    GO_DYNFLAG_LO_NO_INTERACT       = 0x04,                 // appears to disable interaction (not fully verified)
    GO_DYNFLAG_LO_SPARKLE           = 0x08,                 // makes GO sparkle
    GO_DYNFLAG_LO_STOPPED           = 0x10                  // Transport is stopped
};

// client side GO show states
enum GOState : uint8
{
    GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
    GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
    GO_STATE_DESTROYED          = 2                         // show the object in-game as already used and not yet reset (e.g. door opened by a cannon blast)
};

#define MAX_GO_STATE              3

enum GameObjectDestructibleState
{
    GO_DESTRUCTIBLE_INTACT      = 0,
    GO_DESTRUCTIBLE_DAMAGED     = 1,
    GO_DESTRUCTIBLE_DESTROYED   = 2,
    GO_DESTRUCTIBLE_REBUILDING  = 3
};

// EmotesText.dbc
enum TextEmotes
{
    TEXT_EMOTE_AGREE                = 1,
    TEXT_EMOTE_AMAZE                = 2,
    TEXT_EMOTE_ANGRY                = 3,
    TEXT_EMOTE_APOLOGIZE            = 4,
    TEXT_EMOTE_APPLAUD              = 5,
    TEXT_EMOTE_BASHFUL              = 6,
    TEXT_EMOTE_BECKON               = 7,
    TEXT_EMOTE_BEG                  = 8,
    TEXT_EMOTE_BITE                 = 9,
    TEXT_EMOTE_BLEED                = 10,
    TEXT_EMOTE_BLINK                = 11,
    TEXT_EMOTE_BLUSH                = 12,
    TEXT_EMOTE_BONK                 = 13,
    TEXT_EMOTE_BORED                = 14,
    TEXT_EMOTE_BOUNCE               = 15,
    TEXT_EMOTE_BRB                  = 16,
    TEXT_EMOTE_BOW                  = 17,
    TEXT_EMOTE_BURP                 = 18,
    TEXT_EMOTE_BYE                  = 19,
    TEXT_EMOTE_CACKLE               = 20,
    TEXT_EMOTE_CHEER                = 21,
    TEXT_EMOTE_CHICKEN              = 22,
    TEXT_EMOTE_CHUCKLE              = 23,
    TEXT_EMOTE_CLAP                 = 24,
    TEXT_EMOTE_CONFUSED             = 25,
    TEXT_EMOTE_CONGRATULATE         = 26,
    TEXT_EMOTE_COUGH                = 27,
    TEXT_EMOTE_COWER                = 28,
    TEXT_EMOTE_CRACK                = 29,
    TEXT_EMOTE_CRINGE               = 30,
    TEXT_EMOTE_CRY                  = 31,
    TEXT_EMOTE_CURIOUS              = 32,
    TEXT_EMOTE_CURTSEY              = 33,
    TEXT_EMOTE_DANCE                = 34,
    TEXT_EMOTE_DRINK                = 35,
    TEXT_EMOTE_DROOL                = 36,
    TEXT_EMOTE_EAT                  = 37,
    TEXT_EMOTE_EYE                  = 38,
    TEXT_EMOTE_FART                 = 39,
    TEXT_EMOTE_FIDGET               = 40,
    TEXT_EMOTE_FLEX                 = 41,
    TEXT_EMOTE_FROWN                = 42,
    TEXT_EMOTE_GASP                 = 43,
    TEXT_EMOTE_GAZE                 = 44,
    TEXT_EMOTE_GIGGLE               = 45,
    TEXT_EMOTE_GLARE                = 46,
    TEXT_EMOTE_GLOAT                = 47,
    TEXT_EMOTE_GREET                = 48,
    TEXT_EMOTE_GRIN                 = 49,
    TEXT_EMOTE_GROAN                = 50,
    TEXT_EMOTE_GROVEL               = 51,
    TEXT_EMOTE_GUFFAW               = 52,
    TEXT_EMOTE_HAIL                 = 53,
    TEXT_EMOTE_HAPPY                = 54,
    TEXT_EMOTE_HELLO                = 55,
    TEXT_EMOTE_HUG                  = 56,
    TEXT_EMOTE_HUNGRY               = 57,
    TEXT_EMOTE_KISS                 = 58,
    TEXT_EMOTE_KNEEL                = 59,
    TEXT_EMOTE_LAUGH                = 60,
    TEXT_EMOTE_LAYDOWN              = 61,
    TEXT_EMOTE_MESSAGE              = 62,
    TEXT_EMOTE_MOAN                 = 63,
    TEXT_EMOTE_MOON                 = 64,
    TEXT_EMOTE_MOURN                = 65,
    TEXT_EMOTE_NO                   = 66,
    TEXT_EMOTE_NOD                  = 67,
    TEXT_EMOTE_NOSEPICK             = 68,
    TEXT_EMOTE_PANIC                = 69,
    TEXT_EMOTE_PEER                 = 70,
    TEXT_EMOTE_PLEAD                = 71,
    TEXT_EMOTE_POINT                = 72,
    TEXT_EMOTE_POKE                 = 73,
    TEXT_EMOTE_PRAY                 = 74,
    TEXT_EMOTE_ROAR                 = 75,
    TEXT_EMOTE_ROFL                 = 76,
    TEXT_EMOTE_RUDE                 = 77,
    TEXT_EMOTE_SALUTE               = 78,
    TEXT_EMOTE_SCRATCH              = 79,
    TEXT_EMOTE_SEXY                 = 80,
    TEXT_EMOTE_SHAKE                = 81,
    TEXT_EMOTE_SHOUT                = 82,
    TEXT_EMOTE_SHRUG                = 83,
    TEXT_EMOTE_SHY                  = 84,
    TEXT_EMOTE_SIGH                 = 85,
    TEXT_EMOTE_SIT                  = 86,
    TEXT_EMOTE_SLEEP                = 87,
    TEXT_EMOTE_SNARL                = 88,
    TEXT_EMOTE_SPIT                 = 89,
    TEXT_EMOTE_STARE                = 90,
    TEXT_EMOTE_SURPRISED            = 91,
    TEXT_EMOTE_SURRENDER            = 92,
    TEXT_EMOTE_TALK                 = 93,
    TEXT_EMOTE_TALKEX               = 94,
    TEXT_EMOTE_TALKQ                = 95,
    TEXT_EMOTE_TAP                  = 96,
    TEXT_EMOTE_THANK                = 97,
    TEXT_EMOTE_THREATEN             = 98,
    TEXT_EMOTE_TIRED                = 99,
    TEXT_EMOTE_VICTORY              = 100,
    TEXT_EMOTE_WAVE                 = 101,
    TEXT_EMOTE_WELCOME              = 102,
    TEXT_EMOTE_WHINE                = 103,
    TEXT_EMOTE_WHISTLE              = 104,
    TEXT_EMOTE_WORK                 = 105,
    TEXT_EMOTE_YAWN                 = 106,
    TEXT_EMOTE_BOGGLE               = 107,
    TEXT_EMOTE_CALM                 = 108,
    TEXT_EMOTE_COLD                 = 109,
    TEXT_EMOTE_COMFORT              = 110,
    TEXT_EMOTE_CUDDLE               = 111,
    TEXT_EMOTE_DUCK                 = 112,
    TEXT_EMOTE_INSULT               = 113,
    TEXT_EMOTE_INTRODUCE            = 114,
    TEXT_EMOTE_JK                   = 115,
    TEXT_EMOTE_LICK                 = 116,
    TEXT_EMOTE_LISTEN               = 117,
    TEXT_EMOTE_LOST                 = 118,
    TEXT_EMOTE_MOCK                 = 119,
    TEXT_EMOTE_PONDER               = 120,
    TEXT_EMOTE_POUNCE               = 121,
    TEXT_EMOTE_PRAISE               = 122,
    TEXT_EMOTE_PURR                 = 123,
    TEXT_EMOTE_PUZZLE               = 124,
    TEXT_EMOTE_RAISE                = 125,
    TEXT_EMOTE_READY                = 126,
    TEXT_EMOTE_SHIMMY               = 127,
    TEXT_EMOTE_SHIVER               = 128,
    TEXT_EMOTE_SHOO                 = 129,
    TEXT_EMOTE_SLAP                 = 130,
    TEXT_EMOTE_SMIRK                = 131,
    TEXT_EMOTE_SNIFF                = 132,
    TEXT_EMOTE_SNUB                 = 133,
    TEXT_EMOTE_SOOTHE               = 134,
    TEXT_EMOTE_STINK                = 135,
    TEXT_EMOTE_TAUNT                = 136,
    TEXT_EMOTE_TEASE                = 137,
    TEXT_EMOTE_THIRSTY              = 138,
    TEXT_EMOTE_VETO                 = 139,
    TEXT_EMOTE_SNICKER              = 140,
    TEXT_EMOTE_STAND                = 141,
    TEXT_EMOTE_TICKLE               = 142,
    TEXT_EMOTE_VIOLIN               = 143,
    TEXT_EMOTE_SMILE                = 163,
    TEXT_EMOTE_RASP                 = 183,
    TEXT_EMOTE_PITY                 = 203,
    TEXT_EMOTE_GROWL                = 204,
    TEXT_EMOTE_BARK                 = 205,
    TEXT_EMOTE_SCARED               = 223,
    TEXT_EMOTE_FLOP                 = 224,
    TEXT_EMOTE_LOVE                 = 225,
    TEXT_EMOTE_MOO                  = 226,
    TEXT_EMOTE_COMMEND              = 243,
    TEXT_EMOTE_TRAIN                = 264,
    TEXT_EMOTE_HELPME               = 303,
    TEXT_EMOTE_INCOMING             = 304,
    TEXT_EMOTE_CHARGE               = 305,
    TEXT_EMOTE_FLEE                 = 306,
    TEXT_EMOTE_ATTACKMYTARGET       = 307,
    TEXT_EMOTE_OOM                  = 323,
    TEXT_EMOTE_FOLLOW               = 324,
    TEXT_EMOTE_WAIT                 = 325,
    TEXT_EMOTE_HEALME               = 326,
    TEXT_EMOTE_OPENFIRE             = 327,
    TEXT_EMOTE_FLIRT                = 328,
    TEXT_EMOTE_JOKE                 = 329,
    TEXT_EMOTE_GOLFCLAP             = 343,
    TEXT_EMOTE_WINK                 = 363,
    TEXT_EMOTE_PAT                  = 364,
    TEXT_EMOTE_SERIOUS              = 365,
    TEXT_EMOTE_MOUNT_SPECIAL        = 366,
    TEXT_EMOTE_GOODLUCK             = 367,
    TEXT_EMOTE_BLAME                = 368,
    TEXT_EMOTE_BLANK                = 369,
    TEXT_EMOTE_BRANDISH             = 370,
    TEXT_EMOTE_BREATH               = 371,
    TEXT_EMOTE_DISAGREE             = 372,
    TEXT_EMOTE_DOUBT                = 373,
    TEXT_EMOTE_EMBARRASS            = 374,
    TEXT_EMOTE_ENCOURAGE            = 375,
    TEXT_EMOTE_ENEMY                = 376,
    TEXT_EMOTE_EYEBROW              = 377,
    TEXT_EMOTE_TOAST                = 378,
    TEXT_EMOTE_FAIL                 = 379,
    TEXT_EMOTE_HIGHFIVE             = 380,
    TEXT_EMOTE_ABSENT               = 381,
    TEXT_EMOTE_ARM                  = 382,
    TEXT_EMOTE_AWE                  = 383,
    TEXT_EMOTE_BACKPACK             = 384,
    TEXT_EMOTE_BADFEELING           = 385,
    TEXT_EMOTE_CHALLENGE            = 386,
    TEXT_EMOTE_CHUG                 = 387,
    TEXT_EMOTE_DING                 = 389,
    TEXT_EMOTE_FACEPALM             = 390,
    TEXT_EMOTE_FAINT                = 391,
    TEXT_EMOTE_GO                   = 392,
    TEXT_EMOTE_GOING                = 393,
    TEXT_EMOTE_GLOWER               = 394,
    TEXT_EMOTE_HEADACHE             = 395,
    TEXT_EMOTE_HICCUP               = 396,
    TEXT_EMOTE_HISS                 = 398,
    TEXT_EMOTE_HOLDHAND             = 399,
    TEXT_EMOTE_HURRY                = 401,
    TEXT_EMOTE_IDEA                 = 402,
    TEXT_EMOTE_JEALOUS              = 403,
    TEXT_EMOTE_LUCK                 = 404,
    TEXT_EMOTE_MAP                  = 405,
    TEXT_EMOTE_MERCY                = 406,
    TEXT_EMOTE_MUTTER               = 407,
    TEXT_EMOTE_NERVOUS              = 408,
    TEXT_EMOTE_OFFER                = 409,
    TEXT_EMOTE_PET                  = 410,
    TEXT_EMOTE_PINCH                = 411,
    TEXT_EMOTE_PROUD                = 413,
    TEXT_EMOTE_PROMISE              = 414,
    TEXT_EMOTE_PULSE                = 415,
    TEXT_EMOTE_PUNCH                = 416,
    TEXT_EMOTE_POUT                 = 417,
    TEXT_EMOTE_REGRET               = 418,
    TEXT_EMOTE_REVENGE              = 420,
    TEXT_EMOTE_ROLLEYES             = 421,
    TEXT_EMOTE_RUFFLE               = 422,
    TEXT_EMOTE_SAD                  = 423,
    TEXT_EMOTE_SCOFF                = 424,
    TEXT_EMOTE_SCOLD                = 425,
    TEXT_EMOTE_SCOWL                = 426,
    TEXT_EMOTE_SEARCH               = 427,
    TEXT_EMOTE_SHAKEFIST            = 428,
    TEXT_EMOTE_SHIFTY               = 429,
    TEXT_EMOTE_SHUDDER              = 430,
    TEXT_EMOTE_SIGNAL               = 431,
    TEXT_EMOTE_SILENCE              = 432,
    TEXT_EMOTE_SING                 = 433,
    TEXT_EMOTE_SMACK                = 434,
    TEXT_EMOTE_SNEAK                = 435,
    TEXT_EMOTE_SNEEZE               = 436,
    TEXT_EMOTE_SNORT                = 437,
    TEXT_EMOTE_SQUEAL               = 438,
    TEXT_EMOTE_STOPATTACK           = 439,
    TEXT_EMOTE_SUSPICIOUS           = 440,
    TEXT_EMOTE_THINK                = 441,
    TEXT_EMOTE_TRUCE                = 442,
    TEXT_EMOTE_TWIDDLE              = 443,
    TEXT_EMOTE_WARN                 = 444,
    TEXT_EMOTE_SNAP                 = 445,
    TEXT_EMOTE_CHARM                = 446,
    TEXT_EMOTE_COVEREARS            = 447,
    TEXT_EMOTE_CROSSARMS            = 448,
    TEXT_EMOTE_LOOK                 = 449,
    TEXT_EMOTE_OBJECT               = 450,
    TEXT_EMOTE_SWEAT                = 451,
    TEXT_EMOTE_YW                   = 453
};

// Emotes.dbc
// EnumUtils: DESCRIBE THIS
enum Emote : uint32
{
    EMOTE_ONESHOT_NONE                           = 0, // SKIP
    EMOTE_ONESHOT_TALK                           = 1,
    EMOTE_ONESHOT_BOW                            = 2,
    EMOTE_ONESHOT_WAVE                           = 3,
    EMOTE_ONESHOT_CHEER                          = 4,
    EMOTE_ONESHOT_EXCLAMATION                    = 5,
    EMOTE_ONESHOT_QUESTION                       = 6,
    EMOTE_ONESHOT_EAT                            = 7,
    EMOTE_STATE_DANCE                            = 10,
    EMOTE_ONESHOT_LAUGH                          = 11,
    EMOTE_STATE_SLEEP                            = 12,
    EMOTE_STATE_SIT                              = 13,
    EMOTE_ONESHOT_RUDE                           = 14,
    EMOTE_ONESHOT_ROAR                           = 15,
    EMOTE_ONESHOT_KNEEL                          = 16,
    EMOTE_ONESHOT_KISS                           = 17,
    EMOTE_ONESHOT_CRY                            = 18,
    EMOTE_ONESHOT_CHICKEN                        = 19,
    EMOTE_ONESHOT_BEG                            = 20,
    EMOTE_ONESHOT_APPLAUD                        = 21,
    EMOTE_ONESHOT_SHOUT                          = 22,
    EMOTE_ONESHOT_FLEX                           = 23,
    EMOTE_ONESHOT_SHY                            = 24,
    EMOTE_ONESHOT_POINT                          = 25,
    EMOTE_STATE_STAND                            = 26,
    EMOTE_STATE_READY_UNARMED                    = 27,
    EMOTE_STATE_WORK_SHEATHED                    = 28,
    EMOTE_STATE_POINT                            = 29,
    EMOTE_STATE_NONE                             = 30,
    EMOTE_ONESHOT_WOUND                          = 33,
    EMOTE_ONESHOT_WOUND_CRITICAL                 = 34,
    EMOTE_ONESHOT_ATTACK_UNARMED                 = 35,
    EMOTE_ONESHOT_ATTACK1H                       = 36,
    EMOTE_ONESHOT_ATTACK2HTIGHT                  = 37,
    EMOTE_ONESHOT_ATTACK2H_LOOSE                 = 38,
    EMOTE_ONESHOT_PARRY_UNARMED                  = 39,
    EMOTE_ONESHOT_PARRY_SHIELD                   = 43,
    EMOTE_ONESHOT_READY_UNARMED                  = 44,
    EMOTE_ONESHOT_READY1H                        = 45,
    EMOTE_ONESHOT_READY_BOW                      = 48,
    EMOTE_ONESHOT_SPELL_PRECAST                  = 50,
    EMOTE_ONESHOT_SPELL_CAST                     = 51,
    EMOTE_ONESHOT_BATTLE_ROAR                    = 53,
    EMOTE_ONESHOT_SPECIALATTACK1H                = 54,
    EMOTE_ONESHOT_KICK                           = 60,
    EMOTE_ONESHOT_ATTACK_THROWN                  = 61,
    EMOTE_STATE_STUN                             = 64,
    EMOTE_STATE_DEAD                             = 65,
    EMOTE_ONESHOT_SALUTE                         = 66,
    EMOTE_STATE_KNEEL                            = 68,
    EMOTE_STATE_USE_STANDING                     = 69,
    EMOTE_ONESHOT_WAVE_NO_SHEATHE                = 70,
    EMOTE_ONESHOT_CHEER_NO_SHEATHE               = 71,
    EMOTE_ONESHOT_EAT_NO_SHEATHE                 = 92,
    EMOTE_STATE_STUN_NO_SHEATHE                  = 93,
    EMOTE_ONESHOT_DANCE                          = 94,
    EMOTE_ONESHOT_SALUTE_NO_SHEATH               = 113,
    EMOTE_STATE_USE_STANDING_NO_SHEATHE          = 133,
    EMOTE_ONESHOT_LAUGH_NO_SHEATHE               = 153,
    EMOTE_STATE_WORK                             = 173,
    EMOTE_STATE_SPELL_PRECAST                    = 193,
    EMOTE_ONESHOT_READY_RIFLE                    = 213,
    EMOTE_STATE_READY_RIFLE                      = 214,
    EMOTE_STATE_WORK_MINING                      = 233,
    EMOTE_STATE_WORK_CHOPWOOD                    = 234,
    EMOTE_STATE_APPLAUD                          = 253,
    EMOTE_ONESHOT_LIFTOFF                        = 254,
    EMOTE_ONESHOT_YES                            = 273,
    EMOTE_ONESHOT_NO                             = 274,
    EMOTE_ONESHOT_TRAIN                          = 275,
    EMOTE_ONESHOT_LAND                           = 293,
    EMOTE_STATE_AT_EASE                          = 313,
    EMOTE_STATE_READY1H                          = 333,
    EMOTE_STATE_SPELL_KNEEL_START                = 353,
    EMOTE_STATE_SUBMERGED                        = 373,
    EMOTE_ONESHOT_SUBMERGE                       = 374,
    EMOTE_STATE_READY2H                          = 375,
    EMOTE_STATE_READY_BOW                        = 376,
    EMOTE_ONESHOT_MOUNT_SPECIAL                  = 377,
    EMOTE_STATE_TALK                             = 378,
    EMOTE_STATE_FISHING                          = 379,
    EMOTE_ONESHOT_FISHING                        = 380,
    EMOTE_ONESHOT_LOOT                           = 381,
    EMOTE_STATE_WHIRLWIND                        = 382,
    EMOTE_STATE_DROWNED                          = 383,
    EMOTE_STATE_HOLD_BOW                         = 384,
    EMOTE_STATE_HOLD_RIFLE                       = 385,
    EMOTE_STATE_HOLD_THROWN                      = 386,
    EMOTE_ONESHOT_DROWN                          = 387,
    EMOTE_ONESHOT_STOMP                          = 388,
    EMOTE_ONESHOT_ATTACK_OFF                     = 389,
    EMOTE_ONESHOT_ATTACK_OFF_PIERCE              = 390,
    EMOTE_STATE_ROAR                             = 391,
    EMOTE_STATE_LAUGH                            = 392,
    EMOTE_ONESHOT_CREATURE_SPECIAL               = 393,
    EMOTE_ONESHOT_JUMPLANDRUN                    = 394,
    EMOTE_ONESHOT_JUMPEND                        = 395,
    EMOTE_ONESHOT_TALK_NO_SHEATHE                = 396,
    EMOTE_ONESHOT_POINT_NO_SHEATHE               = 397,
    EMOTE_STATE_CANNIBALIZE                      = 398,
    EMOTE_ONESHOT_JUMPSTART                      = 399,
    EMOTE_STATE_DANCESPECIAL                     = 400,
    EMOTE_ONESHOT_DANCESPECIAL                   = 401,
    EMOTE_ONESHOT_CUSTOM_SPELL_01                = 402,
    EMOTE_ONESHOT_CUSTOM_SPELL_02                = 403,
    EMOTE_ONESHOT_CUSTOM_SPELL_03                = 404,
    EMOTE_ONESHOT_CUSTOM_SPELL_04                = 405,
    EMOTE_ONESHOT_CUSTOM_SPELL_05                = 406,
    EMOTE_ONESHOT_CUSTOM_SPELL_06                = 407,
    EMOTE_ONESHOT_CUSTOM_SPELL_07                = 408,
    EMOTE_ONESHOT_CUSTOM_SPELL_08                = 409,
    EMOTE_ONESHOT_CUSTOM_SPELL_09                = 410,
    EMOTE_ONESHOT_CUSTOM_SPELL_10                = 411,
    EMOTE_STATE_EXCLAIM                          = 412,
    EMOTE_STATE_DANCE_CUSTOM                     = 413,
    EMOTE_STATE_SIT_CHAIR_MED                    = 415,
    EMOTE_STATE_CUSTOM_SPELL_01                  = 416,
    EMOTE_STATE_CUSTOM_SPELL_02                  = 417,
    EMOTE_STATE_EAT                              = 418,
    EMOTE_STATE_CUSTOM_SPELL_04                  = 419,
    EMOTE_STATE_CUSTOM_SPELL_03                  = 420,
    EMOTE_STATE_CUSTOM_SPELL_05                  = 421,
    EMOTE_STATE_SPELLEFFECT_HOLD                 = 422,
    EMOTE_STATE_EAT_NO_SHEATHE                   = 423,
    EMOTE_STATE_MOUNT                            = 424,
    EMOTE_STATE_READY2HL                         = 425,
    EMOTE_STATE_SIT_CHAIR_HIGH                   = 426,
    EMOTE_STATE_FALL                             = 427,
    EMOTE_STATE_LOOT                             = 428,
    EMOTE_STATE_SUBMERGED_NEW                    = 429,
    EMOTE_ONESHOT_COWER                          = 430,
    EMOTE_STATE_COWER                            = 431,
    EMOTE_ONESHOT_USE_STANDING                   = 432,
    EMOTE_STATE_STEALTH_STAND                    = 433,
    EMOTE_ONESHOT_OMNICAST_GHOUL                 = 434,
    EMOTE_ONESHOT_ATTACK_BOW                     = 435,
    EMOTE_ONESHOT_ATTACK_RIFLE                   = 436,
    EMOTE_STATE_SWIM_IDLE                        = 437,
    EMOTE_STATE_ATTACK_UNARMED                   = 438,
    EMOTE_ONESHOT_SPELL_CAST_W_SOUND             = 439,
    EMOTE_ONESHOT_DODGE                          = 440,
    EMOTE_ONESHOT_PARRY1H                        = 441,
    EMOTE_ONESHOT_PARRY2H                        = 442,
    EMOTE_ONESHOT_PARRY2HL                       = 443,
    EMOTE_STATE_FLYFALL                          = 444,
    EMOTE_ONESHOT_FLYDEATH                       = 445,
    EMOTE_STATE_FLY_FALL                         = 446,
    EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN            = 447,
    EMOTE_ONESHOT_FLY_SIT_GROUND_UP              = 448,
    EMOTE_ONESHOT_EMERGE                         = 449,
    EMOTE_ONESHOT_DRAGON_SPIT                    = 450,
    EMOTE_STATE_SPECIAL_UNARMED                  = 451,
    EMOTE_ONESHOT_FLYGRAB                        = 452,
    EMOTE_STATE_FLYGRABCLOSED                    = 453,
    EMOTE_ONESHOT_FLYGRABTHROWN                  = 454,
    EMOTE_STATE_FLY_SIT_GROUND                   = 455,
    EMOTE_STATE_WALK_BACKWARDS                   = 456,
    EMOTE_ONESHOT_FLYTALK                        = 457,
    EMOTE_ONESHOT_FLYATTACK1H                    = 458,
    EMOTE_STATE_CUSTOM_SPELL_08                  = 459,
    EMOTE_ONESHOT_FLY_DRAGON_SPIT                = 460,
    EMOTE_STATE_SIT_CHAIR_LOW                    = 461,
    EMOTE_ONESHOT_STUN                           = 462,
    EMOTE_ONESHOT_SPELL_CAST_OMNI                = 463,
    EMOTE_STATE_READY_THROWN                     = 465,
    EMOTE_ONESHOT_WORK_CHOPWOOD                  = 466,
    EMOTE_ONESHOT_WORK_MINING                    = 467,
    EMOTE_STATE_SPELL_CHANNEL_OMNI               = 468,
    EMOTE_STATE_SPELL_CHANNEL_DIRECTED           = 469,
    EMOTE_STAND_STATE_NONE                       = 470,
    EMOTE_STATE_READYJOUST                       = 471,
    EMOTE_STATE_STRANGULATE                      = 473,
    EMOTE_STATE_READY_SPELL_OMNI                 = 474,
    EMOTE_STATE_HOLD_JOUST                       = 475,
    EMOTE_ONESHOT_CRY_JAINA                      = 476
};

// AnimationData.dbc
enum Anim
{
    ANIM_STAND                               = 0,
    ANIM_DEATH                               = 1,
    ANIM_SPELL                               = 2,
    ANIM_STOP                                = 3,
    ANIM_WALK                                = 4,
    ANIM_RUN                                 = 5,
    ANIM_DEAD                                = 6,
    ANIM_RISE                                = 7,
    ANIM_STAND_WOUND                         = 8,
    ANIM_COMBAT_WOUND                        = 9,
    ANIM_COMBAT_CRITICAL                     = 10,
    ANIM_SHUFFLE_LEFT                        = 11,
    ANIM_SHUFFLE_RIGHT                       = 12,
    ANIM_WALK_BACKWARDS                      = 13,
    ANIM_STUN                                = 14,
    ANIM_HANDS_CLOSED                        = 15,
    ANIM_ATTACK_UNARMED                      = 16,
    ANIM_ATTACK1H                            = 17,
    ANIM_ATTACK2H                            = 18,
    ANIM_ATTACK2HL                           = 19,
    ANIM_PARRY_UNARMED                       = 20,
    ANIM_PARRY1H                             = 21,
    ANIM_PARRY2H                             = 22,
    ANIM_PARRY2HL                            = 23,
    ANIM_SHIELD_BLOCK                        = 24,
    ANIM_READY_UNARMED                       = 25,
    ANIM_READY1H                             = 26,
    ANIM_READY2H                             = 27,
    ANIM_READY2HL                            = 28,
    ANIM_READY_BOW                           = 29,
    ANIM_DODGE                               = 30,
    ANIM_SPELL_PRECAST                       = 31,
    ANIM_SPELL_CAST                          = 32,
    ANIM_SPELL_CAST_AREA                     = 33,
    ANIM_NPC_WELCOME                         = 34,
    ANIM_NPC_GOODBYE                         = 35,
    ANIM_BLOCK                               = 36,
    ANIM_JUMP_START                          = 37,
    ANIM_JUMP                                = 38,
    ANIM_JUMP_END                            = 39,
    ANIM_FALL                                = 40,
    ANIM_SWIM_IDLE                           = 41,
    ANIM_SWIM                                = 42,
    ANIM_SWIM_LEFT                           = 43,
    ANIM_SWIM_RIGHT                          = 44,
    ANIM_SWIM_BACKWARDS                      = 45,
    ANIM_ATTACK_BOW                          = 46,
    ANIM_FIRE_BOW                            = 47,
    ANIM_READY_RIFLE                         = 48,
    ANIM_ATTACK_RIFLE                        = 49,
    ANIM_LOOT                                = 50,
    ANIM_READY_SPELL_DIRECTED                = 51,
    ANIM_READY_SPELL_OMNI                    = 52,
    ANIM_SPELL_CAST_DIRECTED                 = 53,
    ANIM_SPELL_CAST_OMNI                     = 54,
    ANIM_BATTLE_ROAR                         = 55,
    ANIM_READY_ABILITY                       = 56,
    ANIM_SPECIAL1H                           = 57,
    ANIM_SPECIAL2H                           = 58,
    ANIM_SHIELD_BASH                         = 59,
    ANIM_EMOTE_TALK                          = 60,
    ANIM_EMOTE_EAT                           = 61,
    ANIM_EMOTE_WORK                          = 62,
    ANIM_EMOTE_USE_STANDING                  = 63,
    ANIM_EMOTE_TALK_EXCLAMATION              = 64,
    ANIM_EMOTE_TALK_QUESTION                 = 65,
    ANIM_EMOTE_BOW                           = 66,
    ANIM_EMOTE_WAVE                          = 67,
    ANIM_EMOTE_CHEER                         = 68,
    ANIM_EMOTE_DANCE                         = 69,
    ANIM_EMOTE_LAUGH                         = 70,
    ANIM_EMOTE_SLEEP                         = 71,
    ANIM_EMOTE_SIT_GROUND                    = 72,
    ANIM_EMOTE_RUDE                          = 73,
    ANIM_EMOTE_ROAR                          = 74,
    ANIM_EMOTE_KNEEL                         = 75,
    ANIM_EMOTE_KISS                          = 76,
    ANIM_EMOTE_CRY                           = 77,
    ANIM_EMOTE_CHICKEN                       = 78,
    ANIM_EMOTE_BEG                           = 79,
    ANIM_EMOTE_APPLAUD                       = 80,
    ANIM_EMOTE_SHOUT                         = 81,
    ANIM_EMOTE_FLEX                          = 82,
    ANIM_EMOTE_SHY                           = 83,
    ANIM_EMOTE_POINT                         = 84,
    ANIM_ATTACK1H_PIERCE                     = 85,
    ANIM_ATTACK2H_LOOSE_PIERCE               = 86,
    ANIM_ATTACK_OFF                          = 87,
    ANIM_ATTACK_OFF_PIERCE                   = 88,
    ANIM_SHEATHE                             = 89,
    ANIM_HIP_SHEATHE                         = 90,
    ANIM_MOUNT                               = 91,
    ANIM_RUN_RIGHT                           = 92,
    ANIM_RUN_LEFT                            = 93,
    ANIM_MOUNT_SPECIAL                       = 94,
    ANIM_KICK                                = 95,
    ANIM_SIT_GROUND_DOWN                     = 96,
    ANIM_SIT_GROUND                          = 97,
    ANIM_SIT_GROUND_UP                       = 98,
    ANIM_SLEEP_DOWN                          = 99,
    ANIM_SLEEP                               = 100,
    ANIM_SLEEP_UP                            = 101,
    ANIM_SIT_CHAIR_LOW                       = 102,
    ANIM_SIT_CHAIR_MED                       = 103,
    ANIM_SIT_CHAIR_HIGH                      = 104,
    ANIM_LOAD_BOW                            = 105,
    ANIM_LOAD_RIFLE                          = 106,
    ANIM_ATTACK_THROWN                       = 107,
    ANIM_READY_THROWN                        = 108,
    ANIM_HOLD_BOW                            = 109,
    ANIM_HOLD_RIFLE                          = 110,
    ANIM_HOLD_THROWN                         = 111,
    ANIM_LOAD_THROWN                         = 112,
    ANIM_EMOTE_SALUTE                        = 113,
    ANIM_KNEEL_START                         = 114,
    ANIM_KNEEL_LOOP                          = 115,
    ANIM_KNEEL_END                           = 116,
    ANIM_ATTACK_UNARMED_OFF                  = 117,
    ANIM_SPECIAL_UNARMED                     = 118,
    ANIM_STEALTH_WALK                        = 119,
    ANIM_STEALTH_STAND                       = 120,
    ANIM_KNOCKDOWN                           = 121,
    ANIM_EATING_LOOP                         = 122,
    ANIM_USE_STANDING_LOOP                   = 123,
    ANIM_CHANNEL_CAST_DIRECTED               = 124,
    ANIM_CHANNEL_CAST_OMNI                   = 125,
    ANIM_WHIRLWIND                           = 126,
    ANIM_BIRTH                               = 127,
    ANIM_USE_STANDING_START                  = 128,
    ANIM_USE_STANDING_END                    = 129,
    ANIM_CREATURE_SPECIAL                    = 130,
    ANIM_DROWN                               = 131,
    ANIM_DROWNED                             = 132,
    ANIM_FISHING_CAST                        = 133,
    ANIM_FISHING_LOOP                        = 134,
    ANIM_FLY                                 = 135,
    ANIM_EMOTE_WORK_NO_SHEATHE               = 136,
    ANIM_EMOTE_STUN_NO_SHEATHE               = 137,
    ANIM_EMOTE_USE_STANDING_NO_SHEATHE       = 138,
    ANIM_SPELL_SLEEP_DOWN                    = 139,
    ANIM_SPELL_KNEEL_START                   = 140,
    ANIM_SPELL_KNEEL_LOOP                    = 141,
    ANIM_SPELL_KNEEL_END                     = 142,
    ANIM_SPRINT                              = 143,
    ANIM_IN_FIGHT                            = 144,
    ANIM_SPAWN                               = 145,
    ANIM_CLOSE                               = 146,
    ANIM_CLOSED                              = 147,
    ANIM_OPEN                                = 148,
    ANIM_OPENED                              = 149,
    ANIM_DESTROY                             = 150,
    ANIM_DESTROYED                           = 151,
    ANIM_REBUILD                             = 152,
    ANIM_CUSTOM_0                            = 153,
    ANIM_CUSTOM_1                            = 154,
    ANIM_CUSTOM_2                            = 155,
    ANIM_CUSTOM_3                            = 156,
    ANIM_DESPAWN                             = 157,
    ANIM_HOLD                                = 158,
    ANIM_DECAY                               = 159,
    ANIM_BOW_PULL                            = 160,
    ANIM_BOW_RELEASE                         = 161,
    ANIM_SHIP_START                          = 162,
    ANIM_SHIP_MOVING                         = 163,
    ANIM_SHIP_STOP                           = 164,
    ANIM_GROUP_ARROW                         = 165,
    ANIM_ARROW                               = 166,
    ANIM_CORPSE_ARROW                        = 167,
    ANIM_GUIDE_ARROW                         = 168,
    ANIM_SWAY                                = 169,
    ANIM_DRUID_CAT_POUNCE                    = 170,
    ANIM_DRUID_CAT_RIP                       = 171,
    ANIM_DRUID_CAT_RAKE                      = 172,
    ANIM_DRUID_CAT_RAVAGE                    = 173,
    ANIM_DRUID_CAT_CLAW                      = 174,
    ANIM_DRUID_CAT_COWER                     = 175,
    ANIM_DRUID_BEAR_SWIPE                    = 176,
    ANIM_DRUID_BEAR_BITE                     = 177,
    ANIM_DRUID_BEAR_MAUL                     = 178,
    ANIM_DRUID_BEAR_BASH                     = 179,
    ANIM_DRAGON_TAIL                         = 180,
    ANIM_DRAGON_STOMP                        = 181,
    ANIM_DRAGON_SPIT                         = 182,
    ANIM_DRAGON_SPIT_HOVER                   = 183,
    ANIM_DRAGON_SPIT_FLY                     = 184,
    ANIM_EMOTE_YES                           = 185,
    ANIM_EMOTE_NO                            = 186,
    ANIM_JUMP_LAND_RUN                       = 187,
    ANIM_LOOT_HOLD                           = 188,
    ANIM_LOOT_UP                             = 189,
    ANIM_STAND_HIGH                          = 190,
    ANIM_IMPACT                              = 191,
    ANIM_LIFTOFF                             = 192,
    ANIM_HOVER                               = 193,
    ANIM_SUCCUBUS_ENTICE                     = 194,
    ANIM_EMOTE_TRAIN                         = 195,
    ANIM_EMOTE_DEAD                          = 196,
    ANIM_EMOTE_DANCE_ONCE                    = 197,
    ANIM_DEFLECT                             = 198,
    ANIM_EMOTE_EAT_NO_SHEATHE                = 199,
    ANIM_LAND                                = 200,
    ANIM_SUBMERGE                            = 201,
    ANIM_SUBMERGED                           = 202,
    ANIM_CANNIBALIZE                         = 203,
    ANIM_ARROW_BIRTH                         = 204,
    ANIM_GROUP_ARROW_BIRTH                   = 205,
    ANIM_CORPSE_ARROW_BIRTH                  = 206,
    ANIM_GUIDE_ARROW_BIRTH                   = 207,
    ANIM_EMOTE_TALK_NO_SHEATHE               = 208,
    ANIM_EMOTE_POINT_NO_SHEATHE              = 209,
    ANIM_EMOTE_SALUTE_NO_SHEATHE             = 210,
    ANIM_EMOTE_DANCE_SPECIAL                 = 211,
    ANIM_MUTILATE                            = 212,
    ANIM_CUSTOM_SPELL_01                     = 213,
    ANIM_CUSTOM_SPELL_02                     = 214,
    ANIM_CUSTOM_SPELL_03                     = 215,
    ANIM_CUSTOM_SPELL_04                     = 216,
    ANIM_CUSTOM_SPELL_05                     = 217,
    ANIM_CUSTOM_SPELL_06                     = 218,
    ANIM_CUSTOM_SPELL_07                     = 219,
    ANIM_CUSTOM_SPELL_08                     = 220,
    ANIM_CUSTOM_SPELL_09                     = 221,
    ANIM_CUSTOM_SPELL_10                     = 222,
    ANIM_STEALTH_RUN                         = 223,
    ANIM_EMERGE                              = 224,
    ANIM_COWER                               = 225,
    ANIM_GRAB                                = 226,
    ANIM_GRAB_CLOSED                         = 227,
    ANIM_GRAB_THROWN                         = 228,
    ANIM_FLY_STAND                           = 229,
    ANIM_FLY_DEATH                           = 230,
    ANIM_FLY_SPELL                           = 231,
    ANIM_FLY_STOP                            = 232,
    ANIM_FLY_WALK                            = 233,
    ANIM_FLY_RUN                             = 234,
    ANIM_FLY_DEAD                            = 235,
    ANIM_FLY_RISE                            = 236,
    ANIM_FLY_STAND_WOUND                     = 237,
    ANIM_FLY_COMBAT_WOUND                    = 238,
    ANIM_FLY_COMBAT_CRITICAL                 = 239,
    ANIM_FLY_SHUFFLE_LEFT                    = 240,
    ANIM_FLY_SHUFFLE_RIGHT                   = 241,
    ANIM_FLY_WALK_BACKWARDS                  = 242,
    ANIM_FLY_STUN                            = 243,
    ANIM_FLY_HANDS_CLOSED                    = 244,
    ANIM_FLY_ATTACK_UNARMED                  = 245,
    ANIM_FLY_ATTACK1H                        = 246,
    ANIM_FLY_ATTACK2H                        = 247,
    ANIM_FLY_ATTACK2HL                       = 248,
    ANIM_FLY_PARRY_UNARMED                   = 249,
    ANIM_FLY_PARRY1H                         = 250,
    ANIM_FLY_PARRY2H                         = 251,
    ANIM_FLY_PARRY2HL                        = 252,
    ANIM_FLY_SHIELD_BLOCK                    = 253,
    ANIM_FLY_READY_UNARMED                   = 254,
    ANIM_FLY_READY1H                         = 255,
    ANIM_FLY_READY2H                         = 256,
    ANIM_FLY_READY2HL                        = 257,
    ANIM_FLY_READY_BOW                       = 258,
    ANIM_FLY_DODGE                           = 259,
    ANIM_FLY_SPELL_PRECAST                   = 260,
    ANIM_FLY_SPELL_CAST                      = 261,
    ANIM_FLY_SPELL_CAST_AREA                 = 262,
    ANIM_FLY_NPC_WELCOME                     = 263,
    ANIM_FLY_NPC_GOODBYE                     = 264,
    ANIM_FLY_BLOCK                           = 265,
    ANIM_FLY_JUMP_START                      = 266,
    ANIM_FLY_JUMP                            = 267,
    ANIM_FLY_JUMP_END                        = 268,
    ANIM_FLY_FALL                            = 269,
    ANIM_FLY_SWIM_IDLE                       = 270,
    ANIM_FLY_SWIM                            = 271,
    ANIM_FLY_SWIM_LEFT                       = 272,
    ANIM_FLY_SWIM_RIGHT                      = 273,
    ANIM_FLY_SWIM_BACKWARDS                  = 274,
    ANIM_FLY_ATTACK_BOW                      = 275,
    ANIM_FLY_FIRE_BOW                        = 276,
    ANIM_FLY_READY_RIFLE                     = 277,
    ANIM_FLY_ATTACK_RIFLE                    = 278,
    ANIM_FLY_LOOT                            = 279,
    ANIM_FLY_READY_SPELL_DIRECTED            = 280,
    ANIM_FLY_READY_SPELL_OMNI                = 281,
    ANIM_FLY_SPELL_CAST_DIRECTED             = 282,
    ANIM_FLY_SPELL_CAST_OMNI                 = 283,
    ANIM_FLY_SPELL_BATTLE_ROAR               = 284,
    ANIM_FLY_READY_ABILITY                   = 285,
    ANIM_FLY_SPECIAL1H                       = 286,
    ANIM_FLY_SPECIAL2H                       = 287,
    ANIM_FLY_SHIELD_BASH                     = 288,
    ANIM_FLY_EMOTE_TALK                      = 289,
    ANIM_FLY_EMOTE_EAT                       = 290,
    ANIM_FLY_EMOTE_WORK                      = 291,
    ANIM_FLY_USE_STANDING                    = 292,
    ANIM_FLY_EMOTE_TALK_EXCLAMATION          = 293,
    ANIM_FLY_EMOTE_TALK_QUESTION             = 294,
    ANIM_FLY_EMOTE_BOW                       = 295,
    ANIM_FLY_EMOTE_WAVE                      = 296,
    ANIM_FLY_EMOTE_CHEER                     = 297,
    ANIM_FLY_EMOTE_DANCE                     = 298,
    ANIM_FLY_EMOTE_LAUGH                     = 299,
    ANIM_FLY_EMOTE_SLEEP                     = 300,
    ANIM_FLY_EMOTE_SIT_GROUND                = 301,
    ANIM_FLY_EMOTE_RUDE                      = 302,
    ANIM_FLY_EMOTE_ROAR                      = 303,
    ANIM_FLY_EMOTE_KNEEL                     = 304,
    ANIM_FLY_EMOTE_KISS                      = 305,
    ANIM_FLY_EMOTE_CRY                       = 306,
    ANIM_FLY_EMOTE_CHICKEN                   = 307,
    ANIM_FLY_EMOTE_BEG                       = 308,
    ANIM_FLY_EMOTE_APPLAUD                   = 309,
    ANIM_FLY_EMOTE_SHOUT                     = 310,
    ANIM_FLY_EMOTE_FLEX                      = 311,
    ANIM_FLY_EMOTE_SHY                       = 312,
    ANIM_FLY_EMOTE_POINT                     = 313,
    ANIM_FLY_ATTACK1H_PIERCE                 = 314,
    ANIM_FLY_ATTACK2H_LOOSE_PIERCE           = 315,
    ANIM_FLY_ATTACK_OFF                      = 316,
    ANIM_FLY_ATTACK_OFF_PIERCE               = 317,
    ANIM_FLY_SHEATH                          = 318,
    ANIM_FLY_HIP_SHEATH                      = 319,
    ANIM_FLY_MOUNT                           = 320,
    ANIM_FLY_RUN_RIGHT                       = 321,
    ANIM_FLY_RUN_LEFT                        = 322,
    ANIM_FLY_MOUNT_SPECIAL                   = 323,
    ANIM_FLY_KICK                            = 324,
    ANIM_FLY_SIT_GROUND_DOWN                 = 325,
    ANIM_FLY_SIT_GROUND                      = 326,
    ANIM_FLY_SIT_GROUND_UP                   = 327,
    ANIM_FLY_SLEEP_DOWN                      = 328,
    ANIM_FLY_SLEEP                           = 329,
    ANIM_FLY_SLEEP_UP                        = 330,
    ANIM_FLY_SIT_CHAIR_LOW                   = 331,
    ANIM_FLY_SIT_CHAIR_MED                   = 332,
    ANIM_FLY_SIT_CHAIR_HIGH                  = 333,
    ANIM_FLY_LOAD_BOW                        = 334,
    ANIM_FLY_LOAD_RIFLE                      = 335,
    ANIM_FLY_ATTACK_THROWN                   = 336,
    ANIM_FLY_READY_THROWN                    = 337,
    ANIM_FLY_HOLD_BOW                        = 338,
    ANIM_FLY_HOLD_RIFLE                      = 339,
    ANIM_FLY_HOLD_THROWN                     = 340,
    ANIM_FLY_LOAD_THROWN                     = 341,
    ANIM_FLY_EMOTE_SALUTE                    = 342,
    ANIM_FLY_KNEEL_START                     = 343,
    ANIM_FLY_KNEEL_LOOP                      = 344,
    ANIM_FLY_KNEEL_END                       = 345,
    ANIM_FLY_ATTACK_UNARMED_OFF              = 346,
    ANIM_FLY_SPECIAL_UNARMED                 = 347,
    ANIM_FLY_STEALTH_WALK                    = 348,
    ANIM_FLY_STEALTH_STAND                   = 349,
    ANIM_FLY_KNOCKDOWN                       = 350,
    ANIM_FLY_EATING_LOOP                     = 351,
    ANIM_FLY_USE_STANDING_LOOP               = 352,
    ANIM_FLY_CHANNEL_CAST_DIRECTED           = 353,
    ANIM_FLY_CHANNEL_CAST_OMNI               = 354,
    ANIM_FLY_WHIRLWIND                       = 355,
    ANIM_FLY_BIRTH                           = 356,
    ANIM_FLY_USE_STANDING_START              = 357,
    ANIM_FLY_USE_STANDING_END                = 358,
    ANIM_FLY_CREATURE_SPECIAL                = 359,
    ANIM_FLY_DROWN                           = 360,
    ANIM_FLY_DROWNED                         = 361,
    ANIM_FLY_FISHING_CAST                    = 362,
    ANIM_FLY_FISHING_LOOP                    = 363,
    ANIM_FLY_FLY                             = 364,
    ANIM_FLY_EMOTE_WORK_NO_SHEATHE           = 365,
    ANIM_FLY_EMOTE_STUN_NO_SHEATHE           = 366,
    ANIM_FLY_EMOTE_USE_STANDING_NO_SHEATHE   = 367,
    ANIM_FLY_SPELL_SLEEP_DOWN                = 368,
    ANIM_FLY_SPELL_KNEEL_START               = 369,
    ANIM_FLY_SPELL_KNEEL_LOOP                = 370,
    ANIM_FLY_SPELL_KNEEL_END                 = 371,
    ANIM_FLY_SPRINT                          = 372,
    ANIM_FLY_IN_FLIGHT                       = 373,
    ANIM_FLY_SPAWN                           = 374,
    ANIM_FLY_CLOSE                           = 375,
    ANIM_FLY_CLOSED                          = 376,
    ANIM_FLY_OPEN                            = 377,
    ANIM_FLY_OPENED                          = 378,
    ANIM_FLY_DESTROY                         = 379,
    ANIM_FLY_DESTROYED                       = 380,
    ANIM_FLY_REBUILD                         = 381,
    ANIM_FLY_CUSTOM_0                        = 382,
    ANIM_FLY_CUSTOM_1                        = 383,
    ANIM_FLY_CUSTOM_2                        = 384,
    ANIM_FLY_CUSTOM_3                        = 385,
    ANIM_FLY_DESPAWN                         = 386,
    ANIM_FLY_HOLD                            = 387,
    ANIM_FLY_DECAY                           = 388,
    ANIM_FLY_BOW_PULL                        = 389,
    ANIM_FLY_BOW_RELEASE                     = 390,
    ANIM_FLY_SHIP_START                      = 391,
    ANIM_FLY_SHIP_MOVING                     = 392,
    ANIM_FLY_SHIP_STOP                       = 393,
    ANIM_FLY_GROUP_ARROW                     = 394,
    ANIM_FLY_ARROW                           = 395,
    ANIM_FLY_CORPSE_ARROW                    = 396,
    ANIM_FLY_GUIDE_ARROW                     = 397,
    ANIM_FLY_SWAY                            = 398,
    ANIM_FLY_DRUID_CAT_POUNCE                = 399,
    ANIM_FLY_DRUID_CAT_RIP                   = 400,
    ANIM_FLY_DRUID_CAT_RAKE                  = 401,
    ANIM_FLY_DRUID_CAT_RAVAGE                = 402,
    ANIM_FLY_DRUID_CAT_CLAW                  = 403,
    ANIM_FLY_DRUID_CAT_COWER                 = 404,
    ANIM_FLY_DRUID_BEAR_SWIPE                = 405,
    ANIM_FLY_DRUID_BEAR_BITE                 = 406,
    ANIM_FLY_DRUID_BEAR_MAUL                 = 407,
    ANIM_FLY_DRUID_BEAR_BASH                 = 408,
    ANIM_FLY_DRAGON_TAIL                     = 409,
    ANIM_FLY_DRAGON_STOMP                    = 410,
    ANIM_FLY_DRAGON_SPIT                     = 411,
    ANIM_FLY_DRAGON_SPIT_HOVER               = 412,
    ANIM_FLY_DRAGON_SPIT_FLY                 = 413,
    ANIM_FLY_EMOTE_YES                       = 414,
    ANIM_FLY_EMOTE_NO                        = 415,
    ANIM_FLY_JUMP_LAND_RUN                   = 416,
    ANIM_FLY_LOOT_HOLD                       = 417,
    ANIM_FLY_LOOT_UP                         = 418,
    ANIM_FLY_STAND_HIGH                      = 419,
    ANIM_FLY_IMPACT                          = 420,
    ANIM_FLY_LIFTOFF                         = 421,
    ANIM_FLY_HOVER                           = 422,
    ANIM_FLY_SUCCUBUS_ENTICE                 = 423,
    ANIM_FLY_EMOTE_TRAIN                     = 424,
    ANIM_FLY_EMOTE_DEAD                      = 425,
    ANIM_FLY_EMOTE_DANCE_ONCE                = 426,
    ANIM_FLY_DEFLECT                         = 427,
    ANIM_FLY_EMOTE_EAT_NO_SHEATHE            = 428,
    ANIM_FLY_LAND                            = 429,
    ANIM_FLY_SUBMERGE                        = 430,
    ANIM_FLY_SUBMERGED                       = 431,
    ANIM_FLY_CANNIBALIZE                     = 432,
    ANIM_FLY_ARROW_BIRTH                     = 433,
    ANIM_FLY_GROUP_ARROW_BIRTH               = 434,
    ANIM_FLY_CORPSE_ARROW_BIRTH              = 435,
    ANIM_FLY_GUIDE_ARROW_BIRTH               = 436,
    ANIM_FLY_EMOTE_TALK_NO_SHEATHE           = 437,
    ANIM_FLY_EMOTE_POINT_NO_SHEATHE          = 438,
    ANIM_FLY_EMOTE_SALUTE_NO_SHEATHE         = 439,
    ANIM_FLY_EMOTE_DANCE_SPECIAL             = 440,
    ANIM_FLY_MUTILATE                        = 441,
    ANIM_FLY_CUSTOM_SPELL_01                 = 442,
    ANIM_FLY_CUSTOM_SPELL_02                 = 443,
    ANIM_FLY_CUSTOM_SPELL_03                 = 444,
    ANIM_FLY_CUSTOM_SPELL_04                 = 445,
    ANIM_FLY_CUSTOM_SPELL_05                 = 446,
    ANIM_FLY_CUSTOM_SPELL_06                 = 447,
    ANIM_FLY_CUSTOM_SPELL_07                 = 448,
    ANIM_FLY_CUSTOM_SPELL_08                 = 449,
    ANIM_FLY_CUSTOM_SPELL_09                 = 450,
    ANIM_FLY_CUSTOM_SPELL_10                 = 451,
    ANIM_FLY_STEALTH_RUN                     = 452,
    ANIM_FLY_EMERGE                          = 453,
    ANIM_FLY_COWER                           = 454,
    ANIM_FLY_GRAB                            = 455,
    ANIM_FLY_GRAB_CLOSED                     = 456,
    ANIM_FLY_GRAB_THROWN                     = 457,
    ANIM_TO_FLY                              = 458,
    ANIM_TO_HOVER                            = 459,
    ANIM_TO_GROUND                           = 460,
    ANIM_FLY_TO_FLY                          = 461,
    ANIM_FLY_TO_HOVER                        = 462,
    ANIM_FLY_TO_GROUND                       = 463,
    ANIM_SETTLE                              = 464,
    ANIM_FLY_SETTLE                          = 465,
    ANIM_DEATH_START                         = 466,
    ANIM_DEATH_LOOP                          = 467,
    ANIM_DEATH_END                           = 468,
    ANIM_FLY_DEATH_START                     = 469,
    ANIM_FLY_DEATH_LOOP                      = 470,
    ANIM_FLY_DEATH_END                       = 471,
    ANIM_DEATH_END_HOLD                      = 472,
    ANIM_FLY_DEATH_END_HOLD                  = 473,
    ANIM_STRANGULATE                         = 474,
    ANIM_FLY_STRANGULATE                     = 475,
    ANIM_READY_JOUST                         = 476,
    ANIM_LOAD_JOUST                          = 477,
    ANIM_HOLD_JOUST                          = 478,
    ANIM_FLY_READY_JOUST                     = 479,
    ANIM_FLY_LOAD_JOUST                      = 480,
    ANIM_FLY_HOLD_JOUST                      = 481,
    ANIM_ATTACK_JOUST                        = 482,
    ANIM_FLY_ATTACK_JOUST                    = 483,
    ANIM_RECLINED_MOUNT                      = 484,
    ANIM_FLY_RECLINED_MOUNT                  = 485,
    ANIM_TO_ALTERED                          = 486,
    ANIM_FROM_ALTERED                        = 487,
    ANIM_FLY_TO_ALTERED                      = 488,
    ANIM_FLY_FROM_ALTERED                    = 489,
    ANIM_IN_STOCKS                           = 490,
    ANIM_FLY_IN_STOCKS                       = 491,
    ANIM_VEHICLE_GRAB                        = 492,
    ANIM_VEHICLE_THROW                       = 493,
    ANIM_FLY_VEHICLE_GRAB                    = 494,
    ANIM_FLY_VEHICLE_THROW                   = 495,
    ANIM_TO_ALTERED_POST_SWAP                = 496,
    ANIM_FROM_ALTERED_POST_SWAP              = 497,
    ANIM_FLY_TO_ALTERED_POST_SWAP            = 498,
    ANIM_FLY_FROM_ALTERED_POST_SWAP          = 499,
    ANIM_RECLINED_MOUNT_PASSENGER            = 500,
    ANIM_FLY_RECLINED_MOUNT_PASSENGER        = 501,
    ANIM_CARRY2H                             = 502,
    ANIM_CARRIED2H                           = 503,
    ANIM_FLY_CARRY2H                         = 504,
    ANIM_FLY_CARRIED2H                       = 505
};

enum LockKeyType
{
    LOCK_KEY_NONE  = 0,
    LOCK_KEY_ITEM  = 1,
    LOCK_KEY_SKILL = 2,
    LOCK_KEY_SPELL = 3,
};

enum LockType
{
    LOCKTYPE_PICKLOCK              = 1,
    LOCKTYPE_HERBALISM             = 2,
    LOCKTYPE_MINING                = 3,
    LOCKTYPE_DISARM_TRAP           = 4,
    LOCKTYPE_OPEN                  = 5,
    LOCKTYPE_TREASURE              = 6,
    LOCKTYPE_CALCIFIED_ELVEN_GEMS  = 7,
    LOCKTYPE_CLOSE                 = 8,
    LOCKTYPE_ARM_TRAP              = 9,
    LOCKTYPE_QUICK_OPEN            = 10,
    LOCKTYPE_QUICK_CLOSE           = 11,
    LOCKTYPE_OPEN_TINKERING        = 12,
    LOCKTYPE_OPEN_KNEELING         = 13,
    LOCKTYPE_OPEN_ATTACKING        = 14,
    LOCKTYPE_GAHZRIDIAN            = 15,
    LOCKTYPE_BLASTING              = 16,
    LOCKTYPE_SLOW_OPEN             = 17,
    LOCKTYPE_SLOW_CLOSE            = 18,
    LOCKTYPE_FISHING               = 19,
    LOCKTYPE_INSCRIPTION           = 20,
    LOCKTYPE_OPEN_FROM_VEHICLE     = 21
};

// CreatureType.dbc
enum CreatureType
{
    CREATURE_TYPE_BEAST            = 1,  // 野兽：包括各种自然界的动物和野生生物。
    CREATURE_TYPE_DRAGONKIN        = 2,  // 龙类：包括龙和与龙有关的生物。
    CREATURE_TYPE_DEMON            = 3,  // 恶魔：来自地狱或扭曲虚空的邪恶生物。
    CREATURE_TYPE_ELEMENTAL        = 4,  // 元素生物：由自然界的基本元素（如火、水、土、风）构成的生物。
    CREATURE_TYPE_GIANT            = 5,  // 巨人：体型庞大的生物。
    CREATURE_TYPE_UNDEAD           = 6,  // 不死生物：已死之人的尸体或幽灵。
    CREATURE_TYPE_HUMANOID         = 7,  // 人型生物：形态类似人类的生物，包括各种族如兽人、精灵等。
    CREATURE_TYPE_CRITTER          = 8,  // 小动物：通常不会对玩家构成威胁的小型生物，如松鼠、兔子等。
    CREATURE_TYPE_MECHANICAL       = 9,  // 机械：由人造材料构建的生物，可能由魔法、科技或两者的结合驱动。
    CREATURE_TYPE_NOT_SPECIFIED    = 10, // 未指定：未被明确分类的生物。
    CREATURE_TYPE_TOTEM            = 11, // 图腾：由萨满等施法者召唤的，具有特定功能的魔法实体。
    CREATURE_TYPE_NON_COMBAT_PET   = 12, // 非战斗宠物：伴随玩家但不参与战斗的小动物或生物。
    CREATURE_TYPE_GAS_CLOUD        = 13  // 气体云：可能为采集资源而存在的，由气体组成的云。
};

uint32 const CREATURE_TYPEMASK_DEMON_OR_UNDEAD = (1 << (CREATURE_TYPE_DEMON-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));
uint32 const CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD = (1 << (CREATURE_TYPE_HUMANOID-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));
uint32 const CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL = (1 << (CREATURE_TYPE_MECHANICAL-1)) | (1 << (CREATURE_TYPE_ELEMENTAL-1));

// CreatureFamily.dbc
enum CreatureFamily
{
    CREATURE_FAMILY_NONE                = 0,
    CREATURE_FAMILY_WOLF                = 1,
    CREATURE_FAMILY_CAT                 = 2,
    CREATURE_FAMILY_SPIDER              = 3,
    CREATURE_FAMILY_BEAR                = 4,
    CREATURE_FAMILY_BOAR                = 5,
    CREATURE_FAMILY_CROCOLISK           = 6,
    CREATURE_FAMILY_CARRION_BIRD        = 7,
    CREATURE_FAMILY_CRAB                = 8,
    CREATURE_FAMILY_GORILLA             = 9,
    CREATURE_FAMILY_HORSE_CUSTOM        = 10, // Does not exist in DBC but used for horse like beasts in DB
    CREATURE_FAMILY_RAPTOR              = 11,
    CREATURE_FAMILY_TALLSTRIDER         = 12,
    CREATURE_FAMILY_FELHUNTER           = 15,
    CREATURE_FAMILY_VOIDWALKER          = 16,
    CREATURE_FAMILY_SUCCUBUS            = 17,
    CREATURE_FAMILY_DOOMGUARD           = 19,
    CREATURE_FAMILY_SCORPID             = 20,
    CREATURE_FAMILY_TURTLE              = 21,
    CREATURE_FAMILY_IMP                 = 23,
    CREATURE_FAMILY_BAT                 = 24,
    CREATURE_FAMILY_HYENA               = 25,
    CREATURE_FAMILY_BIRD_OF_PREY        = 26,
    CREATURE_FAMILY_WIND_SERPENT        = 27,
    CREATURE_FAMILY_REMOTE_CONTROL      = 28,
    CREATURE_FAMILY_FELGUARD            = 29,
    CREATURE_FAMILY_DRAGONHAWK          = 30,
    CREATURE_FAMILY_RAVAGER             = 31,
    CREATURE_FAMILY_WARP_STALKER        = 32,
    CREATURE_FAMILY_SPOREBAT            = 33,
    CREATURE_FAMILY_NETHER_RAY          = 34,
    CREATURE_FAMILY_SERPENT             = 35,
    CREATURE_FAMILY_MOTH                = 37,
    CREATURE_FAMILY_CHIMAERA            = 38,
    CREATURE_FAMILY_DEVILSAUR           = 39,
    CREATURE_FAMILY_GHOUL               = 40,
    CREATURE_FAMILY_SILITHID            = 41,
    CREATURE_FAMILY_WORM                = 42,
    CREATURE_FAMILY_RHINO               = 43,
    CREATURE_FAMILY_WASP                = 44,
    CREATURE_FAMILY_CORE_HOUND          = 45,
    CREATURE_FAMILY_SPIRIT_BEAST        = 46
};

enum CreatureTypeFlags
{
    CREATURE_TYPE_FLAG_TAMEABLE                             = 0x00000001,   // Makes the mob tameable (must also be a beast and have family set)
    CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS                    = 0x00000002,   // Creature is also visible for not alive player. Allows gossip interaction if npcflag allows?
    CREATURE_TYPE_FLAG_BOSS_MOB                             = 0x00000004,   // Changes creature's visible level to "??" in the creature's portrait - Immune Knockback.
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_WOUND_ANIM               = 0x00000008,   // Does not play wound animation on parry
    CREATURE_TYPE_FLAG_NO_FACTION_TOOLTIP                   = 0x00000010,
    CREATURE_TYPE_FLAG_MORE_AUDIBLE                         = 0x00000020,   // Sound related
    CREATURE_TYPE_FLAG_SPELL_ATTACKABLE                     = 0x00000040,
    CREATURE_TYPE_FLAG_INTERACT_WHILE_DEAD                  = 0x00000080,   // Player can interact with the creature if creature is dead (not if player is dead)
    CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM                  = 0x00000100,   // Can be looted by herbalist
    CREATURE_TYPE_FLAG_SKIN_WITH_MINING                     = 0x00000200,   // Can be looted by miner
    CREATURE_TYPE_FLAG_NO_DEATH_MESSAGE                     = 0x00000400,   // Death event will not show up in combat log
    CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT                 = 0x00000800,   // Creature can remain mounted when entering combat
    CREATURE_TYPE_FLAG_CAN_ASSIST                           = 0x00001000,   // ? Can aid any player in combat if in range?
    CREATURE_TYPE_FLAG_NO_PET_BAR                           = 0x00002000,
    CREATURE_TYPE_FLAG_MASK_UID                             = 0x00004000,
    CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING                = 0x00008000,   // Can be looted by engineer
    CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC                      = 0x00010000,   // Can be tamed by hunter as exotic pet
    CREATURE_TYPE_FLAG_USE_MODEL_COLLISION_SIZE             = 0x00020000,   // Collision related. (always using default collision box?)
    CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT    = 0x00040000,
    CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES                = 0x00080000,   // Projectiles can collide with this creature - interacts with TARGET_DEST_TRAJ
    CREATURE_TYPE_FLAG_NO_NAME_PLATE                        = 0x00100000,
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_MOUNTED_ANIMATIONS       = 0x00200000,
    CREATURE_TYPE_FLAG_LINK_ALL                             = 0x00400000,
    CREATURE_TYPE_FLAG_INTERACT_ONLY_WITH_CREATOR           = 0x00800000,
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_UNIT_EVENT_SOUNDS        = 0x01000000,
    CREATURE_TYPE_FLAG_HAS_NO_SHADOW_BLOB                   = 0x02000000,
    CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT                   = 0x04000000,   // ! Creature can be targeted by spells that require target to be in caster's party/raid
    CREATURE_TYPE_FLAG_FORCE_GOSSIP                         = 0x08000000,   // Allows the creature to display a single gossip option.
    CREATURE_TYPE_FLAG_DO_NOT_SHEATHE                       = 0x10000000,
    CREATURE_TYPE_FLAG_DO_NOT_TARGET_ON_INTERACTION         = 0x20000000,
    CREATURE_TYPE_FLAG_DO_NOT_RENDER_OBJECT_NAME            = 0x40000000,
    CREATURE_TYPE_FLAG_QUEST_BOSS                           = 0x80000000    // Not verified
};

enum CreatureEliteType
{
    CREATURE_ELITE_NORMAL          = 0,
    CREATURE_ELITE_ELITE           = 1,
    CREATURE_ELITE_RAREELITE       = 2,
    CREATURE_ELITE_WORLDBOSS       = 3,
    CREATURE_ELITE_RARE            = 4,
    CREATURE_ELITE_TRIVIAL         = 5  // found in 2.2.3 for 2 mobs
};

enum class StringIdType : int32
{
    Template    = 0,
    Spawn       = 1,
    Script      = 2
};

// values based at Holidays.dbc
enum HolidayIds
{
    HOLIDAY_NONE                     = 0,

    HOLIDAY_FIREWORKS_SPECTACULAR    = 62,
    HOLIDAY_FEAST_OF_WINTER_VEIL     = 141,
    HOLIDAY_NOBLEGARDEN              = 181,
    HOLIDAY_CHILDRENS_WEEK           = 201,
    HOLIDAY_CALL_TO_ARMS_AV          = 283,
    HOLIDAY_CALL_TO_ARMS_WS          = 284,
    HOLIDAY_CALL_TO_ARMS_AB          = 285,
    HOLIDAY_FISHING_EXTRAVAGANZA     = 301,
    HOLIDAY_HARVEST_FESTIVAL         = 321,
    HOLIDAY_HALLOWS_END              = 324,
    HOLIDAY_LUNAR_FESTIVAL           = 327,
    // HOLIDAY_LOVE_IS_IN_THE_AIR    = 335, unused/duplicated
    HOLIDAY_FIRE_FESTIVAL            = 341,
    HOLIDAY_CALL_TO_ARMS_EY          = 353,
    HOLIDAY_BREWFEST                 = 372,
    HOLIDAY_DARKMOON_FAIRE_ELWYNN    = 374,
    HOLIDAY_DARKMOON_FAIRE_THUNDER   = 375,
    HOLIDAY_DARKMOON_FAIRE_SHATTRATH = 376,
    HOLIDAY_PIRATES_DAY              = 398,
    HOLIDAY_CALL_TO_ARMS_SA          = 400,
    HOLIDAY_PILGRIMS_BOUNTY          = 404,
    HOLIDAY_WOTLK_LAUNCH             = 406,
    HOLIDAY_DAY_OF_DEAD              = 409,
    HOLIDAY_CALL_TO_ARMS_IC          = 420,
    HOLIDAY_LOVE_IS_IN_THE_AIR       = 423,
    HOLIDAY_KALU_AK_FISHING_DERBY    = 424
};

// values based at QuestInfo.dbc
enum QuestTypes
{
    QUEST_TYPE_ELITE               = 1,
    QUEST_TYPE_LIFE                = 21,
    QUEST_TYPE_PVP                 = 41,
    QUEST_TYPE_RAID                = 62,
    QUEST_TYPE_DUNGEON             = 81,
    QUEST_TYPE_WORLD_EVENT         = 82,
    QUEST_TYPE_LEGENDARY           = 83,
    QUEST_TYPE_ESCORT              = 84,
    QUEST_TYPE_HEROIC              = 85,
    QUEST_TYPE_RAID_10             = 88,
    QUEST_TYPE_RAID_25             = 89
};

// values based at QuestSort.dbc
enum QuestSort
{
    QUEST_SORT_EPIC                             = 1,
    QUEST_SORT_WAILING_CAVERNS_OLD              = 21,
    QUEST_SORT_SEASONAL                         = 22,
    QUEST_SORT_UNDERCITY_OLD                    = 23,
    QUEST_SORT_HERBALISM                        = 24,
    QUEST_SORT_BATTLEGROUNDS                    = 25,
    QUEST_SORT_ULDAMN_OLD                       = 41,
    QUEST_SORT_WARLOCK                          = 61,
    QUEST_SORT_WARRIOR                          = 81,
    QUEST_SORT_SHAMAN                           = 82,
    QUEST_SORT_FISHING                          = 101,
    QUEST_SORT_BLACKSMITHING                    = 121,
    QUEST_SORT_PALADIN                          = 141,
    QUEST_SORT_MAGE                             = 161,
    QUEST_SORT_ROGUE                            = 162,
    QUEST_SORT_ALCHEMY                          = 181,
    QUEST_SORT_LEATHERWORKING                   = 182,
    QUEST_SORT_ENGINEERING                      = 201,
    QUEST_SORT_TREASURE_MAP                     = 221,
    QUEST_SORT_SUNKEN_TEMPLE_OLD                = 241,
    QUEST_SORT_HUNTER                           = 261,
    QUEST_SORT_PRIEST                           = 262,
    QUEST_SORT_DRUID                            = 263,
    QUEST_SORT_TAILORING                        = 264,
    QUEST_SORT_SPECIAL                          = 284,
    QUEST_SORT_COOKING                          = 304,
    QUEST_SORT_FIRST_AID                        = 324,
    QUEST_SORT_LEGENDARY                        = 344,
    QUEST_SORT_DARKMOON_FAIRE                   = 364,
    QUEST_SORT_AHN_QIRAJ_WAR                    = 365,
    QUEST_SORT_LUNAR_FESTIVAL                   = 366,
    QUEST_SORT_REPUTATION                       = 367,
    QUEST_SORT_INVASION                         = 368,
    QUEST_SORT_MIDSUMMER                        = 369,
    QUEST_SORT_BREWFEST                         = 370,
    QUEST_SORT_INSCRIPTION                      = 371,
    QUEST_SORT_DEATH_KNIGHT                     = 372,
    QUEST_SORT_JEWELCRAFTING                    = 373,
    QUEST_SORT_NOBLEGARDEN                      = 374,
    QUEST_SORT_PILGRIMS_BOUNTY                  = 375,
    QUEST_SORT_LOVE_IS_IN_THE_AIR               = 376
};

constexpr uint8 ClassByQuestSort(int32 QuestSort)
{
    switch (QuestSort)
    {
        case QUEST_SORT_WARLOCK:        return CLASS_WARLOCK;
        case QUEST_SORT_WARRIOR:        return CLASS_WARRIOR;
        case QUEST_SORT_SHAMAN:         return CLASS_SHAMAN;
        case QUEST_SORT_PALADIN:        return CLASS_PALADIN;
        case QUEST_SORT_MAGE:           return CLASS_MAGE;
        case QUEST_SORT_ROGUE:          return CLASS_ROGUE;
        case QUEST_SORT_HUNTER:         return CLASS_HUNTER;
        case QUEST_SORT_PRIEST:         return CLASS_PRIEST;
        case QUEST_SORT_DRUID:          return CLASS_DRUID;
        case QUEST_SORT_DEATH_KNIGHT:   return CLASS_DEATH_KNIGHT;
    }
    return 0;
}

enum SkillType
{
    SKILL_NONE                                      = 0,

    SKILL_FROST                                     = 6,
    SKILL_FIRE                                      = 8,
    SKILL_ARMS                                      = 26,
    SKILL_COMBAT                                    = 38,
    SKILL_SUBTLETY                                  = 39,
    SKILL_SWORDS                                    = 43,
    SKILL_AXES                                      = 44,
    SKILL_BOWS                                      = 45,
    SKILL_GUNS                                      = 46,
    SKILL_BEAST_MASTERY                             = 50,
    SKILL_SURVIVAL                                  = 51,
    SKILL_MACES                                     = 54,
    SKILL_2H_SWORDS                                 = 55,
    SKILL_HOLY                                      = 56,
    SKILL_SHADOW                                    = 78,
    SKILL_DEFENSE                                   = 95,
    SKILL_LANG_COMMON                               = 98,
    SKILL_RACIAL_DWARVEN                            = 101,
    SKILL_LANG_ORCISH                               = 109,
    SKILL_LANG_DWARVEN                              = 111,
    SKILL_LANG_DARNASSIAN                           = 113,
    SKILL_LANG_TAURAHE                              = 115,
    SKILL_DUAL_WIELD                                = 118,
    SKILL_RACIAL_TAUREN                             = 124,
    SKILL_ORC_RACIAL                                = 125,
    SKILL_RACIAL_NIGHT_ELF                          = 126,
    SKILL_FIRST_AID                                 = 129,
    SKILL_FERAL_COMBAT                              = 134,
    SKILL_STAVES                                    = 136,
    SKILL_LANG_THALASSIAN                           = 137,
    SKILL_LANG_DRACONIC                             = 138,
    SKILL_LANG_DEMON_TONGUE                         = 139,
    SKILL_LANG_TITAN                                = 140,
    SKILL_LANG_OLD_TONGUE                           = 141,
    SKILL_SURVIVAL2                                 = 142,
    SKILL_RIDING_HORSE                              = 148,
    SKILL_RIDING_WOLF                               = 149,
    SKILL_RIDING_TIGER                              = 150,
    SKILL_RIDING_RAM                                = 152,
    SKILL_SWIMING                                   = 155,
    SKILL_2H_MACES                                  = 160,
    SKILL_UNARMED                                   = 162,
    SKILL_MARKSMANSHIP                              = 163,
    SKILL_BLACKSMITHING                             = 164,
    SKILL_LEATHERWORKING                            = 165,
    SKILL_ALCHEMY                                   = 171,
    SKILL_2H_AXES                                   = 172,
    SKILL_DAGGERS                                   = 173,
    SKILL_THROWN                                    = 176,
    SKILL_HERBALISM                                 = 182,
    SKILL_GENERIC_DND                               = 183,
    SKILL_RETRIBUTION                               = 184,
    SKILL_COOKING                                   = 185,
    SKILL_MINING                                    = 186,
    SKILL_PET_IMP                                   = 188,
    SKILL_PET_FELHUNTER                             = 189,
    SKILL_TAILORING                                 = 197,
    SKILL_ENGINEERING                               = 202,
    SKILL_PET_SPIDER                                = 203,
    SKILL_PET_VOIDWALKER                            = 204,
    SKILL_PET_SUCCUBUS                              = 205,
    SKILL_PET_INFERNAL                              = 206,
    SKILL_PET_DOOMGUARD                             = 207,
    SKILL_PET_WOLF                                  = 208,
    SKILL_PET_CAT                                   = 209,
    SKILL_PET_BEAR                                  = 210,
    SKILL_PET_BOAR                                  = 211,
    SKILL_PET_CROCILISK                             = 212,
    SKILL_PET_CARRION_BIRD                          = 213,
    SKILL_PET_CRAB                                  = 214,
    SKILL_PET_GORILLA                               = 215,
    SKILL_PET_RAPTOR                                = 217,
    SKILL_PET_TALLSTRIDER                           = 218,
    SKILL_RACIAL_UNDED                              = 220,
    SKILL_CROSSBOWS                                 = 226,
    SKILL_WANDS                                     = 228,
    SKILL_POLEARMS                                  = 229,
    SKILL_PET_SCORPID                               = 236,
    SKILL_ARCANE                                    = 237,
    SKILL_PET_TURTLE                                = 251,
    SKILL_ASSASSINATION                             = 253,
    SKILL_FURY                                      = 256,
    SKILL_PROTECTION                                = 257,
    SKILL_PROTECTION2                               = 267,
    SKILL_PET_TALENTS                               = 270,
    SKILL_PLATE_MAIL                                = 293,
    SKILL_LANG_GNOMISH                              = 313,
    SKILL_LANG_TROLL                                = 315,
    SKILL_ENCHANTING                                = 333,
    SKILL_DEMONOLOGY                                = 354,
    SKILL_AFFLICTION                                = 355,
    SKILL_FISHING                                   = 356,
    SKILL_ENHANCEMENT                               = 373,
    SKILL_RESTORATION                               = 374,
    SKILL_ELEMENTAL_COMBAT                          = 375,
    SKILL_SKINNING                                  = 393,
    SKILL_MAIL                                      = 413,
    SKILL_LEATHER                                   = 414,
    SKILL_CLOTH                                     = 415,
    SKILL_SHIELD                                    = 433,
    SKILL_FIST_WEAPONS                              = 473,
    SKILL_RIDING_RAPTOR                             = 533,
    SKILL_RIDING_MECHANOSTRIDER                     = 553,
    SKILL_RIDING_UNDEAD_HORSE                       = 554,
    SKILL_RESTORATION2                              = 573,
    SKILL_BALANCE                                   = 574,
    SKILL_DESTRUCTION                               = 593,
    SKILL_HOLY2                                     = 594,
    SKILL_DISCIPLINE                                = 613,
    SKILL_LOCKPICKING                               = 633,
    SKILL_PET_BAT                                   = 653,
    SKILL_PET_HYENA                                 = 654,
    SKILL_PET_BIRD_OF_PREY                          = 655,
    SKILL_PET_WIND_SERPENT                          = 656,
    SKILL_LANG_GUTTERSPEAK                          = 673,
    SKILL_RIDING_KODO                               = 713,
    SKILL_RACIAL_TROLL                              = 733,
    SKILL_RACIAL_GNOME                              = 753,
    SKILL_RACIAL_HUMAN                              = 754,
    SKILL_JEWELCRAFTING                             = 755,
    SKILL_RACIAL_BLOODELF                           = 756,
    SKILL_PET_EVENT_RC                              = 758,
    SKILL_LANG_DRAENEI                              = 759,
    SKILL_RACIAL_DRAENEI                            = 760,
    SKILL_PET_FELGUARD                              = 761,
    SKILL_RIDING                                    = 762,
    SKILL_PET_DRAGONHAWK                            = 763,
    SKILL_PET_NETHER_RAY                            = 764,
    SKILL_PET_SPOREBAT                              = 765,
    SKILL_PET_WARP_STALKER                          = 766,
    SKILL_PET_RAVAGER                               = 767,
    SKILL_PET_SERPENT                               = 768,
    SKILL_INTERNAL                                  = 769,
    SKILL_DK_BLOOD                                  = 770,
    SKILL_DK_FROST                                  = 771,
    SKILL_DK_UNHOLY                                 = 772,
    SKILL_INSCRIPTION                               = 773,
    SKILL_PET_MOTH                                  = 775,
    SKILL_RUNEFORGING                               = 776,
    SKILL_MOUNTS                                    = 777,
    SKILL_COMPANIONS                                = 778,
    SKILL_PET_EXOTIC_CHIMAERA                       = 780,
    SKILL_PET_EXOTIC_DEVILSAUR                      = 781,
    SKILL_PET_GHOUL                                 = 782,
    SKILL_PET_EXOTIC_SILITHID                       = 783,
    SKILL_PET_EXOTIC_WORM                           = 784,
    SKILL_PET_WASP                                  = 785,
    SKILL_PET_EXOTIC_RHINO                          = 786,
    SKILL_PET_EXOTIC_CORE_HOUND                     = 787,
    SKILL_PET_EXOTIC_SPIRIT_BEAST                   = 788
};

#define MAX_SKILL_TYPE                                789

constexpr SkillType SkillByLockType(LockType locktype)
{
    switch (locktype)
    {
        case LOCKTYPE_PICKLOCK:    return SKILL_LOCKPICKING;
        case LOCKTYPE_HERBALISM:   return SKILL_HERBALISM;
        case LOCKTYPE_MINING:      return SKILL_MINING;
        case LOCKTYPE_FISHING:     return SKILL_FISHING;
        case LOCKTYPE_INSCRIPTION: return SKILL_INSCRIPTION;
        default: break;
    }
    return SKILL_NONE;
}

constexpr uint32 SkillByQuestSort(int32 QuestSort)
{
    switch (QuestSort)
    {
        case QUEST_SORT_HERBALISM:      return SKILL_HERBALISM;
        case QUEST_SORT_FISHING:        return SKILL_FISHING;
        case QUEST_SORT_BLACKSMITHING:  return SKILL_BLACKSMITHING;
        case QUEST_SORT_ALCHEMY:        return SKILL_ALCHEMY;
        case QUEST_SORT_LEATHERWORKING: return SKILL_LEATHERWORKING;
        case QUEST_SORT_ENGINEERING:    return SKILL_ENGINEERING;
        case QUEST_SORT_TAILORING:      return SKILL_TAILORING;
        case QUEST_SORT_COOKING:        return SKILL_COOKING;
        case QUEST_SORT_FIRST_AID:      return SKILL_FIRST_AID;
        case QUEST_SORT_JEWELCRAFTING:  return SKILL_JEWELCRAFTING;
        case QUEST_SORT_INSCRIPTION:    return SKILL_INSCRIPTION;
    }
    return 0;
}

enum SkillCategory
{
    SKILL_CATEGORY_ATTRIBUTES    = 5,
    SKILL_CATEGORY_WEAPON        = 6,
    SKILL_CATEGORY_CLASS         = 7,
    SKILL_CATEGORY_ARMOR         = 8,
    SKILL_CATEGORY_SECONDARY     = 9,                       // secondary professions
    SKILL_CATEGORY_LANGUAGES     = 10,
    SKILL_CATEGORY_PROFESSION    = 11,                      // primary professions
    SKILL_CATEGORY_GENERIC       = 12
};

enum TotemCategory
{
    TC_SKINNING_SKIFE_OLD          = 1,
    TC_EARTH_TOTEM                 = 2,
    TC_AIR_TOTEM                   = 3,
    TC_FIRE_TOTEM                  = 4,
    TC_WATER_TOTEM                 = 5,
    TC_COPPER_ROD                  = 6,
    TC_SILVER_ROD                  = 7,
    TC_GOLDEN_ROD                  = 8,
    TC_TRUESILVER_ROD              = 9,
    TC_ARCANITE_ROD                = 10,
    TC_MINING_PICK_OLD             = 11,
    TC_PHILOSOPHERS_STONE          = 12,
    TC_BLACKSMITH_HAMMER_OLD       = 13,
    TC_ARCLIGHT_SPANNER            = 14,
    TC_GYROMATIC_MA                = 15,
    TC_MASTER_TOTEM                = 21,
    TC_FEL_IRON_ROD                = 41,
    TC_ADAMANTITE_ROD              = 62,
    TC_ETERNIUM_ROD                = 63,
    TC_HOLLOW_QUILL                = 81,
    TC_RUNED_AZURITE_ROD           = 101,
    TC_VIRTUOSO_INKING_SET         = 121,
    TC_DRUMS                       = 141,
    TC_GNOMISH_ARMY_KNIFE          = 161,
    TC_BLACKSMITH_HAMMER           = 162,
    TC_MINING_PICK                 = 165,
    TC_SKINNING_KNIFE              = 166,
    TC_HAMMER_PICK                 = 167,
    TC_BLADED_PICKAXE              = 168,
    TC_FLINT_AND_TINDER            = 169,
    TC_RUNED_COBALT_ROD            = 189,
    TC_RUNED_TITANIUM_ROD          = 190
};

enum UnitDynFlags
{
    UNIT_DYNFLAG_NONE                       = 0x0000,
    UNIT_DYNFLAG_LOOTABLE                   = 0x0001,
    UNIT_DYNFLAG_TRACK_UNIT                 = 0x0002,
    UNIT_DYNFLAG_TAPPED                     = 0x0004,       // Lua_UnitIsTapped
    UNIT_DYNFLAG_TAPPED_BY_PLAYER           = 0x0008,       // Lua_UnitIsTappedByPlayer
    UNIT_DYNFLAG_SPECIALINFO                = 0x0010,
    UNIT_DYNFLAG_DEAD                       = 0x0020,
    UNIT_DYNFLAG_REFER_A_FRIEND             = 0x0040,
    UNIT_DYNFLAG_TAPPED_BY_ALL_THREAT_LIST  = 0x0080        // Lua_UnitIsTappedByAllThreatList
};

enum CorpseDynFlags
{
    CORPSE_DYNFLAG_LOOTABLE        = 0x0001
};

#define PLAYER_CORPSE_LOOT_ENTRY 1

// EnumUtils: DESCRIBE THIS
enum WeatherType
{
    WEATHER_TYPE_FINE       = 0,
    WEATHER_TYPE_RAIN       = 1,
    WEATHER_TYPE_SNOW       = 2,
    WEATHER_TYPE_STORM      = 3,
    WEATHER_TYPE_THUNDERS   = 86,
    WEATHER_TYPE_BLACKRAIN  = 90
};

#define MAX_WEATHER_TYPE 4

// EnumUtils: DESCRIBE THIS
enum ChatMsg : uint8
{
    CHAT_MSG_ADDON                  = 0xFF, // -1
    CHAT_MSG_SYSTEM                 = 0x00,
    CHAT_MSG_SAY                    = 0x01,
    CHAT_MSG_PARTY                  = 0x02,
    CHAT_MSG_RAID                   = 0x03,
    CHAT_MSG_GUILD                  = 0x04,
    CHAT_MSG_OFFICER                = 0x05,
    CHAT_MSG_YELL                   = 0x06,
    CHAT_MSG_WHISPER                = 0x07,
    CHAT_MSG_WHISPER_FOREIGN        = 0x08,
    CHAT_MSG_WHISPER_INFORM         = 0x09,
    CHAT_MSG_EMOTE                  = 0x0A,
    CHAT_MSG_TEXT_EMOTE             = 0x0B,
    CHAT_MSG_MONSTER_SAY            = 0x0C,
    CHAT_MSG_MONSTER_PARTY          = 0x0D,
    CHAT_MSG_MONSTER_YELL           = 0x0E,
    CHAT_MSG_MONSTER_WHISPER        = 0x0F,
    CHAT_MSG_MONSTER_EMOTE          = 0x10,
    CHAT_MSG_CHANNEL                = 0x11,
    CHAT_MSG_CHANNEL_JOIN           = 0x12,
    CHAT_MSG_CHANNEL_LEAVE          = 0x13,
    CHAT_MSG_CHANNEL_LIST           = 0x14,
    CHAT_MSG_CHANNEL_NOTICE         = 0x15,
    CHAT_MSG_CHANNEL_NOTICE_USER    = 0x16,
    CHAT_MSG_AFK                    = 0x17,
    CHAT_MSG_DND                    = 0x18,
    CHAT_MSG_IGNORED                = 0x19,
    CHAT_MSG_SKILL                  = 0x1A,
    CHAT_MSG_LOOT                   = 0x1B,
    CHAT_MSG_MONEY                  = 0x1C,
    CHAT_MSG_OPENING                = 0x1D,
    CHAT_MSG_TRADESKILLS            = 0x1E,
    CHAT_MSG_PET_INFO               = 0x1F,
    CHAT_MSG_COMBAT_MISC_INFO       = 0x20,
    CHAT_MSG_COMBAT_XP_GAIN         = 0x21,
    CHAT_MSG_COMBAT_HONOR_GAIN      = 0x22,
    CHAT_MSG_COMBAT_FACTION_CHANGE  = 0x23,
    CHAT_MSG_BG_SYSTEM_NEUTRAL      = 0x24,
    CHAT_MSG_BG_SYSTEM_ALLIANCE     = 0x25,
    CHAT_MSG_BG_SYSTEM_HORDE        = 0x26,
    CHAT_MSG_RAID_LEADER            = 0x27,
    CHAT_MSG_RAID_WARNING           = 0x28,
    CHAT_MSG_RAID_BOSS_EMOTE        = 0x29,
    CHAT_MSG_RAID_BOSS_WHISPER      = 0x2A,
    CHAT_MSG_FILTERED               = 0x2B,
    CHAT_MSG_BATTLEGROUND           = 0x2C,
    CHAT_MSG_BATTLEGROUND_LEADER    = 0x2D,
    CHAT_MSG_RESTRICTED             = 0x2E,
    CHAT_MSG_BATTLENET              = 0x2F,
    CHAT_MSG_ACHIEVEMENT            = 0x30,
    CHAT_MSG_GUILD_ACHIEVEMENT      = 0x31,
    CHAT_MSG_ARENA_POINTS           = 0x32,
    CHAT_MSG_PARTY_LEADER           = 0x33
};

#define MAX_CHAT_MSG_TYPE 0x34

enum ChatLinkColors : uint32
{
    CHAT_LINK_COLOR_TRADE       = 0xffffd000,   // orange
    CHAT_LINK_COLOR_TALENT      = 0xff4e96f7,   // blue
    CHAT_LINK_COLOR_SPELL       = 0xff71d5ff,   // bright blue
    CHAT_LINK_COLOR_ENCHANT     = 0xffffd000,   // orange
    CHAT_LINK_COLOR_ACHIEVEMENT = 0xffffff00,
    CHAT_LINK_COLOR_GLYPH       = 0xff66bbff
};

// Values from ItemPetFood (power of (value-1) used for compare with CreatureFamilyEntry.PetFoodMask
enum PetDiet
{
    PET_DIET_MEAT       = 1,
    PET_DIET_FISH       = 2,
    PET_DIET_CHEESE     = 3,
    PET_DIET_BREAD      = 4,
    PET_DIET_FUNGAS     = 5,
    PET_DIET_FRUIT      = 6,
    PET_DIET_RAW_MEAT   = 7,
    PET_DIET_RAW_FISH   = 8
};

#define MAX_PET_DIET 9

#define CHAIN_SPELL_JUMP_RADIUS 8

enum GuildLogs
{
    GUILD_BANKLOG_MAX_RECORDS   = 25,
    GUILD_EVENTLOG_MAX_RECORDS  = 100,
};

enum AiReaction
{
    AI_REACTION_ALERT    = 0,                               // pre-aggro (used in client packet handler)
    AI_REACTION_FRIENDLY = 1,                               // (NOT used in client packet handler)
    AI_REACTION_HOSTILE  = 2,                               // sent on every attack, triggers aggro sound (used in client packet handler)
    AI_REACTION_AFRAID   = 3,                               // seen for polymorph (when AI not in control of self?) (NOT used in client packet handler)
    AI_REACTION_DESTROY  = 4                                // used on object destroy (NOT used in client packet handler)
};

// Diminishing Returns Types
enum DiminishingReturnsType
{
    DRTYPE_NONE         = 0,                                // this spell is not diminished, but may have limited it's duration to 10s
    DRTYPE_PLAYER       = 1,                                // this spell is diminished only when applied on players
    DRTYPE_ALL          = 2                                 // this spell is diminished in every case
};

// Diminishing Return Groups
enum DiminishingGroup : uint16
{
    DIMINISHING_NONE                = 0,
    DIMINISHING_BANISH              = 1,
    DIMINISHING_CHARGE              = 2,
    DIMINISHING_OPENING_STUN        = 3, // Cheap Shot and Pounce
    DIMINISHING_CONTROLLED_STUN     = 4,
    DIMINISHING_CONTROLLED_ROOT     = 5,
    DIMINISHING_CYCLONE             = 6,
    DIMINISHING_DISARM              = 7,
    DIMINISHING_DISORIENT           = 8, // Several spells where name cant be generalized.
    DIMINISHING_ENTRAPMENT          = 9,
    DIMINISHING_FEAR                = 10,
    DIMINISHING_HORROR              = 11,
    DIMINISHING_MIND_CONTROL        = 12,
    DIMINISHING_ROOT                = 13,
    DIMINISHING_STUN                = 14,
    DIMINISHING_SCATTER_SHOT        = 15,
    DIMINISHING_SILENCE             = 16,
    DIMINISHING_SLEEP               = 17,
    DIMINISHING_TAUNT               = 18,
    DIMINISHING_LIMITONLY           = 19,
    DIMINISHING_DRAGONS_BREATH      = 20,

    DIMINISHING_MAX
};

enum SummonCategory
{
    SUMMON_CATEGORY_WILD        = 0,
    SUMMON_CATEGORY_ALLY        = 1,
    SUMMON_CATEGORY_PET         = 2,
    SUMMON_CATEGORY_PUPPET      = 3,
    SUMMON_CATEGORY_VEHICLE     = 4,
    SUMMON_CATEGORY_UNK         = 5  // as of patch 3.3.5a only Bone Spike in Icecrown Citadel
                                     // uses this category
};

enum SummonType
{
    SUMMON_TYPE_NONE        = 0,
    SUMMON_TYPE_PET         = 1,
    SUMMON_TYPE_GUARDIAN    = 2,
    SUMMON_TYPE_MINION      = 3,
    SUMMON_TYPE_TOTEM       = 4,
    SUMMON_TYPE_MINIPET     = 5,
    SUMMON_TYPE_GUARDIAN2   = 6,
    SUMMON_TYPE_WILD2       = 7,
    SUMMON_TYPE_WILD3       = 8,    // Related to phases and DK prequest line (3.3.5a)
    SUMMON_TYPE_VEHICLE     = 9,
    SUMMON_TYPE_VEHICLE2    = 10,   // Oculus and Argent Tournament vehicles (3.3.5a)
    SUMMON_TYPE_LIGHTWELL   = 11,
    SUMMON_TYPE_JEEVES      = 12
};

enum SummonSlot
{
    SUMMON_SLOT_PET                 = 0,
    SUMMON_SLOT_TOTEM_FIRE          = 1,
    SUMMON_SLOT_TOTEM_EARTH         = 2,
    SUMMON_SLOT_TOTEM_WATER         = 3,
    SUMMON_SLOT_TOTEM_AIR           = 4,
    SUMMON_SLOT_MINIPET             = 5,
    SUMMON_SLOT_QUEST               = 6,

    MAX_SUMMON_SLOT
};

#define MAX_TOTEM_SLOT      5
#define MAX_GAMEOBJECT_SLOT 4

enum EventId
{
    EVENT_CHARGE            = 1003,
    EVENT_JUMP              = 1004,

    /// Special charge event which is used for charge spells that have explicit targets
    /// and had a path already generated - using it in PointMovementGenerator will not
    /// create a new spline and launch it
    EVENT_CHARGE_PREPATH    = 1005,

    EVENT_FACE              = 1006,
    EVENT_VEHICLE_BOARD     = 1007,
    EVENT_VEHICLE_EXIT      = 1008,
    EVENT_ASSIST_MOVE       = 1009,
};

enum ResponseCodes
{
    RESPONSE_SUCCESS                                       = 0,
    RESPONSE_FAILURE                                       = 1,
    RESPONSE_CANCELLED                                     = 2,
    RESPONSE_DISCONNECTED                                  = 3,
    RESPONSE_FAILED_TO_CONNECT                             = 4,
    RESPONSE_CONNECTED                                     = 5,
    RESPONSE_VERSION_MISMATCH                              = 6,

    CSTATUS_CONNECTING                                     = 7,
    CSTATUS_NEGOTIATING_SECURITY                           = 8,
    CSTATUS_NEGOTIATION_COMPLETE                           = 9,
    CSTATUS_NEGOTIATION_FAILED                             = 10,
    CSTATUS_AUTHENTICATING                                 = 11,

    AUTH_OK                                                = 12,
    AUTH_FAILED                                            = 13,
    AUTH_REJECT                                            = 14,
    AUTH_BAD_SERVER_PROOF                                  = 15,
    AUTH_UNAVAILABLE                                       = 16,
    AUTH_SYSTEM_ERROR                                      = 17,
    AUTH_BILLING_ERROR                                     = 18,
    AUTH_BILLING_EXPIRED                                   = 19,
    AUTH_VERSION_MISMATCH                                  = 20,
    AUTH_UNKNOWN_ACCOUNT                                   = 21,
    AUTH_INCORRECT_PASSWORD                                = 22,
    AUTH_SESSION_EXPIRED                                   = 23,
    AUTH_SERVER_SHUTTING_DOWN                              = 24,
    AUTH_ALREADY_LOGGING_IN                                = 25,
    AUTH_LOGIN_SERVER_NOT_FOUND                            = 26,
    AUTH_WAIT_QUEUE                                        = 27,
    AUTH_BANNED                                            = 28,
    AUTH_ALREADY_ONLINE                                    = 29,
    AUTH_NO_TIME                                           = 30,
    AUTH_DB_BUSY                                           = 31,
    AUTH_SUSPENDED                                         = 32,
    AUTH_PARENTAL_CONTROL                                  = 33,
    AUTH_LOCKED_ENFORCED                                   = 34,

    REALM_LIST_IN_PROGRESS                                 = 35,
    REALM_LIST_SUCCESS                                     = 36,
    REALM_LIST_FAILED                                      = 37,
    REALM_LIST_INVALID                                     = 38,
    REALM_LIST_REALM_NOT_FOUND                             = 39,

    ACCOUNT_CREATE_IN_PROGRESS                             = 40,
    ACCOUNT_CREATE_SUCCESS                                 = 41,
    ACCOUNT_CREATE_FAILED                                  = 42,

    CHAR_LIST_RETRIEVING                                   = 43,
    CHAR_LIST_RETRIEVED                                    = 44,
    CHAR_LIST_FAILED                                       = 45,

    CHAR_CREATE_IN_PROGRESS                                = 46,
    CHAR_CREATE_SUCCESS                                    = 47,
    CHAR_CREATE_ERROR                                      = 48,
    CHAR_CREATE_FAILED                                     = 49,
    CHAR_CREATE_NAME_IN_USE                                = 50,
    CHAR_CREATE_DISABLED                                   = 51,
    CHAR_CREATE_PVP_TEAMS_VIOLATION                        = 52,
    CHAR_CREATE_SERVER_LIMIT                               = 53,
    CHAR_CREATE_ACCOUNT_LIMIT                              = 54,
    CHAR_CREATE_SERVER_QUEUE                               = 55,
    CHAR_CREATE_ONLY_EXISTING                              = 56,
    CHAR_CREATE_EXPANSION                                  = 57,
    CHAR_CREATE_EXPANSION_CLASS                            = 58,
    CHAR_CREATE_LEVEL_REQUIREMENT                          = 59,
    CHAR_CREATE_UNIQUE_CLASS_LIMIT                         = 60,
    CHAR_CREATE_CHARACTER_IN_GUILD                         = 61,
    CHAR_CREATE_RESTRICTED_RACECLASS                       = 62,
    CHAR_CREATE_CHARACTER_CHOOSE_RACE                      = 63,
    CHAR_CREATE_CHARACTER_ARENA_LEADER                     = 64,
    CHAR_CREATE_CHARACTER_DELETE_MAIL                      = 65,
    CHAR_CREATE_CHARACTER_SWAP_FACTION                     = 66,
    CHAR_CREATE_CHARACTER_RACE_ONLY                        = 67,
    CHAR_CREATE_CHARACTER_GOLD_LIMIT                       = 68,
    CHAR_CREATE_FORCE_LOGIN                                = 69,

    CHAR_DELETE_IN_PROGRESS                                = 70,
    CHAR_DELETE_SUCCESS                                    = 71,
    CHAR_DELETE_FAILED                                     = 72,
    CHAR_DELETE_FAILED_LOCKED_FOR_TRANSFER                 = 73,
    CHAR_DELETE_FAILED_GUILD_LEADER                        = 74,
    CHAR_DELETE_FAILED_ARENA_CAPTAIN                       = 75,

    CHAR_LOGIN_IN_PROGRESS                                 = 76,
    CHAR_LOGIN_SUCCESS                                     = 77,
    CHAR_LOGIN_NO_WORLD                                    = 78,
    CHAR_LOGIN_DUPLICATE_CHARACTER                         = 79,
    CHAR_LOGIN_NO_INSTANCES                                = 80,
    CHAR_LOGIN_FAILED                                      = 81,
    CHAR_LOGIN_DISABLED                                    = 82,
    CHAR_LOGIN_NO_CHARACTER                                = 83,
    CHAR_LOGIN_LOCKED_FOR_TRANSFER                         = 84,
    CHAR_LOGIN_LOCKED_BY_BILLING                           = 85,
    CHAR_LOGIN_LOCKED_BY_MOBILE_AH                         = 86,

    CHAR_NAME_SUCCESS                                      = 87,
    CHAR_NAME_FAILURE                                      = 88,
    CHAR_NAME_NO_NAME                                      = 89,
    CHAR_NAME_TOO_SHORT                                    = 90,
    CHAR_NAME_TOO_LONG                                     = 91,
    CHAR_NAME_INVALID_CHARACTER                            = 92,
    CHAR_NAME_MIXED_LANGUAGES                              = 93,
    CHAR_NAME_PROFANE                                      = 94,
    CHAR_NAME_RESERVED                                     = 95,
    CHAR_NAME_INVALID_APOSTROPHE                           = 96,
    CHAR_NAME_MULTIPLE_APOSTROPHES                         = 97,
    CHAR_NAME_THREE_CONSECUTIVE                            = 98,
    CHAR_NAME_INVALID_SPACE                                = 99,
    CHAR_NAME_CONSECUTIVE_SPACES                           = 100,
    CHAR_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS        = 101,
    CHAR_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END = 102,
    CHAR_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME            = 103
};

enum ComplaintStatus : uint8
{
    COMPLAINT_DISABLED                      = 0,
    COMPLAINT_ENABLED_WITHOUT_AUTO_IGNORE   = 1,
    COMPLAINT_ENABLED_WITH_AUTO_IGNORE      = 2
};

/// Ban function modes
enum BanMode
{
    BAN_ACCOUNT,
    BAN_CHARACTER,
    BAN_IP
};

/// Ban function return codes
enum BanReturn
{
    BAN_SUCCESS,
    BAN_SYNTAX_ERROR,
    BAN_NOTFOUND,
    BAN_EXISTS
};

enum PvPTeamId
{
    PVP_TEAM_HORDE       = 0, // Battleground: Horde,    Arena: Green
    PVP_TEAM_ALLIANCE    = 1, // Battleground: Alliance, Arena: Gold
    PVP_TEAM_NEUTRAL     = 2  // Battleground: Neutral,  Arena: None
};

uint8 constexpr PVP_TEAMS_COUNT = 2;

// indexes of BattlemasterList.dbc
enum BattlegroundTypeId : uint32
{
    BATTLEGROUND_TYPE_NONE      = 0, // None
    BATTLEGROUND_AV             = 1, // Alterac Valley
    BATTLEGROUND_WS             = 2, // Warsong Gulch
    BATTLEGROUND_AB             = 3, // Arathi Basin
    BATTLEGROUND_NA             = 4, // Nagrand Arena
    BATTLEGROUND_BE             = 5, // Blade's Edge Arena
    BATTLEGROUND_AA             = 6, // All Arenas
    BATTLEGROUND_EY             = 7, // Eye of the Storm
    BATTLEGROUND_RL             = 8, // Ruins of Lordaernon
    BATTLEGROUND_SA             = 9, // Strand of the Ancients
    BATTLEGROUND_DS             = 10, // Dalaran Sewers
    BATTLEGROUND_RV             = 11, // Ring of Valor
    BATTLEGROUND_IC             = 30, // Isle of Conquest
    BATTLEGROUND_RB             = 32  // Random Battleground
};

#define MAX_BATTLEGROUND_TYPE_ID 33

enum BattlefieldBattleId : uint8
{
    BATTLEFIELD_BATTLEID_WINTERGRASP = 1, // Wintergrasp battle
    BATTLEFIELD_BATTLEID_MAX = 2
};

enum MailResponseType
{
    MAIL_SEND               = 0,
    MAIL_MONEY_TAKEN        = 1,
    MAIL_ITEM_TAKEN         = 2,
    MAIL_RETURNED_TO_SENDER = 3,
    MAIL_DELETED            = 4,
    MAIL_MADE_PERMANENT     = 5
};

enum MailResponseResult
{
    MAIL_OK                            = 0,
    MAIL_ERR_EQUIP_ERROR               = 1,
    MAIL_ERR_CANNOT_SEND_TO_SELF       = 2,
    MAIL_ERR_NOT_ENOUGH_MONEY          = 3,
    MAIL_ERR_RECIPIENT_NOT_FOUND       = 4,
    MAIL_ERR_NOT_YOUR_TEAM             = 5,
    MAIL_ERR_INTERNAL_ERROR            = 6,
    MAIL_ERR_DISABLED_FOR_TRIAL_ACC    = 14,
    MAIL_ERR_RECIPIENT_CAP_REACHED     = 15,
    MAIL_ERR_CANT_SEND_WRAPPED_COD     = 16,
    MAIL_ERR_MAIL_AND_CHAT_SUSPENDED   = 17,
    MAIL_ERR_TOO_MANY_ATTACHMENTS      = 18,
    MAIL_ERR_MAIL_ATTACHMENT_INVALID   = 19,
    MAIL_ERR_ITEM_HAS_EXPIRED          = 21
};

enum PetTameFailure
{
    PETTAME_INVALIDCREATURE         = 1,
    PETTAME_TOOMANY                 = 2,
    PETTAME_CREATUREALREADYOWNED    = 3,
    PETTAME_NOTTAMEABLE             = 4,
    PETTAME_ANOTHERSUMMONACTIVE     = 5,
    PETTAME_UNITSCANTTAME           = 6,
    PETTAME_NOPETAVAILABLE          = 7,
    PETTAME_INTERNALERROR           = 8,
    PETTAME_TOOHIGHLEVEL            = 9,
    PETTAME_DEAD                    = 10,
    PETTAME_NOTDEAD                 = 11,
    PETTAME_CANTCONTROLEXOTIC       = 12,
    PETTAME_UNKNOWNERROR            = 13
};

// EnumUtils: DESCRIBE THIS
enum SpellFamilyNames
{
    SPELLFAMILY_GENERIC     = 0,  // TITLE Generic
    SPELLFAMILY_UNK1        = 1,  // TITLE Unk1 (events, holidays, ...)
    // 2 - unused
    SPELLFAMILY_MAGE        = 3,  // TITLE Mage
    SPELLFAMILY_WARRIOR     = 4,  // TITLE Warrior
    SPELLFAMILY_WARLOCK     = 5,  // TITLE Warlock
    SPELLFAMILY_PRIEST      = 6,  // TITLE Priest
    SPELLFAMILY_DRUID       = 7,  // TITLE Druid
    SPELLFAMILY_ROGUE       = 8,  // TITLE Rogue
    SPELLFAMILY_HUNTER      = 9,  // TITLE Hunter
    SPELLFAMILY_PALADIN     = 10, // TITLE Paladin
    SPELLFAMILY_SHAMAN      = 11, // TITLE Shaman
    SPELLFAMILY_UNK2        = 12, // TITLE Unk2 (Silence resistance?)
    SPELLFAMILY_POTION      = 13, // TITLE Potion
    // 14 - unused
    SPELLFAMILY_DEATHKNIGHT = 15, // TITLE Death Knight
    // 16 - unused
    SPELLFAMILY_PET         = 17  // TITLE Pet
};

enum TradeStatus
{
    TRADE_STATUS_BUSY           = 0,
    TRADE_STATUS_BEGIN_TRADE    = 1,
    TRADE_STATUS_OPEN_WINDOW    = 2,
    TRADE_STATUS_TRADE_CANCELED = 3,
    TRADE_STATUS_TRADE_ACCEPT   = 4,
    TRADE_STATUS_BUSY_2         = 5,
    TRADE_STATUS_NO_TARGET      = 6,
    TRADE_STATUS_BACK_TO_TRADE  = 7,
    TRADE_STATUS_TRADE_COMPLETE = 8,
    TRADE_STATUS_TRADE_REJECTED = 9,
    TRADE_STATUS_TARGET_TO_FAR  = 10,
    TRADE_STATUS_WRONG_FACTION  = 11,
    TRADE_STATUS_CLOSE_WINDOW   = 12,
    // 13?
    TRADE_STATUS_IGNORE_YOU     = 14,
    TRADE_STATUS_YOU_STUNNED    = 15,
    TRADE_STATUS_TARGET_STUNNED = 16,
    TRADE_STATUS_YOU_DEAD       = 17,
    TRADE_STATUS_TARGET_DEAD    = 18,
    TRADE_STATUS_YOU_LOGOUT     = 19,
    TRADE_STATUS_TARGET_LOGOUT  = 20,
    TRADE_STATUS_TRIAL_ACCOUNT  = 21,                       // Trial accounts can not perform that action
    TRADE_STATUS_WRONG_REALM    = 22,                       // You can only trade conjured items... (cross realm BG related).
    TRADE_STATUS_NOT_ON_TAPLIST = 23                        // Related to trading soulbound loot items
};

enum XPColorChar : uint8
{
    XP_RED,
    XP_ORANGE,
    XP_YELLOW,
    XP_GREEN,
    XP_GRAY
};

enum RemoveMethod : uint8
{
    GROUP_REMOVEMETHOD_DEFAULT  = 0,
    GROUP_REMOVEMETHOD_KICK     = 1,
    GROUP_REMOVEMETHOD_LEAVE    = 2,
    GROUP_REMOVEMETHOD_KICK_LFG = 3
};

enum ActivateTaxiReply
{
    ERR_TAXIOK                      = 0,
    ERR_TAXIUNSPECIFIEDSERVERERROR  = 1,
    ERR_TAXINOSUCHPATH              = 2,
    ERR_TAXINOTENOUGHMONEY          = 3,
    ERR_TAXITOOFARAWAY              = 4,
    ERR_TAXINOVENDORNEARBY          = 5,
    ERR_TAXINOTVISITED              = 6,
    ERR_TAXIPLAYERBUSY              = 7,
    ERR_TAXIPLAYERALREADYMOUNTED    = 8,
    ERR_TAXIPLAYERSHAPESHIFTED      = 9,
    ERR_TAXIPLAYERMOVING            = 10,
    ERR_TAXISAMENODE                = 11,
    ERR_TAXINOTSTANDING             = 12
};

enum DuelCompleteType : uint8
{
    DUEL_INTERRUPTED = 0,
    DUEL_WON         = 1,
    DUEL_FLED        = 2
};

struct BattlegroundQueueTypeId
{
    uint16 BattlemasterListId;
    uint8 BracketId;
    uint8 TeamSize;

    static constexpr BattlegroundQueueTypeId FromPacked(uint64 packedQueueId)
    {
        return { .BattlemasterListId = uint16((packedQueueId >> 16) & 0xFFFF), .BracketId = uint8((packedQueueId >> 8) & 0x7F), .TeamSize = uint8(packedQueueId & 0x7F) };
    }

    constexpr uint64 GetPacked() const
    {
        return (uint64(BattlemasterListId) << 16)
            | (uint64(BracketId & 0xFF) << 8)
            | (uint64(TeamSize & 0x3F))
            | UI64LIT(0x1F90000000000000);
    }

    constexpr bool operator==(BattlegroundQueueTypeId const& right) const = default;

    constexpr std::strong_ordering operator<=>(BattlegroundQueueTypeId const& right) const = default;
};

constexpr BattlegroundQueueTypeId BATTLEGROUND_QUEUE_NONE = { 0, 0, 0 };

enum GroupJoinBattlegroundResult
{
    // positive values are indexes in BattlemasterList.dbc
    ERR_GROUP_JOIN_BATTLEGROUND_FAIL        = 0,            // Your group has joined a battleground queue, but you are not eligible (showed for non existing BattlemasterList.dbc indexes)
    ERR_BATTLEGROUND_NONE                   = -1,           // not show anything
    ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS   = -2,           // You cannot join the battleground yet because you or one of your party members is flagged as a Deserter.
    ERR_ARENA_TEAM_PARTY_SIZE               = -3,           // Incorrect party size for this arena.
    ERR_BATTLEGROUND_TOO_MANY_QUEUES        = -4,           // You can only be queued for 2 battles at once
    ERR_BATTLEGROUND_CANNOT_QUEUE_FOR_RATED = -5,           // You cannot queue for a rated match while queued for other battles
    ERR_BATTLEDGROUND_QUEUED_FOR_RATED      = -6,           // You cannot queue for another battle while queued for a rated arena match
    ERR_BATTLEGROUND_TEAM_LEFT_QUEUE        = -7,           // Your team has left the arena queue
    ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND    = -8,           // You can't do that in a battleground.
    ERR_BATTLEGROUND_JOIN_XP_GAIN           = -9,           // wtf, doesn't exist in client...
    ERR_BATTLEGROUND_JOIN_RANGE_INDEX       = -10,          // Cannot join the queue unless all members of your party are in the same battleground level range.
    ERR_BATTLEGROUND_JOIN_TIMED_OUT         = -11,          // %s was unavailable to join the queue. (uint64 guid exist in client cache)
    ERR_BATTLEGROUND_JOIN_FAILED            = -12,          // Join as a group failed (uint64 guid doesn't exist in client cache)
    ERR_LFG_CANT_USE_BATTLEGROUND           = -13,          // You cannot queue for a battleground or arena while using the dungeon system.
    ERR_IN_RANDOM_BG                        = -14,          // Can't do that while in a Random Battleground queue.
    ERR_IN_NON_RANDOM_BG                    = -15           // Can't queue for Random Battleground while in another Battleground queue.
};

enum PetNameInvalidReason
{
    // custom, not send
    PET_NAME_SUCCESS                                        = 0,

    PET_NAME_INVALID                                        = 1,
    PET_NAME_NO_NAME                                        = 2,
    PET_NAME_TOO_SHORT                                      = 3,
    PET_NAME_TOO_LONG                                       = 4,
    PET_NAME_MIXED_LANGUAGES                                = 6,
    PET_NAME_PROFANE                                        = 7,
    PET_NAME_RESERVED                                       = 8,
    PET_NAME_THREE_CONSECUTIVE                              = 11,
    PET_NAME_INVALID_SPACE                                  = 12,
    PET_NAME_CONSECUTIVE_SPACES                             = 13,
    PET_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS          = 14,
    PET_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END   = 15,
    PET_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME              = 16
};

enum DungeonStatusFlag
{
    DUNGEON_STATUSFLAG_NORMAL = 0x01,
    DUNGEON_STATUSFLAG_HEROIC = 0x02,

    RAID_STATUSFLAG_10MAN_NORMAL = 0x01,
    RAID_STATUSFLAG_25MAN_NORMAL = 0x02,
    RAID_STATUSFLAG_10MAN_HEROIC = 0x04,
    RAID_STATUSFLAG_25MAN_HEROIC = 0x08
};

enum PartyResult
{
    ERR_PARTY_RESULT_OK                 = 0,
    ERR_BAD_PLAYER_NAME_S               = 1,
    ERR_TARGET_NOT_IN_GROUP_S           = 2,
    ERR_TARGET_NOT_IN_INSTANCE_S        = 3,
    ERR_GROUP_FULL                      = 4,
    ERR_ALREADY_IN_GROUP_S              = 5,
    ERR_NOT_IN_GROUP                    = 6,
    ERR_NOT_LEADER                      = 7,
    ERR_PLAYER_WRONG_FACTION            = 8,
    ERR_IGNORING_YOU_S                  = 9,
    ERR_LFG_PENDING                     = 12,
    ERR_INVITE_RESTRICTED               = 13,
    ERR_GROUP_SWAP_FAILED               = 14,               // if (PartyOperation == PARTY_OP_SWAP) ERR_GROUP_SWAP_FAILED else ERR_INVITE_IN_COMBAT
    ERR_INVITE_UNKNOWN_REALM            = 15,
    ERR_INVITE_NO_PARTY_SERVER          = 16,
    ERR_INVITE_PARTY_BUSY               = 17,
    ERR_PARTY_TARGET_AMBIGUOUS          = 18,
    ERR_PARTY_LFG_INVITE_RAID_LOCKED    = 19,
    ERR_PARTY_LFG_BOOT_LIMIT            = 20,
    ERR_PARTY_LFG_BOOT_COOLDOWN_S       = 21,
    ERR_PARTY_LFG_BOOT_IN_PROGRESS      = 22,
    ERR_PARTY_LFG_BOOT_TOO_FEW_PLAYERS  = 23,
    ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S   = 24,
    ERR_RAID_DISALLOWED_BY_LEVEL        = 25,
    ERR_PARTY_LFG_BOOT_IN_COMBAT        = 26,
    ERR_VOTE_KICK_REASON_NEEDED         = 27,
    ERR_PARTY_LFG_BOOT_DUNGEON_COMPLETE = 28,
    ERR_PARTY_LFG_BOOT_LOOT_ROLLS       = 29,
    ERR_PARTY_LFG_TELEPORT_IN_COMBAT    = 30
};

enum DiminishingLevels
{
    DIMINISHING_LEVEL_1             = 0,
    DIMINISHING_LEVEL_2             = 1,
    DIMINISHING_LEVEL_3             = 2,
    DIMINISHING_LEVEL_IMMUNE        = 3,
    DIMINISHING_LEVEL_4             = 3,
    DIMINISHING_LEVEL_TAUNT_IMMUNE  = 4
};

enum WeaponAttackType : uint8
{
    BASE_ATTACK   = 0,
    OFF_ATTACK    = 1,
    RANGED_ATTACK = 2,
    MAX_ATTACK
};

enum CharterTypes
{
    CHARTER_TYPE_NONE           = 0,
    CHARTER_TYPE_ANY            = 10,

    GUILD_CHARTER_TYPE          = 9,
    ARENA_TEAM_CHARTER_2v2_TYPE = 2,
    ARENA_TEAM_CHARTER_3v3_TYPE = 3,
    ARENA_TEAM_CHARTER_5v5_TYPE = 5
};

enum LineOfSightChecks
{
    LINEOFSIGHT_CHECK_VMAP      = 0x1, // check static floor layout data
    LINEOFSIGHT_CHECK_GOBJECT   = 0x2, // check dynamic game object data

    LINEOFSIGHT_ALL_CHECKS      = (LINEOFSIGHT_CHECK_VMAP | LINEOFSIGHT_CHECK_GOBJECT)
};

enum ServerProcessTypes
{
    SERVER_PROCESS_AUTHSERVER = 0,
    SERVER_PROCESS_WORLDSERVER = 1,

    NUM_SERVER_PROCESS_TYPES
};

enum class MountResult : uint32
{
    InvalidMountee = 0,
    TooFarAway     = 1,
    AlreadyMounted = 2,
    NotMountable   = 3,
    NotYourPet     = 4,
    Other          = 5,
    Looting        = 6,
    RaceCantMount  = 7,
    Shapeshifted   = 8,
    ForcedDismount = 9,
    Ok             = 10 // never sent
};

enum AreaId : uint32
{
    AREA_WINTERGRASP                = 4197,
    AREA_THE_SUNKEN_RING            = 4538,
    AREA_THE_BROKEN_TEMPLATE        = 4539,
    AREA_WINTERGRASP_FORTRESS       = 4575,
    AREA_THE_CHILLED_QUAGMIRE       = 4589,
    AREA_WESTPARK_WORKSHOP          = 4611,
    AREA_EASTPARK_WORKSHOP          = 4612,
};

enum WorldState : uint32
{
    WS_BATTLEFIELD_WG_VEHICLE_H        = 3490,
    WS_BATTLEFIELD_WG_MAX_VEHICLE_H    = 3491,
    WS_BATTLEFIELD_WG_VEHICLE_A        = 3680,
    WS_BATTLEFIELD_WG_MAX_VEHICLE_A    = 3681,
    WS_BATTLEFIELD_WG_WORKSHOP_K_W     = 3698,
    WS_BATTLEFIELD_WG_WORKSHOP_K_E     = 3699,
    WS_BATTLEFIELD_WG_WORKSHOP_NW      = 3700,
    WS_BATTLEFIELD_WG_WORKSHOP_NE      = 3701,
    WS_BATTLEFIELD_WG_WORKSHOP_SW      = 3702,
    WS_BATTLEFIELD_WG_WORKSHOP_SE      = 3703,
    WS_BATTLEFIELD_WG_SHOW_WORLDSTATE  = 3710,
    WS_BATTLEFIELD_WG_TIME_BATTLE_END  = 3781,
    WS_BATTLEFIELD_WG_ACTIVE           = 3801,
    WS_BATTLEFIELD_WG_DEFENDER         = 3802,
    WS_BATTLEFIELD_WG_ATTACKER         = 3803,
    WS_BATTLEFIELD_WG_ATTACKED_H       = 4022,
    WS_BATTLEFIELD_WG_ATTACKED_A       = 4023,
    WS_BATTLEFIELD_WG_DEFENDED_H       = 4024,
    WS_BATTLEFIELD_WG_DEFENDED_A       = 4025,
    WS_BATTLEFIELD_WG_TIME_NEXT_BATTLE = 4354,

    WS_ARENA_DISTRIBUTION_TIME  = 20001,                     // Next arena distribution time
    WS_WEEKLY_QUEST_RESET_TIME  = 20002,                     // Next weekly quest reset time
    WS_BG_DAILY_RESET_TIME      = 20003,                     // Next daily BG reset time
    WS_CLEANING_FLAGS           = 20004,                     // Cleaning Flags
    WS_GUILD_DAILY_RESET_TIME   = 20006,                     // Next guild cap reset time
    WS_MONTHLY_QUEST_RESET_TIME = 20007,                     // Next monthly quest reset time
    WS_DAILY_QUEST_RESET_TIME   = 20008,                     // Next daily quest reset time
    WS_DAILY_CALENDAR_DELETION_OLD_EVENTS_TIME = 20009,      // Next daily calendar deletions of old events time
};

namespace Trinity
{
namespace Impl
{
    struct TC_SHARED_API CurrentServerProcessHolder
    {
        static ServerProcessTypes type() { return _type; }
        static ServerProcessTypes _type;
    };
}
}
#define THIS_SERVER_PROCESS (Trinity::Impl::CurrentServerProcessHolder::type())

#define MAX_CREATURE_SPELL_DATA_SLOT 4

#endif
