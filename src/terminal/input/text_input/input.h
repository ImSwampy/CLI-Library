#ifndef CLI_LIBRARY_INPUT_H
#define CLI_LIBRARY_INPUT_H

#include "../../terminal.h"
#include <string>

#if defined(OS_WINDOWS)
#include <conio.h>
#endif

class Input {
public:
    // CONSTRUCTOR //
    Input();
    explicit Input(std::string _default_value);
    ~Input();

    // VOID //
    void display();


    // SETTER //
    void set_default_value(std::string new_default_value);

    // GETTER //
    std::string get_input();

private:

    std::string default_value;
    std::string input;

    friend class Terminal;
    void set_parent(class Terminal &_terminal);
    class Terminal *terminal = nullptr;
};


#endif //CLI_LIBRARY_INPUT_H
