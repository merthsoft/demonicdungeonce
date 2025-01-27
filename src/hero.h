#ifndef _HERO_H_
#define _HERO_H_

#include <stdint.h>

#include "const.h"

typedef enum {
    hc_None,
    hc_Rogue,
    hc_Barbarian,
    hc_Swordsman,
    hc_Wizard,
    hc_Archer
} HeroClass;

typedef enum {
    hp_Red,
    hp_Purple,
    hp_Green,
    hp_Gray
} HeroPalette;

typedef struct {
    HeroClass Class;
    HeroPalette Palette;
    char* Name;
    uint8_t Health;
    uint8_t Faith;

    uint8_t Damage;
} Hero;

#endif