#include "cpu.h"
#include <cstdint>
#include <iostream>

using namespace std;

Cpu::Cpu(){
    //system = s;
    programCounter = 0x200;//start of program
    stackPointer = 0;//start of stack
    soundTimer = 0;//disabled
    stackPointer = 0;//disabled
}
void Cpu::processNextInstruction(System *system){
    uint16_t opCode;
    opCode = system->memory.loadIntruction(programCounter);
    switch(opCode & 0xF000){//switches the first nibble in the opCode. This allows instructions with parameters to implemented easier 
        case 0x1000:
            
        break;
        case 0x2000:

        break;

        case 0x5000:
        //skip mean go to next thing on list
             
            if(generalPurposeRegisters[(opCode & 0x0F00) >> 8] == generalPurposeRegisters[(opCode & 0x0F0) >> 4]){
                programCounter+=2;
            }
        break;

        case 0x8000:
            switch(opCode & 0x000F){
                case 0x0000:
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                break;

                case 0x0001:
                    generalPurposeRegisters[(opCode & 0x0F00) >> 8] = generalPurposeRegisters[(opCode & 0x0F00) >> 8] | generalPurposeRegisters[(opCode & 0x00F0) >> 4];
                    
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
    cout << "generalPurposeRegisters:" << endl;
    for(int i=0; i<0xF; ++i){
        cout << "\t" << i << ": " << (int)generalPurposeRegisters[i] << endl;
    }
    cout << "f";
}