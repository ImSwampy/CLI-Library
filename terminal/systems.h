#ifndef SYSTEMS_H
#define SYSTEMS_H

// define commands for Windows systems
#if defined(_WIN32) || defined(_WIN64)
#define Clear_CMD "cls" // clear terminal

// define commands for MacOS systems
#elif defined(__APPLE__) || defined(__MACH__)
#define Clear_CMD "clear" // clear terminal

// define commands for Linux systems
#elif defined(__linux__)
#define Clear_CMD "clear" // clear terminal

#else

#endif

#endif //SYSTEMS_H
