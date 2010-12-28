#ifndef QDEFINES_H
#define QDEFINES_H

#include <QtCore/QString>

QString PreventionTypeString[] =
{
    QString("SPELL_PREVENTION_TYPE_NONE"),
    QString("SPELL_PREVENTION_TYPE_SILENCE"),
    QString("SPELL_PREVENTION_TYPE_PACIFY")
};

QString DmgClassString[] =
{
    QString("SPELL_DAMAGE_CLASS_NONE"),
    QString("SPELL_DAMAGE_CLASS_MAGIC"),
    QString("SPELL_DAMAGE_CLASS_MELEE"),
    QString("SPELL_DAMAGE_CLASS_RANGED")
};

QString SchoolString[] =
{
    QString("SPELL_SCHOOL_NORMAL"),
    QString("SPELL_SCHOOL_HOLY"),
    QString("SPELL_SCHOOL_FIRE"),
    QString("SPELL_SCHOOL_NATURE"),
    QString("SPELL_SCHOOL_FROST"),
    QString("SPELL_SCHOOL_SHADOW"),
    QString("SPELL_SCHOOL_ARCANE")
};

QString EffectString[] =
{
    QString("SPELL_EFFECT_NONE"),
    QString("SPELL_EFFECT_INSTAKILL"),
    QString("SPELL_EFFECT_SCHOOL_DAMAGE"),
    QString("SPELL_EFFECT_DUMMY"),
    QString("SPELL_EFFECT_PORTAL_TELEPORT"),
    QString("SPELL_EFFECT_TELEPORT_UNITS"),
    QString("SPELL_EFFECT_APPLY_AURA"),
    QString("SPELL_EFFECT_ENVIRONMENTAL_DAMAGE"),
    QString("SPELL_EFFECT_POWER_DRAIN"),
    QString("SPELL_EFFECT_HEALTH_LEECH"),
    QString("SPELL_EFFECT_HEAL"),
    QString("SPELL_EFFECT_BIND"),
    QString("SPELL_EFFECT_PORTAL"),
    QString("SPELL_EFFECT_RITUAL_BASE"),
    QString("SPELL_EFFECT_RITUAL_SPECIALIZE"),
    QString("SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL"),
    QString("SPELL_EFFECT_QUEST_COMPLETE"),
    QString("SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL"),
    QString("SPELL_EFFECT_RESURRECT"),
    QString("SPELL_EFFECT_ADD_EXTRA_ATTACKS"),
    QString("SPELL_EFFECT_DODGE"),
    QString("SPELL_EFFECT_EVADE"),
    QString("SPELL_EFFECT_PARRY"),
    QString("SPELL_EFFECT_BLOCK"),
    QString("SPELL_EFFECT_CREATE_ITEM"),
    QString("SPELL_EFFECT_WEAPON"),
    QString("SPELL_EFFECT_DEFENSE"),
    QString("SPELL_EFFECT_PERSISTENT_AREA_AURA"),
    QString("SPELL_EFFECT_SUMMON"),
    QString("SPELL_EFFECT_LEAP"),
    QString("SPELL_EFFECT_ENERGIZE"),
    QString("SPELL_EFFECT_WEAPON_PERCENT_DAMAGE"),
    QString("SPELL_EFFECT_TRIGGER_MISSILE"),
    QString("SPELL_EFFECT_OPEN_LOCK"),
    QString("SPELL_EFFECT_SUMMON_CHANGE_ITEM"),
    QString("SPELL_EFFECT_APPLY_AREA_AURA_PARTY"),
    QString("SPELL_EFFECT_LEARN_SPELL"),
    QString("SPELL_EFFECT_SPELL_DEFENSE"),
    QString("SPELL_EFFECT_DISPEL"),
    QString("SPELL_EFFECT_LANGUAGE"),
    QString("SPELL_EFFECT_DUAL_WIELD"),
    QString("SPELL_EFFECT_SUMMON_WILD"),
    QString("SPELL_EFFECT_SUMMON_GUARDIAN"),
    QString("SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER"),
    QString("SPELL_EFFECT_SKILL_STEP"),
    QString("SPELL_EFFECT_ADD_HONOR"),
    QString("SPELL_EFFECT_SPAWN"),
    QString("SPELL_EFFECT_TRADE_SKILL"),
    QString("SPELL_EFFECT_STEALTH"),
    QString("SPELL_EFFECT_DETECT"),
    QString("SPELL_EFFECT_TRANS_DOOR"),
    QString("SPELL_EFFECT_FORCE_CRITICAL_HIT"),
    QString("SPELL_EFFECT_GUARANTEE_HIT"),
    QString("SPELL_EFFECT_ENCHANT_ITEM"),
    QString("SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY"),
    QString("SPELL_EFFECT_TAMECREATURE"),
    QString("SPELL_EFFECT_SUMMON_PET"),
    QString("SPELL_EFFECT_LEARN_PET_SPELL"),
    QString("SPELL_EFFECT_WEAPON_DAMAGE"),
    QString("SPELL_EFFECT_OPEN_LOCK_ITEM"),
    QString("SPELL_EFFECT_PROFICIENCY"),
    QString("SPELL_EFFECT_SEND_EVENT"),
    QString("SPELL_EFFECT_POWER_BURN"),
    QString("SPELL_EFFECT_THREAT"),
    QString("SPELL_EFFECT_TRIGGER_SPELL"),
    QString("SPELL_EFFECT_HEALTH_FUNNEL"),
    QString("SPELL_EFFECT_POWER_FUNNEL"),
    QString("SPELL_EFFECT_HEAL_MAX_HEALTH"),
    QString("SPELL_EFFECT_INTERRUPT_CAST"),
    QString("SPELL_EFFECT_DISTRACT"),
    QString("SPELL_EFFECT_PULL"),
    QString("SPELL_EFFECT_PICKPOCKET"),
    QString("SPELL_EFFECT_ADD_FARSIGHT"),
    QString("SPELL_EFFECT_SUMMON_POSSESSED"),
    QString("SPELL_EFFECT_SUMMON_TOTEM"),
    QString("SPELL_EFFECT_HEAL_MECHANICAL"),
    QString("SPELL_EFFECT_SUMMON_OBJECT_WILD"),
    QString("SPELL_EFFECT_SCRIPT_EFFECT"),
    QString("SPELL_EFFECT_ATTACK"),
    QString("SPELL_EFFECT_SANCTUARY"),
    QString("SPELL_EFFECT_ADD_COMBO_POINTS"),
    QString("SPELL_EFFECT_CREATE_HOUSE"),
    QString("SPELL_EFFECT_BIND_SIGHT"),
    QString("SPELL_EFFECT_DUEL"),
    QString("SPELL_EFFECT_STUCK"),
    QString("SPELL_EFFECT_SUMMON_PLAYER"),
    QString("SPELL_EFFECT_ACTIVATE_OBJECT"),
    QString("SPELL_EFFECT_SUMMON_TOTEM_SLOT1"),
    QString("SPELL_EFFECT_SUMMON_TOTEM_SLOT2"),
    QString("SPELL_EFFECT_SUMMON_TOTEM_SLOT3"),
    QString("SPELL_EFFECT_SUMMON_TOTEM_SLOT4"),
    QString("SPELL_EFFECT_THREAT_ALL"),
    QString("SPELL_EFFECT_ENCHANT_HELD_ITEM"),
    QString("SPELL_EFFECT_SUMMON_PHANTASM"),
    QString("SPELL_EFFECT_SELF_RESURRECT"),
    QString("SPELL_EFFECT_SKINNING"),
    QString("SPELL_EFFECT_CHARGE"),
    QString("SPELL_EFFECT_SUMMON_CRITTER"),
    QString("SPELL_EFFECT_KNOCK_BACK"),
    QString("SPELL_EFFECT_DISENCHANT"),
    QString("SPELL_EFFECT_INEBRIATE"),
    QString("SPELL_EFFECT_FEED_PET"),
    QString("SPELL_EFFECT_DISMISS_PET"),
    QString("SPELL_EFFECT_REPUTATION"),
    QString("SPELL_EFFECT_SUMMON_OBJECT_SLOT1"),
    QString("SPELL_EFFECT_SUMMON_OBJECT_SLOT2"),
    QString("SPELL_EFFECT_SUMMON_OBJECT_SLOT3"),
    QString("SPELL_EFFECT_SUMMON_OBJECT_SLOT4"),
    QString("SPELL_EFFECT_DISPEL_MECHANIC"),
    QString("SPELL_EFFECT_SUMMON_DEAD_PET"),
    QString("SPELL_EFFECT_DESTROY_ALL_TOTEMS"),
    QString("SPELL_EFFECT_DURABILITY_DAMAGE"),
    QString("SPELL_EFFECT_SUMMON_DEMON"),
    QString("SPELL_EFFECT_RESURRECT_NEW"),
    QString("SPELL_EFFECT_ATTACK_ME"),
    QString("SPELL_EFFECT_DURABILITY_DAMAGE_PCT"),
    QString("SPELL_EFFECT_SKIN_PLAYER_CORPSE"),
    QString("SPELL_EFFECT_SPIRIT_HEAL"),
    QString("SPELL_EFFECT_SKILL"),
    QString("SPELL_EFFECT_APPLY_AREA_AURA_PET"),
    QString("SPELL_EFFECT_TELEPORT_GRAVEYARD"),
    QString("SPELL_EFFECT_NORMALIZED_WEAPON_DMG"),
    QString("SPELL_EFFECT_122"),
    QString("SPELL_EFFECT_SEND_TAXI"),
    QString("SPELL_EFFECT_PLAYER_PULL"),
    QString("SPELL_EFFECT_MODIFY_THREAT_PERCENT"),
    QString("SPELL_EFFECT_126"),
    QString("SPELL_EFFECT_127"),
    QString("SPELL_EFFECT_128"),
    QString("SPELL_EFFECT_129")
};

QString TargetFlagsString[] =
{
    QString("TARGET_FLAG_SELF"),
    QString("TARGET_FLAG_UNUSED1"),
    QString("TARGET_FLAG_UNIT"),
    QString("TARGET_FLAG_UNUSED2"),
    QString("TARGET_FLAG_UNUSED3"),
    QString("TARGET_FLAG_ITEM"),
    QString("TARGET_FLAG_SOURCE_LOCATION"),
    QString("TARGET_FLAG_DEST_LOCATION"),
    QString("TARGET_FLAG_OBJECT_UNK"),
    QString("TARGET_FLAG_UNIT_UNK"),
    QString("TARGET_FLAG_PVP_CORPSE"),
    QString("TARGET_FLAG_UNIT_CORPSE"),
    QString("TARGET_FLAG_OBJECT"),
    QString("TARGET_FLAG_TRADE_ITEM"),
    QString("TARGET_FLAG_STRING"),
    QString("TARGET_FLAG_UNK1"),
    QString("TARGET_FLAG_CORPSE"),
    QString("TARGET_FLAG_UNK2")
};

uint64 CreatureTypeFlags[] =
{
    0x00000000,
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400
};

uint64 TargetFlags[] =
{
    0x00000000,
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400,
    0x00000800,
    0x00001000,
    0x00002000,
    0x00004000,
    0x00008000,
    0x00010000
};

uint64 AttributesVal[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400,
    0x00000800,
    0x00001000,
    0x00002000,
    0x00004000,
    0x00008000,
    0x00010000,
    0x00020000,
    0x00040000,
    0x00080000,
    0x00100000,
    0x00200000,
    0x00400000,
    0x00800000,
    0x01000000,
    0x02000000,
    0x04000000,
    0x08000000,
    0x10000000,
    0x20000000,
    0x40000000,
    0x80000000
};

QString CreatureTypeString[] =
{
    QString("NONE"),
    QString("BEAST"),
    QString("DRAGONKIN"),
    QString("DEMON"),
    QString("ELEMENTAL"),
    QString("GIANT"),
    QString("UNDEAD"),
    QString("HUMANOID"),
    QString("CRITTER"),
    QString("MECHANICAL"),
    QString("NOT_SPECIFIED"),
    QString("TOTEM")
};

QString AttributesString[] =
{
    QString("SPELL_ATTR_UNK0"),
    QString("SPELL_ATTR_RANGED"),
    QString("SPELL_ATTR_ON_NEXT_SWING_1"),
    QString("SPELL_ATTR_UNK3"),
    QString("SPELL_ATTR_UNK4"),
    QString("SPELL_ATTR_TRADESPELL"),
    QString("SPELL_ATTR_PASSIVE"),
    QString("SPELL_ATTR_UNK7"),
    QString("SPELL_ATTR_UNK8"),
    QString("SPELL_ATTR_UNK9"),
    QString("SPELL_ATTR_ON_NEXT_SWING_2"),
    QString("SPELL_ATTR_UNK11"),
    QString("SPELL_ATTR_DAYTIME_ONLY"),
    QString("SPELL_ATTR_NIGHT_ONLY"),
    QString("SPELL_ATTR_INDOORS_ONLY"),
    QString("SPELL_ATTR_OUTDOORS_ONLY"),
    QString("SPELL_ATTR_NOT_SHAPESHIFT"),
    QString("SPELL_ATTR_ONLY_STEALTHED"),
    QString("SPELL_ATTR_UNK18"),
    QString("SPELL_ATTR_LEVEL_DAMAGE_CALCULATION"),
    QString("SPELL_ATTR_STOP_ATTACK_TARGET"),
    QString("SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK"),
    QString("SPELL_ATTR_UNK22"),
    QString("SPELL_ATTR_UNK23"),
    QString("SPELL_ATTR_CASTABLE_WHILE_MOUNTED"),
    QString("SPELL_ATTR_DISABLED_WHILE_ACTIVE"),
    QString("SPELL_ATTR_UNK26"),
    QString("SPELL_ATTR_CASTABLE_WHILE_SITTING"),
    QString("SPELL_ATTR_CANT_USED_IN_COMBAT"),
    QString("SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY"),
    QString("SPELL_ATTR_UNK30"),
    QString("SPELL_ATTR_CANT_CANCEL")
};

QString AttributesExString[] =
{
    QString("SPELL_ATTR_EX_UNK0"),
    QString("SPELL_ATTR_EX_DRAIN_ALL_POWER"),
    QString("SPELL_ATTR_EX_CHANNELED_1"),
    QString("SPELL_ATTR_EX_UNK3"),
    QString("SPELL_ATTR_EX_UNK4"),
    QString("SPELL_ATTR_EX_NOT_BREAK_STEALTH"),
    QString("SPELL_ATTR_EX_CHANNELED_2"),
    QString("SPELL_ATTR_EX_NEGATIVE"),
    QString("SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET"),
    QString("SPELL_ATTR_EX_UNK9"),
    QString("SPELL_ATTR_EX_NO_INITIAL_AGGRO"),
    QString("SPELL_ATTR_EX_UNK11"),
    QString("SPELL_ATTR_EX_UNK12"),
    QString("SPELL_ATTR_EX_UNK13"),
    QString("SPELL_ATTR_EX_UNK14"),
    QString("SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY"),
    QString("SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE"),
    QString("SPELL_ATTR_EX_UNK17"),
    QString("SPELL_ATTR_EX_UNK18"),
    QString("SPELL_ATTR_EX_UNK19"),
    QString("SPELL_ATTR_EX_REQ_TARGET_COMBO_POINTS"),
    QString("SPELL_ATTR_EX_UNK21"),
    QString("SPELL_ATTR_EX_REQ_COMBO_POINTS"),
    QString("SPELL_ATTR_EX_UNK23"),
    QString("SPELL_ATTR_EX_UNK24"),
    QString("SPELL_ATTR_EX_UNK25"),
    QString("SPELL_ATTR_EX_UNK26"),
    QString("SPELL_ATTR_EX_UNK27"),
    QString("SPELL_ATTR_EX_UNK28"),
    QString("SPELL_ATTR_EX_UNK29"),
    QString("SPELL_ATTR_EX_UNK30"),
    QString("SPELL_ATTR_EX_UNK31")
};

QString AttributesEx2String[] =
{
    QString("SPELL_ATTR_EX2_UNK0"),
    QString("SPELL_ATTR_EX2_UNK1"),
    QString("SPELL_ATTR_EX2_CANT_REFLECTED"),
    QString("SPELL_ATTR_EX2_UNK3"),
    QString("SPELL_ATTR_EX2_UNK4"),
    QString("SPELL_ATTR_EX2_AUTOREPEAT_FLAG"),
    QString("SPELL_ATTR_EX2_UNK6"),
    QString("SPELL_ATTR_EX2_UNK7"),
    QString("SPELL_ATTR_EX2_UNK8"),
    QString("SPELL_ATTR_EX2_UNK9"),
    QString("SPELL_ATTR_EX2_UNK10"),
    QString("SPELL_ATTR_EX2_HEALTH_FUNNEL"),
    QString("SPELL_ATTR_EX2_UNK12"),
    QString("SPELL_ATTR_EX2_UNK13"),
    QString("SPELL_ATTR_EX2_UNK14"),
    QString("SPELL_ATTR_EX2_UNK15"),
    QString("SPELL_ATTR_EX2_UNK16"),
    QString("SPELL_ATTR_EX2_UNK17"),
    QString("SPELL_ATTR_EX2_UNK18"),
    QString("SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT"),
    QString("SPELL_ATTR_EX2_UNK20"),
    QString("SPELL_ATTR_EX2_DAMAGE_REDUCED_SHIELD"),
    QString("SPELL_ATTR_EX2_UNK22"),
    QString("SPELL_ATTR_EX2_UNK23"),
    QString("SPELL_ATTR_EX2_UNK24"),
    QString("SPELL_ATTR_EX2_UNK25"),
    QString("SPELL_ATTR_EX2_UNK26"),
    QString("SPELL_ATTR_EX2_UNK27"),
    QString("SPELL_ATTR_EX2_UNK28"),
    QString("SPELL_ATTR_EX2_CANT_CRIT"),
    QString("SPELL_ATTR_EX2_UNK30"),
    QString("SPELL_ATTR_EX2_FOOD_BUFF")
};

QString AttributesEx3String[] =
{
    QString("SPELL_ATTR_EX3_UNK0"),
    QString("SPELL_ATTR_EX3_UNK1"),
    QString("SPELL_ATTR_EX3_UNK2"),
    QString("SPELL_ATTR_EX3_UNK3"),
    QString("SPELL_ATTR_EX3_UNK4"),
    QString("SPELL_ATTR_EX3_UNK5"),
    QString("SPELL_ATTR_EX3_UNK6"),
    QString("SPELL_ATTR_EX3_UNK7"),
    QString("SPELL_ATTR_EX3_UNK8"),
    QString("SPELL_ATTR_EX3_UNK9"),
    QString("SPELL_ATTR_EX3_MAIN_HAND"),
    QString("SPELL_ATTR_EX3_BATTLEGROUND"),
    QString("SPELL_ATTR_EX3_CAST_ON_DEAD"),
    QString("SPELL_ATTR_EX3_UNK13"),
    QString("SPELL_ATTR_EX3_UNK14"),
    QString("SPELL_ATTR_EX3_UNK15"),
    QString("SPELL_ATTR_EX3_UNK16"),
    QString("SPELL_ATTR_EX3_UNK17"),
    QString("SPELL_ATTR_EX3_UNK18"),
    QString("SPELL_ATTR_EX3_UNK19"),
    QString("SPELL_ATTR_EX3_DEATH_PERSISTENT"),
    QString("SPELL_ATTR_EX3_UNK21"),
    QString("SPELL_ATTR_EX3_REQ_WAND"),
    QString("SPELL_ATTR_EX3_UNK23"),
    QString("SPELL_ATTR_EX3_REQ_OFFHAND"),
    QString("SPELL_ATTR_EX3_UNK25"),
    QString("SPELL_ATTR_EX3_UNK26"),
    QString("SPELL_ATTR_EX3_UNK27"),
    QString("SPELL_ATTR_EX3_UNK28"),
    QString("SPELL_ATTR_EX3_UNK29"),
    QString("SPELL_ATTR_EX3_UNK30"),
    QString("SPELL_ATTR_EX3_UNK31")
};

QString AttributesEx4String[] =
{
    QString("SPELL_ATTR_EX4_UNK0"),
    QString("SPELL_ATTR_EX4_UNK1"),
    QString("SPELL_ATTR_EX4_UNK2"),
    QString("SPELL_ATTR_EX4_UNK3"),
    QString("SPELL_ATTR_EX4_UNK4"),
    QString("SPELL_ATTR_EX4_UNK5"),
    QString("SPELL_ATTR_EX4_NOT_STEALABLE"),
    QString("SPELL_ATTR_EX4_UNK7"),
    QString("SPELL_ATTR_EX4_UNK8"),
    QString("SPELL_ATTR_EX4_UNK9"),
    QString("SPELL_ATTR_EX4_SPELL_VS_EXTEND_COST"),
    QString("SPELL_ATTR_EX4_UNK11"),
    QString("SPELL_ATTR_EX4_UNK12"),
    QString("SPELL_ATTR_EX4_UNK13"),
    QString("SPELL_ATTR_EX4_UNK14"),
    QString("SPELL_ATTR_EX4_UNK15"),
    QString("SPELL_ATTR_EX4_NOT_USABLE_IN_ARENA"),
    QString("SPELL_ATTR_EX4_USABLE_IN_ARENA"),
    QString("SPELL_ATTR_EX4_UNK18"),
    QString("SPELL_ATTR_EX4_UNK19"),
    QString("SPELL_ATTR_EX4_UNK20"),
    QString("SPELL_ATTR_EX4_UNK21"),
    QString("SPELL_ATTR_EX4_UNK22"),
    QString("SPELL_ATTR_EX4_UNK23"),
    QString("SPELL_ATTR_EX4_UNK24"),
    QString("SPELL_ATTR_EX4_UNK25"),
    QString("SPELL_ATTR_EX4_CAST_ONLY_IN_OUTLAND"),
    QString("SPELL_ATTR_EX4_UNK27"),
    QString("SPELL_ATTR_EX4_UNK28"),
    QString("SPELL_ATTR_EX4_UNK29"),
    QString("SPELL_ATTR_EX4_UNK30"),
    QString("SPELL_ATTR_EX4_UNK31")
};

// Check...
uint64 FormMask[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400,
    0x00000800,
    0x00001000,
    /*
    0x00002000,
    0x00004000,
    0x00008000,
    0x00010000,
    0x00020000,
    */
    0x00040000,
    0x00080000,
    /*
    0x00100000,
    0x00200000,
    0x00400000,
    0x00800000,
    0x01000000,
    0x02000000,
    0x04000000,
    0x08000000,
    */
    0x10000000,
    0x20000000,
    0x40000000,
    0x80000000
};

QString FormString[] =
{
    QString("FORM_NONE"),
    QString("FORM_CAT"),
    QString("FORM_TREE"),
    QString("FORM_TRAVEL"),
    QString("FORM_AQUA"),
    QString("FORM_BEAR"),
    QString("FORM_AMBIENT"),
    QString("FORM_GHOUL"),
    QString("FORM_DIREBEAR"),
    QString("FORM_CREATUREBEAR"),
    QString("FORM_CREATURECAT"),
    QString("FORM_GHOSTWOLF"),
    QString("FORM_BATTLESTANCE"),
    QString("FORM_DEFENSIVESTANCE"),
    QString("FORM_BERSERKERSTANCE"),
    QString("FORM_SHADOW"),
    QString("FORM_STEALTH"),
    QString("FORM_MOONKIN"),
    QString("FORM_SPIRITOFREDEMPTION")
};

QString ItemClassString[] =
{
    QString("CONSUMABLE"),
    QString("CONTAINER"),
    QString("WEAPON"),
    QString("GEM"),
    QString("ARMOR"),
    QString("REAGENT"),
    QString("PROJECTILE"),
    QString("TRADE_GOODS"),
    QString("GENERIC"),
    QString("RECIPE"),
    QString("MONEY"),
    QString("QUIVER"),
    QString("QUEST"),
    QString("KEY"),
    QString("PERMANENT"),
    QString("MISC")
};

uint64 ItemSubWeaponMask[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400,
    0x00000800,
    0x00001000,
    0x00002000,
    0x00004000,
    0x00008000,
    0x00010000,
    0x00020000,
    0x00040000,
    0x00080000
};

QString ItemSubWeaponString[] =
{
    QString("AXE"),
    QString("AXE2"),
    QString("BOW"),
    QString("GUN"),
    QString("MACE"),
    QString("MACE2"),
    QString("POLEARM"),
    QString("SWORD"),
    QString("SWORD2"),
    QString("OBSOLETE"),
    QString("STAFF"),
    QString("EXOTIC"),
    QString("EXOTIC2"),
    QString("FIST"),
    QString("MISC"),
    QString("DAGGER"),
    QString("THROWN"),
    QString("SPEAR"),
    QString("CROSSBOW"),
    QString("WAND"),
    QString("FISHING_POLE")
};

uint64 ItemSubArmorMask[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400
};

QString ItemSubArmorString[] =
{
    QString("MISC"),
    QString("CLOTH"),
    QString("LEATHER"),
    QString("MAIL"),
    QString("PLATE"),
    QString("BUCKLER"),
    QString("SHIELD"),
    QString("LIBRAM"),
    QString("IDOL"),
    QString("TOTEM"),
    QString("SIGIL")
};

uint64 ItemSubMiscMask[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010
};

QString ItemSubMiscString[] =
{
    QString("JUNK"),
    QString("REAGENT"),
    QString("PET"),
    QString("HOLIDAY"),
    QString("OTHER"),
    QString("MOUNT")
};

uint64 InventoryTypeMask[] =
{
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000100,
    0x00000200,
    0x00000400,
    0x00000800,
    0x00001000,
    0x00002000,
    0x00004000,
    0x00008000,
    0x00010000,
    0x00020000,
    0x00040000,
    0x00080000,
    0x00100000,
    0x00200000,
    0x00400000,
    0x00800000,
    0x01000000,
    0x02000000,
    0x04000000,
    0x08000000,
    0x10000000
};

QString InventoryTypeString[] =
{
    QString("NON_EQUIP"),
    QString("HEAD"),
    QString("NECK"),
    QString("SHOULDERS"),
    QString("BODY"),
    QString("CHEST"),
    QString("WAIST"),
    QString("LEGS"),
    QString("FEET"),
    QString("WRISTS"),
    QString("HANDS"),
    QString("FINGER"),
    QString("TRINKET"),
    QString("WEAPON"),
    QString("SHIELD"),
    QString("RANGED"),
    QString("CLOAK"),
    QString("WEAPON_2H"),
    QString("BAG"),
    QString("TABARD"),
    QString("ROBE"),
    QString("WEAPONMAINHAND"),
    QString("WEAPONOFFHAND"),
    QString("HOLDABLE"),
    QString("AMMO"),
    QString("THROWN"),
    QString("RANGEDRIGHT"),
    QString("QUIVER"),
    QString("RELIC")
};

QString MechanicString[] =
{
    QString("MECHANIC_NONE"),
    QString("MECHANIC_CHARM"),
    QString("MECHANIC_DISORIENTED"),
    QString("MECHANIC_DISARM"),
    QString("MECHANIC_DISTRACT"),
    QString("MECHANIC_FEAR"),
    QString("MECHANIC_FUMBLE"),
    QString("MECHANIC_ROOT"),
    QString("MECHANIC_PACIFY"),
    QString("MECHANIC_SILENCE"),
    QString("MECHANIC_SLEEP"),
    QString("MECHANIC_SNARE"),
    QString("MECHANIC_STUN"),
    QString("MECHANIC_FREEZE"),
    QString("MECHANIC_KNOCKOUT"),
    QString("MECHANIC_BLEED"),
    QString("MECHANIC_BANDAGE"),
    QString("MECHANIC_POLYMORPH"),
    QString("MECHANIC_BANISH"),
    QString("MECHANIC_SHIELD"),
    QString("MECHANIC_SHACKLE"),
    QString("MECHANIC_MOUNT"),
    QString("MECHANIC_PERSUADE"),
    QString("MECHANIC_TURN"),
    QString("MECHANIC_HORROR"),
    QString("MECHANIC_INVULNERABILITY"),
    QString("MECHANIC_INTERRUPT"),
    QString("MECHANIC_DAZE"),
    QString("MECHANIC_DISCOVERY"),
    QString("MECHANIC_IMMUNE_SHIELD"),
    QString("MECHANIC_SAPPED")
};

QString DispelTypeString[] =
{
    QString("DISPEL_NONE"),
    QString("DISPEL_MAGIC"),
    QString("DISPEL_CURSE"),
    QString("DISPEL_DISEASE"),
    QString("DISPEL_POISON"),
    QString("DISPEL_STEALTH"),
    QString("DISPEL_INVISIBILITY"),
    QString("DISPEL_ALL"),
    QString("DISPEL_SPE_NPC_ONLY"),
    QString("DISPEL_ENRAGE"),
    QString("DISPEL_ZG_TICKET")
};

QString AuraStateString[] =
{
    QString("NONE"),
    QString("AURA_STATE_DEFENSE"),
    QString("AURA_STATE_HEALTHLESS_20_PERCENT"),
    QString("AURA_STATE_BERSERKING"),
    QString("AURA_STATE_FROZEN"),
    QString("AURA_STATE_JUDGEMENT"),
    QString("AURA_STATE_UNKNOWN6"),
    QString("AURA_STATE_HUNTER_PARRY")
};

QString ProcFlagDesc[] =
{
    //00 0x00000001 000000000000000000000001 -
    QString("00 Killed by aggressor that receive experience or honor"),
    //01 0x00000002 000000000000000000000010 -
    QString("01 Kill that yields experience or honor"),
    //02 0x00000004 000000000000000000000100 -
    QString("02 Successful melee attack"),
    //03 0x00000008 000000000000000000001000 -
    QString("03 Taken damage from melee strike hit"),
    //04 0x00000010 000000000000000000010000 -
    QString("04 Successful attack by Spell that use melee weapon"),
    //05 0x00000020 000000000000000000100000 -
    QString("05 Taken damage by Spell that use melee weapon"),
    //06 0x00000040 000000000000000001000000 -
    QString("06 Successful Ranged attack(and wand spell cast)"),
    //07 0x00000080 000000000000000010000000 -
    QString("07 Taken damage from ranged attack"),
    //08 0x00000100 000000000000000100000000 -
    QString("08 Successful Ranged attack by Spell that use ranged weapon"),
    //09 0x00000200 000000000000001000000000 -
    QString("09 Taken damage by Spell that use ranged weapon"),
    //10 0x00000400 000000000000010000000000 -
    QString("10 Successful ??? spell hit"),
    //11 0x00000800 000000000000100000000000 -
    QString("11 Taken ??? spell hit"),
    //12 0x00001000 000000000001000000000000 -
    QString("12 Successful ??? spell cast"),
    //13 0x00002000 000000000010000000000000 -
    QString("13 Taken ??? spell hit"),
    //14 0x00004000 000000000100000000000000 -
    QString("14 Successful cast positive spell"),
    //15 0x00008000 000000001000000000000000 -
    QString("15 Taken positive spell hit"),
    //16 0x00010000 000000010000000000000000 -
    QString("16 Successful damage from harmful spell cast (���� ���������� ������)"),
    //17 0x00020000 000000100000000000000000 -
    QString("17 Taken spell damage"),
    //18 0x00040000 000001000000000000000000 -
    QString("18 Deal periodic damage"),
    //19 0x00080000 000010000000000000000000 -
    QString("19 Taken periodic damage"),
    //20 0x00100000 000100000000000000000000 -
    QString("20 Taken any damage"),
    //21 0x00200000 001000000000000000000000 -
    QString("21 On trap activation (��� ������������ �������)"),
    //22 0x00800000 010000000000000000000000 -
    QString("22 Taken off-hand melee attacks"),
    //23 0x00800000 100000000000000000000000 -
    QString("23 Successful off-hand melee attacks"),
    QString("24"),
    QString("25"),
    QString("26"),
    QString("27"),
    QString("28"),
    QString("29"),
    QString("30"),
    QString("31")
};

QString EffectTargetString[] =
{
    QString("NO_TARGET"),
    QString("TARGET_SELF"),
    QString("TARGET_RANDOM_ENEMY_CHAIN_IN_AREA"),
    QString("TARGET_RANDOM_FRIEND_CHAIN_IN_AREA"),
    QString("TARGET_4"),
    QString("TARGET_PET"),
    QString("TARGET_CHAIN_DAMAGE"),
    QString("TARGET_AREAEFFECT_INSTANT"),
    QString("TARGET_AREAEFFECT_CUSTOM"),
    QString("TARGET_INNKEEPER_COORDINATES"),
    QString("TARGET_10"),
    QString("TARGET_11"),
    QString("TARGET_12"),
    QString("TARGET_13"),
    QString("TARGET_14"),
    QString("TARGET_ALL_ENEMY_IN_AREA"),
    QString("TARGET_ALL_ENEMY_IN_AREA_INSTANT"),
    QString("TARGET_TABLE_X_Y_Z_COORDINATES"),
    QString("TARGET_EFFECT_SELECT"),
    QString("TARGET_19"),
    QString("TARGET_ALL_PARTY_AROUND_CASTER"),
    QString("TARGET_SINGLE_FRIEND"),
    QString("TARGET_CASTER_COORDINATES"),
    QString("TARGET_GAMEOBJECT"),
    QString("TARGET_IN_FRONT_OF_CASTER"),
    QString("TARGET_DUELVSPLAYER"),
    QString("TARGET_GAMEOBJECT_ITEM"),
    QString("TARGET_MASTER"),
    QString("TARGET_ALL_ENEMY_IN_AREA_CHANNELED"),
    QString("TARGET_29"),
    QString("TARGET_ALL_FRIENDLY_UNITS_AROUND_CASTER"),
    QString("TARGET_ALL_FRIENDLY_UNITS_IN_AREA"),
    QString("TARGET_MINION"),
    QString("TARGET_ALL_PARTY"),
    QString("TARGET_ALL_PARTY_AROUND_CASTER_2"),
    QString("TARGET_SINGLE_PARTY"),
    QString("TARGET_ALL_HOSTILE_UNITS_AROUND_CASTER"),
    QString("TARGET_AREAEFFECT_PARTY"),
    QString("TARGET_SCRIPT"),
    QString("TARGET_SELF_FISHING"),
    QString("TARGET_FOCUS_OR_SCRIPTED_GAMEOBJECT"),
    QString("TARGET_TOTEM_EARTH"),
    QString("TARGET_TOTEM_WATER"),
    QString("TARGET_TOTEM_AIR"),
    QString("TARGET_TOTEM_FIRE"),
    QString("TARGET_CHAIN_HEAL"),
    QString("TARGET_SCRIPT_COORDINATES"),
    QString("TARGET_DYNAMIC_OBJECT_FRONT"),
    QString("TARGET_DYNAMIC_OBJECT_BEHIND"),
    QString("TARGET_DYNAMIC_OBJECT_LEFT_SIDE"),
    QString("TARGET_DYNAMIC_OBJECT_RIGHT_SIDE"),
    QString("TARGET_51"),
    QString("TARGET_AREAEFFECT_CUSTOM_2"),
    QString("TARGET_CURRENT_ENEMY_COORDINATES"),
    QString("TARGET_LARGE_FRONTAL_CONE"),
    QString("TARGET_55"),
    QString("TARGET_ALL_RAID_AROUND_CASTER"),
    QString("TARGET_SINGLE_FRIEND_2"),
    QString("TARGET_58"),
    QString("TARGET_59"),
    QString("TARGET_NARROW_FRONTAL_CONE"),
    QString("TARGET_AREAEFFECT_PARTY_AND_CLASS"),
    QString("TARGET_62"),
    QString("TARGET_DUELVSPLAYER_COORDINATES")
};

#endif