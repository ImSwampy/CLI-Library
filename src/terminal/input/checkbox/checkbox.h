#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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

    std::optional<Choice> get_choice(unsigned short choice_index);

private:
    std::vector<Choice> choices;
    unsigned short hovered = 0;
    std::string select_sign = "[*]";
    std::string not_select_sign = "[ ]";

    friend class Terminal;
    void display_checkbox();
    std::vector<Choice> get_selected();
};



#endif //CHECKBOX_H
