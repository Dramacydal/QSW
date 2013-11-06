#include "DBCStructure.h"
#include "DBCStores.h"

/**
    SpellMisc methods
*/

quint32 SpellInfo::getAttributes() const
{
    return spellMisc ? spellMisc->Attributes : 0;
}

quint32 SpellInfo::getAttributesEx1() const
{
    return spellMisc ? spellMisc->AttributesEx1 : 0;
}

quint32 SpellInfo::getAttributesEx2() const
{
    return spellMisc ? spellMisc->AttributesEx2 : 0;
}

quint32 SpellInfo::getAttributesEx3() const
{
    return spellMisc ? spellMisc->AttributesEx3 : 0;
}

quint32 SpellInfo::getAttributesEx4() const
{
    return spellMisc ? spellMisc->AttributesEx4 : 0;
}

quint32 SpellInfo::getAttributesEx5() const
{
    return spellMisc ? spellMisc->AttributesEx5 : 0;
}

quint32 SpellInfo::getAttributesEx6() const
{
    return spellMisc ? spellMisc->AttributesEx6 : 0;
}

quint32 SpellInfo::getAttributesEx7() const
{
    return spellMisc ? spellMisc->AttributesEx7 : 0;
}

quint32 SpellInfo::getAttributesEx8() const
{
    return spellMisc ? spellMisc->AttributesEx8 : 0;
}

quint32 SpellInfo::getAttributesEx9() const
{
    return spellMisc ? spellMisc->AttributesEx9 : 0;
}

quint32 SpellInfo::getAttributesEx10() const
{
    return spellMisc ? spellMisc->AttributesEx10 : 0;
}

quint32 SpellInfo::getAttributesEx11() const
{
    return spellMisc ? spellMisc->AttributesEx11 : 0;
}

quint32 SpellInfo::getCastingTimeIndex() const
{
    return spellMisc ? spellMisc->CastTimeIndex : 0;
}

quint32 SpellInfo::getDurationIndex() const
{
    return spellMisc ? spellMisc->DurationIndex : 0;
}

quint32 SpellInfo::getRangeIndex() const
{
    return spellMisc ? spellMisc->RangeIndex : 0;
}

float SpellInfo::getSpeed() const
{
    return spellMisc ? spellMisc->Speed : 0;
}

quint32 SpellInfo::getSpellVisual(quint8 index) const
{
    return spellMisc ? spellMisc->SpellVisual[index] : 0;
}

quint32 SpellInfo::getSpellIconId() const
{
    return spellMisc ? spellMisc->SpellIconId : 0;
}

quint32 SpellInfo::getSpellBuffIconId() const
{
    return spellMisc ? spellMisc->SpellBuffIconId : 0;
}

quint32 SpellInfo::getSchoolMask() const
{
    return spellMisc ? spellMisc->SchoolMask : 0;
}

qint32 SpellInfo::getPowerType() const
{
    return spellPower ? spellPower->PowerType : 0;
}

/**
    SpellAuraOptions methods
 */

quint32 SpellInfo::getStackAmount() const
{
    return spellAuraOptions ? spellAuraOptions->StackAmount : 0;
}

quint32 SpellInfo::getProcCharges() const
{
    return spellAuraOptions ? spellAuraOptions->ProcCharges : 0;
}

quint32 SpellInfo::getProcChance() const
{
    return spellAuraOptions ? spellAuraOptions->ProcChance : 0;
}

quint32 SpellInfo::getProcFlags() const
{
    return spellAuraOptions ? spellAuraOptions->ProcFlags : 0;
}

/**
    SpellAuraRestrictions methods
 */

quint32 SpellInfo::getCasterAuraState() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->CasterAuraState : 0;
}

quint32 SpellInfo::getTargetAuraState() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->TargetAuraState : 0;
}

quint32 SpellInfo::getCasterAuraStateNot() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->CasterAuraStateNot : 0;
}

quint32 SpellInfo::getTargetAuraStateNot() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->TargetAuraStateNot : 0;
}

quint32 SpellInfo::getCasterAuraSpell() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->CasterAuraSpell : 0;
}

quint32 SpellInfo::getTargetAuraSpell() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->TargetAuraSpell : 0;
}

quint32 SpellInfo::getExcludeCasterAuraSpell() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->ExcludeCasterAuraSpell : 0;
}

quint32 SpellInfo::getExcludeTargetAuraSpell() const
{
    return spellAuraRestrictions ? spellAuraRestrictions->ExcludeTargetAuraSpell : 0;
}

/**
    SpellCastingRequirements methods
 */

quint32 SpellInfo::getFacingCasterFlags() const
{
    return spellCastingRequirements ? spellCastingRequirements->FacingCasterFlags : 0;
}

qint32 SpellInfo::getAreaGroupId() const
{
    return spellCastingRequirements ? spellCastingRequirements->AreaGroupId : -1;
}

quint32 SpellInfo::getRequiresSpellFocus() const
{
    return spellCastingRequirements ? spellCastingRequirements->RequiresSpellFocus : 0;
}

quint32 SpellInfo::getMinFactionId() const
{
    return spellCastingRequirements ? spellCastingRequirements->MinFactionId : 0;
}

quint32 SpellInfo::getMinReputation() const
{
    return spellCastingRequirements ? spellCastingRequirements->MinReputation : 0;
}

quint32 SpellInfo::getRequiredAuraVision() const
{
    return spellCastingRequirements ? spellCastingRequirements->RequiredAuraVision : 0;
}

/**
    SpellCategories methods
 */

quint32 SpellInfo::getCategory() const
{
    return spellCategories ? spellCategories->Category : 0;
}

quint32 SpellInfo::getDamageClass() const
{
    return spellCategories ? spellCategories->DamageClass : 0;
}

quint32 SpellInfo::getDispel() const
{
    return spellCategories ? spellCategories->Dispel : 0;
}

quint32 SpellInfo::getMechanic() const
{
    return spellCategories ? spellCategories->Mechanic : 0;
}

quint32 SpellInfo::getPreventionType() const
{
    return spellCategories ? spellCategories->PreventionType : 0;
}

quint32 SpellInfo::getStartRecoveryCategory() const
{
    return spellCategories ? spellCategories->StartRecoveryCategory : 0;
}

/**
    SpellClassOptions methods
 */

quint32 SpellInfo::getSpellFamilyName() const
{
    return spellClassOptions ? spellClassOptions->SpellFamilyName : 0;
}

quint32 SpellInfo::getSpellFamilyFlags(quint8 index) const
{
    return spellClassOptions ? spellClassOptions->SpellFamilyFlags[index] : 0;
}

quint32 SpellInfo::getModalNextSpell() const
{
    return spellClassOptions ? spellClassOptions->ModalNextSpell : 0;
}

/**
    SpellCooldowns methods
 */

quint32 SpellInfo::getStartRecoveryTime() const
{
    return spellCooldowns ? spellCooldowns->StartRecoveryTime : 0;
}

quint32 SpellInfo::getRecoveryTime() const
{
    return spellCooldowns ? spellCooldowns->RecoveryTime : 0;
}

quint32 SpellInfo::getCategoryRecoveryTime() const
{
    return spellCooldowns ? spellCooldowns->CategoryRecoveryTime : 0;
}

/**
    SpellEquippedItems methods
 */

qint32 SpellInfo::getEquippedItemClass() const
{
    return spellEquippedItems ? spellEquippedItems->EquippedItemClass : -1;
}

qint32 SpellInfo::getEquippedItemSubClassMask() const
{
    return spellEquippedItems ? spellEquippedItems->EquippedItemSubClassMask : -1;
}

qint32 SpellInfo::getEquippedItemInventoryTypeMask() const
{
    return spellEquippedItems ? spellEquippedItems->EquippedItemInventoryTypeMask : -1;
}

/**
    SpellInterrupts methods
 */

quint32 SpellInfo::getInterruptFlags() const
{
    return spellInterrupts ? spellInterrupts->InterruptFlags : 0;
}

quint32 SpellInfo::getAuraInterruptFlags() const
{
    return spellInterrupts ? spellInterrupts->AuraInterruptFlags : 0;
}

quint32 SpellInfo::getChannelInterruptFlags() const
{
    return spellInterrupts ? spellInterrupts->ChannelInterruptFlags : 0;
}

/**
    SpellLevels methods
 */

quint32 SpellInfo::getBaseLevel() const
{
    return spellLevels ? spellLevels->BaseLevel : 0;
}

quint32 SpellInfo::getMaxLevel() const
{
    return spellLevels ? spellLevels->MaxLevel : 0;
}

quint32 SpellInfo::getSpellLevel() const
{
    return spellLevels ? spellLevels->SpellLevel : 0;
}

/**
    SpellPower methods
 */

quint32 SpellInfo::getManaCost() const
{
    return spellPower ? spellPower->ManaCost : 0;
}

float SpellInfo::getManaCostPercentage() const
{
    return spellPower ? spellPower->ManaCostPercentage : 0;
}

quint32 SpellInfo::getManaPerSecond() const
{
    return spellPower ? spellPower->ManaPerSecond : 0;
}

quint32 SpellInfo::getManaCostPerLevel() const
{
    return spellPower ? spellPower->ManaCostPerlevel : 0;
}

quint32 SpellInfo::getPowerDisplayId() const
{
    return spellPower ? spellPower->PowerDisplayId : 0;
}

/**
    SpellShapeshift methods
 */

quint32 SpellInfo::getStances() const
{
    return spellShapeshift ? spellShapeshift->Stances : 0;
}

quint32 SpellInfo::getStancesNot() const
{
    return spellShapeshift ? spellShapeshift->StancesNot : 0;
}

quint32 SpellInfo::getStanceBarOrder() const
{
    return spellShapeshift ? spellShapeshift->StanceBarOrder : 0;
}

/**
    SpellTargetRestrictions methods
 */

quint32 SpellInfo::getTargets() const
{
    return spellTargetRestrictions ? spellTargetRestrictions->Targets : 0;
}

quint32 SpellInfo::getTargetCreatureType() const
{
    return spellTargetRestrictions ? spellTargetRestrictions->TargetCreatureType : 0;
}

quint32 SpellInfo::getMaxAffectedTargets() const
{
    return spellTargetRestrictions ? spellTargetRestrictions->MaxAffectedTargets : 0;
}

quint32 SpellInfo::getMaxTargetLevel() const
{
    return spellTargetRestrictions ? spellTargetRestrictions->MaxTargetLevel : 0;
}

float SpellInfo::getMaxTargetRadius() const
{
    return spellTargetRestrictions ? spellTargetRestrictions->MaxTargetRadius : 0.0f;
}

/**
    SpellEffect methods
 */

quint32 SpellInfo::getEffectSpellClassMask(quint8 eff, quint8 index, quint8 diff) const
{
    return spellEffects[diff][eff] ? spellEffects[diff][eff]->EffectSpellClassMask[index] : 0;
}

quint32 SpellInfo::getEffect(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->Effect : 0;
}

float SpellInfo::getEffectValueMultiplier(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectValueMultiplier : 0.0f;
}

quint32 SpellInfo::getEffectApplyAuraName(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectApplyAuraName : 0;
}

quint32 SpellInfo::getEffectAmplitude(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectAmplitude : 0;
}

qint32 SpellInfo::getEffectBasePoints(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectBasePoints : 0;
}

float SpellInfo::getEffectBonusCoefficient(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectBonusCoefficient : 0;
}

float SpellInfo::getEffectDamageMultiplier(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectDamageMultiplier : 0;
}

quint32 SpellInfo::getEffectChainTarget(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectChainTarget : 0;
}

qint32 SpellInfo::getEffectDieSides(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectDieSides : 0;
}

quint32 SpellInfo::getEffectItemType(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectItemType : 0;
}

quint32 SpellInfo::getEffectMechanic(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectMechanic : 0;
}

qint32 SpellInfo::getEffectMiscValue(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectMiscValue : 0;
}

qint32 SpellInfo::getEffectMiscValueB(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectMiscValueB : 0;
}

float SpellInfo::getEffectPointsPerComboPoint(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectPointsPerComboPoint : 0.0f;
}

quint32 SpellInfo::getEffectRadiusIndex(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectRadiusIndex : 0;
}

quint32 SpellInfo::getEffectRadiusMaxIndex(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectRadiusMaxIndex : 0;
}

float SpellInfo::getEffectRealPointsPerLevel(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectRealPointsPerLevel : 0.0f;
}

/*const quint32* SpellInfo::getEffectSpellClassMask(quint8 index, quint8 diff) const
{
    static quint32 nullClassMask[MAX_CLASS_MASK];
    memset(nullClassMask, 0, sizeof(nullClassMask));
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectSpellClassMask : nullClassMask;
}*/

quint32 SpellInfo::getEffectTriggerSpell(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectTriggerSpell : 0;
}

quint32 SpellInfo::getEffectImplicitTargetA(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectImplicitTargetA : 0;
}

quint32 SpellInfo::getEffectImplicitTargetB(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectImplicitTargetB : 0;
}

quint32 SpellInfo::getEffectSpellId(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectSpellId : 0;
}

quint32 SpellInfo::getEffectIndex(quint8 index, quint8 diff) const
{
    return spellEffects[diff][index] ? spellEffects[diff][index]->EffectIndex : 0;
}

/**
    SpellTotems methods
 */

quint32 SpellInfo::getTotem(quint8 index) const
{
    return spellTotems ? spellTotems->Totem[index] : 0;
}

quint32 SpellInfo::getTotemCategory(quint8 index) const
{
    return spellTotems ? spellTotems->TotemCategory[index] : 0;
}

/**
    SpellReagents methods
 */

qint32 SpellInfo::getReagent(quint8 index) const
{
    return spellReagents ? spellReagents->Reagent[index] : 0;
}

quint32 SpellInfo::getReagentCount(quint8 index) const
{
    return spellReagents ? spellReagents->ReagentCount[index] : 0;
}

QString SpellInfo::getSpellIconName() const
{
    return spellIcon ? QString(spellIcon->IconPath).section('\\', -1) : QString("");
}

SpellInfo::SpellInfo(SpellEntry const* spellInfo)
{
    if (!spellInfo)
        return;

    spellEntry = spellInfo;

    Id = spellInfo->Id;
    SpellName = spellInfo->SpellName;
    Rank = spellInfo->Rank;
    Description = spellInfo->Description;
    ToolTip = spellInfo->ToolTip;
    RuneCostId = spellInfo->RuneCostId;
    SpellMissileId = spellInfo->SpellMissileId;
    SpellDescriptionVariableId = spellInfo->SpellDescriptionVariableId;
    //unk_f1;
    SpellScalingId = spellInfo->SpellScalingId;
    SpellAuraOptionsId = spellInfo->SpellAuraOptionsId;
    SpellAuraRestrictionsId = spellInfo->SpellAuraRestrictionsId;
    SpellCastingRequirementsId = spellInfo->SpellCastingRequirementsId;
    SpellCategoriesId = spellInfo->SpellCategoriesId;
    SpellClassOptionsId = spellInfo->SpellClassOptionsId;
    SpellCooldownsId = spellInfo->SpellCooldownsId;
    SpellEquippedItemsId = spellInfo->SpellEquippedItemsId;
    SpellInterruptsId = spellInfo->SpellInterruptsId;
    SpellLevelsId = spellInfo->SpellReagentsId;
    //SpellPowerId;
    SpellReagentsId = spellInfo->SpellReagentsId;
    SpellShapeshiftId = spellInfo->SpellShapeshiftId;
    SpellTargetRestrictionsId = spellInfo->SpellTargetRestrictionsId;
    SpellTotemsId = spellInfo->SpellTotemsId;
    SpellMiscId = spellInfo->SpellMiscId;

    spellMisc = spellEntry->SpellMiscId ? sSpellMiscStore.LookupEntry(spellEntry->SpellMiscId) : NULL;
    spellAuraOptions = spellEntry->SpellAuraOptionsId ? sSpellAuraOptionsStore.LookupEntry(spellEntry->SpellAuraOptionsId) : NULL;
    spellAuraRestrictions = spellEntry->SpellAuraRestrictionsId ? sSpellAuraRestrictionsStore.LookupEntry(spellEntry->SpellAuraRestrictionsId) : NULL;
    spellCastingRequirements = spellEntry->SpellCastingRequirementsId ? sSpellCastingRequirementsStore.LookupEntry(spellEntry->SpellCastingRequirementsId) : NULL;
    spellCategories = spellEntry->SpellCategoriesId ? sSpellCategoriesStore.LookupEntry(spellEntry->SpellCategoriesId) : NULL;
    spellClassOptions = spellEntry->SpellClassOptionsId ? sSpellClassOptionsStore.LookupEntry(spellEntry->SpellClassOptionsId) : NULL;
    spellCooldowns = spellEntry->SpellCooldownsId ? sSpellCooldownsStore.LookupEntry(spellEntry->SpellCooldownsId) : NULL;
    spellEquippedItems = spellEntry->SpellEquippedItemsId ? sSpellEquippedItemsStore.LookupEntry(spellEntry->SpellEquippedItemsId) : NULL;
    spellInterrupts = spellEntry->SpellInterruptsId ? sSpellInterruptsStore.LookupEntry(spellEntry->SpellInterruptsId) : NULL;
    spellLevels = spellEntry->SpellLevelsId ? sSpellLevelsStore.LookupEntry(spellEntry->SpellLevelsId) : NULL;
    spellPower = sSpellPowerStore.LookupEntry(spellEntry->Id);
    spellReagents = spellEntry->SpellReagentsId ? sSpellReagentsStore.LookupEntry(spellEntry->SpellReagentsId) : NULL;
    spellScaling = spellEntry->SpellScalingId ? sSpellScalingStore.LookupEntry(spellEntry->SpellScalingId) : NULL;
    spellShapeshift = spellEntry->SpellShapeshiftId ? sSpellShapeshiftStore.LookupEntry(spellEntry->SpellShapeshiftId) : NULL;
    spellTargetRestrictions = spellEntry->SpellTargetRestrictionsId ? sSpellTargetRestrictionsStore.LookupEntry(spellEntry->SpellTargetRestrictionsId) : NULL;
    spellTotems = spellEntry->SpellTotemsId ? sSpellTotemsStore.LookupEntry(spellEntry->SpellTotemsId) : NULL;
    durationInfo = spellMisc ? sSpellDurationStore.LookupEntry(spellMisc->DurationIndex) : NULL;
    spellIcon = spellMisc ? sSpellIconStore.LookupEntry(spellMisc->SpellIconId) : NULL;
    castTimeEntry = sSpellCastTimesStore.LookupEntry(getCastingTimeIndex());
    rangeEntry = sSpellRangeStore.LookupEntry(getRangeIndex());

    SpellEffects const* effect = GetSpellEffects(spellEntry->Id);

    for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        for (quint8 j = 0; j < MAX_DIFFICULTY; ++j)
        {
            spellEffects[j][i] = effect ? effect->effects[j][i] : NULL;
            spellRadius[j][i] = sSpellRadiusStore.LookupEntry(getEffectRadiusIndex(i, j));
            spellRadiusMax[j][i] = sSpellRadiusStore.LookupEntry(getEffectRadiusMaxIndex(i, j));
        }
    }

    talentEntry = NULL;
    for (quint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* entry = sTalentStore.LookupEntry(i);
        if (!entry)
            continue;

        if (entry->spell != spellInfo->Id)
            continue;

        talentEntry = entry;
        break;
    }
}

SpellEffectEntry const* SpellInfo::getSpellEffect(quint8 idx, quint8 diff) const
{
    return spellEffects[diff][idx];
}

quint8 SpellInfo::getMaxEffect() const
{
    quint8 eff = 0;
    for (quint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        for (quint8 j = 0; j < MAX_DIFFICULTY; ++j)
            if (spellEffects[j][i])
                eff = i + 1;

    return eff;
}
