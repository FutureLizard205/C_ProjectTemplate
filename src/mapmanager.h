#ifndef WARPWRIGGLECLI_MAPMANAGER_H
#define WARPWRIGGLECLI_MAPMANAGER_H

#include <stdio.h>
#include <stdint.h>
#include "globalvariables.h"

int tileType(const uint_fast8_t tileCode);
int tileId(const uint_fast8_t tileCode);
int loadMap(char *mapFileName);

#endif //WARPWRIGGLECLI_MAPMANAGER_H
