#ifndef _RENDER_H_
#define _RENDER_H_

#include "gamestate.h"

#ifdef __cplusplus
extern "C" {
#endif

void Render_Frame(uint8_t frame_number, uint24_t x, uint8_t y, uint24_t width, uint8_t height);

void Render_State(GameState* gameState);

#ifdef __cplusplus
}
#endif

#endif