#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <thread>



#include "systems/systems.h"
#include "input/checkbox/checkbox.h"

typedef enum {
    DOWN,
    UP,
    SPACE,
    ENTER,
} Keys;

class Terminal {
public:
    Terminal();
    void print(std::string text);
    void print(class Checkbox &checkbox);
    void println(std::string text);
    void clear();
    Keys detect_kb_input(bool _continue = true);
private:
    Checkbox *checkbox = nullptr;
    unsigned cursor_pos[2] = {0, 0};
};

#endif //TERMINAL_H
