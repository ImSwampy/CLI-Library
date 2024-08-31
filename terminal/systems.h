#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <iostream>
#include <cstdlib>  // Required for std::system

// Define commands for Windows systems
#if defined(_WIN32) || defined(_WIN64)
inline void clear_console() {
    std::system("cls");
}

// Define commands for MacOS systems
#elif defined(__APPLE__) || defined(__MACH__)
inline void clear_console() {
    std::cout << "\033c";
}

// Define commands for Linux systems
#elif defined(__linux__)
inline void clear_console() {
    std::cout << "\033c";
}

// Fallback for unsupported systems
#else
inline void clear_console() {
    std::cerr << "Clear console command not supported on this system." << std::endl;
}

#endif

#endif // SYSTEMS_H
