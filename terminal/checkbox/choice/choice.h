#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>

class Choice {
public:
    // Constructors
    Choice();
    Choice(std::string name);
    Choice(std::string name, std::string description);
    Choice(std::string name, std::string description, std::string path_to_script);

    void load_script(std::string path_to_file);
    void execute();

    // Setter
    void set_name(std::string name);
    void set_description(std::string name);
    void set_script(std::string name);

    // Getter
    std::string get_name();
    std::string get_description();
private:
    std::string name;
    std::string script;
    std::string description;
};



#endif //CHOICE_H
