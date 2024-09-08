#ifndef SYSTEMS_H
#define SYSTEMS_H

#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS

#elif defined(__linux__)
#define OS_LINUX
#endif

#endif // SYSTEMS_H
