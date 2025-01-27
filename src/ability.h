#ifndef _ABILITY_H_
#define _ABILITY_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum AbilityType { at_Melee, at_Ranged, at_Magic } AbilityType;

typedef enum AbilityTargetType { 
    att_None,
    att_Enemy,
    att_Enemies,
    att_Hero,
    att_Party,
    att_Self
} AbilityTargetType;

typedef enum StatusEffect { 
    se_None         = 0,
    se_Ablaze       = 1 << 1,
    se_Poison       = 1 << 1,
    se_Stun         = 1 << 3,
    se_CantMiss     = 1 << 4,
    se_FirstMove    = 1 << 5,
    se_LastMove     = 1 << 6,
    se_PerfectDodge = 1 << 7,
    se_Immovable    = 1 << 8
 } StatusEffect;

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

    StatusEffect AppliedEffect;
    uint8_t AppliedEffectTurnCount;
    uint8_t AppliedEffectAmount;

    int8_t HealthRangeLow;
    int8_t HealthRangeHigh;

    int8_t FaithRangeLow;
    int8_t FaithRangeHigh;

    int8_t MoveAmount;
} AbilityDefinition;

typedef struct Ability {
    char* Name;
    char* Description;

    uint8_t RowMask;

    AbilityDefinition Primary;
    AbilityDefinition* Secondary;
} Ability;

#ifdef __cplusplus
}
#endif

#endif