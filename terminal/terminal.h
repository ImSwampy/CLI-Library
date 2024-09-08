#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <thread>

#include "systems/systems.h"
#include "input/checkbox/checkbox.h"
#include "input/radio/radio.h"
#include "utils/common.h"

#if defined(OS_WINDOWS)
#include <windows.h>
#endif

class Terminal {
public:
    Terminal();
    ~Terminal();
    void print(std::string text);
    void print(class Checkbox &checkbox);
    void print(class Radio &radio);
    void println(std::string text);
    std::string input(std::string default_value);
    void clear();
    Keys detect_kb_input();
    std::vector<Choice> get_choices(Checkbox &checkbox);
    std::optional<Choice> get_choice(Radio &radio);
private:

};

#endif //TERMINAL_H
