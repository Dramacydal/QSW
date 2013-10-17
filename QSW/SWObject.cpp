#include "SWObject.h"
#include "SWSearch.h"

SWObject::SWObject(SWMainForm* form)
    : m_form(form), m_regExp(false), m_type(0), m_enums(form->getEnums())
{
    LoadDBCStores();
}

void SWObject::search()
{
    SWSearch* search = new SWSearch(this);
    search->search();
    delete search;
}

float getRadius(SpellEntry const* spellInfo, quint8 effIndex)
{
    SpellRadiusEntry const* spellRadius = sSpellRadiusStore.LookupEntry(spellInfo->getEffectRadiusIndex(effIndex));
    if (spellRadius)
        return spellRadius->Radius;

    return 0.0f;
}

quint32 getDuration(SpellEntry const* spellInfo)
{
    SpellDurationEntry const* durationInfo = sSpellDurationStore.LookupEntry(spellInfo->getDurationIndex());
    if (durationInfo)
        return quint32(durationInfo->Duration[0] / 1000);

    return 1;
}

quint32 getRealDuration(SpellEntry const* spellInfo, quint8 effIndex)
{
    return quint32(getDuration(spellInfo) / (spellInfo->getEffectAmplitude(effIndex) ? quint32(spellInfo->getEffectAmplitude(effIndex) / 1000) : 5));
}

void RegExpU(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpH(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpV(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpQ(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpI(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpB(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpA(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpD(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpO(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpS(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpT(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(3).isEmpty())
    {
        if (!rx.cap(4).isEmpty())
        {
            SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpN(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

void RegExpX(SpellEntry const* spellInfo, QRegExp rx, QString &str)
{
    if (!rx.cap(4).isEmpty())
    {
        SpellEntry const* tSpell = sSpellStore.LookupEntry(rx.cap(4).toInt());
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

QString SWObject::getDescription(QString str, SpellEntry const* spellInfo)
{
    if (!m_form->isRegExp())
        return str;

    QRegExp rx("\\$+(([/,*])?([0-9]*);)?([d+\\;)(\\d*)?([1-9]*)([A-z])([1-3]*)(([A-z, ]*)\\:([A-z, ]*)\\;)?");
    while (str.contains(rx))
    {
        if (rx.indexIn(str) != -1)
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
    }
    return str;
}

quint32 SWObject::getParentSpellId(quint32 triggerId)
{
    for (quint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
        if (SpellEntry const* spellInfo = sSpellStore.LookupEntry(i))
            for (quint8 eff = EFFECT_INDEX_0; eff < MAX_EFFECT_INDEX; ++eff)
                if (spellInfo->getEffectTriggerSpell(eff) == triggerId)
                    return spellInfo->Id;
    return 0;
}

QString SWObject::getSpellIconName(quint32 iconId)
{
    SpellIconEntry const* iconInfo = sSpellIconStore.LookupEntry(iconId);

    if (!iconInfo)
        return QString("");

    return QString(iconInfo->IconPath).section('\\', -1);
}

void SWObject::showInfo(SpellEntry const* spellInfo, quint8 num)
{
    if (!spellInfo)
        return;

    QWebView* browser = m_form->getBrowser(num);
    html.clear();

    QString sName(QString::fromUtf8(spellInfo->SpellName));
    QString sDescription(QString::fromUtf8(spellInfo->Description));
    QString sRank(QString::fromUtf8(spellInfo->Rank));
    QString sToolTip(QString::fromUtf8(spellInfo->ToolTip));
    QString sSpellFamilyFlags0(QString("%0").arg(spellInfo->getSpellFamilyFlags(0), 8, 16, QChar('0')));
    QString sSpellFamilyFlags1(QString("%0").arg(spellInfo->getSpellFamilyFlags(1), 8, 16, QChar('0')));
    QString sSpellFamilyFlags2(QString("%0").arg(spellInfo->getSpellFamilyFlags(2), 8, 16, QChar('0')));
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
                        "</div>").arg(getSpellIconName(spellInfo->getSpellIconId()).toLower()));

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

    quint32 parentId = getParentSpellId(spellInfo->Id);
    if (parentId)
    {
        if (SpellEntry const* parentInfo = sSpellStore.LookupEntry(parentId))
        {
            QString sParentName(QString::fromUtf8(parentInfo->SpellName));
            QString sParentRank(QString::fromUtf8(parentInfo->Rank));

            if (!sParentRank.isEmpty())
                sParentName.append(" (" + sParentRank + ")");

            html.append(QString("<div class='b-vlink'><b>Parent spell:</b> <a href='http://spellwork/%0' class='blue_link'>%0 - %1</a></div>")
                .arg(parentId)
                .arg(sParentName));
        }
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

    html.append(QString("<li>SpellFamilyName = %0, SpellFamilyFlags = 0x%1 %2 %3</li>")
        .arg(m_enums->getSpellFamilies()[spellInfo->getSpellFamilyName()])
        .arg(sSpellFamilyFlags2.toUpper())
        .arg(sSpellFamilyFlags1.toUpper())
        .arg(sSpellFamilyFlags0.toUpper()));

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

    if (spellInfo->getCasterAuraSpell())
    {
        if(SpellEntry const* spell = sSpellStore.LookupEntry(spellInfo->getCasterAuraSpell()))
        {
            html.append(QString("<li>Caster Aura Spell (%0) %1</li>")
                .arg(spellInfo->getCasterAuraSpell())
                .arg(QString::fromUtf8(spell->SpellName)));
        }
        else
            html.append(QString("<li>Caster Aura Spell (%0) ?????</li>").arg(spellInfo->getCasterAuraSpell()));
    }

    if (spellInfo->getTargetAuraSpell())
    {
        if(SpellEntry const* spell = sSpellStore.LookupEntry(spellInfo->getTargetAuraSpell()))
        {
            html.append(QString("<li>Target Aura Spell (%0) %1</li>")
                .arg(spellInfo->getTargetAuraSpell())
                .arg(QString::fromUtf8(spell->SpellName)));
        }
        else
            html.append(QString("<li>Target Aura Spell (%0) ?????</li>").arg(spellInfo->getTargetAuraSpell()));
    }

    if (spellInfo->getExcludeCasterAuraSpell())
    {
        if(SpellEntry const* spell = sSpellStore.LookupEntry(spellInfo->getExcludeCasterAuraSpell()))
        {
            html.append(QString("<li>Ex Caster Aura Spell (%0) %1</li>")
                .arg(spellInfo->getExcludeCasterAuraSpell())
                .arg(QString::fromUtf8(spell->SpellName)));
        }
        else
            html.append(QString("<li>Ex Caster Aura Spell (%0) ?????</li>").arg(spellInfo->getExcludeCasterAuraSpell()));
    }

    if (spellInfo->getExcludeTargetAuraSpell())
    {
        if(SpellEntry const* spell = sSpellStore.LookupEntry(spellInfo->getExcludeTargetAuraSpell()))
        {
            html.append(QString("<li>Ex Target Aura Spell (%0) %1</li>")
                .arg(spellInfo->getExcludeTargetAuraSpell())
                .arg(QString::fromUtf8(spell->SpellName)));
        }
        else
            html.append(QString("<li>Ex Target Aura Spell (%0) ?????</li>").arg(spellInfo->getExcludeTargetAuraSpell()));
    }

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

    html.append("</ul></div></div>");

    appendSpellEffectInfo(spellInfo, num);

    html.append("</body></html>");

    // Formatting for debug
    html.replace("><", ">\n<");

    browser->setHtml(html, QUrl(QString("http://spellwork/%0").arg(spellInfo->Id)));
    browser->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void SWObject::appendRangeInfo(SpellEntry const* spellInfo, quint8 num)
{
    SpellRangeEntry const* range = sSpellRangeStore.LookupEntry(spellInfo->getRangeIndex());
    if (range)
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

void SWObject::appendProcInfo(SpellEntry const* spellInfo, quint8 num)
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

void SWObject::appendSpellEffectInfo(SpellEntry const* spellInfo, quint8 num)
{
    html.append("<div class='b-box-title'>Effects</div>"
                "<div class='b-box-body'>"
                "<div class='b-box'>");

    quint8 effectsCount = getEffectsCount(spellInfo->Id);
    for (quint8 eff = 0; eff < effectsCount; ++eff)
    {
        if (!spellInfo->getSpellEffect(eff))
        {
            html.append(QString("<div class='b-effect_name'>Effect %0:</div>"
                                "<ul>"
		                        "<li>NO EFFECT</li>"
		                        "</ul>").arg(eff));
        }
        else
        {
            QString _BasePoints(QString("<li>BasePoints = %0").arg(spellInfo->getEffectBasePoints(eff)));

            QString _RealPoints;
            if (spellInfo->getEffectRealPointsPerLevel(eff) != 0)
                _RealPoints = QString(" + Level * %0").arg(spellInfo->getEffectRealPointsPerLevel(eff), 0, 'f', 2);

            QString _DieSides;
            if (1 < spellInfo->getEffectDieSides(eff))
            {
                if (spellInfo->getEffectRealPointsPerLevel(eff) != 0)
                    _DieSides = QString(" to %0 + lvl * %1")
                    .arg(spellInfo->getEffectBasePoints(eff) + spellInfo->getEffectDieSides(eff))
                        .arg(spellInfo->getEffectRealPointsPerLevel(eff), 0, 'f', 2);
                else
                    _DieSides = QString(" to %0").arg(spellInfo->getEffectBasePoints(eff) + spellInfo->getEffectDieSides(eff));
            }

            QString _PointsPerCombo;
            if (spellInfo->getEffectPointsPerComboPoint(eff) != 0)
                _PointsPerCombo = QString(" + combo * %0").arg(spellInfo->getEffectPointsPerComboPoint(eff), 0, 'f', 2);

            QString _DamageMultiplier;
            if (spellInfo->getEffectDamageMultiplier(eff) != 1.0f)
                _DamageMultiplier = QString(" * %0").arg(spellInfo->getEffectDamageMultiplier(eff), 0, 'f', 2);

            QString _Multiple;
            if (spellInfo->getEffectValueMultiplier(eff) != 0)
                _Multiple = QString(", Multiple = %0").arg(spellInfo->getEffectValueMultiplier(eff), 0, 'f', 2);

            QString _Result = _BasePoints + _RealPoints + _DieSides + _PointsPerCombo + _DamageMultiplier + _Multiple + "</li>";

            html.append(QString("<div class='b-effect_name'>Effect %0:</div>"
                                "<ul>").arg(eff));

            html.append(QString("<li>Id: %0 (%1)</li>")
                .arg(spellInfo->getEffect(eff))
                .arg(m_enums->getSpellEffects()[spellInfo->getEffect(eff)]));

            html.append(_Result);

            html.append(QString("<li>Targets (%0, %1) (%2, %3)</li>")
                .arg(spellInfo->getEffectImplicitTargetA(eff))
                .arg(spellInfo->getEffectImplicitTargetB(eff))
                .arg(m_enums->getTargets()[spellInfo->getEffectImplicitTargetA(eff)])
                .arg(m_enums->getTargets()[spellInfo->getEffectImplicitTargetB(eff)]));

            appendAuraInfo(spellInfo, eff, num);

            appendRadiusInfo(spellInfo, eff, num);

            appendTriggerInfo(spellInfo, eff, num);

            if (spellInfo->getEffectChainTarget(eff) != 0)
                html.append(QString("<li>EffectChainTarget = %0</li>").arg(spellInfo->getEffectChainTarget(eff)));

            if (spellInfo->getEffectMechanic(eff) != 0)
            {
                html.append(QString("<li>Effect Mechanic = %0 (%1)</li>")
                    .arg(spellInfo->getEffectMechanic(eff))
                    .arg(m_enums->getMechanics()[spellInfo->getEffectMechanic(eff)]));
            }

            quint32 ClassMask[3];

            switch (eff)
            {
                case 0: 
                    ClassMask[0] = spellInfo->getEffectSpellClassMaskA(0);
                    ClassMask[1] = spellInfo->getEffectSpellClassMaskA(1);
                    ClassMask[2] = spellInfo->getEffectSpellClassMaskA(2); 
                    break;
                case 1:
                    ClassMask[0] = spellInfo->getEffectSpellClassMaskB(0);
                    ClassMask[1] = spellInfo->getEffectSpellClassMaskB(1);
                    ClassMask[2] = spellInfo->getEffectSpellClassMaskB(2); 
                    break;
                case 2:
                    ClassMask[0] = spellInfo->getEffectSpellClassMaskC(0);
                    ClassMask[1] = spellInfo->getEffectSpellClassMaskC(1);
                    ClassMask[2] = spellInfo->getEffectSpellClassMaskC(2); 
                    break;
            }

            if (ClassMask[0] || ClassMask[1] || ClassMask[2])
            {
                QString sClassMask2(QString("%0").arg(ClassMask[2], 8, 16, QChar('0')));
                QString sClassMask1(QString("%0").arg(ClassMask[1], 8, 16, QChar('0')));
                QString sClassMask0(QString("%0").arg(ClassMask[0], 8, 16, QChar('0')));

                html.append(QString("<li>SpellClassMask = %0 %1 %2</li>")
                                .arg(sClassMask2.toUpper())
                                .arg(sClassMask1.toUpper())
                                .arg(sClassMask0.toUpper()));

                html.append("<ul>");
                for (quint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
                {
                    SpellEntry const* t_spellInfo = sSpellStore.LookupEntry(i);
                    if (t_spellInfo)
                    {
                        bool hasSkill = false;
                        if ((t_spellInfo->getSpellFamilyName() == spellInfo->getSpellFamilyName()) &&
                            ((t_spellInfo->getSpellFamilyFlags(0) & ClassMask[0]) ||
                             (t_spellInfo->getSpellFamilyFlags(1) & ClassMask[1]) ||
                             (t_spellInfo->getSpellFamilyFlags(2) & ClassMask[2])))
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
                }
                html.append("</ul>");
            }
            html.append("</ul>");
        }
    }
    html.append("</div></div>");
}

void SWObject::appendTriggerInfo(SpellEntry const* spellInfo, quint8 index, quint8 num)
{
    quint32 trigger = spellInfo->getEffectTriggerSpell(index);
    if (trigger != 0)
    {
        SpellEntry const* triggerSpell = sSpellStore.LookupEntry(trigger);
        if (triggerSpell)
        {
            QString sName(QString::fromUtf8(triggerSpell->SpellName));
            QString sRank(QString::fromUtf8(triggerSpell->Rank));

            if (!sRank.isEmpty())
                sName.append(" (" + sRank + ")");

            html.append(QString("<li><b>Trigger spell:</b> <a href='http://spellwork/%0' class='blue_link'>%0 - %1</a>. Chance = %2</li>")
                .arg(trigger)
                .arg(sName)
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
        else
        {
            html.append(QString("<li>Trigger spell: %0 Not found</li>").arg(trigger));
        }
    }
}

void SWObject::appendRadiusInfo(SpellEntry const* spellInfo, quint8 index, quint8 num)
{
    quint16 rIndex = spellInfo->getEffectRadiusIndex(index);
    quint16 rIndexMax = spellInfo->getEffectRadiusMaxIndex(index);
    if (!rIndex && !rIndexMax)
        return;

    SpellRadiusEntry const* spellRadius = sSpellRadiusStore.LookupEntry(rIndex);
    SpellRadiusEntry const* spellRadiusMax = sSpellRadiusStore.LookupEntry(rIndexMax);

    QString str = QString("<li>Radius (Id %0) %1 Max: (Id %2) %3</li>");
    str = str.arg(rIndex);
    if (spellRadius)
        str = str.arg(spellRadius->Radius, 0, 'f', 2);
    else
        str = str.arg("Not found");
    str = str.arg(rIndexMax);
    if (spellRadiusMax)
        str = str.arg(spellRadiusMax->Radius, 0, 'f', 2);
    else
        str = str.arg("Not found");

    html.append(str);
}

void SWObject::appendAuraInfo(SpellEntry const* spellInfo, quint8 index, quint8 num)
{
    QString sAura(m_enums->getSpellAuras()[spellInfo->getEffectApplyAuraName(index)]);
    quint32 misc = spellInfo->getEffectMiscValue(index);

    if (spellInfo->getEffectApplyAuraName(index) == 0)
    {
        if (spellInfo->getEffectMiscValue(index) != 0)
            html.append(QString("<li>EffectMiscValueA = %0</li>").arg(spellInfo->getEffectMiscValue(index)));

        if (spellInfo->getEffectMiscValueB(index) != 0)
            html.append(QString("<li>EffectMiscValueB = %0</li>").arg(spellInfo->getEffectMiscValueB(index)));

        if (spellInfo->getEffectAmplitude(index) != 0)
            html.append(QString("<li>EffectAmplitude = %0</li>").arg(spellInfo->getEffectAmplitude(index)));

        return;
    }

    QString _BaseAuraInfo;
    _BaseAuraInfo = QString("<li>Aura Id %0 (%1), value = %2, misc = %3 ")
        .arg(spellInfo->getEffectApplyAuraName(index))
        .arg(sAura)
        .arg(spellInfo->getEffectBasePoints(index))
        .arg(misc);

    QString _SpecialAuraInfo;
    switch (spellInfo->getEffectApplyAuraName(index))
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

    QString _MiscB = QString("), miscB = %0").arg(spellInfo->getEffectMiscValueB(index));
    QString _Periodic = QString(", periodic = %0").arg(spellInfo->getEffectAmplitude(index));
    QString _Result = _BaseAuraInfo + _SpecialAuraInfo + _MiscB + _Periodic;
    html.append(_Result + "</li>");
}

QString SWObject::containAttributes(SpellEntry const* spellInfo, AttrType attr, quint8 index)
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

void SWObject::appendSkillInfo(SpellEntry const* spellInfo, quint8 num)
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

void SWObject::appendCastTimeInfo(SpellEntry const* spellInfo, quint8 num)
{
    SpellCastTimesEntry const* castInfo = sSpellCastTimesStore.LookupEntry(spellInfo->getCastingTimeIndex());
    if (castInfo)
    {
        html.append(QString("<li>CastingTime (Id %0) = %1</li>")
            .arg(castInfo->Id)
            .arg(float(castInfo->CastTime) / 1000, 0, 'f', 2));
    }
}

void SWObject::appendDurationInfo(SpellEntry const* spellInfo, quint8 num)
{
    SpellDurationEntry const* durationInfo = sSpellDurationStore.LookupEntry(spellInfo->getDurationIndex());
    if (durationInfo)
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
