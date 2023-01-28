#include "screen.h"
#include "memory.h"
#include "cpu.h"
#include <string>

#ifndef SYSTEM_H
#define SYSTEM_H
class System{
    public:
        void runProgram(std::string fileName);
    private:
        Screen screen;
        Memory memory;
        Cpu cpu(this);
};
#endif