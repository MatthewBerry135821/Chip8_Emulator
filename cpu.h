#include "system.h"
#ifndef CPU_H
#define CPU_H
class Cpu{
    public:
        Cpu(System *s);
        void processNextInstruction();
    private:
        System *system;
        uint16_t stack[16];
        uint8_t generalPurposeRegisters[0xF];
        uint16_t registerIndex;
        bool registerVF;
        uint8_t delayTimer;
        uint8_t soundTimer;
        uint8_t stackPointer;
        uint16_t programCounter;
};
#endif