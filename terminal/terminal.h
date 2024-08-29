#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <thread>
#include <windows.h>


#include "systems.h"
#include "checkbox/checkbox.h"

class Terminal {
public:
    Terminal();
    static void print(std::string text);
    static void print(Checkbox checkbox);
    static void println(std::string text);
    static void clear();
    void detect_kb_input();
private:
    Checkbox *checkbox = nullptr;
    unsigned cursor_pos[2] = {0, 0};
};

#endif //TERMINAL_H
