#ifndef UNTITLED5_RADIO_H
#define UNTITLED5_RADIO_H

#include <string>
#include <vector>
#include <optional>

#include "../choice/choice.h"
#include "../../utils/common.h"
#include "../../utils/colors/color.h"

class Radio {
public:
    // constructor
    Radio();
    ~Radio();

    // setter
    void add_choice(Choice &choice);
    void select();
    void select(unsigned short choice_index);
    void change_hover(hover_opt option);

    std::optional<Choice> get_choice(unsigned short choice_index);

    void set_selection(std::string selected, std::string not_selected);
    void set_selection(Box box, std::string sign);



private:
    std::vector<Choice> choices;
    unsigned short hovered = 0;
    short got_selected = -1;

    std::string select_sign = " >";
    std::string not_select_sign = "  ";

    friend class Terminal;
    void display_radio();
    std::optional<Choice> get_selected();
};


#endif //UNTITLED5_RADIO_H
