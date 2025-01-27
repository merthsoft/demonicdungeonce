#include "ability.h"

Ability MinimalAbility = {
    .Name = "Minimal ability example",
    .Description = "Do melee damage to any emeny from anywhere.",
    .RowMask = 0b1111,

    .Primary = {
        .AbilityType = at_Melee,
        .TargetType = att_Enemy,
        .RowMask = 0b1111,
    }
};

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

        .AppliedEffect = se_Ablaze,
        .AppliedEffectAmount = 2,
        .AppliedEffectTurnCount = 2,
    }
};

Ability Lighting = {
    .Name = "Lighting",
    .Description = "Stuns an enemy",
    .RowMask = 0b1100,
    
    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Enemy,
        .RowMask = 0b0111,

        .DamageModifier = -25,
        .CritModifier = 25,

        .AppliedEffect = se_Stun,
    }
};

Ability AdrenalineRush = {
    .Name = "Adrenaline Rush",
    .Description = "Heal, and go first next round",
    .RowMask = 0b0001,

    .Primary = {
        .AbilityType = at_Magic,
        .TargetType = att_Self,
        
        .AppliedEffect = se_FirstMove,
        
        .HealthRangeLow = 2,
        .HealthRangeHigh = 4,
    }
};

Ability PoisonJab = {
    .Name = "Poison Jab",
    .Description = "Stab an enemy with your poison dagger",
    .RowMask = 0b0010,

    .Primary = {
        .AbilityType = at_Melee,
        .TargetType = att_Enemy,
        .RowMask = 0b1100,

        .DamageModifier = -25,

        .AppliedEffect = se_Poison,
        .AppliedEffectAmount = 1,
        .AppliedEffectTurnCount = 4,
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

        .AppliedEffect = se_Poison,
        .AppliedEffectAmount = 2,
        .AppliedEffectTurnCount = 4,
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

        .AppliedEffect = se_Stun,
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