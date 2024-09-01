
#ifndef UNTITLED5_COLOR_H
#define UNTITLED5_COLOR_H

#include <windows.h>
#include <iostream>

const typedef enum {
    FG_BLACK = 0x0,
    FG_RED = FOREGROUND_RED,
    FG_GREEN = FOREGROUND_GREEN,
    FG_BLUE = FOREGROUND_BLUE,
    FG_CYAN = 0x3,
    FG_YELLOW = 0x6,
    FG_WHITE = 0x7,
    FG_ORANGE = FOREGROUND_RED | FOREGROUND_GREEN,
} Foreground;

const typedef enum {
    BG_BLACK = 0x00,
    BG_RED = BACKGROUND_RED,
    BG_GREEN = BACKGROUND_GREEN,
    BG_BLUE = BACKGROUND_BLUE,
    BG_CYAN = 0x30,
    BG_YELLOW = 0x60,
    BG_WHITE = 0x70,
    BG_ORANGE = BACKGROUND_RED | BACKGROUND_GREEN,
} Background;

void TextColor(std::string text, Foreground color, bool newline = false) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << text;
    if (newline) std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, 0x7 | 0x00);
}

void BackgroundColor(void *TextColor, Background color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    TextColor;
    SetConsoleTextAttribute(hConsole, 0x7 | 0x00);
}

class Color {

};


#endif //UNTITLED5_COLOR_H
