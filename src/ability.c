#include "ability.h"

Ability NullAbility = {
    .Name = "NULL ABILITY",
    .Description = "NULL ABILITY",
};

Ability* NullAbilities[NumAbilitiesPerClass] = {
    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
    &NullAbility,
};

Ability** HeroAbilities[NumHeroClasses] = {
    RogueAbilities,
    AxemamAbilities,
    NullAbilities,      // Knight
    MageAbilities,
    ArcherAbilities,
    PriestAbilities,
    NullAbilities,      // Adventurer
    NullAbilities       // Blacksmith
};