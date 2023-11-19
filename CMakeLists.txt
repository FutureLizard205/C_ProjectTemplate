cmake_minimum_required(VERSION 3.26)
project(WarpWriggleCLI C)

set(CMAKE_C_STANDARD 11)

add_executable(WarpWriggleCLI
        src/main.c
        src/mapmanager.c
        src/screenmanager.c
        src/screenmanager.h)
