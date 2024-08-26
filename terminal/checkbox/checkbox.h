#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <string>
#include <iostream>

typedef enum {
    multiple,
    single
} Checkbox_types;
// radio vs checkbox

class Checkbox {
public:
    // constructor
    Checkbox();
    Checkbox(Checkbox_types type);
    Checkbox(Checkbox_types type, std::string *_choices, int length);
    ~Checkbox();

    // setter
    void set_choices(std::string *_choices, int length);
    void set_type(Checkbox_types _type);
    void set_choice(Checkbox_types type);

    // getter
    std::string get_choice(size_t choice);

    // utils
    void display_checkbox();

private:
    Checkbox_types type = multiple;
    int choice = 0;
    int *multi_choice = nullptr;
    std::string *choices = nullptr;
};



#endif //CHECKBOX_H
