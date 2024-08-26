#include "terminal.h"

Terminal::Terminal() = default;

// print
void Terminal::print(std::string text) {
    std::cout << text;
}

// print line
void Terminal::println(std::string text) {
    std::cout << text << std::endl;
}

// clear cuz yk
void Terminal::clear() {
    system(Clear_CMD);
}