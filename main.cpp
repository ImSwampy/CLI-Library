#include <iostream>

#include "terminal/terminal.h"
#include "terminal/checkbox/checkbox.h"

int main() {
    Terminal terminal;
    do {
        std::cout << terminal.detect_kb_input() << std::endl;
    } while (terminal.detect_kb_input() != Keys::ENTER);
}
