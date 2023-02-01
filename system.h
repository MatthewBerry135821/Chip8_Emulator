#include "screen.h"
#include "memory.h"
#include "cpu.h"
#include <string>
#include <cstdint>

#ifndef SYSTEM_H
#define SYSTEM_H
class System{
    public:
        void runProgram(std::string fileName);
        void testImplementation();
        Memory memory;
    private:
        Screen screen;
        //Cpu cpu(this);
        Cpu cpu;
};
#endif