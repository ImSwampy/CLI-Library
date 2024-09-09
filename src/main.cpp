#include <iostream>

#include "terminal/utils/colors/color.h"
#include "terminal/terminal.h"
#include "terminal/input/radio/radio.h"

int main() {
    /*
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
        terminal.print(checkbox);
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

    terminal.clear();

    auto res = terminal.get_choices(checkbox);
    for (auto ch : res) {
        std::cout << ch.get_name() << std::endl;
        auto a = std::hash<std::string>{}("QKSJDKLJKKLQSDKJLQSDJPZOIEAÖE120390219OAIRPOZAE");
    }
    Sleep(5000);
    std::cin.ignore();
    */



    Terminal terminal;
    Radio radio;
    radio.display_description(true);
    Choice choice1;
    choice1.set_name("choice1");
    choice1.set_description("description1");
    Choice choice2;
    choice2.set_name("choice2");
    choice2.set_description("description2");
    Choice choice3;
    choice3.set_name("choice3");
    choice3.set_description("description3");
    radio.add_choice(choice1);
    radio.add_choice(choice2);
    radio.add_choice(choice3);
    radio.set_parent(terminal);

    Keys input;
    terminal.print(radio);
    do {
        input = terminal.detect_kb_input();
        if (input == Keys::DOWN) {
            radio.change_hover(hover_opt::increase);
        } else if (input == Keys::UP) {
            radio.change_hover(hover_opt::decrease);
        } else if (input == Keys::SPACE) {
            radio.select();
        }
        terminal.clear();
        terminal.print(radio);
    } while (input != Keys::ENTER);

    terminal.clear();
    /*
    auto res = terminal.get_choice(radio);
    std::cout << res->get_name() << std::endl;
    Sleep(5000);
    std::cin.ignore();
    */
}