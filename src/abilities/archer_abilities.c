#include "../ability.h"

Ability Focus = {
    .Name = "Focus",
    .Description = "Next move is a guaranteed hit.",
    .RowMask = 0b1111,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Self,
        
        .AppliedEffectsFlags = se_CantMiss,
    }
};

Ability FireArrow = {
    .Name = "Fire Arrow",
    .Description = "Sets target ablaze.",
    .RowMask = 0b1100,  // Must be in 3rd or 4th position

    .Primary = {
        .AbilityType = at_Ranged,
        .TargetType = att_Enemy,
        .RowMask = 0b0111, // Must be in 2nd, 3rd, or 4th

        .DamageModifier = -50,
        .CritModifier = -25,

        .AppliedEffectsFlags = se_Ablaze,
        .AppliedEffectsAmount = 2,
        .AppliedEffectsTurnCount = 4,
    }
};

Ability* ArcherAbilities[NumAbilitiesPerClass] = {
    &Focus,
    &FireArrow,

    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
};