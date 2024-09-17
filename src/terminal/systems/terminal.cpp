#include "../terminal.h"

#if defined(OS_WINDOWS)

#include <windows.h>
#include <conio.h>
#include <cstdlib>

#define EXTENDED_KEY 224

inline void Terminal::clear() {
    system("cls");
}

Keys Terminal::detect_kb_input() {
    while (true) {
        int ch = _getch();
        if (ch == EXTENDED_KEY) {
            ch = _getch();
            if (ch == 72) {
                return Keys::UP;
            }
            if (ch == 80) {
                return Keys::DOWN;
            }
        }
        else {
            if (ch == 32) {
                return Keys::SPACE;
            }
            if (ch == 13) {
                return Keys::ENTER;
            }
        }
    }
}

#elif defined(OS_LINUX)

#define KEY_ESC 27

#include <unistd.h>
#include <termios.h>

inline void Terminal::clear() {
    std::cout << "\033c";
}


Keys Terminal::detect_kb_input(bool) {
    while (true) {
        int ch = getchar();
        if (ch == KEY_ESC) {
            getchar();
            ch = getchar();

            if (ch == 65) {
                return Keys::UP;
            }
            if (ch == 66) {
                return Keys::DOWN;
            }
        }
        else {
            if (ch == 32) {
                return Keys::SPACE;
            }
            if (ch == 10) {
                return Keys::ENTER;
            }
        }
    }
    return Keys::UP;
}

#endif
