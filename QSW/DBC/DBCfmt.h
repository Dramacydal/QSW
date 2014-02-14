#ifndef DBCSFRM_H
#define DBCSFRM_H

const char* AreaGroupfmt = "niiiiiii";
#if _BUILD >= 17538
const char* AreaTablefmt = "niixxxxxxxxxxsxxxxxxxxxxxxxxxx";
#else
const char* AreaTablefmt = "niixxxxxxxxxxsxxxxxxxxxxxxxx";
#endif
const char* ChrClassesfmt = "dxxsxxxxxxxxxxxxxx";
const char* ChrSpecializationsfmt = "dxxxxxxxxxxsxx";
const char* MapEntryfmt = "nxxxxsxxxxxxxxxxxxx";
#if _BUILD <= 16135
const char* SkillLinefmt = "nissisix";
#else
const char* SkillLinefmt = "nissisixx";
#endif
const char* SkillLineAbilityfmt = "niiiiiiiiiixx";
const char* SpecializationSpellsfmt = "diiix";
#if _BUILD >= 17538
const char* SpellAuraOptionsfmt = "dixiiiixx";
#else
const char* SpellAuraOptionsfmt = "dixiiii";
#endif
const char* SpellAuraRestrictionsfmt = "dixiiiiiiii";
const char* SpellCastingRequirementsfmt = "diiiiii";
const char* SpellCategoriesfmt = "dixiiiiiix";
const char* SpellClassOptionsfmt = "diiiiii";
const char* SpellCooldownsfmt = "dixiii";
const char* SpellEffectEntryfmt = "diifiiiffiiiiiifiifiiiiixiiiix";
const char* SpellEquippedItemsfmt = "dixiii";
const char* SpellInterruptsfmt = "dixiiixx";
const char* SpellLevelsfmt = "dixiii";
const char* SpellPowerfmt = "xnxiiixiifxxx";
const char* SpellReagentsfmt = "diiiiiiiiiiiiiiiixx";
const char* SpellScalingfmt = "diiiifixx";
const char* SpellShapeshiftfmt = "dixixi";
const char* SpellTargetRestrictionsfmt = "dixfxiiii";
const char* SpellTotemsfmt = "diiii";
#if _BUILD >= 17538
const char* SpellMiscfmt = "dixiiiiiiiiiiiiiiiifiiiii";
#else
const char* SpellMiscfmt = "dixiiiiiiiiiiiiiiifiiiii";
#endif
const char* SpellEntryfmt = "nssssiiixiiiiiiiiiixiiiii";
const char* SpellCastTimefmt = "nifi";
const char* SpellRadiusfmt = "nfxxx";
const char* SpellRangefmt = "nffffiss";
const char* SpellDurationfmt = "niii";
const char* SpellIconfmt = "ns";
const char* Talentfmt = "nxxxixxxiix";

#endif
