#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>
#include <fstream>

class Choice {
public:
    // Constructors
    Choice();
    Choice(std::string _name);
    Choice(std::string _name, std::string _description);
    Choice(std::string _name, std::string _description, std::string _path_to_script);

    void load_script(std::string path_to_file);
    void execute();

    // Setter
    void set_name(std::string _name);
    void set_description(std::string _name);
    void set_script(std::string _name);

    // Getter
    std::string get_name();
    std::string get_description();
private:
    std::string name;
    std::string script;
    std::string description;
};



#endif //CHOICE_H
