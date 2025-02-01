#ifndef _HERO_H_
#define _HERO_H_

#include <stdint.h>

#include "ability_index_flags.h"
#include "const.h"
#include "status_effect.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    hc_Rogue,
    hc_Axeman,
    hc_Knight,
    hc_Mage,
    hc_Archer,
    hc_Priest,
    hc_Adventurer,
    hc_Blacksmith,
} HeroClass;

typedef enum {
    hp_Red,
    hp_Purple,
    hp_Green,
    hp_Gray
} HeroPalette;

typedef struct Hero {
    const char* Name;
    
    HeroClass Class;
    HeroPalette Palette;
    
    uint8_t Health;
    uint8_t MaxHealth;
    uint8_t Faith;

    uint8_t Damage;
    uint8_t Accuracy;
    uint8_t Crit;
    uint8_t Defence;
    uint8_t Speed;
    uint8_t Dodge;

    AbilityIndexFlags AbilityUnlockedFlags;
    AbilityIndexFlags AbilityEnabledFlags;

    StatusEffectFlags StatusEffectsFlags;
    uint8_t StatusEffectDuration[NumStatusEffects];
    uint8_t StatusEffectAmount[NumStatusEffects];
} Hero;

#ifdef __cplusplus
}
#endif

#endif