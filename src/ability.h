#ifndef _ABILITY_H_
#define _ABILITY_H_

#include <stdint.h>

#include "const.h"
#include "status_effect.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum AbilityType { at_None, at_Melee, at_Ranged, at_Magic } AbilityType;

typedef enum AbilityTargetType { 
    att_None,
    att_Enemy,
    att_Enemies,
    att_Hero,
    att_Party,
    att_Self
} AbilityTargetType;

typedef struct AbilityEffect {
    AbilityType AbilityType;
    AbilityTargetType TargetType;

    uint8_t RowMask;
    uint8_t TargetCountOverride;

    int16_t DamageModifier;
    int16_t AccuracyModifier;
    int16_t CritModifier;

    int8_t AppliedModifierTurnCount;
    int16_t AppliedDamageModifier;
    int16_t AppliedAccuracyModifier;
    int16_t AppliedCritModifier;
    int16_t AppliedSpeedModifier;
    int16_t AppliedDefenceModifier;
    int16_t AppliedDodgeModifier;

    StatusEffectFlags AppliedEffectsFlags;
    uint8_t AppliedEffectsTurnCount;
    uint8_t AppliedEffectsAmount;

    int8_t HealthRangeLow;
    int8_t HealthRangeHigh;

    int8_t FaithRangeLow;
    int8_t FaithRangeHigh;

    int8_t MoveAmount;
} AbilityDefinition;

typedef struct Ability {
    const char* Name;
    const char* Description;

    uint8_t RowMask;

    AbilityDefinition Primary;
    AbilityDefinition* Secondary;
} Ability;

extern Ability NullAbility;

extern Ability* NullAbilities[NumAbilitiesPerClass];

extern Ability* ArcherAbilities[NumAbilitiesPerClass];
extern Ability* AxemamAbilities[NumAbilitiesPerClass];
extern Ability* MageAbilities[NumAbilitiesPerClass];
extern Ability* PriestAbilities[NumAbilitiesPerClass];
extern Ability* RogueAbilities[NumAbilitiesPerClass];

extern Ability** HeroAbilities[NumHeroClasses];

#ifdef __cplusplus
}
#endif

#endif