#include "../terminal.h"

#if defined(OS_WINDOWS)

#include <windows.h>

void Terminal::clear() {
    system("cls");
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