#include "memory.h"

uint16_t Memory::loadIntruction(uint16_t memoryLocation){
    return (data[memoryLocation] << 8) + data[memoryLocation+1];
}
void Memory::testForceSetNextInstruction(uint16_t opCode){
    for(int i = 0; i < 0xFFF; i += 2){
        data[i] = (opCode & 0xFF00) >> 8;
        data[i+1] = (opCode & 0x00FF);
    }
}