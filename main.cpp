#include <iostream>
#include <windows.h>
#include "terminal/utils/colors/color.h"


#include "terminal/terminal.h"

int main() {
    Terminal terminal;
    Checkbox checkbox;
    Choice choice1;
    choice1.set_name("choice1");
    Choice choice2;
    choice2.set_name("choice2");
    Choice choice3;
    choice3.set_name("choice3");
    checkbox.add_choice(choice1);
    checkbox.add_choice(choice2);
    checkbox.add_choice(choice3);

    Keys input;
    do {
        input = terminal.detect_kb_input();
        if (input == Keys::DOWN) {
            checkbox.change_hover(hover_opt::increase);
        } else if (input == Keys::UP) {
            checkbox.change_hover(hover_opt::decrease);
        } else if (input == Keys::SPACE) {
            checkbox.select();
        }
        Sleep(150);
        terminal.clear();
        terminal.print(checkbox);
    } while (terminal.detect_kb_input() != Keys::ENTER);

    BackgroundColor(TextColor("nigga", FG_BLUE, true), BG_BLUE);
    std::cout << "gmqsdqsdqs";
    std::cin.ignore();

    return 0;


}
