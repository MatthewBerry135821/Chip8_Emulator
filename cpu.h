//#include "system.h"
#include <cstdint>
class System;
#include <cstdint>
#ifndef CPU_H
#define CPU_H
class Cpu{
    public:
        Cpu(System *s = nullptr);
        void dumpState();
        void processNextInstruction();
    private:
        System *system;
        uint16_t stack[16];
        uint8_t generalRegisters[0xF]; //V in Cowdog's doc
        uint16_t registerIndex;
        bool registerVF;
        uint8_t delayTimer;
        uint8_t soundTimer;
        uint8_t stackPointer;
        uint16_t programCounter;
};
#include "system.h"
#endif