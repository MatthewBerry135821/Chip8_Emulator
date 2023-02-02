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
        case 0x1000:
            programCounter = (opCode & 0x0FFF);
        break;
        case 0x2000:

        break;

        case 0x5000:
        //skip mean go to next thing on list
             
            if(generalPurposeRegisters[(opCode & 0x0F00) >> 8] == generalPurposeRegisters[(opCode & 0x0F0) >> 4]){
                programCounter+=2;
            }
        break;
        
        case 0x6000: //LD Vx, byte
            generalPurposeRegisters[(opCode & 0x0F00) >> 8] = opCode & 0x00FF;
        break;            
        
        case 0x7000: //ADD Vx, byte
            generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] + opCode & 0x00FF;
        break;
        
        case 0x8000:
            switch(opCode & 0x000F){
                case 0x0000: //8xy0 - LD Vx, Vy
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;
                
                case 0x0001: //8xy1 - OR Vx, Vy
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] | generalPurposeRegisters[(opCode & 0x00F0) >> 4];    
                break;
                
                case 0x0002: //8xy2 - AND Vx, Vy
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] & generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;
                
                case 0x0003: //8xy3 - XOR Vx, Vy
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] ^ generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;
                
                case 0x0004: //8xy4 - ADD Vx, Vy
                    registerVF = (generalPurposeRegisters[(opCode & 0x0F00) >> 8] + generalPurposeRegisters[(opCode & 0x00F0) >> 4]) > 0xFF;
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] + generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;
                
                case 0x0005: //8xy5 - SUB Vx, Vy
                    registerVF = generalPurposeRegisters[(opCode & 0x0F00) >> 8] > generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                    generalPurposeRegisters[(opCode & 0xF000) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] - generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;
                
                case 0x0006: //8xy6 - SHR Vx {, Vy}
                    registerVF = generalPurposeRegisters[(opCode & 0x0F00) >> 8] & 0x01 == 0x01;
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] / 2;
                break;
                
                case 0x0007: //8xy7 - SUBN Vx, Vy
                    registerVF = generalPurposeRegisters[(opCode & 0x00F0) >> 4] > generalPurposeRegisters[(opCode & 0x0F00) >> 8];
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x00F0) >> 4] - generalPurposeRegisters[(opCode & 0x0F00) >> 8];
                break;
                
                case 0x000E: //8xyE - SHL Vx {, Vy}
                    registerVF = generalPurposeRegisters[(opCode & 0x0F00) >> 8] & 0x80 == 0x80;
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] * 2;
                break;
                
                default:
                break;
            }
        break;
        
        case 0x9000: //SNE Vx, Vy
            if(generalPurposeRegisters[(opCode & 0x0F00) >> 8] != generalPurposeRegisters[(opCode & 0x00F0) >> 4])
                programCounter+=2;
        break;
        
        case 0xA000:
             registerIndex = opCode & 0x0FFF;   
        break;
        case 0xB000:
            programCounter = (opCode & 0x0FFF) + generalPurposeRegisters[0];
        break;
        
    }
    programCounter += 2;//programCounter stores location of the currently executing op code so it should be updated after it has been processed not when loaded
}