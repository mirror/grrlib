/*===========================================
        GRRLIB (GX version) 3.0.5 alpha
        Code     : NoNameNo
        Additional Code : Crayon
        GX hints : RedShade

        Template Code (Minimum Requirement)
============================================*/
#include "GRRLIB/GRRLIB.h"

#include <stdlib.h>

#include <wiiuse/wpad.h>
#include <fat.h>

#include "gfx/BMfont1.h"
#include "gfx/BMfont2.h"
#include "gfx/BMfont3.h"
#include "gfx/BMfont4.h"
#include "gfx/test_jpg.h"

// RGBA Colors
#define GRRLIB_BLACK  0x000000FF
#define GRRLIB_WHITE  0xFFFFFFFF
#define GRRLIB_RED    0xFF0000FF
#define GRRLIB_BLUE   0x0000FFFF
#define GRRLIB_GREEN  0x008000FF
#define GRRLIB_GRAY   0x808080FF
#define GRRLIB_YELLOW 0xFFFF00FF
#define GRRLIB_SILVER 0xC0C0C0FF

Mtx GXmodelView2D;

int main() {
    int left = 0;
    ir_t ir1;
    u32 wpaddown, wpadheld;

    GRRLIB_Init();

    fatInitDefault();
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    GRRLIB_texImg tex_test_jpg = GRRLIB_LoadTextureJPG(test_jpg);

    GRRLIB_texImg tex_BMfont1 = GRRLIB_LoadTexturePNG(BMfont1);
    GRRLIB_InitTileSet(&tex_BMfont1, 32, 32, 32);

    GRRLIB_texImg tex_BMfont2 = GRRLIB_LoadTexturePNG(BMfont2);
    GRRLIB_InitTileSet(&tex_BMfont2, 16, 16, 32);

    GRRLIB_texImg tex_BMfont3 = GRRLIB_LoadTexturePNG(BMfont3);
    GRRLIB_InitTileSet(&tex_BMfont3, 32, 32, 32);

    GRRLIB_texImg tex_BMfont4 = GRRLIB_LoadTexturePNG(BMfont4);
    GRRLIB_InitTileSet(&tex_BMfont4, 16, 16, 32);


    while(1){
        WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
        wpaddown = WPAD_ButtonsDown(0);
        wpadheld = WPAD_ButtonsHeld(0);

        WPAD_IR(WPAD_CHAN_0, &ir1);

        GRRLIB_FillScreen(GRRLIB_BLACK);

        GRRLIB_DrawImg(10, 10, tex_test_jpg, 0, 1, 1, GRRLIB_WHITE);

        GRRLIB_Printf(left, 200, tex_BMfont1, GRRLIB_WHITE, 1, "X VALUE:%d", (int)ir1.sx);
        GRRLIB_Printf(left, 250, tex_BMfont4, GRRLIB_WHITE, 1, "X VALUE:%d", (int)ir1.sx);
        GRRLIB_Printf(left, 300, tex_BMfont3, GRRLIB_WHITE, 1, "X VALUE  : %d", tex_test_jpg.w);
        GRRLIB_Printf(left, 350, tex_BMfont2, GRRLIB_WHITE, 1, "X VALUE  : 1");

        GRRLIB_Render();

        if (wpaddown & WPAD_BUTTON_A) exit(0);
        if (wpadheld & WPAD_BUTTON_LEFT) left--;
        if (wpadheld & WPAD_BUTTON_RIGHT) left++;
    }
    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
    return 0;
}
