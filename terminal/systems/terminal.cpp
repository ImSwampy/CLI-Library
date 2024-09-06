#include "../terminal.h"

#if defined(OS_WINDOWS)

#include <windows.h>
#include <conio.h>

#define EXTENDED_KEY 224

void Terminal::clear() {
    system("cls");
}


Keys Terminal::detect_kb_input(bool) {

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

#include <unistd.h>
#include <termios.h>

void Terminal::clear() {
    std::cout << "\033c";
}


inline Keys Terminal::detect_kb_input(bool) {
    while (true) {
        char c;
        read(STDIN_FILENO, &c, 1);

        switch (c) {
            case ' ':
                return Keys::SPACE;
            case '\n':
                return Keys::ENTER;
            case 27:
                char arrow[2];
                read(STDIN_FILENO, arrow, 2)
                if (arrow[])
        }
    }
}

#endif