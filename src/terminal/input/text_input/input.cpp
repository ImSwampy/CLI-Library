#include "input.h"

// DESTRUCTOR //
Input::Input() {default_value = "";}
Input::Input(std::string _default_value) : default_value(_default_value) {}
// END CONSTRUCTOR //

// DESTRUCTOR //
Input::~Input() {
    terminal = nullptr;
}
// END DESTRUCTOR //



void Input::display() {
    terminal->print(TextColor(default_value + "\r", BRIGHT_BLACK));
    std::string input_buffer;
    int char_int;
    do {
        char_int = _getch();
        if (char_int == 8) {
            input_buffer.pop_back();
        } else {
            input_buffer.push_back(char(char_int));
        }
        terminal->clear();
        terminal->print(input_buffer);
    } while (char_int != 13);
    terminal->clear();
    if (input_buffer.empty()) {
        input = default_value;
    }
    input = input_buffer;
}



void Input::set_default_value(std::string new_default_value) {
    default_value = new_default_value;
}

void Input::set_parent(class Terminal &_terminal) {
    terminal = &_terminal;
}

std::string Input::get_input() {
    return input;
}
