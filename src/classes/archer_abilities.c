#include "../ability.h"

Ability Focus = {
    .Name = "Focus",
    .Description = "Next move is a guaranteed hit.",
    .RowMask = 0b1111,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Self,
        
        .AppliedEffect = se_CantMiss,
        .AppliedEffectTurnCount = 1,
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

        .AppliedEffect = se_Ablaze,
        .AppliedEffectAmount = 2,
        .AppliedEffectTurnCount = 4,
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