#include "cpu.h"
#include <cstdint>
#include <iostream>
#include <cstdlib>

using namespace std;

Cpu::Cpu(System *s){
    system = s;
    programCounter = 0x200;//start of program
    stackPointer = 0;//start of stack
    soundTimer = 0;//disabled
    stackPointer = 0;//disabled
}
void Cpu::processNextInstruction(){
    uint16_t opCode;
    opCode = system->memory.loadIntruction(programCounter);
    switch(opCode & 0xF000){//switches the first nibble in the opCode. This allows instructions with parameters to implemented easier 
        case 0x1000:
            
        break;
        case 0x2000:

        break;

        case 0x3000:
            if(generalRegisters[(0x0F00 & opCode) >> 8] == (opCode & 0x00FF))
            {
                programCounter += 0x2;
            }
        break;

        case 0x4000:
            if(generalRegisters[(0x0F00 & opCode) >> 8] != (opCode & 0x00FF))
            {
                programCounter += 0x2;
            }
        break;

        case 0x5000:
        //skip mean go to next thing on list
             
            if(generalRegisters[(opCode & 0x0F00) >> 8] == generalRegisters[(opCode & 0x0F0) >> 4]){
                programCounter+=2;
            }
        break;

        case 0x6000:
            generalRegisters[(0x0F00 & opCode) >> 8] = (opCode & 0x00FF);
        break;

        case 0x7000:
            generalRegisters[(0x0F00 & opCode) >> 8] += (opCode & 0x00FF);
        break;

        case 0x8000:
            switch(opCode & 0x000F){
                case 0x0000:
                    generalRegisters[(opCode & 0x0F00) >> 8] = generalRegisters[(opCode & 0x00F0) >> 4];
                break;

                case 0x0001:
                    generalRegisters[(opCode & 0x0F00) >> 8] = generalRegisters[(opCode & 0x0F00) >> 8] | generalRegisters[(opCode & 0x00F0) >> 4];
                    
                break;
                case 0x0002:
                break;
                case 0x0003:
                break;
                case 0x0004:
                break;
                case 0x0006:
                break;
                case 0x0007:
                break;
                case 0x000E:
                break;
                default:
                break;


            }
        break;

        case 0x9000:
            if(generalRegisters[(0x0F00 & opCode) >> 8] != generalRegisters[(0x00F0 & opCode) >> 4])
            {
                programCounter+=2;
            }
        break;

        case 0xA000:
             registerIndex = opCode & 0x0FFF;   
        break;

        case 0xB000:
            programCounter = (opCode & 0x0FFF) + generalRegisters[0];
        break;
        
        case 0xC000:
            generalRegisters[(0x0F00 & opCode) >> 8] = (opCode & 0x00FF) & (rand() % 256);
        break;

        case 0xF000:
            switch(opCode & 0x00FF){
                case 0xF007:
                    generalRegisters[opCode & 0x0F00 >> 8] = delayTimer;
                break;

                case 0x000A:
                break;

                case 0x0015:
                    delayTimer = generalRegisters[opCode & 0x0F00 >> 8];
                break;

                case 0x0018:
                    soundTimer = generalRegisters[opCode & 0x0F00 >> 8];
                break;

                case 0x001E:
                    registerIndex += generalRegisters[opCode & 0x0F00 >> 8];
                break;

                case 0x0029:
                    registerIndex =  0;
                break;

                case 0x0033:
                break;

                case 0x0055:
                break;
            }
        break;
    }
    programCounter += 2;//programCounter stores location of the currently executing op code so it should be updated after it has been processed not when loaded
}
void Cpu::dumpState(){
    cout << "registerIndex: " << (int)registerIndex << endl;
    cout << "registerVF: " << (int)registerVF << endl;
    cout << "delayTimer: " << (int)delayTimer << endl;
    cout << "soundTimer: " << (int)soundTimer << endl;
    cout << "stackPointer: " << (int)stackPointer << endl;
    cout << "programCounter: " << (int)programCounter << endl;
    cout << "stack:" << endl;
    for(int i=0; i<16; ++i){
        cout << "\t" << i << ": " << (int)stack[i] << endl;
    }
    cout << "generalRegisters:" << endl;
    for(int i=0; i<0xF; ++i){
        cout << "\t" << i << ": " << (int)generalRegisters[i] << endl;
    }
    cout << "f";
}