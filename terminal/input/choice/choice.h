#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>
#include <fstream>

class Choice {
public:
    // Constructors
    Choice();
    Choice(std::string _name);

    void load_script(std::string path_to_file);
    void execute();

    void set_name(std::string _name);
    void set_script(std::string _name);
    void select();
    bool is_selected();

    // Getter
    std::string get_name();
private:
    std::string name;
    std::string script;

    bool selected = false;
};



#endif //CHOICE_H
