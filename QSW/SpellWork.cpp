#include "SpellWork.h"
#include "QDefines.h"

SpellWork::SpellWork(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    model = NULL;
    m_spellInfo = NULL;

    LoadDBCStores();

    connect(SpellList, SIGNAL(clicked(QModelIndex)), this, SLOT(SlotSearchFromList(QModelIndex)));

    connect(findButton, SIGNAL(clicked()), this, SLOT(SlotSearch()));
    connect(findButton, SIGNAL(clicked()), SpellList, SLOT(resizeRowsToContents()));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(SlotAbout()));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

SpellWork::~SpellWork()
{
}

About::About(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

About::~About()
{
}

void SpellWork::SlotAbout()
{
    About *about = new About;
    about->show();
}

void SpellWork::SlotSearch()
{
    bool isString = false;

    SpellInfoBrowser->clear();

    if (model)
        model->clear();

    if (!findLine_e1->text().isEmpty())
    {
        for (int i = 0; i < findLine_e1->text().size(); ++i)
        {
            if (findLine_e1->text().at(i) > QChar('9'))
            {
                isString = true;
                break;
            }
        }

        if (isString)
        {
            model = new QStandardItemModel(1, 2);
            int count = -1;
            for (int i = 0; i < sSpellStore.GetNumRows(); i++)
            {
                m_spellInfo = sSpellStore.LookupEntry(i);
				if (m_spellInfo && QString(m_spellInfo->SpellName[0]).contains(findLine_e1->text(), Qt::CaseInsensitive))
                {
                    count++;
                    QString sRank((char*)m_spellInfo->Rank[0]);

                    QStandardItem *item_id = new QStandardItem(QString("%0").arg(m_spellInfo->Id));
                    QStandardItem *item_name;
                    if (sRank.isEmpty())
                        item_name = new QStandardItem(QString("%0").arg((char*)m_spellInfo->SpellName[0]));
                    else
                        item_name = new QStandardItem(QString("%0 (%1)").arg((char*)m_spellInfo->SpellName[0]).arg((char*)m_spellInfo->Rank[0]));

                    model->setItem(count, 0, item_id);
                    model->setItem(count, 1, item_name);
                }
            }
            model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
            model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
            SpellList->setModel(model);
            SpellList->setColumnWidth(0, 40);
            SpellList->setColumnWidth(1, 195);
        }
        else
        {
            model = new QStandardItemModel(1, 2);

            m_spellInfo = sSpellStore.LookupEntry(findLine_e1->text().toInt());

            if (m_spellInfo)
            {
                QString sRank((char*)m_spellInfo->Rank[0]);

                QStandardItem *item_id = new QStandardItem(QString("%0").arg(m_spellInfo->Id));
                QStandardItem *item_name;
                if (sRank.isEmpty())
                    item_name = new QStandardItem(QString("%0").arg((char*)m_spellInfo->SpellName[0]));
                else
                    item_name = new QStandardItem(QString("%0 (%1)").arg((char*)m_spellInfo->SpellName[0]).arg((char*)m_spellInfo->Rank[0]));

                model->setItem(0, 0, item_id);
                model->setItem(0, 1, item_name);
                model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
                model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
                SpellList->setModel(model);
                SpellList->setColumnWidth(0, 40);
                SpellList->setColumnWidth(1, 195);
                ShowInfo(m_spellInfo);
            }
        }
    }
    else if (!findLine_e2->text().isEmpty())
    {
        model = new QStandardItemModel(1, 2);
        int count = -1;
        for (int i = 0; i < sSpellStore.GetNumRows(); i++)
        {
            m_spellInfo = sSpellStore.LookupEntry(i);
            if (m_spellInfo && m_spellInfo->SpellIconID == findLine_e2->text().toInt())
            {
                count++;
                QString sRank((char*)m_spellInfo->Rank[0]);

                QStandardItem *item_id = new QStandardItem(QString("%0").arg(m_spellInfo->Id));
                QStandardItem *item_name;
                if (sRank.isEmpty())
                    item_name = new QStandardItem(QString("%0").arg((char*)m_spellInfo->SpellName[0]));
                else
                    item_name = new QStandardItem(QString("%0 (%1)").arg((char*)m_spellInfo->SpellName[0]).arg((char*)m_spellInfo->Rank[0]));

                model->setItem(count, 0, item_id);
                model->setItem(count, 1, item_name);
            }
        }
        model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
        SpellList->setModel(model);
        SpellList->setColumnWidth(0, 40);
        SpellList->setColumnWidth(1, 195);
    }
}

void SpellWork::SlotSearchFromList(const QModelIndex &index)
{
    QStandardItem *spellItem = model->item(index.row());
    
    QString value(spellItem->text());

    uint32 id = value.toInt();

    SpellInfoBrowser->clear();

    m_spellInfo = sSpellStore.LookupEntry(id);
    if (m_spellInfo)
        ShowInfo(m_spellInfo);
        
}

void SpellWork::ShowInfo(SpellEntry const* spellInfo)
{
    if (!spellInfo)
        return;

    QString line("==================================================");

    QString sName((char*)spellInfo->SpellName[0]);
    QString sDescription((char*)spellInfo->Description[0]);
    QString sRank((char*)spellInfo->Rank[0]);
    QString sToolTip((char*)spellInfo->ToolTip[0]);
    QString sSpellFamilyFlags(QString("%0").arg(spellInfo->SpellFamilyFlags, 16, 16, QChar('0')));
    QString sAttributes(QString("%0").arg(spellInfo->Attributes, 8, 16, QChar('0')));
    QString sAttributesEx(QString("%0").arg(spellInfo->AttributesEx, 8, 16, QChar('0')));
    QString sAttributesEx2(QString("%0").arg(spellInfo->AttributesEx2, 8, 16, QChar('0')));
    QString sAttributesEx3(QString("%0").arg(spellInfo->AttributesEx3, 8, 16, QChar('0')));
    QString sAttributesEx4(QString("%0").arg(spellInfo->AttributesEx4, 8, 16, QChar('0')));

    SpellInfoBrowser->append(QString("<b>ID:</b> %0").arg(spellInfo->Id));

    if (sRank.isEmpty())
        SpellInfoBrowser->append(QString("<b>Name:</b> %0").arg(sName));
    else
        SpellInfoBrowser->append(QString("<b>Name:</b> %0 (%1)").arg(sName).arg(sRank));

    if (!sDescription.isEmpty())
        SpellInfoBrowser->append(QString("<b>Description:</b> %0").arg(sDescription));

    if (!sToolTip.isEmpty())
        SpellInfoBrowser->append(QString("<b>ToolTip:</b> %0").arg(sToolTip));

    SpellInfoBrowser->append(line);
    SpellInfoBrowser->append(QString("Category = %0, SpellIconID = %1, ActiveIconID = %2, SpellVisual = %3")
        .arg(spellInfo->Category)
        .arg(spellInfo->SpellIconID)
        .arg(spellInfo->activeIconID)
        .arg(spellInfo->SpellVisual));

    SpellInfoBrowser->append(QString("SpellFamilyName = %0, SpellFamilyFlags = 0x%1\n").arg(StringSpellConst(spellInfo, SPELLFAMILY_NAME)).arg(sSpellFamilyFlags.toUpper()));

    SpellInfoBrowser->append(QString("SpellSchool = %0 (%1)").arg(spellInfo->School).arg(SchoolString[spellInfo->School]));
    SpellInfoBrowser->append(QString("DamageClass = %0 (%1)").arg(spellInfo->DmgClass).arg(DmgClass[spellInfo->DmgClass]));
    SpellInfoBrowser->append(QString("PreventionType = %0 (%1)").arg(spellInfo->PreventionType).arg(PreventionType[spellInfo->PreventionType]));
    
    if (spellInfo->Attributes || spellInfo->AttributesEx || spellInfo->AttributesEx2 ||
        spellInfo->AttributesEx3 || spellInfo->AttributesEx4)
        SpellInfoBrowser->append(line);

    if (spellInfo->Attributes)
        SpellInfoBrowser->append(QString("Attributes: 0x%0").arg(sAttributes.toUpper()));
    if (spellInfo->AttributesEx)
        SpellInfoBrowser->append(QString("AttributesEx: 0x%0").arg(sAttributesEx.toUpper()));
    if (spellInfo->AttributesEx2)
        SpellInfoBrowser->append(QString("AttributesEx2: 0x%0").arg(sAttributesEx2.toUpper()));
    if (spellInfo->AttributesEx3)
        SpellInfoBrowser->append(QString("AttributesEx3: 0x%0").arg(sAttributesEx3.toUpper()));
    if (spellInfo->AttributesEx4)
        SpellInfoBrowser->append(QString("AttributesEx4: 0x%0").arg(sAttributesEx4.toUpper()));

    SpellInfoBrowser->append(line);



    if (spellInfo->manaCost || spellInfo->ManaCostPercentage)
        SpellInfoBrowser->append(QString("Power Type = %0").arg(StringSpellConst(spellInfo, POWER_TYPE_NAME)));

    for (uint8 i = EFFECT_INDEX_0; i < MAX_EFFECT_INDEX; i++)
    {
        if (!spellInfo->Effect[i])
            SpellInfoBrowser->append(QString("Effect %0:  NO EFFECT").arg(i));
        else
            SpellInfoBrowser->append(QString("Effect %0: Id %1 (%2)").arg(i).arg(spellInfo->Effect[i]).arg(EffectString[spellInfo->Effect[i]]));
    }

}

QString SpellWork::StringSpellConst(SpellEntry const *spellInfo, StringConst strConst)
{
    switch (strConst)
    {
        case POWER_TYPE_NAME:
            switch (spellInfo->powerType)
            {
                case POWER_MANA:
                    return QString("POWER_MANA");
                case POWER_RAGE:
                    return QString("POWER_RAGE");
                case POWER_FOCUS:
                    return QString("POWER_FOCUS");
                case POWER_ENERGY:
                    return QString("POWER_ENERGY");
                case POWER_HAPPINESS:
                    return QString("POWER_HAPPINESS");
                case POWER_RUNES:
                    return QString("POWER_RUNES");
                case POWER_HEALTH:
                    return QString("POWER_HEALTH");
                default:
                    return QString("POWER_UNKNOWN");
            }
            break;
        case SPELLFAMILY_NAME:
            switch (spellInfo->SpellFamilyName)
            {
                case SPELLFAMILY_GENERIC:
                    return QString("SPELLFAMILY_GENERIC");
                case SPELLFAMILY_MAGE:
                    return QString("SPELLFAMILY_MAGE");
                case SPELLFAMILY_WARRIOR:
                    return QString("SPELLFAMILY_WARRIOR");
                case SPELLFAMILY_WARLOCK:
                    return QString("SPELLFAMILY_WARLOCK");
                case SPELLFAMILY_PRIEST:
                    return QString("SPELLFAMILY_PRIEST");
                case SPELLFAMILY_DRUID:
                    return QString("SPELLFAMILY_DRUID");
                case SPELLFAMILY_ROGUE:
                    return QString("SPELLFAMILY_ROGUE");
                case SPELLFAMILY_HUNTER:
                    return QString("SPELLFAMILY_HUNTER");
                case SPELLFAMILY_PALADIN:
                    return QString("SPELLFAMILY_PALADIN");
                case SPELLFAMILY_SHAMAN:
                    return QString("SPELLFAMILY_SHAMAN");
                case SPELLFAMILY_POTION:
                    return QString("SPELLFAMILY_POTION");
                case SPELLFAMILY_DEATHKNIGHT:
                    return QString("SPELLFAMILY_DEATHKNIGHT");
                default:
                    return QString("SPELLFAMILY_UNKNOWN");
            }
            break;
    }
    return QString();
}
