cmake_minimum_required(VERSION 3.28)
project(untitled5)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled5 main.cpp
        terminal/terminal.cpp
        terminal/terminal.h
        terminal/systems.h
        terminal/checkbox/checkbox.cpp
        terminal/checkbox/checkbox.h
        terminal/checkbox/choice/choice.cpp
        terminal/checkbox/choice/choice.h)