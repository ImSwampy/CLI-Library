#include "terminal.h"

Terminal::Terminal() {
#if defined(OS_WINDOWS)

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE), hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode;
    GetConsoleMode(hOutput, &dwMode);
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOutput, dwMode)) {
        std::cerr << "SetConsoleMode failed." << std::endl << "No color enabled." << std::endl;
    }
#elif defined(OS_LINUX)
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
#endif
};

Terminal::~Terminal() {
#if defined(OS_LINUX)
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
#endif
}

void Terminal::print(std::string text) { std::cout << text; }
void Terminal::print(char character) { std::cout << character; }

void Terminal::print(Checkbox &checkbox) {
    checkbox.display_checkbox();
}


void Terminal::print(Radio &radio) {
    radio.display_radio();
}

void Terminal::println(std::string text) { std::cout << text << std::endl; }

std::vector<Choice> Terminal::get_choices(Checkbox &checkbox) {
    return checkbox.get_selected();
}

std::optional<Choice> Terminal::get_choice(Radio &radio) {
    return radio.get_selected();
}

void Terminal::add(class Checkbox &checkbox) {
    checkbox.set_parent(*this);
}

void Terminal::add(class Radio &radio) {
    radio.set_parent(*this);
}

void Terminal::add(Input &input) {
    input.set_parent(*this);
}

