#include "terminal.h"

Terminal::Terminal() = default;

// print
void Terminal::print(std::string text) {
    std::cout << text;
}


void Terminal::print(Checkbox &checkbox) {
    checkbox.display_checkbox();
}

// print line
void Terminal::println(std::string text) {
    std::cout << text << std::endl;
}

