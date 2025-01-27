#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <time.h>

#include "const.h"
#include "hero.h"

typedef enum GameMode { gm_Combat } GameMode;

typedef struct GameState {
    GameMode GameMode;

    uint8_t FrameNumber;

    Hero* Party[PartySize];
    uint8_t SelectedHero;
    uint8_t SelectedEnemy;
    uint8_t SelectedMove;
} GameState;

#endif