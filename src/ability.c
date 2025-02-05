#include "ability.h"

Ability NullAbility = {
    .Name = "NULL ABILITY",
    .Description = "This ability hasn't been implemneted yet",
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