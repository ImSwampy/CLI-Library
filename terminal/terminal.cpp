#include "terminal.h"

Terminal::Terminal() = default;

// print
void Terminal::print(std::string text) {
    std::cout << text;
}


void Terminal::print(Checkbox &checkbox) {
    checkbox.display_checkbox();
}


void Terminal::print(Radio &radio) {
    radio.display_radio();
}

// print line
void Terminal::println(std::string text) {
    std::cout << text << std::endl;
}

std::vector<Choice> Terminal::get_choices(Checkbox &checkbox) {
    return checkbox.get_selected();
}

std::optional<Choice> Terminal::get_choice(Radio &radio) {
    return radio.get_selected();
}

