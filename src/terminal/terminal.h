#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <variant>

#include "systems/systems.h"
#include "input/checkbox/checkbox.h"
#include "input/radio/radio.h"
#include "input/text_input/input.h"
#include "utils/common.h"

#if defined(OS_WINDOWS)
#include <windows.h>
#endif

class Terminal {
public:
    Terminal();
    ~Terminal();
    void print(std::string text);
    void print(char character);
    void print(class Checkbox &checkbox);
    void print(class Radio &radio);
    void println(std::string text);
    inline void clear();
    inline Keys detect_kb_input();
    std::vector<Choice> get_choices(class Checkbox &checkbox);
    Choice get_choice(class Radio &radio);

    void add(class Checkbox &checkbox);
    void add(class Radio &radio);
    void add(class Input &input);
};

#endif //TERMINAL_H
