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

// clear cuz yk
void Terminal::clear() {
    clear_console();
}

Keys Terminal::detect_kb_input(bool) {
    while (true) {
        if (GetConsoleWindow() == GetForegroundWindow()) {
            if (GetAsyncKeyState(VK_DOWN) < 0)
            {
                return Keys::DOWN;
            }
            if (GetAsyncKeyState(VK_UP) < 0)
            {
                return Keys::UP;
            }
            if (GetAsyncKeyState(VK_SPACE) < 0)
            {
                return Keys::SPACE;
            }
            if (GetAsyncKeyState(VK_RETURN) < 0)
            {
                return Keys::ENTER;
            }
        }
    }
}
