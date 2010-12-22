#ifndef QDEFINES_H
#define QDEFINES_H

#include <QtCore/QString>

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

#endif