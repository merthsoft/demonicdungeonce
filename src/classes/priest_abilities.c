#include "../ability.h"

Ability LayHands = {
    .Name = "Lay hands",
    .Description = "Heal an ally, gain faith",
    .RowMask = 0b1111,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Hero,
        .RowMask = 0b1111,

        .HealthRangeLow = 1,
        .HealthRangeHigh = 3
    },

    .Secondary = &(AbilityDefinition){
        .AbilityType = at_Magic,
        .TargetType = att_Self,
    
        .FaithRangeLow = 5,
        .FaithRangeHigh = 10
    }
};

Ability* PriestAbilities[NumAbilitiesPerClass] = {
    &LayHands,

    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
};