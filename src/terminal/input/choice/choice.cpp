#include "choice.h"

// CONSTRUCTORS //

Choice::Choice() {
    name = "Choice name";
    description = "Choice description";
    selected = false;
}

Choice::Choice(std::string _name) {
    _name.empty() ? name = "Choice name" : _name;
    description = "Choice description";
    selected = false;
}

Choice::Choice(std::string _name, std::string _description) {
    _name.empty() ? name = "Choice name" : _name;
    _description.empty() ? description = "Choice description" : _description;
    selected = false;
}

Choice::Choice(std::string _name, std::string _description, bool is_selected) {
    _name.empty() ? name = "Choice name" : _name;
    _description.empty() ? description = "Choice description" : _description;
    selected = is_selected;
}

// END CONSTRUCTORS //



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

void Choice::set_description(std::string _description) {
    if (!_description.empty()) {
        description = _description;
    }
}

std::string Choice::get_description() {
    return description;
}

void Choice::set_script(function *function) {
    script = function;
}

void Choice::execute_script() {
    script();
}






