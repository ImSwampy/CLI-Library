    #include "choice.h"

Choice::Choice() {
    name = "Name here";
    description = "Description here";
    script = "echo \"script be scripting\"";
}

Choice::Choice(std::string _name) : name(_name) {
    description = "Description here";
    script = "echo \"script be scripting\"";
}

Choice::Choice(std::string _name, std::string _description) : name(_name), description(_description) {
    script = "echo \"script be scripting\"";
}

Choice::Choice(std::string _name, std::string _description, std::string _path_to_script) : name(_name), description(_description), script(_path_to_script) {

}

void Choice::execute() {
    if (!script.empty()) {
        system(script.c_str());
    } else {
        std::cerr << "Error: 'script' is not defined" << std::endl;
    }
}

std::string Choice::get_description() {
    return description;
}

std::string Choice::get_name() {
    return name;
}

void Choice::load_script(std::string path_to_file) {
    // open script file
    std::ifstream file;
    file.open(script);
    std::string script_buff;
    // save it to script variable
    while (file.is_open()) {
        script.append(std::to_string(file.get()));
        script.append("\n");
    }
    file.close();
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




