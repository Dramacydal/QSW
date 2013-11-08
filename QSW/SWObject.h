#ifndef SWOBJECT_H
#define SWOBJECT_H

#include "SWMainForm.h"
#include "SWEnums.h"
#include "SWEvent.h"
#include "DBC/DBCStores.h"
#include "SWDefines.h"
#include "SimpleHistory.h"

class SWMainForm;

class SWObject
{
    public:
        SWObject(SWMainForm *form);
        ~SWObject();

        void showInfo(SpellInfo const* spellInfo, quint8 num = 0);
        std::set<SpellInfo const*> getParentSpellIds(quint32 triggerId);
        void compare();
        void search();

        void appendSpecInfo(SpellInfo const* spellInfo, quint8 num);
        void appendTalentInfo(SpellInfo const* spellInfo, quint8 num);
        void appendReplacementInfo(SpellInfo const* spellInfo, quint8 num);
        void appendSkillInfo(SpellInfo const* spellInfo, quint8 num);
        void appendAffectsInfo(SpellInfo const* spellInfo, quint8 num);
        void appendCastTimeInfo(SpellInfo const* spellInfo, quint8 num);
        void appendDurationInfo(SpellInfo const* spellInfo, quint8 num);
        void appendRangeInfo(SpellInfo const* spellInfo, quint8 num);
        void appendSpellEffectInfo(SpellInfo const* spellInfo, quint8 num);
        void appendSpellEffectInfo(SpellInfo const* spellInfo, quint8 num, quint8 eff, quint8 diff);
        void appendAuraInfo(SpellInfo const* spellInfo, quint8 index, quint8 num, quint8 diff);
        void appendRadiusInfo(SpellInfo const* spellInfo, quint8 index, quint8 num, quint8 diff);
        void appendTriggerInfo(SpellInfo const* spellInfo, quint8 index, quint8 num, quint8 diff);
        void appendProcInfo(SpellInfo const *spellInfo, quint8 num);

        QString containAttributes(SpellInfo const* spellInfo, AttrType attr, quint8 index = 0);
        QString getDescription(QString str, SpellInfo const *spellInfo);
        QString getClassName(quint32 unitClass);
        QString getSpellLink(quint32 spellId);
        QString getSpellLink(SpellInfo const* entry);

        quint8 getType() const { return m_type; }
        void setType(quint8 type) { m_type = type; }

        SWMainForm* getForm() { return m_form; }

    private:
        SWMainForm *m_form;
        SWEnums* m_enums;
        SimpleHistory* m_history;

        QString html;

        bool m_regExp;
        quint8 m_type;
};

namespace Converter
{
    quint64 getULongLong(QString value);
    qint64  getLongLong(QString value);
    quint32 getULong(QString value);
    qint32  getLong(QString value);
};

#endif // SWOBJECT_H
