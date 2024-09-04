#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>
#include <fstream>

typedef enum {
    increase,
    decrease
} hover_opt;

class Choice {
public:
    // Constructors
    explicit Choice();
    explicit Choice(std::string _name);
    explicit Choice(std::string _name, bool is_selected);

    void set_name(std::string _name);
    void select();
    bool is_selected();

    // Getter
    std::string get_name();
private:
    std::string name;
    bool selected = false;
};



#endif //CHOICE_H
