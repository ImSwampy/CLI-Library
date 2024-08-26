#include <iostream>

#include "terminal/terminal.h"
#include "terminal/checkbox/checkbox.h"

int main() {
    /*
    Terminal terminal = Terminal();
    terminal.println("caca");
    std::cin.ignore();
    terminal.clear();
    terminal.println("boudin");
    std::cin.ignore();
    */

    std::string *test = new std::string[3]{"idk1", "idk2", "idk3"};
    Checkbox checkbox = Checkbox();
    checkbox.set_choices(test, 3);
    delete[] test;
    return 0;
}
