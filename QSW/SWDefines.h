#ifndef SWDEFINES_H
#define SWDEFINES_H

#include <QtCore/QString>
#include <QtCore/QMetaType>

extern QString CLIENT_VERSION;
extern QString QSW_BUILD;
extern QString CLIENT_BUILD;

extern quint8  Locale;
extern QString ProcFlagDesc[];

#define MAX_PROC 32 
#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2
#define MAX_SPELL_TOTEM_CATEGORIES 2
#define MAX_CLASS_MASK 4

#define arrayLength(a, b) sizeof(a) / sizeof(b)

enum AttrType
{
    TYPE_ATTR,
    TYPE_ATTR_EX1,
    TYPE_ATTR_EX2,
    TYPE_ATTR_EX3,
    TYPE_ATTR_EX4,
    TYPE_ATTR_EX5,
    TYPE_ATTR_EX6,
    TYPE_ATTR_EX7,
    TYPE_ATTR_EX8,
    TYPE_ATTR_EX9,
    TYPE_ATTR_EX10,
    TYPE_ATTR_EX11,
#if _BUILD >= 17538
    TYPE_ATTR_EX12,
#endif
    TYPE_TARGETS,
    TYPE_CREATURE,
    TYPE_FORMS,
    TYPE_FORMS_NOT,
    TYPE_ITEM_WEAPON,
    TYPE_ITEM_ARMOR,
    TYPE_ITEM_MISC,
    TYPE_ITEM_INVENTORY,
    TYPE_CR,
    TYPE_SCHOOL_MASK,
    MAX_ATTR_TYPE
};

enum SpellEffectIndex
{
    EFFECT_INDEX_0     = 0,
    EFFECT_INDEX_1     = 1,
    EFFECT_INDEX_2     = 2,
    EFFECT_INDEX_3     = 3,
    EFFECT_INDEX_4     = 4,
    EFFECT_INDEX_5     = 5,
    EFFECT_INDEX_6     = 6,
    EFFECT_INDEX_7     = 7,
    EFFECT_INDEX_8     = 8,
    EFFECT_INDEX_9     = 9,
    EFFECT_INDEX_10    = 10,
    EFFECT_INDEX_11    = 11,
    EFFECT_INDEX_12    = 12,
    EFFECT_INDEX_13    = 13,
    EFFECT_INDEX_14    = 14,
    EFFECT_INDEX_15    = 15,
    EFFECT_INDEX_16    = 16,
    EFFECT_INDEX_17    = 17,
    EFFECT_INDEX_18    = 18,
    EFFECT_INDEX_19    = 19,
    EFFECT_INDEX_20    = 20,
    EFFECT_INDEX_21    = 21,
    EFFECT_INDEX_22    = 22,
    EFFECT_INDEX_23    = 23,
    EFFECT_INDEX_24    = 24,
    EFFECT_INDEX_25    = 25,
    EFFECT_INDEX_26    = 26,
    EFFECT_INDEX_27    = 27,
    EFFECT_INDEX_28    = 28,
    EFFECT_INDEX_29    = 29,
    EFFECT_INDEX_30    = 30,
    EFFECT_INDEX_31    = 31,
    MAX_EFFECT_INDEX   = 32,
};

#define MAX_DIFFICULTY 10

#endif // SWDEFINES_H
