#include "radio.h"

Radio::Radio() = default;

Radio::~Radio() = default;

void Radio::add_choice(Choice &choice) {
    choices.push_back(choice);
}

void Radio::select() {
    if (hovered < choices.size()) {
        if (got_selected != -1) choices[got_selected].select();
        choices[hovered].select();
        got_selected = hovered;
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}

void Radio::select(unsigned short choice_index) {
    if (choice_index < choices.size()) {
        if (got_selected != -1) choices[got_selected].select();
        choices[choice_index].select();
        got_selected = hovered;
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}


void Radio::display_radio() {
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].is_selected()) {
            // Doesn't compile on linux. Should fix.
            //Win_TextColor(select_sign + " ", FG_RED);
        } else {
            std::cout << not_select_sign << " ";
        }
        if (i == hovered) {
            // Doesn't compile on linux. Should fix.
            //Win_TextColor(choices[i].get_name(), FG_BLACK, BG_WHITE, true);
        } else {
            std::cout << choices[i].get_name() << std::endl;
        }
    }
}

void Radio::change_hover(hover_opt option) {
    switch (option) {
        case hover_opt::increase:
            if (hovered+1 < choices.size()) {
                hovered++;
            } else {
                hovered = choices.size()-1;
            }
            break;
        case hover_opt::decrease:
            if (hovered-1 > 0) {
                hovered--;
            } else {
                hovered = 0;
            }
            break;
    }
}

std::optional<Choice> Radio::get_choice(unsigned short choice_index) {
    if (choice_index < choices.size()) {
        return choices[choice_index];
    }
    return {};
}

std::optional<Choice> Radio::get_selected() {
    for (auto &choice : choices) {
        if (choice.is_selected()) {
            return choice;
        }
    }
    return {};
}

void Radio::set_selection(std::string selected, std::string not_selected) {
    if (!selected.empty() && !not_selected.empty()) {
        select_sign = selected;
        not_select_sign = not_selected;
    }

}

void Radio::set_selection(Box box, std::string sign) {
    if (box == Box::selected && !sign.empty()) {
        select_sign = sign;
    } else if (box == Box::not_selected) {
        not_select_sign = sign;
    }
}
