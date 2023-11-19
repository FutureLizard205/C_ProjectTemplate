//
// Created by miguel on 18-11-2023.
//

#include <stdint.h>
#include <time.h>

#include "globalvariables.h"
#include "mapmanager.h"
#include "screenmanager.h"

uint_fast8_t mapTiles[256];

int main() {
    loadMap("mapfilename");

    int_fast16_t msTimeWait = 500;
    struct timespec ts;
    ts.tv_sec = msTimeWait / 1000;
    ts.tv_nsec = (msTimeWait % 1000) * 1000000;

    for (int i = 0; i < 5; i++) {
        drawMap();
        nanosleep(&ts, NULL);
    }




    return 0;
}