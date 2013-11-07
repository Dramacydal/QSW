#include "SWObject.h"
#include "SWSearch.h"
#include <QMessageBox>

SWObject::SWObject(SWMainForm* form)
    : m_form(form), m_regExp(false), m_type(0), m_enums(form->getEnums()), m_history(form->getHistory())
{
    LoadDBCStores();
}

void SWObject::search()
{
    SWSearch* search = new SWSearch(this);
    search->search();
    delete search;
}

float getRadius(SpellInfo const* spellInfo, quint8 effIndex, quint8 diff = 0)
{
    return spellInfo->spellRadius[diff][effIndex] ? spellInfo->spellRadius[diff][effIndex]->Radius : 0.0f;
}

float getRadiusMax(SpellInfo const* spellInfo, quint8 effIndex, quint8 diff = 0)
{
    return spellInfo->spellRadiusMax[diff][effIndex] ? spellInfo->spellRadiusMax[diff][effIndex]->Radius : 0.0f;
}

quint32 getDuration(SpellInfo const* spellInfo)
{
    if (spellInfo->durationInfo)
        return quint32(spellInfo->durationInfo->Duration[0] / 1000);

    return 1;
}

quint32 getRealDuration(SpellInfo const* spellInfo, quint8 effIndex)
{
    return quint32(getDuration(spellInfo) / (spellInfo->getEffectAmplitude(effIndex) ? quint32(spellInfo->getEffectAmplitude(effIndex) / 1000) : 5));
}

void RegExpU(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(tSpell->getStackAmount()));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(spellInfo->getStackAmount()));
    }
}

void RegExpH(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(tSpell->getProcChance()));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(spellInfo->getProcChance()));
    }
}

void RegExpV(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(tSpell->getMaxTargetLevel()));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(spellInfo->getMaxTargetLevel()));
    }
}

void RegExpQ(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32(tSpell->getEffectMiscValue(rx.cap(6).toInt()-1) / rx.cap(3).toInt()))));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32(tSpell->getEffectMiscValue(rx.cap(6).toInt()-1) * rx.cap(3).toInt()))));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32(spellInfo->getEffectMiscValue(rx.cap(6).toInt()-1) / rx.cap(3).toInt()))));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32(spellInfo->getEffectMiscValue(rx.cap(6).toInt()-1) * rx.cap(3).toInt()))));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(abs(tSpell->getEffectMiscValue(rx.cap(6).toInt()-1))));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(abs(spellInfo->getEffectMiscValue(rx.cap(6).toInt()-1))));
    }
}

void RegExpI(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            if (tSpell->getMaxAffectedTargets() != 0)
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(tSpell->getMaxAffectedTargets()));
            }
            else
            {
                str.replace(rx.cap(0), QString("nearby"));
            }
        }
    }
    else
    {
        if (spellInfo->getMaxAffectedTargets() != 0)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(spellInfo->getMaxAffectedTargets()));
        }
        else
        {
            str.replace(rx.cap(0), QString("nearby"));
        }
    }
}

void RegExpB(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32((tSpell->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1)) / rx.cap(3).toInt()))));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32((tSpell->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1) * rx.cap(3).toInt())))));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32((spellInfo->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1) / rx.cap(3).toInt())))));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32((spellInfo->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1) * rx.cap(3).toInt())))));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(abs(qint32(tSpell->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1)))));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(abs(qint32(spellInfo->getEffectPointsPerComboPoint(rx.cap(6).toInt()-1)))));
    }
}

void RegExpA(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(getRadius(tSpell, rx.cap(6).toInt()-1) / rx.cap(2).toInt())));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(getRadius(tSpell, rx.cap(6).toInt()-1) * rx.cap(2).toInt())));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(getRadius(spellInfo, rx.cap(6).toInt()-1) / rx.cap(2).toInt())));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(getRadius(spellInfo, rx.cap(6).toInt()-1) * rx.cap(2).toInt())));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(getRadius(tSpell, rx.cap(6).toInt()-1)));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(getRadius(spellInfo, rx.cap(6).toInt()-1)));
    }
}

void RegExpD(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(getDuration(tSpell) / rx.cap(3).toInt())));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(getDuration(tSpell) * rx.cap(3).toInt())));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(getDuration(spellInfo) / rx.cap(3).toInt())));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(getDuration(spellInfo) * rx.cap(3).toInt())));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0 seconds")
                .arg(getDuration(tSpell)));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0 seconds")
            .arg(getDuration(spellInfo)));
    }
}

void RegExpO(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32((getRealDuration(tSpell, rx.cap(6).toInt()-1) * (tSpell->getEffectBasePoints(rx.cap(6).toInt()-1))) / rx.cap(3).toInt())));
                }
                else if(rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32((getRealDuration(tSpell, rx.cap(6).toInt()-1) * (tSpell->getEffectBasePoints(rx.cap(6).toInt()-1))) * rx.cap(3).toInt())));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32((getRealDuration(spellInfo, rx.cap(6).toInt()-1) * (spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1))) / rx.cap(3).toInt())));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32((getRealDuration(spellInfo, rx.cap(6).toInt()-1) * (spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1))) * rx.cap(3).toInt())));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(getRealDuration(tSpell, rx.cap(6).toInt()-1) * (tSpell->getEffectBasePoints(rx.cap(6).toInt()-1))));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(getRealDuration(spellInfo, rx.cap(6).toInt()-1) * (spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1))));
    }
}

void RegExpS(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32((tSpell->getEffectBasePoints(rx.cap(6).toInt()-1)) / rx.cap(3).toInt()))));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(abs(qint32((tSpell->getEffectBasePoints(rx.cap(6).toInt()-1)) * rx.cap(3).toInt()))));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32((spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1)) / rx.cap(3).toInt()))));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(abs(qint32((spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1)) * rx.cap(3).toInt()))));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(abs(tSpell->getEffectBasePoints(rx.cap(6).toInt()-1))));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(abs(spellInfo->getEffectBasePoints(rx.cap(6).toInt()-1))));
    }
}

void RegExpT(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
            if (tSpell)
            {
                if (rx.cap(2) == QString("/"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(quint32(tSpell->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000) / rx.cap(3).toInt())));
                }
                else if (rx.cap(2) == QString("*"))
                {
                    str.replace(rx.cap(0), QString("%0")
                        .arg(quint32(quint32(tSpell->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000) * rx.cap(3).toInt())));
                }
            }
        }
        else
        {
            if (rx.cap(2) == QString("/"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(quint32(spellInfo->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000) / rx.cap(3).toInt())));
            }
            else if (rx.cap(2) == QString("*"))
            {
                str.replace(rx.cap(0), QString("%0")
                    .arg(quint32(quint32(spellInfo->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000) * rx.cap(3).toInt())));
            }
        }
    }
    else if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(quint32(tSpell->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000)));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(quint32(spellInfo->getEffectAmplitude(rx.cap(6).toInt()-1) / 1000)));
    }
}

void RegExpN(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(tSpell->getProcCharges()));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(spellInfo->getProcCharges()));
    }
}

void RegExpX(SpellInfo const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellInfo const* tSpell = GetSpellInfo(rx.cap(4).toInt());
        if (tSpell)
        {
            str.replace(rx.cap(0), QString("%0")
                .arg(tSpell->getEffectChainTarget(rx.cap(6).toInt()-1)));
        }
    }
    else
    {
        str.replace(rx.cap(0), QString("%0")
            .arg(spellInfo->getEffectChainTarget(rx.cap(6).toInt()-1)));
    }
}

QString SWObject::getDescription(QString str, SpellInfo const* spellInfo)
{
    if (!m_form->isRegExp())
        return str;

    QRegExp rx("\\$+(([/,*])?([0-9]*);)?([d+\\;)(\\d*)?([1-9@]*)([A-z]+)(\\d*)(([A-z, ]*)\\:([A-z, ]*)\\;)?");
    while (str.contains(rx))
    {
        if (rx.indexIn(str) != -1)
        {
            /*QString st = "";
            for (auto i = 0; i < rx.captureCount(); ++i)
                st += QString("%0 '%1'\n").arg(i).arg(rx.cap(i));

            QMessageBox::warning(NULL, "Desc", st);
            //return str;
            str.replace(rx.cap(0),rx.cap(5));
            continue;*/

            QString cap = rx.cap(5).toLower();
            if (cap == "spellaura")
            {
                quint32 spellId = rx.cap(6).toInt();
                if (SpellInfo const* other = GetSpellInfo(spellId))
                {
                    str.replace(rx.cap(0), QString::fromUtf8(other->ToolTip));
                    str = getDescription(str, other);
                }
                else
                    str.replace(rx.cap(0), QString("<Spell %0 needed for tooltip not found>").arg(spellId));
            }
            else if (cap == "spelldesc")
            {
                quint32 spellId = rx.cap(6).toInt();
                if (SpellInfo const* other = GetSpellInfo(spellId))
                {
                    str.replace(rx.cap(0), QString::fromUtf8(other->Description));
                    str = getDescription(str, other);
                }
                else
                    str.replace(rx.cap(0), QString("<Spell %0 needed for description not found>").arg(spellId));
            }
            else if (cap == "spellname")
            {
                quint32 spellId = rx.cap(6).toInt();
                if (SpellInfo const* other = GetSpellInfo(spellId))
                {
                    str.replace(rx.cap(0), QString::fromUtf8(other->SpellName) + "<br>");
                    str = getDescription(str, other);
                }
                else
                    str.replace(rx.cap(0), QString("<Spell %0 needed for spell name not found>").arg(spellId));
            }
            else if (cap == "spellicon")
            {
                quint32 spellId = rx.cap(6).toInt();
                if (SpellInfo const* other = GetSpellInfo(spellId))
                {
                    QString iconStr = QString(
                                        "<br><br><img src=\"http://wow.zamimg.com/images/wow/icons/small/%0.jpg\"><br>"
                                        ).arg(other->getSpellIconName().toLower());

                    str.replace(rx.cap(0), iconStr);
                    str = getDescription(str, other);
                }
                else
                    str.replace(rx.cap(0), QString("<Spell %0 needed for icon link not found>").arg(spellId));
            }
            else
            {
                QChar symbol = rx.cap(5)[0].toLower();
                switch (symbol.toLatin1())
                {
                    case 'u': RegExpU(spellInfo, rx, str); break;
                    case 'h': RegExpH(spellInfo, rx, str); break;
                    case 'z': str.replace(rx.cap(0), QString("[Home]")); break;
                    case 'v': RegExpV(spellInfo, rx, str); break;
                    case 'q': RegExpQ(spellInfo, rx, str); break;
                    case 'i': RegExpI(spellInfo, rx, str); break;
                    case 'b': RegExpB(spellInfo, rx, str); break;
                    case 'm':
                    case 's':
                        RegExpS(spellInfo, rx, str);
                        break;
                    case 'a': RegExpA(spellInfo, rx, str); break;
                    case 'd': RegExpD(spellInfo, rx, str); break;
                    case 'o': RegExpO(spellInfo, rx, str); break;
                    case 't': RegExpT(spellInfo, rx, str); break;
                    case 'l': str.replace(rx.cap(0), rx.cap(9)); break;
                    case 'g': str.replace(rx.cap(0), rx.cap(8)); break;
                    case 'n': RegExpN(spellInfo, rx, str); break;
                    case 'x': RegExpX(spellInfo, rx, str); break;
                    default: return str;
                }
            }
            QMessageBox::warning(NULL, "Desc", str + "\n------------------\n" + cap);
        }
    }
    return str;
}

std::list<quint32> SWObject::getParentSpellIds(quint32 triggerId)
{
    std::list<quint32> l;
    for (auto itr : sSpellInfoStore)
    {
        SpellInfo const* spellInfo = itr.second;
        for (quint8 eff = EFFECT_INDEX_0; eff < MAX_EFFECT_INDEX; ++eff)
        {
            if (spellInfo->getEffectTriggerSpell(eff) == triggerId)
                l.push_back(spellInfo->Id);
            else if ((spellInfo->getEffectApplyAuraName(eff) == 332 || spellInfo->getEffectApplyAuraName(eff) == 333) &&
                     spellInfo->getEffectBasePoints(eff) == triggerId)
                l.push_back(spellInfo->Id);
        }
    }

    return l;
}

void SWObject::showInfo(SpellInfo const* spellInfo, quint8 num)
{
    if (!spellInfo)
        return;

    QWebView* browser = m_form->getBrowser(num);
    html.clear();

    QString sName(QString::fromUtf8(spellInfo->SpellName));
    QString sDescription(QString::fromUtf8(spellInfo->Description));
    QString sRank(QString::fromUtf8(spellInfo->Rank));
    QString sToolTip(QString::fromUtf8(spellInfo->ToolTip));
    QString sSpellFamilyFlags[MAX_CLASS_MASK];
    for (auto i = 0; i < MAX_CLASS_MASK; ++i)
        sSpellFamilyFlags[i] = QString("%0").arg(spellInfo->getSpellFamilyFlags(i), 8, 16, QChar('0'));
    QString sAttributes(QString("%0").arg(spellInfo->getAttributes(), 8, 16, QChar('0')));
    QString sAttributesEx1(QString("%0").arg(spellInfo->getAttributesEx1(), 8, 16, QChar('0')));
    QString sAttributesEx2(QString("%0").arg(spellInfo->getAttributesEx2(), 8, 16, QChar('0')));
    QString sAttributesEx3(QString("%0").arg(spellInfo->getAttributesEx3(), 8, 16, QChar('0')));
    QString sAttributesEx4(QString("%0").arg(spellInfo->getAttributesEx4(), 8, 16, QChar('0')));
    QString sAttributesEx5(QString("%0").arg(spellInfo->getAttributesEx5(), 8, 16, QChar('0')));
    QString sAttributesEx6(QString("%0").arg(spellInfo->getAttributesEx6(), 8, 16, QChar('0')));
    QString sAttributesEx7(QString("%0").arg(spellInfo->getAttributesEx7(), 8, 16, QChar('0')));
    QString sAttributesEx8(QString("%0").arg(spellInfo->getAttributesEx8(), 8, 16, QChar('0')));
    QString sAttributesEx9(QString("%0").arg(spellInfo->getAttributesEx9(), 8, 16, QChar('0')));
    QString sAttributesEx10(QString("%0").arg(spellInfo->getAttributesEx10(), 8, 16, QChar('0')));
    QString sAttributesEx11(QString("%0").arg(spellInfo->getAttributesEx11(), 8, 16, QChar('0')));
    QString sTargetMask(QString("%0").arg(spellInfo->getTargets(), 8, 16, QChar('0')));
    QString sCreatureTypeMask(QString("%0").arg(spellInfo->getTargetCreatureType(), 8, 16, QChar('0')));
    QString sFormMask(QString("%0").arg(spellInfo->getStances(), 8, 16, QChar('0')));
    QString sFormMaskNot(QString("%0").arg(spellInfo->getStancesNot(), 8, 16, QChar('0')));
    QString sIF(QString("%0").arg(spellInfo->getInterruptFlags(), 8, 16, QChar('0')));
    QString sAIF(QString("%0").arg(spellInfo->getAuraInterruptFlags(), 8, 16, QChar('0')));
    QString sCIF(QString("%0").arg(spellInfo->getChannelInterruptFlags(), 8, 16, QChar('0')));

    html.append("<html>"
                "<head>"
                "<link rel='stylesheet' type='text/css' href='qrc:///SpellWork/Recources/styles.css'>"
                "</head>");

    html.append(QString("<body>"
                        "<div class='b-tooltip_icon'>"
                        "<style>"
                        "div.icon { width: 68px; height: 68px; background: url(http://wow.zamimg.com/images/wow/icons/large/%0.jpg) no-repeat center; }"
                        "div.icon div { background: url(http://wow.zamimg.com/images/Icon/large/border/default.png) no-repeat center;}"
                        "div.icon div div:hover { background: url(http://wow.zamimg.com/images/Icon/large/hilite/default.png) no-repeat center; }"
                        "div.icon div div {width: 68px; height: 68px;}"
                        "</style>"
                        "<div class='icon'><div><div>"
                        "</div></div></div>"
                        "</div>").arg(spellInfo->getSpellIconName().toLower()));

    html.append("<div class='b-tooltip_body'>");

    if (!sRank.isEmpty())
        sName.append(QString(" (%0)").arg(sRank));
    
    html.append(QString("<b>Id:</b> %0<br />")
        .arg(spellInfo->Id));

    html.append(QString("<b>Name:</b> %0<br />")
        .arg(sName));

    if (!sDescription.isEmpty())
        html.append(QString("<b>Description:</b> %0<br />").arg(getDescription(sDescription, spellInfo)));

    if (!sToolTip.isEmpty())
        html.append(QString("<b>ToolTip:</b> %0<br />").arg(getDescription(sToolTip, spellInfo)));

    html.append("</div>");

    std::list<quint32> parentSpells = getParentSpellIds(spellInfo->Id);
    if (!parentSpells.empty())
    {
        html.append("<div class='b-vlink'><b>Parent spells:</b><br>");
        for (std::list<quint32>::const_iterator itr = parentSpells.begin(); itr != parentSpells.end(); ++itr)
        {
            if (SpellInfo const* parentInfo = GetSpellInfo(*itr))
            {
                QString sParentName(QString::fromUtf8(parentInfo->SpellName));
                QString sParentRank(QString::fromUtf8(parentInfo->Rank));

                if (!sParentRank.isEmpty())
                    sParentName.append(" (" + sParentRank + ")");

                html.append(QString("&nbsp;&nbsp;&nbsp;&nbsp;%0</br>")
                            .arg(getSpellLink(*itr)));
            }
        }
        html.append("</div>");
    }

    html.append("<div class='b-box-title'>General info</div>"
                "<div class='b-box-body'>"
                "<div class='b-box'>"
                "<ul>");

    if (spellInfo->getModalNextSpell())
        html.append(QString("<li>ModalNextSpell: %0</li>")
            .arg(spellInfo->getModalNextSpell()));

    html.append(QString("<li>Category = %0, SpellIconId = %1, SpellBuffIconId = %2, SpellVisual = (%3, %4)</li>")
        .arg(spellInfo->getCategory())
        .arg(spellInfo->getSpellIconId())
        .arg(spellInfo->getSpellBuffIconId())
        .arg(spellInfo->getSpellVisual(0))
        .arg(spellInfo->getSpellVisual(1)));

    html.append(QString("<li>SpellFamilyName = %0 (%1), SpellFamilyFlags = 0x%2 %3 %4 %5 (%6 %7 %8 %9)</li>")
        .arg(m_enums->getSpellFamilies()[spellInfo->getSpellFamilyName()])
        .arg(spellInfo->getSpellFamilyName())
        .arg(sSpellFamilyFlags[3].toUpper())
        .arg(sSpellFamilyFlags[2].toUpper())
        .arg(sSpellFamilyFlags[1].toUpper())
        .arg(sSpellFamilyFlags[0].toUpper())
        .arg(spellInfo->getSpellFamilyFlags(3))
        .arg(spellInfo->getSpellFamilyFlags(2))
        .arg(spellInfo->getSpellFamilyFlags(1))
        .arg(spellInfo->getSpellFamilyFlags(0)));

    html.append(QString("<li>SpellSchoolMask = %0 (%1)</li>")
        .arg(spellInfo->getSchoolMask())
        .arg(containAttributes(spellInfo, TYPE_SCHOOL_MASK)));

    html.append(QString("<li>DamageClass = %0 (%1)</li>")
        .arg(spellInfo->getDamageClass())
        .arg(m_enums->getDamageClasses()[spellInfo->getDamageClass()]));

    html.append(QString("<li>PreventionType = %0 (%1)</li>")
        .arg(spellInfo->getPreventionType())
        .arg(m_enums->getPreventionTypes()[spellInfo->getPreventionType()]));

    html.append("</ul></div></div>");

    if (spellInfo->getAttributes() || spellInfo->getAttributesEx1() || spellInfo->getAttributesEx2() ||
        spellInfo->getAttributesEx3() || spellInfo->getAttributesEx4() || spellInfo->getAttributesEx5() ||
        spellInfo->getAttributesEx6() || spellInfo->getAttributesEx7() || spellInfo->getAttributesEx8() ||
        spellInfo->getAttributesEx9() ||  spellInfo->getAttributesEx10() ||  spellInfo->getAttributesEx11())
    {
        html.append("<div class='b-box-title'>Attributes</div>"
                    "<div class='b-box-body'>"
                    "<div class='b-box'>"
                    "<ul>");

        if (spellInfo->getAttributes())
            html.append(QString("<li>Attributes: 0x%0 (%1)</li>")
                .arg(sAttributes.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR)));

        if (spellInfo->getAttributesEx1())
            html.append(QString("<li>AttributesEx1: 0x%0 (%1)</li>")
                .arg(sAttributesEx1.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX1)));

        if (spellInfo->getAttributesEx2())
            html.append(QString("<li>AttributesEx2: 0x%0 (%1)</li>")
                .arg(sAttributesEx2.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX2)));

        if (spellInfo->getAttributesEx3())
            html.append(QString("<li>AttributesEx3: 0x%0 (%1)</li>")
                .arg(sAttributesEx3.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX3)));

        if (spellInfo->getAttributesEx4())
            html.append(QString("<li>AttributesEx4: 0x%0 (%1)</li>")
                .arg(sAttributesEx4.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX4)));

        if (spellInfo->getAttributesEx5())
            html.append(QString("<li>AttributesEx5: 0x%0 (%1)</li>")
                .arg(sAttributesEx5.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX5)));

        if (spellInfo->getAttributesEx6())
            html.append(QString("<li>AttributesEx6: 0x%0 (%1)</li>")
                .arg(sAttributesEx6.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX6)));

        if (spellInfo->getAttributesEx7())
            html.append(QString("<li>AttributesEx7: 0x%0 (%1)</li>")
                .arg(sAttributesEx7.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX7)));

        if (spellInfo->getAttributesEx8())
            html.append(QString("<li>AttributesEx8: 0x%0 (%1)</li>")
                .arg(sAttributesEx8.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX8)));

        if (spellInfo->getAttributesEx9())
            html.append(QString("<li>AttributesEx9: 0x%0 (%1)</li>")
                .arg(sAttributesEx9.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX9)));

        if (spellInfo->getAttributesEx10())
            html.append(QString("<li>AttributesEx10: 0x%0 (%1)</li>")
                .arg(sAttributesEx10.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX10)));

        if (spellInfo->getAttributesEx11())
            html.append(QString("<li>AttributesEx11: 0x%0 (%1)</li>")
                .arg(sAttributesEx11.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ATTR_EX11)));

        html.append("</ul>"
                    "</div>"
                    "</div>");
    }

    html.append("<div class='b-box-title'>Advanced info</div>"
                "<div class='b-box-body'>"
                "<div class='b-box'>"
                "<ul>");

    appendSpecInfo(spellInfo, num);
    appendTalentInfo(spellInfo, num);

    if (spellInfo->getTargets())
        html.append(QString("<li>Targets Mask = 0x%0 (%1)</li>")
            .arg(sTargetMask.toUpper())
            .arg(containAttributes(spellInfo, TYPE_TARGETS)));

    if (spellInfo->getTargetCreatureType())
        html.append(QString("<li>Creature Type Mask = 0x%0 (%1)</li>")
            .arg(sCreatureTypeMask.toUpper())
            .arg(containAttributes(spellInfo, TYPE_CREATURE)));

    if (spellInfo->getStances())
        html.append(QString("<li>Stances: 0x%0 (%1)</li>")
            .arg(sFormMask.toUpper())
            .arg(containAttributes(spellInfo, TYPE_FORMS)));

    if (spellInfo->getStancesNot())
        html.append(QString("<li>Stances not: 0x%0 (%1)</li>")
            .arg(sFormMaskNot.toUpper())
            .arg(containAttributes(spellInfo, TYPE_FORMS_NOT)));

    appendSkillInfo(spellInfo, num);

    html.append(QString("<li>Spell Level = %0, BaseLevel %1, MaxLevel %2, MaxTargetLevel %3</li>")
        .arg(spellInfo->getSpellLevel())
        .arg(spellInfo->getBaseLevel())
        .arg(spellInfo->getMaxLevel())
        .arg(spellInfo->getMaxTargetLevel()));

    if (spellInfo->getEquippedItemClass() != -1)
    {
        html.append(QString("<li>EquippedItemClass = %0 (%1)</li>")
            .arg(spellInfo->getEquippedItemClass())
            .arg(m_enums->getItemClasses()[spellInfo->getEquippedItemClass()]));

        if (spellInfo->getEquippedItemSubClassMask())
        {
            html.append("<ul>");
            QString sItemSubClassMask(QString("%0").arg(spellInfo->getEquippedItemSubClassMask(), 8, 16, QChar('0')));
            switch (spellInfo->getEquippedItemClass())
            {
                case 2: // WEAPON
                html.append(QString("<li>SubClass mask 0x%0 (%1)</li>")
                    .arg(sItemSubClassMask.toUpper())
                    .arg(containAttributes(spellInfo, TYPE_ITEM_WEAPON)));
                    break;
                case 4: // ARMOR
                html.append(QString("<li>SubClass mask 0x%0 (%1)</li>")
                    .arg(sItemSubClassMask.toUpper())
                    .arg(containAttributes(spellInfo, TYPE_ITEM_ARMOR)));
                    break;
                case 15: // MISC
                html.append(QString("<li>SubClass mask 0x%0 (%1)</li>")
                    .arg(sItemSubClassMask.toUpper())
                    .arg(containAttributes(spellInfo, TYPE_ITEM_MISC)));
                    break;
            }

            html.append("</ul>");
        }

        if (spellInfo->getEquippedItemInventoryTypeMask())
        {
            QString sItemInventoryMask(QString("%0").arg(spellInfo->getEquippedItemInventoryTypeMask(), 8, 16, QChar('0')));
            html.append(QString("<li>InventoryType mask = 0x%0 (%1)</li>")
                .arg(sItemInventoryMask.toUpper())
                .arg(containAttributes(spellInfo, TYPE_ITEM_INVENTORY)));
        }
    }

    html.append(QString("<li>Category = %0</li>")
        .arg(spellInfo->getCategory()));

    html.append(QString("<li>DispelType = %0 (%1)</li>")
        .arg(spellInfo->getDispel())
        .arg(m_enums->getDispelTypes()[spellInfo->getDispel()]));

    html.append(QString("<li>Mechanic = %0 (%1)</li>")
        .arg(spellInfo->getMechanic())
        .arg(m_enums->getMechanics()[spellInfo->getMechanic()]));

    appendRangeInfo(spellInfo, num);

    if (quint32 maxTargets = spellInfo->getMaxAffectedTargets())
        html.append(QString("<li>Max affected targets: %0</li>")
            .arg(maxTargets));

    if (spellInfo->getSpeed())
        html.append(QString("<li>Speed: %0</li>")
            .arg(spellInfo->getSpeed(), 0, 'f', 2));

    if (spellInfo->getStackAmount())
        html.append(QString("<li>Stackable up to %0</li>")
            .arg(spellInfo->getStackAmount()));

    appendCastTimeInfo(spellInfo, num);

    if (spellInfo->getRecoveryTime() || spellInfo->getCategoryRecoveryTime() || spellInfo->getStartRecoveryCategory())
    {
        html.append(QString("<li>RecoveryTime: %0 ms, CategoryRecoveryTime: %1 ms</li>")
            .arg(spellInfo->getRecoveryTime())
            .arg(spellInfo->getCategoryRecoveryTime()));

        html.append(QString("<li>StartRecoveryCategory = %0, StartRecoveryTime = %1 ms</li>")
            .arg(spellInfo->getStartRecoveryCategory())
            .arg(float(spellInfo->getStartRecoveryTime()), 0, 'f', 2));
    }

    appendDurationInfo(spellInfo, num);

    if (spellInfo->getManaCost() || spellInfo->getManaCostPercentage())
    {
        if (spellInfo->getManaCost())
        {
            html.append(QString("<li>Power Type = %0, Cost %1")
                .arg(m_enums->getPowers()[spellInfo->getPowerType()])
                .arg(spellInfo->getManaCost()));
        }
        else if (spellInfo->getManaCostPercentage())
        {
            html.append(QString("<li>Power Type = %0, Cost %1% of base mana")
                .arg(m_enums->getPowers()[spellInfo->getPowerType()])
                .arg(spellInfo->getManaCostPercentage()));
        }

        if (spellInfo->getManaCostPerLevel())
            html.append(QString(" + lvl * %0")
                .arg(spellInfo->getManaCostPerLevel()));

        if (spellInfo->getManaPerSecond())
            html.append(QString(" + %0 Per Second")
                .arg(spellInfo->getManaPerSecond()));

        html.append("</li>");
    }

    html.append(QString("<li>Interrupt Flags: 0x%0, AuraIF 0x%1, ChannelIF 0x%2</li>")
        .arg(sIF.toUpper())
        .arg(sAIF.toUpper())
        .arg(sCIF.toUpper()));

    if (spellInfo->getCasterAuraState())
        html.append(QString("<li>CasterAuraState = %0 (%1)</li>")
            .arg(spellInfo->getCasterAuraState())
            .arg(m_enums->getAuraStates()[spellInfo->getCasterAuraState()]));

    if (spellInfo->getTargetAuraState())
        html.append(QString("<li>TargetAuraState = %0 (%1)</li>")
            .arg(spellInfo->getTargetAuraState())
            .arg(m_enums->getAuraStates()[spellInfo->getTargetAuraState()]));

    if (spellInfo->getCasterAuraStateNot())
        html.append(QString("<li>CasterAuraStateNot = %0 (%1)</li>")
            .arg(spellInfo->getCasterAuraStateNot())
            .arg(m_enums->getAuraStates()[spellInfo->getCasterAuraStateNot()]));

    if (spellInfo->getTargetAuraStateNot())
        html.append(QString("<li>TargetAuraStateNot = %0 (%1)</li>")
            .arg(spellInfo->getTargetAuraStateNot())
            .arg(m_enums->getAuraStates()[spellInfo->getTargetAuraStateNot()]));

    if (quint32 spellId = spellInfo->getCasterAuraSpell())
        html.append(QString("<li>Caster Aura Spell: %0</li>")
                    .arg(getSpellLink(spellId)));

    if (quint32 spellId = spellInfo->getTargetAuraSpell())
        html.append(QString("<li>Target Aura Spell: %0</li>")
                    .arg(getSpellLink(spellId)));

    if (quint32 spellId = spellInfo->getExcludeCasterAuraSpell())
        html.append(QString("<li>Ex Caster Aura Spell: %0</li>")
                    .arg(getSpellLink(spellId)));

    if (quint32 spellId = spellInfo->getExcludeTargetAuraSpell())
        html.append(QString("<li>Ex Target Aura Spell: %0</li>")
                    .arg(getSpellLink(spellId)));

    if (spellInfo->getRequiresSpellFocus())
        html.append(QString("<li>Requires Spell Focus %0</li>")
            .arg(spellInfo->getRequiresSpellFocus()));

    if (spellInfo->getProcFlags())
    {
        QString sProcFlags(QString("%0").arg(spellInfo->getProcFlags(), 8, 16, QChar('0')));
        html.append(QString("<li><b>Proc flag 0x%0, chance = %1, charges - %2</b></li>")
            .arg(sProcFlags.toUpper())
            .arg(spellInfo->getProcChance())
            .arg(spellInfo->getProcCharges()));

        appendProcInfo(spellInfo, num);
    }
    else
    {
        html.append(QString("<li>Chance = %0, charges - %1</li>")
            .arg(spellInfo->getProcChance())
            .arg(spellInfo->getProcCharges()));
    }

    appendReplacementInfo(spellInfo, num);

    appendAffectsInfo(spellInfo, num);

    html.append("</ul></div></div>");

    appendSpellEffectInfo(spellInfo, num);

    html.append("</body></html>");

    // Formatting for debug
    html.replace("><", ">\n<");

    browser->setHtml(html, QUrl(QString("http://spellwork/%0").arg(spellInfo->Id)));
    browser->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void SWObject::appendRangeInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    if (SpellRangeEntry const* range = spellInfo->rangeEntry)
    {
        html.append(QString("<li>SpellRange (Id %0) \"%1\"</li>"
                            "<ul><li>MinRange = %2</li>"
                            "<li>MaxRange = %3</li></ul>")
            .arg(range->Id)
            .arg(QString::fromUtf8(range->Name))
            .arg(range->MinRangeFriendly)
            .arg(range->MaxRangeFriendly));
    }
}

void SWObject::appendProcInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    quint8 i = 0;
    quint64 proc = spellInfo->getProcFlags();

    html.append("<ul>");
    while (proc != 0)
    {
        if ((proc & 1) != 0)
            html.append(QString("<li>%0</li>").arg(ProcFlagDesc[i]));
        ++i;
        proc >>= 1;
    }
    html.append("</ul>");
}

void SWObject::appendSpellEffectInfo(SpellInfo const* spellInfo, quint8 num, quint8 eff, quint8 diff)
{
    if (!spellInfo->getSpellEffect(eff))
    {
        html.append(QString("<li>NO EFFECT</li>"
                            "</ul>").arg(eff));
    }
    else
    {
        QString _BasePoints(QString("<li>BasePoints = %0").arg(spellInfo->getEffectBasePoints(eff, diff)));

        QString _RealPoints;
        if (spellInfo->getEffectRealPointsPerLevel(eff, diff) != 0)
            _RealPoints = QString(" + Level * %0").arg(spellInfo->getEffectRealPointsPerLevel(eff, diff), 0, 'f', 2);

        QString _DieSides;
        if (1 < spellInfo->getEffectDieSides(eff, diff))
        {
            if (spellInfo->getEffectRealPointsPerLevel(eff, diff) != 0)
                _DieSides = QString(" to %0 + lvl * %1")
                .arg(spellInfo->getEffectBasePoints(eff, diff) + spellInfo->getEffectDieSides(eff, diff))
                    .arg(spellInfo->getEffectRealPointsPerLevel(eff, diff), 0, 'f', 2);
            else
                _DieSides = QString(" to %0").arg(spellInfo->getEffectBasePoints(eff, diff) + spellInfo->getEffectDieSides(eff, diff));
        }

        QString _PointsPerCombo;
        if (spellInfo->getEffectPointsPerComboPoint(eff, diff) != 0)
            _PointsPerCombo = QString(" + combo * %0").arg(spellInfo->getEffectPointsPerComboPoint(eff, diff), 0, 'f', 2);

        QString _DamageMultiplier;
        if (spellInfo->getEffectDamageMultiplier(eff, diff) != 1.0f)
            _DamageMultiplier = QString(" * %0").arg(spellInfo->getEffectDamageMultiplier(eff, diff), 0, 'f', 2);

        QString _Multiple;
        if (spellInfo->getEffectValueMultiplier(eff, diff) != 0)
            _Multiple = QString(", Multiple = %0").arg(spellInfo->getEffectValueMultiplier(eff, diff), 0, 'f', 2);

        QString _Result = _BasePoints + _RealPoints + _DieSides + _PointsPerCombo + _DamageMultiplier + _Multiple + "</li>";

        html.append(QString("<li>Id: %0 (%1)</li>")
            .arg(spellInfo->getEffect(eff, diff))
            .arg(m_enums->getSpellEffects()[spellInfo->getEffect(eff, diff)]));

        html.append(_Result);

        html.append(QString("<li>EffectBonusCoefficient = %0</li>").arg(spellInfo->getEffectBonusCoefficient(eff, diff)));
        html.append(QString("<li>Targets (%0, %1) (%2, %3)</li>")
            .arg(spellInfo->getEffectImplicitTargetA(eff, diff))
            .arg(spellInfo->getEffectImplicitTargetB(eff, diff))
            .arg(m_enums->getTargets()[spellInfo->getEffectImplicitTargetA(eff, diff)])
            .arg(m_enums->getTargets()[spellInfo->getEffectImplicitTargetB(eff, diff)]));

        if (quint32 effectItemType = spellInfo->getEffectItemType(eff, diff))
            html.append(QString("<li>EffectItemType: %0</li>").arg(effectItemType));

        appendAuraInfo(spellInfo, eff, num, diff);

        appendRadiusInfo(spellInfo, eff, num, diff);

        appendTriggerInfo(spellInfo, eff, num, diff);

        if (quint32 effectChainTarget = spellInfo->getEffectChainTarget(eff, diff))
            html.append(QString("<li>EffectChainTarget = %0</li>").arg(effectChainTarget));

        if (quint32 effectMechanic = spellInfo->getEffectMechanic(eff, diff) != 0)
        {
            html.append(QString("<li>Effect Mechanic = %0 (%1)</li>")
                .arg(effectMechanic)
                .arg(m_enums->getMechanics()[effectMechanic]));
        }

        quint32 ClassMask[MAX_CLASS_MASK];
        for (auto i = 0; i < MAX_CLASS_MASK; ++i)
            ClassMask[i] = spellInfo->getEffectSpellClassMask(eff, i, diff);

        for (auto i = 0; i < MAX_CLASS_MASK; ++i)
        {
            if (!ClassMask[i])
                continue;

            QString sClassMask3(QString("%0").arg(ClassMask[3], 8, 16, QChar('0')));
            QString sClassMask2(QString("%0").arg(ClassMask[2], 8, 16, QChar('0')));
            QString sClassMask1(QString("%0").arg(ClassMask[1], 8, 16, QChar('0')));
            QString sClassMask0(QString("%0").arg(ClassMask[0], 8, 16, QChar('0')));

            html.append(QString("<li>SpellClassMask = %0 %1 %2 %3</li>")
                            .arg(sClassMask3.toUpper())
                            .arg(sClassMask2.toUpper())
                            .arg(sClassMask1.toUpper())
                            .arg(sClassMask0.toUpper()));

            html.append("<ul>");
            for (auto itr : sSpellInfoStore)
            {
                SpellInfo const* t_spellInfo = itr.second;
                bool hasSkill = false;
                if ((itr.second->getSpellFamilyName() == spellInfo->getSpellFamilyName()) &&
                    ((itr.second->getSpellFamilyFlags(0) & ClassMask[0]) ||
                     (itr.second->getSpellFamilyFlags(1) & ClassMask[1]) ||
                     (itr.second->getSpellFamilyFlags(2) & ClassMask[2]) ||
                     (itr.second->getSpellFamilyFlags(3) & ClassMask[3])))
                {
                    QString sName(QString::fromUtf8(t_spellInfo->SpellName));
                    QString sRank(QString::fromUtf8(t_spellInfo->Rank));

                    if (!sRank.isEmpty())
                        sName.append(" (" + sRank + ")");

                    for (quint32 sk = 0; sk < sSkillLineAbilityStore.GetNumRows(); sk++)
                    {
                        SkillLineAbilityEntry const* skillInfo = sSkillLineAbilityStore.LookupEntry(sk);
                        if (skillInfo && skillInfo->SpellId == t_spellInfo->Id && skillInfo->SkillId > 0)
                        {
                            hasSkill = true;
                            html.append(QString("<li><a href='http://spellwork/%1' class='blue_link'>+ %1 - %2</a></li>")
                                    .arg(t_spellInfo->Id)
                                    .arg(sName));
                            break;
                        }
                    }

                    if (!hasSkill)
                    {
                        html.append(QString("<li><a href='http://spellwork/%1' class='red_link'>- %1 - %2</a></li>")
                                .arg(t_spellInfo->Id)
                                .arg(sName));
                    }
                }
            }
            html.append("</ul>");
            break;
        }
        html.append("</ul>");
    }

    if (spellInfo->hasDifficultyData && diff == 0)
        for (quint8 i = 1; i < MAX_DIFFICULTY; ++i)
            if (spellInfo->getSpellEffect(eff, i))
            {
                html.append(QString("<details><summary>Replace at %0 (%1):</summary><ul>")
                            .arg(m_enums->getDifficulties()[i]).arg(i));
                appendSpellEffectInfo(spellInfo, num, eff, i);
                html.append("</ul></details>");
            }
}

void SWObject::appendSpellEffectInfo(SpellInfo const* spellInfo, quint8 num)
{
    html.append("<div class='b-box-title'>Effects</div>"
                "<div class='b-box-body'>"
                "<div class='b-box'>");

    quint8 effectsCount = spellInfo->getMaxEffect();
    for (quint8 eff = 0; eff < effectsCount; ++eff)
    {
        html.append(QString("<div class='b-effect_name'>Effect %0:</div>"
                "<ul>").arg(eff));
        appendSpellEffectInfo(spellInfo, num, eff, 0);
    }
    html.append("</div></div>");
}

void SWObject::appendTriggerInfo(SpellInfo const* spellInfo, quint8 index, quint8 num, quint8 diff)
{
    quint32 trigger = spellInfo->getEffectTriggerSpell(index, diff);
    if (!trigger)
        return;

    SpellInfo const* triggerSpell = GetSpellInfo(trigger);
    if (!triggerSpell)
    {
        html.append(QString("<li>Trigger spell: %0 Not found</li>").arg(trigger));
        return;
    }

    QString sName(QString::fromUtf8(triggerSpell->SpellName));
    QString sRank(QString::fromUtf8(triggerSpell->Rank));

    if (!sRank.isEmpty())
        sName.append(" (" + sRank + ")");

    html.append(QString("<li><b>Trigger spell:</b> %0. Chance = %1</li>")
                .arg(getSpellLink(triggerSpell->Id))
                .arg(triggerSpell->getProcChance()));

    QString sDescription(QString::fromUtf8(triggerSpell->Description));
    QString sTooltip(QString::fromUtf8(triggerSpell->ToolTip));

    html.append("<ul>");

    if (!sDescription.isEmpty())
        html.append(QString("<li>Description: %0</li>").arg(getDescription(sDescription, triggerSpell)));

    if (!sTooltip.isEmpty())
        html.append(QString("<li>ToolTip: %0</li>").arg(getDescription(sTooltip, triggerSpell)));

    if (triggerSpell->getProcFlags() != 0)
    {
        html.append(QString("<li>Charges - %0</li>").arg(triggerSpell->getProcCharges()));
        html.append("<hr style='margin: 0 25px;'>");
        appendProcInfo(triggerSpell, num);
    }

    html.append("</ul>");
}

void SWObject::appendRadiusInfo(SpellInfo const* spellInfo, quint8 index, quint8 /*num*/, quint8 diff)
{
    SpellRadiusEntry const* spellRadius = spellInfo->spellRadius[diff][index];
    SpellRadiusEntry const* spellRadiusMax = spellInfo->spellRadiusMax[diff][index];
    if (!spellRadius && !spellRadiusMax)
        return;

    QString str = QString("<li>Radius (Id %0) %1 Max: (Id %2) %3</li>");
    str = str.arg(spellInfo->getEffectRadiusIndex(index, diff));
    if (spellRadius)
        str = str.arg(spellRadius->Radius, 0, 'f', 2);
    else
        str = str.arg("Not found");
    str = str.arg(spellInfo->getEffectRadiusMaxIndex(index, diff));
    if (spellRadiusMax)
        str = str.arg(spellRadiusMax->Radius, 0, 'f', 2);
    else
        str = str.arg("Not found");

    html.append(str);
}

void SWObject::appendAuraInfo(SpellInfo const* spellInfo, quint8 index, quint8 /*num*/, quint8 diff)
{
    QString sAura(m_enums->getSpellAuras()[spellInfo->getEffectApplyAuraName(index, diff)]);
    quint32 misc = spellInfo->getEffectMiscValue(index);

    if (spellInfo->getEffectApplyAuraName(index, diff) == 0)
    {
        if (misc)
            html.append(QString("<li>EffectMiscValueA = %0</li>").arg(misc));

        if (quint32 effectMiscValueB = spellInfo->getEffectMiscValueB(index, diff))
            html.append(QString("<li>EffectMiscValueB = %0</li>").arg(effectMiscValueB));

        if (quint32 effectAmplitude = spellInfo->getEffectAmplitude(index, diff))
            html.append(QString("<li>EffectAmplitude = %0</li>").arg(effectAmplitude));

        return;
    }

    QString sBp = "%0";
    quint32 auraId = spellInfo->getEffectApplyAuraName(index, diff);
    if (auraId == 332 || auraId == 333)
    {
        if (quint32 bp = spellInfo->getEffectBasePoints(index, diff))
            sBp = getSpellLink(bp);
        else
            sBp = sBp.arg(0);
    }
    else
        sBp = sBp.arg(spellInfo->getEffectBasePoints(index, diff));

    QString _BaseAuraInfo = QString("<li>Aura Id %0 (%1), value = %2, misc = %3 ")
        .arg(auraId)
        .arg(sAura)
        .arg(sBp)
        .arg(misc);

    QString _SpecialAuraInfo;
    switch (spellInfo->getEffectApplyAuraName(index, diff))
    {
        case 29:
            _SpecialAuraInfo = QString("(%0").arg(m_enums->getUnitMods()[misc]);
            break;
        case 189:
            _SpecialAuraInfo = QString("(%0").arg(containAttributes(spellInfo, TYPE_CR, index));
            break;
        case 107:
        case 108:
            _SpecialAuraInfo = QString("(%0").arg(m_enums->getSpellMods()[misc]);
            break;
        // todo: more case
        default:
            _SpecialAuraInfo = QString("(%0").arg(misc);
            break;
    }

    QString _MiscB = QString("), miscB = %0").arg(spellInfo->getEffectMiscValueB(index, diff));
    QString _Periodic = QString(", periodic = %0").arg(spellInfo->getEffectAmplitude(index, diff));
    QString _Result = _BaseAuraInfo + _SpecialAuraInfo + _MiscB + _Periodic;
    html.append(_Result + "</li>");
}

QString SWObject::containAttributes(SpellInfo const* spellInfo, AttrType attr, quint8 index)
{
    QString str("");
    switch (attr)
    {
        case TYPE_ATTR:
        {
            EnumIterator itr(m_enums->getAttributes());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributes() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX1:
        {
            EnumIterator itr(m_enums->getAttributesEx1());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx1() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX2:
        {
            EnumIterator itr(m_enums->getAttributesEx2());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx2() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX3:
        {
            EnumIterator itr(m_enums->getAttributesEx3());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx3() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX4:
        {
            EnumIterator itr(m_enums->getAttributesEx4());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx4() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX5:
        {
            EnumIterator itr(m_enums->getAttributesEx5());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx5() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX6:
        {
            EnumIterator itr(m_enums->getAttributesEx6());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx6() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX7:
        {
            EnumIterator itr(m_enums->getAttributesEx7());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx7() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX8:
        {
            EnumIterator itr(m_enums->getAttributesEx8());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx8() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX9:
        {
            EnumIterator itr(m_enums->getAttributesEx9());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx9() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX10:
        {
            EnumIterator itr(m_enums->getAttributesEx10());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx10() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ATTR_EX11:
        {
            EnumIterator itr(m_enums->getAttributesEx11());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getAttributesEx11() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_TARGETS:
        {
            EnumIterator itr(m_enums->getTargetFlags());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getTargets() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_CREATURE:
        {
            EnumIterator itr(m_enums->getCreatureTypes());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getTargetCreatureType() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_FORMS:
        {
            EnumIterator itr(m_enums->getShapeshiftForms());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getStances() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_FORMS_NOT:
        {
            EnumIterator itr(m_enums->getShapeshiftForms());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getStancesNot() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ITEM_WEAPON:
        {
            EnumIterator itr(m_enums->getItemSubClassWeapons());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getEquippedItemSubClassMask() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ITEM_ARMOR:
        {
            EnumIterator itr(m_enums->getItemSubClassArmors());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getEquippedItemSubClassMask() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ITEM_MISC:
        {
            EnumIterator itr(m_enums->getItemSubClassMiscs());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getEquippedItemSubClassMask() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_ITEM_INVENTORY:
        {
            EnumIterator itr(m_enums->getInventoryTypes());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getEquippedItemInventoryTypeMask() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_CR:
        {
            EnumIterator itr(m_enums->getCombatRatings());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getEffectMiscValue(index) & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        case TYPE_SCHOOL_MASK:
        {
            EnumIterator itr(m_enums->getSchools());
            while (itr.hasNext())
            {
                itr.next();
                if (spellInfo->getSchoolMask() & itr.key())
                {
                    QString tstr(QString("%0, ").arg(itr.value()));
                    str += tstr;
                }
            }
            if (!str.isEmpty())
                str.chop(2);
            return str;
        }
        break;
        default:
        break;
    }
    return str;
}

QString SWObject::getClassName(quint32 unitClass)
{
    ChrClassesEntry const* entry = sChrClassesStore.LookupEntry(unitClass);

    return entry ? entry->name : "Unknown";
}

void SWObject::appendSpecInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    QString specInfo;
    for (quint32 i = 0; i < sSpecializationSpellsStore.GetNumRows(); ++i)
    {
        if (SpecializationSpellsEntry const* entry = sSpecializationSpellsStore.LookupEntry(i))
        {
            if (entry->LearnSpell != spellInfo->Id)
                continue;

            if (ChrSpecializationsEntry const* spec = sChrSpecializationStore.LookupEntry((entry->Spec)))
                specInfo += QString("<li>%0 - \"%1\"")
                        .arg(entry->Spec).arg(spec->specializationName);
            else
                specInfo += QString("<li>%0 - \"%1\"")
                        .arg(entry->Spec).arg("Unknown");

            if (entry->OverrideSpell)
                specInfo += QString(", replaces: %0</li>").arg(getSpellLink(entry->OverrideSpell));
            else
                specInfo += "</li>";

        }
    }

    if (specInfo.size() > 0)
    {
        html.append(QString("<li>Used in specializations:</li>"
                            "<ul>%0</ul></li>")
                    .arg(specInfo));
    }
}

void SWObject::appendTalentInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    TalentEntry const* entry = spellInfo->talentEntry;
    if (!entry)
        return;

    QString app = QString("<li>Talent Id: %0 Class: \"%1\" (%2)</li>")
            .arg(entry->Id).arg(getClassName(entry->Class)).arg(entry->Class);
    if (entry->replaceSpellId)
        app += QString("<ul><li>Overrides spell: %0</li></ul>").arg(getSpellLink(entry->replaceSpellId));
    html.append(app);
}

void SWObject::appendReplacementInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    QString auraReplaceInfo;
    for (auto itr : sSpellInfoStore)
    {
        SpellInfo const* entry = itr.second;
        if (entry->getSpellFamilyName() != spellInfo->getSpellFamilyName())
            continue;

        bool matches = false;
        for (quint32 eff = 0; eff < MAX_EFFECT_INDEX; ++eff)
        {
            if (entry->getEffectApplyAuraName(eff) == 332 || entry->getEffectApplyAuraName(eff) == 333)
            {
                quint32 replaceSpell = entry->getEffectBasePoints(eff);
                if (replaceSpell == spellInfo->Id)
                    break;

                for (quint32 j = 0; j < MAX_CLASS_MASK; ++j)
                    if (entry->getEffectSpellClassMask(eff, j) & spellInfo->getSpellFamilyFlags(j))
                    {
                        matches = true;
                        auraReplaceInfo += QString("<li>Replaced by %0 aura to %1</li>")
                                .arg(getSpellLink(entry->Id))
                                .arg(getSpellLink(replaceSpell));
                        break;
                    }
                if (matches)
                    break;
            }
        }
    }

    QString talentReplaceInfo;
    for (quint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        if (TalentEntry const* entry = sTalentStore.LookupEntry(i))
        {
            if (entry->replaceSpellId != spellInfo->Id)
                continue;

            talentReplaceInfo += QString("<li>Replaced by %0 talent (%1)</li>")
                    .arg(getSpellLink(entry->spell))
                    .arg(entry->Id);
        }
    }

    QString specReplaceInfo;
    for (quint32 i = 0; i < sSpecializationSpellsStore.GetNumRows(); ++i)
    {
        if (SpecializationSpellsEntry const* entry = sSpecializationSpellsStore.LookupEntry(i))
        {
            if (entry->OverrideSpell != spellInfo->Id)
                continue;

            SpellInfo const* replace = GetSpellInfo(entry->LearnSpell);
            if (!replace)
                continue;

            specReplaceInfo += QString("<li>Replaced by %0 spell in \"%1\" (%2) specialization.</li>")
                    .arg(getSpellLink(replace->Id));

            if (ChrSpecializationsEntry const* spec = sChrSpecializationStore.LookupEntry(entry->Spec))
                specReplaceInfo = specReplaceInfo.arg(spec->specializationName).arg(entry->Spec);
            else
                specReplaceInfo = specReplaceInfo.arg("Unknown").arg(entry->Spec);
        }
    }

    if (!auraReplaceInfo.size() && !talentReplaceInfo.size() && !specReplaceInfo.size())
        return;

    html.append("<li>Replacements:</li>");

    if (auraReplaceInfo.size() > 0)
        html.append(QString("<ul>%0</ul>").arg(auraReplaceInfo));
    if (talentReplaceInfo.size() > 0)
        html.append(QString("<ul>%0</ul>").arg(talentReplaceInfo));
    if (specReplaceInfo.size() > 0)
        html.append(QString("<ul>%0</ul>").arg(specReplaceInfo));
}

void SWObject::appendSkillInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    for (quint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
    {
        SkillLineAbilityEntry const* skillInfo = sSkillLineAbilityStore.LookupEntry(i);
        if (skillInfo && skillInfo->SpellId == spellInfo->Id)
        {
            if (SkillLineEntry const* skill = sSkillLineStore.LookupEntry(skillInfo->SkillId))
            {
                html.append(QString("<li>Skill (Id %0) \"%1\"</li>"
                                    "<ul><li>ReqSkillValue = %2</li>"
                                    "<li>Forward Spell = %3</li>"
                                    "<li>MinMaxValue (%4, %5)</li>"
                                    "<li>CharacterPoints = %6</li></ul>")
                    .arg(skill->Id)
                    .arg(QString::fromUtf8(skill->Name))
                    .arg(skillInfo->ReqSkillValue)
                    .arg(skillInfo->ForwardSpellId)
                    .arg(skillInfo->MinValue)
                    .arg(skillInfo->MaxValue)
                    .arg(skillInfo->CharPoints));
            }
            else
                html.append(QString("<li>Skill (Id %0) (not found)</li>")
                    .arg(skillInfo->SkillId));
            break;
        }
    }
}

void SWObject::appendAffectsInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    if (!spellInfo->getSpellFamilyName())
        return;

    QString body;
    for (auto itr : sSpellInfoStore)
    {
        SpellInfo const* spell = itr.second;

        if (spell->getSpellFamilyName() != spellInfo->getSpellFamilyName())
            continue;

        if (spell->Id == spellInfo->Id)
            continue;

        bool _break = false;
        for (quint32 j = 0; j < MAX_EFFECT_INDEX; ++j)
        {
            for (quint32 k = 0; k < MAX_CLASS_MASK; ++k)
                if (spell->getEffectSpellClassMask(j, k) & spellInfo->getSpellFamilyFlags(k))
                {
                    body += getSpellLink(spell) + "\n";
                    _break =true;
                    break;
                }
            if (_break)
                break;
        }
    }

    if (body.isEmpty())
        return;

    html.append(QString("<br><details><summary>This spell is affected by:</summary><pre>%0</pre></details>")
                .arg(body));
}

void SWObject::appendCastTimeInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    if (SpellCastTimesEntry const* castInfo = spellInfo->castTimeEntry)
    {
        html.append(QString("<li>CastingTime (Id %0) = %1</li>")
            .arg(castInfo->Id)
            .arg(float(castInfo->CastTime) / 1000, 0, 'f', 2));
    }
}

void SWObject::appendDurationInfo(SpellInfo const* spellInfo, quint8 /*num*/)
{
    if (SpellDurationEntry const* durationInfo = spellInfo->durationInfo)
    {
        html.append(QString("<li>Duration: ID (%0)  %1, %2, %3</li>")
            .arg(durationInfo->Id)
            .arg(durationInfo->Duration[0])
            .arg(durationInfo->Duration[1])
            .arg(durationInfo->Duration[2]));
    }
}

void SWObject::compare()
{
    QStringList list1 = m_form->webView2->page()->mainFrame()->toHtml().split("\n");
    QStringList list2 = m_form->webView3->page()->mainFrame()->toHtml().split("\n");

    QString html2;
    html.clear();
    html2.clear();

    QRegExp rx("(<[A-Za-z_0-9]*>)+([A-Za-z_0-9-!\"#$%&'()*+,./:;=?@[\\]_`{|}~\\s]*)+(</[A-Za-z_0-9]*>)");

    for (QStringList::iterator itr1 = list1.begin(); itr1 != list1.end(); ++itr1)
    {
        bool yes = false;

        for (QStringList::iterator itr2 = list2.begin(); itr2 != list2.end(); ++itr2)
        {
            if ((*itr1) == (*itr2))
            {
                yes = true;
                break;
            }
        }

        if (yes)
        {
            if (rx.indexIn((*itr1)) != -1)
            {
                // QString r1 = rx.cap(0); // Full
                QString r2 = rx.cap(1); // <xxx>
                QString r3 = rx.cap(2); // <>xxx</>
                QString r4 = rx.cap(3); // </xxx>

                if (r2 == "<b>")
                    html.append(QString("<span style='background-color: cyan'>%0</span>").arg((*itr1)));
                else if (r2 == "<style>")
                {
                    html.append((*itr1));
                }
                else
                {
                    r3 = QString("<span style='background-color: cyan'>%0</span>").arg(r3);
                    r3.prepend(r2);
                    r3.append(r4);
                    html.append(r3);
                }
            }
            else
                html.append((*itr1));
        }
        else
        {
            if (rx.indexIn((*itr1)) != -1)
            {
                // QString r1 = rx.cap(0); // Full
                QString r2 = rx.cap(1); // <xxx>
                QString r3 = rx.cap(2); // <>xxx</>
                QString r4 = rx.cap(3); // </xxx>

                if (r2 == "<b>")
                    html.append(QString("<span style='background-color: salmon'>%0</span>").arg((*itr1)));
                else if (r2 == "<style>")
                {
                    html.append((*itr1));
                }
                else
                {
                    r3 = QString("<span style='background-color: salmon'>%0</span>").arg(r3);
                    r3.prepend(r2);
                    r3.append(r4);
                    html.append(r3);
                }
            }
            else
                html.append((*itr1));
        }
    }

    // second
    for (QStringList::iterator itr2 = list2.begin(); itr2 != list2.end(); ++itr2)
    {
        bool yes = false;

        for (QStringList::iterator itr1 = list1.begin(); itr1 != list1.end(); ++itr1)
        {
            if ((*itr2) == (*itr1))
            {
                yes = true;
                break;
            }
        }

        if (yes)
        {
            if (rx.indexIn((*itr2)) != -1)
            {
                // QString r1 = rx.cap(0); // Full
                QString r2 = rx.cap(1); // <xxx>
                QString r3 = rx.cap(2); // <>xxx</>
                QString r4 = rx.cap(3); // </xxx>

                if (r2 == "<b>")
                    html2.append(QString("<span style='background-color: cyan'>%0</span>").arg((*itr2)));
                else if (r2 == "<style>")
                {
                    html2.append((*itr2));
                }
                else
                {
                    r3 = QString("<span style='background-color: cyan'>%0</span>").arg(r3);
                    r3.prepend(r2);
                    r3.append(r4);
                    html2.append(r3);
                }
            }
            else
                html2.append((*itr2));
        }
        else
        {
            if (rx.indexIn((*itr2)) != -1)
            {
                // QString r1 = rx.cap(0); // Full
                QString r2 = rx.cap(1); // <xxx>
                QString r3 = rx.cap(2); // <>xxx</>
                QString r4 = rx.cap(3); // </xxx>

                if (r2 == "<b>")
                    html2.append(QString("<span style='background-color: salmon'>%0</span>").arg((*itr2)));
                else if (r2 == "<style>")
                {
                    html2.append((*itr2));
                }
                else
                {
                    r3 = QString("<span style='background-color: salmon'>%0</span>").arg(r3);
                    r3.prepend(r2);
                    r3.append(r4);
                    html2.append(r3);
                }
            }
            else
                html2.append((*itr2));
        }
    }

    m_form->webView2->setHtml(html);
    m_form->webView3->setHtml(html2);
}

QString SWObject::getSpellLink(quint32 spellId)
{
    if (SpellInfo const* info = GetSpellInfo(spellId))
        return getSpellLink(info);
    else
        return QString("%0 - not found").arg(spellId);
}

QString SWObject::getSpellLink(SpellInfo const* entry)
{
    return QString("<a href='http://spellwork/%0' class='blue_link'>%0 - %1</a>")
            .arg(entry->Id)
            .arg(QString::fromUtf8(entry->SpellName));
}

quint64 Converter::getULongLong(QString value)
{
    bool ok;
    quint64 dec = value.toULongLong(&ok, 10);
    return ok ? dec : value.toULongLong(&ok, 16);
}

qint64 Converter::getLongLong(QString value)
{
    bool ok;
    qint64 dec = value.toLongLong(&ok, 10);
    return ok ? dec : value.toLongLong(&ok, 16);
}

quint32 Converter::getULong(QString value)
{
    bool ok;
    quint32 dec = value.toULong(&ok, 10);
    return ok ? dec : value.toULong(&ok, 16);
}

qint32 Converter::getLong(QString value)
{
    bool ok;
    qint32 dec = value.toLong(&ok, 10);;
    return ok ? dec : value.toLong(&ok, 16);
}
