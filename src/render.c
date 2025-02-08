#include <graphx.h>

#include "render.h"

#include "gfx/gfx.h"

#define Party_Draw_Selector_Start_X 1
#define Party_Draw_Selector_Start_Y 1

#define Party_Draw_Start_X 1
#define Party_Draw_Start_Y 19

#define Party_Draw_Health_Start_X Party_Draw_Start_X
#define Party_Draw_Health_Start_Y (Party_Draw_Hero_Height + Party_Draw_Start_Y + 1)

#define Party_Draw_Divinity_Start_X Party_Draw_Start_X
#define Party_Draw_Divinity_Start_Y (Party_Draw_Health_Start_Y + 10)

#define Party_Draw_StatusIcons_Start_X Party_Draw_Start_X
#define Party_Draw_StatusIcons_Start_Y (Party_Draw_Divinity_Start_Y + 10)

#define Party_Draw_Hero_Width 32
#define Party_Draw_Hero_Height 48

#define Party_Draw_Hero_Scale_X 2
#define Party_Draw_Hero_Scale_Y 3

#define Floor_Size 16
#define Floor_Start_X 0
#define Floor_Start_Y (Party_Draw_Start_Y + Party_Draw_Hero_Height)

#define Combat_Mode_Frame_0_X 0
#define Combat_Mode_Frame_0_Y 107

#define Combat_Mode_Frame_0_Width 160
#define Combat_Mode_Frame_0_Height 35

#define Combat_Mode_Frame_1_X 160
#define Combat_Mode_Frame_1_Y Combat_Mode_Frame_0_Y

#define Combat_Mode_Frame_1_Width Combat_Mode_Frame_0_Width
#define Combat_Mode_Frame_1_Height Combat_Mode_Frame_0_Height

#define Combat_Mode_Frame_2_X 0
#define Combat_Mode_Frame_2_Y 142

#define Combat_Mode_Frame_2_Width 160
#define Combat_Mode_Frame_2_Height 63

#define Combat_Mode_Frame_3_X 160
#define Combat_Mode_Frame_3_Y Combat_Mode_Frame_2_Y

#define Combat_Mode_Frame_3_Width Combat_Mode_Frame_2_Width
#define Combat_Mode_Frame_3_Height Combat_Mode_Frame_2_Height

#define Combat_Mode_Frame_4_X 0
#define Combat_Mode_Frame_4_Y 205

#define Combat_Mode_Frame_4_Width 320
#define Combat_Mode_Frame_4_Height 35

#define Combat_Mode_Enemy_Start_X 191
#define Combat_Mode_Enemy_Start_Y Party_Draw_Start_Y
#define Combat_Mode_Enemy_Health_Y Party_Draw_Health_Start_Y

#define Frame_Size 16
#define Frame_Margin 8

#define F_Button_Width 64

void Render_Frame(uint8_t frame_number, uint24_t x, uint8_t y, uint24_t width, uint8_t height) {
    uint16_t frame_index = frame_number * 9;

    for (int32_t i = Frame_Size; i < width - Frame_Size; i += Frame_Size) {
        for (int32_t j = Frame_Size; j < height - Frame_Size; j += Frame_Size) {
            gfx_Sprite(frames_tiles[frame_index + 4], x + i, y + j);
        }
    }

    for (uint24_t i = Frame_Size; i < width - Frame_Size; i += Frame_Size) {
        gfx_Sprite_NoClip(frames_tiles[frame_index + 1], x + i, y);
        gfx_Sprite_NoClip(frames_tiles[frame_index + 7], x + i, y + height - Frame_Size);
    }

    for (uint24_t j = Frame_Size; j < height - Frame_Size; j += Frame_Size) {
        gfx_Sprite_NoClip(frames_tiles[frame_index + 3], x, y + j);
        gfx_Sprite_NoClip(frames_tiles[frame_index + 5], x + width - Frame_Size, y + j);
    }

    gfx_Sprite_NoClip(frames_tiles[frame_index], x, y);
    gfx_Sprite_NoClip(frames_tiles[frame_index + 2], x + width - Frame_Size, y);
    gfx_Sprite_NoClip(frames_tiles[frame_index + 6], x, y + height - Frame_Size);
    gfx_Sprite_NoClip(frames_tiles[frame_index + 8], x + width - Frame_Size, y + height - Frame_Size);
}

void Render_Hall() {
    gfx_Sprite_NoClip((gfx_sprite_t*)dungeon_tile_112_data, Floor_Start_X, Floor_Start_Y);
    for (uint8_t i = 0; i < GFX_LCD_WIDTH / Floor_Size - 1; i++)
    gfx_Sprite_NoClip((gfx_sprite_t*)dungeon_tile_113_data, Floor_Start_X + Floor_Size*i + Floor_Size, Floor_Start_Y);
}

void Render_Combat_Frames() {
    Render_Frame(0, Combat_Mode_Frame_0_X, Combat_Mode_Frame_0_Y, Combat_Mode_Frame_0_Width, Combat_Mode_Frame_0_Height);
    Render_Frame(0, Combat_Mode_Frame_1_X, Combat_Mode_Frame_1_Y, Combat_Mode_Frame_1_Width, Combat_Mode_Frame_1_Height);
    Render_Frame(0, Combat_Mode_Frame_2_X, Combat_Mode_Frame_2_Y, Combat_Mode_Frame_2_Width, Combat_Mode_Frame_2_Height);
    Render_Frame(0, Combat_Mode_Frame_3_X, Combat_Mode_Frame_3_Y, Combat_Mode_Frame_3_Width, Combat_Mode_Frame_3_Height);
    Render_Frame(0, Combat_Mode_Frame_4_X, Combat_Mode_Frame_4_Y, Combat_Mode_Frame_4_Width, Combat_Mode_Frame_4_Height);

    for (uint8_t i = 1; i <= 4; i++)
        gfx_Sprite_NoClip(divider, Combat_Mode_Frame_4_X + i * F_Button_Width, Combat_Mode_Frame_4_Y + Frame_Margin);
}

void Render_Hero(Hero* hero, uint8_t frameNumber, uint24_t x, uint8_t y, uint8_t scale_x, uint8_t scale_y) {
    const gfx_sprite_t* sprite = (gfx_sprite_t*)heroes_tiles_data[hero->Class * NumSpriteFrames + hero->Palette * NumSpriteFrames * NumHeroClasses +  frameNumber];
    gfx_ScaledSprite_NoClip(sprite, x, y, scale_x, scale_y);
}

void Render_Party(GameState* gameState) {
    for (uint8_t i = 0; i < PartySize; i++) {
        gfx_SetColor(6);
        gfx_FillRectangle(Party_Draw_Health_Start_X + i * Party_Draw_Hero_Width + 2, Party_Draw_Health_Start_Y + 2, bar_empty_width - 5, bar_empty_height - 4);
        gfx_TransparentSprite_NoClip(bar_empty, Party_Draw_Health_Start_X + i * Party_Draw_Hero_Width, Party_Draw_Health_Start_Y);
        
        gfx_SetColor(1);
        gfx_FillRectangle(Party_Draw_Divinity_Start_X + i * Party_Draw_Hero_Width + 2, Party_Draw_Divinity_Start_Y + 2, bar_empty_width - 5, bar_empty_height - 4);
        gfx_TransparentSprite_NoClip(bar_empty, Party_Draw_Divinity_Start_X + i * Party_Draw_Hero_Width, Party_Draw_Divinity_Start_Y);
        
        Render_Hero(gameState->Party[i], gameState->FrameNumber, Party_Draw_Start_X + i * Party_Draw_Hero_Width, Party_Draw_Start_Y, Party_Draw_Hero_Scale_X, Party_Draw_Hero_Scale_Y);
        
        if (i == 0 || i == 1)
            gfx_Sprite_NoClip(ailments_tiles[i], Party_Draw_StatusIcons_Start_X + i * Party_Draw_Hero_Width, Party_Draw_StatusIcons_Start_Y);

        // ENEMIES LOL
        gfx_SetColor(6);
        gfx_FillRectangle(Combat_Mode_Enemy_Start_X + i * Party_Draw_Hero_Width + 2, Combat_Mode_Enemy_Health_Y + 2, bar_empty_width - 5, bar_empty_height - 4);
        gfx_TransparentSprite_NoClip(bar_empty, Combat_Mode_Enemy_Start_X + i * Party_Draw_Hero_Width, Combat_Mode_Enemy_Health_Y);
        gfx_ScaledSprite_NoClip(monsters_tiles[i * NumSpriteFrames + gameState->FrameNumber], Combat_Mode_Enemy_Start_X + i * Party_Draw_Hero_Width, Combat_Mode_Enemy_Start_Y, Party_Draw_Hero_Scale_X, Party_Draw_Hero_Scale_Y);
    }
}

void Render_Combat_Text(GameState* gameState) {
    Hero* hero = gameState->Party[gameState->SelectedHero];

    gfx_SetTextFGColor(11);
    gfx_SetColor(12);

    gfx_PrintStringXY(hero->Name, Combat_Mode_Frame_0_X + Frame_Margin, Combat_Mode_Frame_0_Y + Frame_Margin);
    int width = gfx_GetStringWidth(hero->Name);
    gfx_FillRectangle_NoClip(Combat_Mode_Frame_0_X + Frame_Margin - 1, Combat_Mode_Frame_0_Y + Frame_Margin + 9, width + 2, 1);
    gfx_PrintStringXY("Aflame", Combat_Mode_Frame_0_X + Frame_Margin, Combat_Mode_Frame_0_Y + Frame_Margin + 11);

    gfx_PrintStringXY("HP: ", Combat_Mode_Frame_0_X + Frame_Margin + 2 * Combat_Mode_Frame_0_Width / 3, Combat_Mode_Frame_0_Y + Frame_Margin);
    gfx_PrintUInt(hero->Health, 2);

    gfx_PrintStringXY("Div: ", Combat_Mode_Frame_0_X + Frame_Margin + 2 * Combat_Mode_Frame_0_Width / 3 - 5, Combat_Mode_Frame_0_Y + Frame_Margin + 11);
    gfx_PrintUInt(hero->Faith, 2);

    gfx_PrintStringXY("Quick Shot", Combat_Mode_Frame_2_X + Frame_Margin, Combat_Mode_Frame_2_Y + Frame_Margin);
    width = gfx_GetStringWidth("Quick Shot");
    gfx_FillRectangle_NoClip(Combat_Mode_Frame_2_X + Frame_Margin - 1, Combat_Mode_Frame_2_Y + Frame_Margin + 9, width + 2, 1);

    gfx_PrintStringXY("Fire at a target", Combat_Mode_Frame_2_X + Frame_Margin, Combat_Mode_Frame_2_Y + Frame_Margin + 12);
    gfx_PrintStringXY("Ranged", Combat_Mode_Frame_2_X + Frame_Margin, Combat_Mode_Frame_2_Y + Frame_Margin + 22);
    gfx_PrintStringXY("Physical 3-5", Combat_Mode_Frame_2_X + Frame_Margin, Combat_Mode_Frame_2_Y + Frame_Margin + 32);
    
    gfx_PrintStringXY("Quick", Combat_Mode_Frame_4_X + Frame_Margin, Combat_Mode_Frame_4_Y + Frame_Margin);
    gfx_PrintStringXY("Shot", Combat_Mode_Frame_4_X + Frame_Margin, Combat_Mode_Frame_4_Y + Frame_Margin + 10);
    gfx_PrintStringXY("Lob", Combat_Mode_Frame_4_X + F_Button_Width + Frame_Margin/2, Combat_Mode_Frame_4_Y + Frame_Margin);
    gfx_PrintStringXY("Shot", Combat_Mode_Frame_4_X + F_Button_Width + Frame_Margin/2, Combat_Mode_Frame_4_Y + Frame_Margin + 10);
    gfx_PrintStringXY("Field", Combat_Mode_Frame_4_X + 2*F_Button_Width + Frame_Margin/2, Combat_Mode_Frame_4_Y + Frame_Margin);
    gfx_PrintStringXY("Medicine", Combat_Mode_Frame_4_X + 2*F_Button_Width + Frame_Margin/2, Combat_Mode_Frame_4_Y + Frame_Margin + 10);

    gfx_PrintStringXY("Move", Combat_Mode_Frame_4_X + Frame_Margin + 4*F_Button_Width + 5, Combat_Mode_Frame_4_Y + Frame_Margin + 5);
}

void Render_Selector(uint8_t selectorNumber, uint24_t x, uint8_t y) {
    gfx_Sprite_NoClip(selectors_tiles[selectorNumber], x, y);
}

void Render_State(GameState* gameState) {
    Render_Combat_Frames();
    Render_Party(gameState);
    Render_Selector(0, Party_Draw_Start_X + gameState->SelectedHero * Party_Draw_Hero_Width + 10, gameState->FrameNumber*2 + 2);
    Render_Selector(1, Combat_Mode_Enemy_Start_X + (gameState->SelectedHero+1) * Party_Draw_Hero_Width - 2 + 10, (3-gameState->FrameNumber)*2 + 2);
    Render_Combat_Text(gameState);
}