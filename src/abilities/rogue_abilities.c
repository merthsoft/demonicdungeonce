#include "../ability.h"

Ability PoisonJab = {
    .Name = "Poison Jab",
    .Description = "Stab an enemy with your poison dagger",
    .RowMask = 0b0010,

    .Primary = {
        .AbilityType = at_Melee,
        .TargetType = att_Enemy,
        .RowMask = 0b1100,

        .DamageModifier = -25,

        .AppliedEffectsFlags = se_Poison,
        .AppliedEffectsAmount = 1,
        .AppliedEffectsTurnCount = 4,
    }
};

Ability PoisonDart = {
    .Name = "Poison Dart",
    .Description = "Throw a poisoned dart at an enemy",
    .RowMask = 0b1100,

    .Primary = {
        .AbilityType = at_Ranged,
        .TargetType = att_Enemy,
        .RowMask = 0b0111,

        .DamageModifier = -50,
        .CritModifier = 25,

        .AppliedEffectsFlags = se_Poison,
        .AppliedEffectsAmount = 2,
        .AppliedEffectsTurnCount = 4,
    }
};

Ability Blackjack = {
    .Name = "Blackjack",
    .Description = "Strike an enemy and stun them",
    .RowMask = 0b0110,

    .Primary = {
        .AbilityType = at_Melee,
        .TargetType = att_Enemy,
        .RowMask = 0b1000,

        .AppliedEffectsFlags = se_Stun,
    }
};

Ability Fade = {
    .Name = "Fade",
    .Description = "Fade into the shadows, boosting your dodge",
    .RowMask = 0b0011,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Self,

        .AppliedDodgeModifier = 50,
        .MoveAmount = -1,
    }
};

Ability* RogueAbilities[NumAbilitiesPerClass] = {
    &PoisonJab,
    &PoisonDart,
    &Blackjack,
    &Fade,

    &NullAbility,
    &NullAbility,
};