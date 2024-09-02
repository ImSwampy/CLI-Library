#include "checkbox.h"

Checkbox::Checkbox() = default;

Checkbox::~Checkbox() = default;

void Checkbox::add_choice(Choice &choice) {
    choices.push_back(choice);
}

void Checkbox::select() {
    if (0 < hovered < choices.size()-1) {
        choices[hovered].select();
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}

void Checkbox::select(int choice_index) {
    if (0 < choice_index < choices.size()) {
        choices[choice_index].select();
    } else {
        std::cerr << "selection out of bounds." << std::endl;
    }
}


void Checkbox::display_checkbox() {
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].is_selected()) {
            std::cout << SELECTED << " ";
        } else {
            std::cout << NOT_SELECTED << " ";
        }
        if (i == hovered) {
            std::cout << choices[i].get_name() << "\t<-" << std::endl;
        } else {
            std::cout << choices[i].get_name() << std::endl;
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

std::string Checkbox::get_choice(int choice_index) {
    return choices[choice_index].get_name();
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



