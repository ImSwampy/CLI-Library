#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

#include "../choice/choice.h"
#include "../../terminal.h"


#define SELECTED "[*]"
#define NOT_SELECTED "[ ]"

typedef enum {
    increase,
    decrease
} hover_opt;

class Checkbox {
public:
    // constructor
    Checkbox();
    ~Checkbox();

    // setter
    void add_choice(Choice &choice);
    void select();
    void select(int choice_index);
    void change_hover(hover_opt option);

    std::string get_choice(int choice_index);



private:
    std::vector<Choice> choices;
    unsigned short hovered = 0;
    void display_checkbox();
    std::vector<Choice> get_selected();
    friend class Terminal;
};



#endif //CHECKBOX_H
