#include "checkbox.h"

Checkbox::Checkbox() = default;

Checkbox::Checkbox(Checkbox_types type) : type(type) {}

Checkbox::Checkbox(Checkbox_types type, std::string *_choices, int length) : type(type) {
    if (length < 2) {
        std::cerr << "Error: choices length needs to be at least 2" << std::endl;
    } else {
        choices = new std::string[length];
        for (int i = 0; i < length; ++i) {
            choices[i] = _choices[i];
        }
    }
}

Checkbox::~Checkbox() {
    // free memory
    delete[] choices;
    delete[] multi_choice;
}

void Checkbox::set_choices(std::string *_choices, int length) {
    // checkif choices already set, and free it from memory if necessary
    if (choices == nullptr) {
        delete[] choices;
        choices = nullptr;
    }
    if (type == Checkbox_types::multiple) {
        multi_choice = new int[length];
    }

    // check the number of choices
    if (length < 2) {
        std::cerr << "Error: choices length needs to be at least 2" << std::endl;
    } else {
        // dynamically create choices
        choices = new std::string[length];
        for (int i = 0; i < length; ++i) {
            // assign each choices items to the parameter
            choices[i] = _choices[i];
        }
    }
}

void Checkbox::set_type(Checkbox_types _type){
    if (choices == nullptr) {
        std::cerr << "You need to specify the options first." << std::endl;
    }
    if (_type != Checkbox_types::single && multi_choice != nullptr) {
        delete[] multi_choice;
    }
    type = _type;
}

std::string Checkbox::get_choice(size_t choice) {
    system("mkdir hello");
}


