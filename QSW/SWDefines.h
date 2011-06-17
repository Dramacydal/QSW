#ifndef SWDEFINES_H
#define SWDEFINES_H

#include <QtCore/QString>


extern quint8  Locale;
extern QString SpellStruct[];
extern QString ProcFlagDesc[];

#define MAX_STRUCT 91
#define MAX_PROC 32 
#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2

enum AttrType
{
    TYPE_ATTR,
    TYPE_ATTR_EX,
    TYPE_ATTR_EX2,
    TYPE_ATTR_EX3,
    TYPE_ATTR_EX4,
    TYPE_TARGETS,
    TYPE_CREATURE,
    TYPE_FORMS,
    TYPE_FORMS_NOT,
    TYPE_ITEM_WEAPON,
    TYPE_ITEM_ARMOR,
    TYPE_ITEM_MISC,
    TYPE_ITEM_INVENTORY,
    TYPE_CR,
    MAX_ATTR_TYPE
};

enum SpellEffectIndex
{
    EFFECT_INDEX_0     = 0,
    EFFECT_INDEX_1     = 1,
    EFFECT_INDEX_2     = 2,
    MAX_EFFECT_INDEX
};

enum Threads
{
    THREAD_SEARCH,
    MAX_THREAD
};


#endif // SWDEFINES_H
