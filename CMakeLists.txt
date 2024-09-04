cmake_minimum_required(VERSION 3.28)
project(untitled5)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(untitled5 main.cpp
        terminal/terminal.cpp
        terminal/terminal.h
        terminal/systems/systems.h
        terminal/input/checkbox/checkbox.cpp
        terminal/input/checkbox/checkbox.h
        terminal/input/choice/choice.cpp
        terminal/input/choice/choice.h
        terminal/utils/colors/color.cpp
        terminal/utils/colors/color.h
        terminal/systems/terminal.cpp
        terminal/input/radio/radio.cpp
        terminal/input/radio/radio.h
        terminal/utils/common.h)

