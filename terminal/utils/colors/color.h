#ifndef UNTITLED5_COLOR_H
#define UNTITLED5_COLOR_H


#include <iostream>
#include "../../systems/systems.h"

#if defined(OS_WINDOWS)

#include <windows.h>
const typedef enum {
    FG_BLACK = 0x0,
    FG_RED = FOREGROUND_RED,
    FG_GREEN = FOREGROUND_GREEN,
    FG_BLUE = FOREGROUND_BLUE,
    FG_CYAN = 0x3,
    FG_YELLOW = 0x6,
    FG_WHITE = 0x7,
    FG_ORANGE = FOREGROUND_RED | FOREGROUND_GREEN,
} Win_Foreground;

const typedef enum {
    BG_BLACK = 0x00,
    BG_RED = BACKGROUND_RED,
    BG_GREEN = BACKGROUND_GREEN,
    BG_BLUE = BACKGROUND_BLUE,
    BG_CYAN = 0x30,
    BG_YELLOW = 0x60,
    BG_WHITE = 0x70,
    BG_ORANGE = BACKGROUND_RED | BACKGROUND_GREEN,
} Win_Background;

inline void Win_TextColor(std::string text, Win_Foreground color, Win_Background background = BG_BLACK, bool newline = false) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << text;
    if (newline) std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, 0x7 | 0x00);
}

class Color {

};

#elif (OS == LINUX)

#endif

#endif //UNTITLED5_COLOR_H
