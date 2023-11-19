#include <libgen.h>
#include <stdint.h>
#include <wchar.h>
#include "mapmanager.h"

/*
 * Returns the tile type of a given tile code (element of mapTiles[])
 * Codes:   0 -> Ground
 *          1 -> Wall
 *          ...
 *          15 -> (nothing)
 */
int tileType(const uint_fast8_t tileCode) {
    return (tileCode / 16);
}

int tileId(const uint_fast8_t tileCode) {
    return (tileCode % 16);
}

void idTilesCalc() {
    int id;
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            if (tileType(mapTiles[y * 16 + x]) == 1) {
                id = 0;

                // Analyze the adjacent tiles:

                if (tileType(mapTiles[(y - 1) * 16 + x]) == 1 && y != 0) id = id + 1;
                if (tileType(mapTiles[(y) * 16 + x + 1]) == 1 && x != 15) id = id + 2;
                if (tileType(mapTiles[(y + 1) * 16 + x]) == 1 && y != 15) id = id + 4;
                if (tileType(mapTiles[(y) * 16 + x - 1]) == 1 && x != 0) id = id + 8;

                mapTiles[y * 16 + x] += id;
            }
        }
    }
}

/*
 * Will load a mapfile's data to the integer array, byte by byte
 * Return codes:    0 -> Success
 *                  1 -> File not found
 *                  2 ->
 */
int loadMap(char *mapFileName) {
    for (int i = 0; i < 256; i++) {
        mapTiles[i] = 0;
    }

    mapTiles[2] = 16;
    mapTiles[3] = 16;
    mapTiles[4] = 16;

    mapTiles[6] = 16;
    mapTiles[7] = 16;

    mapTiles[9] = 16;

    idTilesCalc();

    return 0;
}
