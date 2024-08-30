#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <thread>
#include <windows.h>


#include "systems.h"
#include "checkbox/checkbox.h"

typedef enum {
    DOWN,
    UP,
    SPACE,
    ENTER,
} Keys;

class Terminal {
public:
    Terminal();
    static void print(std::string text);
    static void print(Checkbox checkbox);
    static void println(std::string text);
    static void clear();
    Keys detect_kb_input(bool _continue = true);
private:
    Checkbox *checkbox = nullptr;
    unsigned cursor_pos[2] = {0, 0};
};

#endif //TERMINAL_H
