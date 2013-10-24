#include "SWSearch.h"
#include "SWModels.h"

Q_DECLARE_METATYPE(MetaSpell*)

MetaSpell::MetaSpell() : m_spellInfo(NULL)
{

}

SWSearch::SWSearch(SWObject* sw, QObject* parent)
: QObject(parent), m_sw(sw), m_form(sw->getForm())
{
    m_scriptEngine = new QScriptEngine(this);

    EnumHash enums = m_form->getEnums()->getEnums();

    for (EnumHash::const_iterator itr = enums.begin(); itr != enums.end(); ++itr)
        for (Enumerator::const_iterator itr2 = itr->begin(); itr2 != itr->end(); ++itr2)
            m_scriptEngine->globalObject().setProperty(itr2.value(), qsreal(itr2.key()));

    m_script = m_scriptEngine->evaluate("(function() { return (" + m_form->getFilterText() + "); })");
}

SWSearch::~SWSearch()
{
    delete m_scriptEngine;
}

bool SWSearch::hasValue(SpellInfo const* spellInfo)
{
    MetaSpell metaSpell;
    metaSpell.setSpell(spellInfo);

    m_scriptEngine->globalObject().setProperty("spell", m_scriptEngine->newQObject(&metaSpell));

    return m_script.call(QScriptValue()).toBool();
}

void SWSearch::search()
{
    SpellListModel *model = new SpellListModel(m_form);

    if (m_sw->getType() == 1)
    {
        for (auto itr : sSpellInfoStore)
        {
            bool family = false;
            bool aura = false;
            bool effect = false;
            bool targetA = false;
            bool targetB = false;

            if (m_form->comboBox->currentIndex() > 0)
            {
                quint16 familyId = m_form->comboBox->itemData(m_form->comboBox->currentIndex()).toInt();
                if (itr.second->getSpellFamilyName() == familyId)
                    family = true;
            }
            else
                family = true;

            if (m_form->comboBox_2->currentIndex() > 0)
            {
                quint16 auraId = m_form->comboBox_2->itemData(m_form->comboBox_2->currentIndex()).toInt();
                for (quint8 i = EFFECT_INDEX_0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if (itr.second->getEffectApplyAuraName(i) == auraId)
                    {
                        aura = true;
                        break;
                    }
                }
            }
            else
                aura = true;

            if (m_form->comboBox_3->currentIndex() > 0)
            {
                quint16 effectId = m_form->comboBox_3->itemData(m_form->comboBox_3->currentIndex()).toInt();
                for (quint8 i = EFFECT_INDEX_0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if (itr.second->getEffect(i) == effectId)
                    {
                        effect = true;
                        break;
                    }
                }
            }
            else
                effect = true;

            if (m_form->comboBox_4->currentIndex() > 0)
            {
                quint16 targetId = m_form->comboBox_4->itemData(m_form->comboBox_4->currentIndex()).toInt();
                for (quint8 i = EFFECT_INDEX_0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if (itr.second->getEffectImplicitTargetA(i) == targetId)
                    {
                        targetA = true;
                        break;
                    }
                }
            }
            else
                targetA = true;

            if (m_form->comboBox_5->currentIndex() > 0)
            {
                quint16 targetId = m_form->comboBox_5->itemData(m_form->comboBox_5->currentIndex()).toInt();
                for (quint8 i = EFFECT_INDEX_0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if (itr.second->getEffectImplicitTargetB(i) == targetId)
                    {
                        targetB = true;
                        break;
                    }
                }
            }
            else
                targetB = true;

            if (family && aura && effect && targetA && targetB)
            {
                QString sRank(QString::fromUtf8(itr.second->Rank));
                QString sFullName(QString::fromUtf8(itr.second->SpellName));

                if (!sRank.isEmpty())
                    sFullName.append(QString(" (%0)").arg(sRank));

                QStringList spellRecord;
                spellRecord << QString("%0").arg(itr.second->Id) << sFullName;

                model->appendRecord(spellRecord);
            }
        }
        Event* ev = new Event(Event::Type(Event::EVENT_SEND_MODEL));
        ev->addValue(QVariant::fromValue(model));
        QApplication::postEvent(m_form, ev);
    }
    else if (m_sw->getType() == 2)
    {
        if (!m_form->compareSpell_1->text().isEmpty() && !m_form->compareSpell_2->text().isEmpty())
        {
            SpellInfo const* sInfo1 = GetSpellInfo(m_form->compareSpell_1->text().toInt());
            SpellInfo const* sInfo2 = GetSpellInfo(m_form->compareSpell_2->text().toInt());

            if (sInfo1 && sInfo2)
            {
                Event* ev = new Event(Event::Type(Event::EVENT_SEND_CSPELL));
                ev->addValue(QVariant::fromValue(sInfo1));
                ev->addValue(QVariant::fromValue(sInfo2));
                QApplication::postEvent(m_form, ev);
            }
        }
    }
    else if (m_sw->getType() == 3)
    {
        for (auto itr : sSpellInfoStore)
        {
            if (hasValue(itr.second))
            {
                QString sRank(QString::fromUtf8(itr.second->Rank));
                QString sFullName(QString::fromUtf8(itr.second->SpellName));

                if (!sRank.isEmpty())
                    sFullName.append(QString(" (%0)").arg(sRank));

                QStringList spellRecord;
                spellRecord << QString("%0").arg(itr.second->Id) << sFullName;

                model->appendRecord(spellRecord);
            }
        }

        Event* ev = new Event(Event::Type(Event::EVENT_SEND_MODEL));
        ev->addValue(QVariant::fromValue(model));
        QApplication::postEvent(m_form, ev);
    }
    else
    {
        if (!m_form->findLine_e1->text().isEmpty())
        {
            if (!m_form->findLine_e1->text().toInt())
            {
                for (auto itr : sSpellInfoStore)
                {
                    if (QString(QString::fromUtf8(itr.second->SpellName)).contains(m_form->findLine_e1->text(), Qt::CaseInsensitive))
                    {
                        QString sRank(QString::fromUtf8(itr.second->Rank));
                        QString sFullName(QString::fromUtf8(itr.second->SpellName));

                        if (!sRank.isEmpty())
                            sFullName.append(QString(" (%0)").arg(sRank));

                        QStringList spellRecord;
                        spellRecord << QString("%0").arg(itr.second->Id) << sFullName;

                        model->appendRecord(spellRecord);
                    }
                }

                Event* ev = new Event(Event::Type(Event::EVENT_SEND_MODEL));
                ev->addValue(QVariant::fromValue(model));
                QApplication::postEvent(m_form, ev);
            }
            else
            {
                SpellInfo const* m_spellInfo = GetSpellInfo(m_form->findLine_e1->text().toInt());

                if (m_spellInfo)
                {
                    QString sRank(QString::fromUtf8(m_spellInfo->Rank));
                    QString sFullName(QString::fromUtf8(m_spellInfo->SpellName));

                    if (!sRank.isEmpty())
                        sFullName.append(QString(" (%0)").arg(sRank));

                    QStringList spellRecord;
                    spellRecord << QString("%0").arg(m_spellInfo->Id) << sFullName;

                    model->appendRecord(spellRecord);

                    Event* ev1 = new Event(Event::Type(Event::EVENT_SEND_MODEL));
                    ev1->addValue(QVariant::fromValue(model));
                    QApplication::postEvent(m_form, ev1);

                    Event* ev2 = new Event(Event::Type(Event::EVENT_SEND_SPELL));
                    ev2->addValue(QVariant::fromValue(m_spellInfo));
                    QApplication::postEvent(m_form, ev2);
                }
            }
        }
        else if (!m_form->findLine_e3->text().isEmpty())
        {
            for (auto itr : sSpellInfoStore)
            {
                if (QString(QString::fromUtf8(itr.second->Description)).contains(m_form->findLine_e3->text(), Qt::CaseInsensitive))
                {
                    QString sRank(QString::fromUtf8(itr.second->Rank));
                    QString sFullName(QString::fromUtf8(itr.second->SpellName));

                    if (!sRank.isEmpty())
                        sFullName.append(QString(" (%0)").arg(sRank));

                    QStringList spellRecord;
                    spellRecord << QString("%0").arg(itr.second->Id) << sFullName;

                    model->appendRecord(spellRecord);
                }
            }

            Event* ev = new Event(Event::Type(Event::EVENT_SEND_MODEL));
            ev->addValue(QVariant::fromValue(model));
            QApplication::postEvent(m_form, ev);
        }
        else
        {
            for (auto itr : sSpellInfoStore)
            {
                QString sRank(QString::fromUtf8(itr.second->Rank));
                QString sFullName(QString::fromUtf8(itr.second->SpellName));

                if (!sRank.isEmpty())
                    sFullName.append(QString(" (%0)").arg(sRank));

                QStringList spellRecord;
                spellRecord << QString("%0").arg(itr.second->Id) << sFullName;

                model->appendRecord(spellRecord);
            }

            Event* ev = new Event(Event::Type(Event::EVENT_SEND_MODEL));
            ev->addValue(QVariant::fromValue(model));
            QApplication::postEvent(m_form, ev);
        }
    }
}
