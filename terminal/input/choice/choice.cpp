#include "choice.h"



Choice::Choice() {
    name = "Name here";
    selected = false;
}

Choice::Choice(std::string _name) : name(_name) {
    selected = false;
}

Choice::Choice(std::string _name, bool is_selected) : name(_name), selected(is_selected) {
}

std::string Choice::get_name() {
    return name;
}

void Choice::set_name(std::string _name) {
    if (!_name.empty()) {
        name = _name;
    }
}

void Choice::select() {
    selected = !selected;
}

bool Choice::is_selected() {
    return selected;
}




