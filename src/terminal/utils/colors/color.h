#ifndef UNTITLED5_COLOR_H
#define UNTITLED5_COLOR_H

#include <format>
#include <string>

#include <iostream>
#include "../../systems/systems.h"

typedef enum {
    BLACK = 30,
    DARK_RED = 31,
    DARK_GREEN = 32,
    DARK_YELLOW = 33,
    DARK_BLUE = 34,
    DARK_MAGENTA = 35,
    DARK_CYAN = 36,
    DARK_WHITE = 37,
    BRIGHT_BLACK = 90,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    BRIGHT_MAGENTA = 95,
    BRIGHT_CYAN = 96,
    WHITE = 97,
    REVERSE = 7,
    DEFAULT = 0,
    BOLD = 1,
} Color;



inline std::string TextColor(std::string text, Color text_color, Color background = DEFAULT) {
    return std::format("\033[{}m\033[{}m{}{}", std::to_string(text_color), std::to_string(background+10), text, "\033[0m");
}

#endif //UNTITLED5_COLOR_H
