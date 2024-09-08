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
    explicit Choice(std::string _name, std::string _description);
    explicit Choice(std::string _name, std::string _description, bool is_selected);

    void set_name(std::string _name);
    void set_description(std::string _description);

    void select();
    bool is_selected();

    // Getter
    std::string get_name();
    std::string get_description();
private:
    std::string name;
    std::string description;
    bool selected = false;
};



#endif //CHOICE_H
