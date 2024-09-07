#include "terminal.h"

#if defined(OS_WINDOWS)

Terminal::Terminal() = default;
Terminal::~Terminal() = default;

#elif defined(OS_LINUX)
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

Terminal::Terminal() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

Terminal::~Terminal() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

#endif

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

