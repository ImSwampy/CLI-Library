#include "checkbox.h"

Checkbox::Checkbox() = default;

Checkbox::~Checkbox() {
    delete terminal;
};

void Checkbox::add_choice(Choice &choice) {
    choices.push_back(choice);
}

void Checkbox::select() {
    if (hovered < choices.size()) {
        choices[hovered].select();
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}

void Checkbox::select(unsigned short choice_index) {
    if (choice_index < choices.size()) {
        choices[choice_index].select();
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}


void Checkbox::display_checkbox() {
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].is_selected()) {
            terminal->print(TextColor(select_sign + " ", BOLD));
        } else {
            terminal->print(not_select_sign + " ");
        }
        if (i == hovered) {
            terminal->println(TextColor(choices[i].get_name(), DARK_YELLOW,REVERSE));
        } else {
            terminal->println(choices[i].get_name());
        }
    }
}

void Checkbox::change_hover(hover_opt option) {
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

std::optional<Choice> Checkbox::get_choice(unsigned short choice_index) {
    if (choice_index < choices.size()) {
        return choices[choice_index];
    }
    return {};
}

std::vector<Choice> Checkbox::get_selected() {
    std::vector<Choice> total_selected;

    for (auto &choice : choices) {
        if (choice.is_selected()) {
            total_selected.push_back(choice);
        }
    }

    return total_selected;
}

void Checkbox::set_selection(std::string selected, std::string not_selected) {
    if (!selected.empty() && !not_selected.empty()) {
        select_sign = selected;
        not_select_sign = not_selected;
    }

}

void Checkbox::set_selection(Box box, std::string sign) {
    if (box == Box::selected && !sign.empty()) {
        select_sign = sign;
    } else if (box == Box::not_selected) {
        not_select_sign = sign;
    }
}

void Checkbox::set_parent(class Terminal &_terminal) {
    terminal = &_terminal;
}



