#include "../ability.h"

Ability Lightning = {
    .Name = "Lighting",
    .Description = "Stuns an enemy",
    .RowMask = 0b1100,
    
    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Enemy,
        .RowMask = 0b0111,

        .DamageModifier = -25,
        .CritModifier = 25,

        .AppliedEffectsFlags = se_Stun,
    }
};

Ability FireBall = {
    .Name = "Fire Ball",
    .Description = "Set two adjacent enemies ablaze",
    .RowMask = 0b1100,
    
    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Enemies,

        .RowMask = 0b0111,
        .TargetCountOverride = 2,

        .DamageModifier = -25,
        .CritModifier = 25,

        .AppliedEffectsFlags = se_Ablaze,
        .AppliedEffectsAmount = 2,
        .AppliedEffectsTurnCount = 2,
    }
};

Ability* MageAbilities[NumAbilitiesPerClass] = {
    &FireBall,
    &Lightning,

    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
};