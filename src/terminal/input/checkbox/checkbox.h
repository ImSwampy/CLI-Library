#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <string>
#include <iostream>
#include <vector>
#include <vector>
#include <optional>

#include "../choice/choice.h"
#include "../../terminal.h"
#include "../../utils/common.h"
#include "../../utils/colors/color.h"

class Checkbox {
public:
    // constructor
    Checkbox();
    ~Checkbox();

    // setter
    void add_choice(Choice &choice);
    void change_hover(hover_opt option);
    void select();
    void select(unsigned short choice_index);
    void set_selection(std::string selected, std::string not_selected);
    void set_selection(Box box, std::string sign);


    Choice get_choice(unsigned short choice_index);

private:
    // Storage
    std::vector<Choice> choices;

    // Selection
    unsigned short hovered = 0;

    // Interface
    std::string select_sign = "[*]";
    std::string not_select_sign = "[ ]";


    // Terminal implementation
    friend class Terminal;
    void set_parent(class Terminal &_terminal);
    void display_checkbox();
    std::optional<Choice> get_selected();
    class Terminal *terminal = nullptr;
};



#endif //CHECKBOX_H
