//
// Created by miguel on 18-11-2023.
//

#include <stdint.h>
#include <locale.h>
#include <fcntl.h>

#if _WIN32
#include <windows.h>
#define msWait(x) Sleep(x)
#else
#include <unistd.h>
#define msWait(x) usleep(x*1000)
#endif

#include "globalvariables.h"
#include "mapmanager.h"
#include "screenmanager.h"

uint_fast8_t mapTiles[256];

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    setlocale(LC_CTYPE, "");    // use the locale configured in the execution environment, be it Linux or Windows

    loadMap("mapfilename");

    int_fast16_t msTimeWait = 500;

    for (int i = 0; i < 5; i++) {
        drawMap();
        msWait(msTimeWait);
    }




    return 0;
}
