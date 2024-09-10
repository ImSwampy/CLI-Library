#include "input.h"

std::string Input::input(const std::string default_value) {
    std::cout << default_value;
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        input = default_value;
    }
    return input;
}
