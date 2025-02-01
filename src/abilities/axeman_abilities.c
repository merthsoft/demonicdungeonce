#include "../ability.h"

Ability AdrenalineRush = {
    .Name = "Adrenaline Rush",
    .Description = "Heal, and go first next round",
    .RowMask = 0b0001,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Self,
        
        .AppliedEffectsFlags = se_FirstMove,
        
        .HealthRangeLow = 2,
        .HealthRangeHigh = 4,
    }
};

Ability* AxemamAbilities[NumAbilitiesPerClass] = {
    &AdrenalineRush,

    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
};