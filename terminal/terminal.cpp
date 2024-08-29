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

void Terminal::detect_kb_input() {
    while (true) {
        if (GetConsoleWindow() == GetForegroundWindow()) {
            if (GetKeyState(VK_DOWN) < 0) {
                std::cout << "down" << std::endl;
                while ((GetKeyState(VK_DOWN) < 0)) {}
            }
            else if (GetKeyState(VK_UP) < 0) {
                std::cout << "up" << std::endl;
                while ((GetKeyState(VK_UP) < 0)) {}
            }
            else if (GetKeyState(VK_SPACE) < 0) {
                std::cout << "space" << std::endl;
                while ((GetKeyState(VK_SPACE) < 0)) {
                }
            }
        }
    }
}
