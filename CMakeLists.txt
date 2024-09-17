cmake_minimum_required(VERSION 3.25)
project(CLI-Library)

if(NOT (${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "Windows"))
    message(FATAL_ERROR "Operating system is unsupported.")
endif()

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file (GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES}
        src/terminal/input/text_input/input.cpp
        src/terminal/input/text_input/input.h)