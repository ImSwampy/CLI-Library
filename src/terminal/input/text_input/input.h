#ifndef CLI_LIBRARY_INPUT_H
#define CLI_LIBRARY_INPUT_H

#include "../../terminal.h"
#include <string>

class Input {
public:
    std::string input(const std::string default_value);
};


#endif //CLI_LIBRARY_INPUT_H
