#ifndef TERMINAL_H
#define TERMINAL_H

#include <cstdlib>
#include <iostream>
#include "systems.h"

class Terminal {
public:
    Terminal();
    static void print(std::string text);
    static void println(std::string text);
    static void clear();
private:
    unsigned cursor_pos[2] = {0, 0};
};



#endif //TERMINAL_H
