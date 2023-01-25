#include "cpu.h"
Cpu::Cpu(System *s = nullptr){
    system = s;
    programCounter = 0x200;//start of program
    stackPointer = 0;//start of stack
    soundTimer = 0;//disabled
    stackPointer = 0;//disabled
}
void Cpu::processNextInstruction(){
    uint16_t opCode;
    opCode = system.memory.loadIntruction(programCounter);
    switch(opCode & 0xF000){//switches the first nibble in the opCode. This allows instructions with parameters to implemented easier 
        case 0x100:
        break;
        case 0x200:
        break;
    }
    programCounter += 2;//programCounter stores location of the currently executing op code so it should be updated after it has been processed not when loaded
}