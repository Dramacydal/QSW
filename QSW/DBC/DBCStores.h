#ifndef DBCSTORES_H
#define DBCSTORES_H
#include <cassert>
#include "DBCStore.h"
#include "DBCStructure.h"

SpellEffectEntry const* GetSpellEffectEntry(quint32 spellId, quint8 effect);
SpellInfo const* GetSpellInfo(quint32 id);

extern DBCStorage <ChrClassesEntry>              sChrClassesStore;
extern DBCStorage <ChrSpecializationsEntry>      sChrSpecializationStore;
extern DBCStorage <SkillLineEntry>               sSkillLineStore;
extern DBCStorage <SkillLineAbilityEntry>        sSkillLineAbilityStore;
extern DBCStorage <SpecializationSpellsEntry>    sSpecializationSpellsStore;
extern DBCStorage <SpellCastTimesEntry>          sSpellCastTimesStore;
extern DBCStorage <SpellDurationEntry>           sSpellDurationStore;
extern DBCStorage <SpellRadiusEntry>             sSpellRadiusStore;
extern DBCStorage <SpellRangeEntry>              sSpellRangeStore;
extern DBCStorage <SpellIconEntry>               sSpellIconStore;
extern DBCStorage <SpellEntry>                   sSpellStore;
extern DBCStorage <SpellMiscEntry>               sSpellMiscStore;
extern DBCStorage <SpellEffectEntry>             sSpellEffectStore;
extern DBCStorage <SpellAuraOptionsEntry>        sSpellAuraOptionsStore;
extern DBCStorage <SpellAuraRestrictionsEntry>   sSpellAuraRestrictionsStore;
extern DBCStorage <SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
extern DBCStorage <SpellCategoriesEntry>         sSpellCategoriesStore;
extern DBCStorage <SpellClassOptionsEntry>       sSpellClassOptionsStore;
extern DBCStorage <SpellCooldownsEntry>          sSpellCooldownsStore;
extern DBCStorage <SpellEquippedItemsEntry>      sSpellEquippedItemsStore;
extern DBCStorage <SpellInterruptsEntry>         sSpellInterruptsStore;
extern DBCStorage <SpellLevelsEntry>             sSpellLevelsStore;
extern DBCStorage <SpellPowerEntry>              sSpellPowerStore;
extern DBCStorage <SpellReagentsEntry>           sSpellReagentsStore;
extern DBCStorage <SpellScalingEntry>            sSpellScalingStore;
extern DBCStorage <SpellShapeshiftEntry>         sSpellShapeshiftStore;
extern DBCStorage <SpellTargetRestrictionsEntry> sSpellTargetRestrictionsStore;
extern DBCStorage <SpellTotemsEntry>             sSpellTotemsStore;
extern DBCStorage <TalentEntry>                  sTalentStore;
extern SpellStore sSpellInfoStore;
void LoadDBCStores();

#endif
