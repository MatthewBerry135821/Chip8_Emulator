#include "screen.h"
#include "memory.h"
#include "cpu.h"
#include <string>
#include <cstdint>

#ifndef SYSTEM_H
#define SYSTEM_H
class System{
    public:
        System();
        void runProgram(std::string fileName);
        void testImplementation();
        friend class Cpu;
    private:
        Screen screen;
        Memory memory;
        Cpu cpu;
};
#endif