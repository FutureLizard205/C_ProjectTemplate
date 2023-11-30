#include "screenmanager.h"


static const wchar_t floor = 0x0020;       // (space)

static const wchar_t wall[16] = {
        0x26AC,       // ⚬
        0x2568,       // ╨
        0x255E,       // ╞
        0x255A,       // ╚
        0x2565,       // ╥
        0x2551,       // ║
        0x2554,       // ╔
        0x2560,       // ╠
        0x2561,       // ╡
        0x255D,       // ╝
        0x2550,      // ═
        0x2569,      // ╩
        0x2557,      // ╗
        0x2563,      // ╣
        0x2566,      // ╦
        0x256C,      // ╬
};


void clearScreen() {
    wprintf(L"\033[H\033[J");
}


void drawMap() {
    
    clearScreen();
    for (int x = 0; x < 16; x++) {
        switch (tileType(mapTiles[x])) {
            case 0:
                wprintf(L"%lc", floor);
                break;

            case 1:
                wprintf(L"%lc", wall[tileId(mapTiles[x])]);
                break;

            default:
                wprintf(L"-");
        }
    }

    fflush(stdout);
}
