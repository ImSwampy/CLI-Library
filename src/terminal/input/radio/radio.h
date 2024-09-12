#ifndef UNTITLED5_RADIO_H
#define UNTITLED5_RADIO_H

#include <string>
#include <vector>

#include "../../terminal.h"
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

    Choice get_choice(unsigned short choice_index);
    std::string get_description();

    void set_selection(std::string selected, std::string not_selected);
    void set_selection(Box box, std::string sign);

    void display_description(bool should_display);
    void handle_keys();

private:
    // Storage
    std::vector<Choice> choices;

    // Selection
    unsigned short hovered = 0;
    short got_selected = -1;

    // Interface stuff
    bool _display_description = false;
    std::string select_sign = " >";
    std::string not_select_sign = "  ";

    // Terminal implementation
    friend class Terminal;
    class Terminal *terminal = nullptr;
    void set_parent(class Terminal &_terminal);
    void display_radio();
    Choice get_selected();
};


#endif //UNTITLED5_RADIO_H
