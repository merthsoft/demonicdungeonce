#include <graphx.h>
#include <time.h>
#include <sys/rtc.h>
#include <sys/util.h>
#include <keypadc.h>
#include <math.h>
#include <string.h>

#include "const.h"
#include "gfx/gfx.h"
#include "hero.h"
#include "render.h"

bool main_step(GameState* gameState);
void main_draw(GameState* gameState);

Hero Kerm = {
    .Name = "Kerm",
    .Class = hc_Barbarian,
    .Palette = hp_Gray,
    .Health = 10,
    .Faith = 10,
};

Hero Jon = {
    .Name = "TheStorm",
    .Class = hc_Swordsman,
    .Palette = hp_Red,
    .Health = 10,
    .Faith = 10,
};

Hero Tari = {
    .Name = "Tari",
    .Class = hc_Wizard,
    .Palette = hp_Purple,
    .Health = 10,
    .Faith = 10,
};

Hero ElfPrince = {
    .Name = "ElfPrince",
    .Class = hc_Archer,
    .Palette = hp_Green,
    .Health = 10,
    .Faith = 10,
};

int main(void) {
    while(kb_AnyKey());

    GameState gameState;
    memset(&gameState, 0, sizeof(GameState));
    gameState.Party[0] = &ElfPrince;
    gameState.Party[1] = &Tari;
    gameState.Party[2] = &Jon;
    gameState.Party[3] = &Kerm;

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(17);
    
    bool done = false;
    clock_t startTime;
    clock_t endTime;
    clock_t difference = 0;
    uint8_t animationIndex = 0;

    while (!done) {
        endTime = startTime;
        startTime = clock();
        difference += startTime - endTime;

        if (difference >= CLOCKS_PER_SEC/4) {
            animationIndex = (animationIndex + 1) % NumAnimationFrames;
            gameState.FrameNumber = animationIndex % 4 == 3 ? 1 : animationIndex % 4;
            difference = 0;
        }
        
        done |= main_step(&gameState);

        main_draw(&gameState);
        endTime = clock();

        gfx_SwapDraw();
    }

    gfx_End();

    return 0;
}

bool main_step(GameState* gameState) {
    kb_Scan();

    return kb_IsDown(kb_KeyDel) | kb_IsDown(kb_KeyClear) | kb_IsDown(kb_KeyMode);
}

void main_draw(GameState* gameState) {
    gfx_FillScreen(0);
    Render_State(gameState);
}
