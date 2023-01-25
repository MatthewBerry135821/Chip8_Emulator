#include "cpu.h"

void Cpu::processNextInstruction(){
    uint16_t opCode;
    //load OpCode
    switch(opCode & 0xF000){//switches the first nibble in the opCode. This allows instructions with parameters to implemented easier 
        case 0x100:
        break;
        case 0x200:
        break;
    }
    programCounter += 2;//programCounter stores location of the currently executing op code so it should be updated after it has been processed not when loaded
}