#ifndef _HERO_H_
#define _HERO_H_

#include <stdint.h>

#include "const.h"

#define NumHeroClasses 8
#define NumAbilitiesPerHero 4

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

typedef struct {
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

    uint8_t AbilityUnlockedFlag;
    uint8_t AbilityEnabledFlag;
} Hero;

#endif