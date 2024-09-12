#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>
#include <fstream>
#include <functional>

typedef enum {
    increase,
    decrease
} hover_opt;

class Choice {
public:
    // Constructors
    Choice();
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

    void execute_script();
    void set_script(std::function<void()> function);
private:
    std::string name;
    std::string description;
    std::function<void()> script = nullptr;
    bool selected = false;
};



#endif //CHOICE_H
