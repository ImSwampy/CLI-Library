cmake_minimum_required(VERSION 3.28)
project(untitled5)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled5 main.cpp
        terminal/terminal.cpp
        terminal/terminal.h
        terminal/systems.h
        terminal/input/checkbox/checkbox.cpp
        terminal/input/checkbox/checkbox.h
        terminal/input/choice/choice.cpp
        terminal/input/choice/choice.h
        terminal/utils/colors/color.cpp
        terminal/utils/colors/color.h)