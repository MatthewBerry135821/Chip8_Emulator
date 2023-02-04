#include "system.h"
#include <iostream>
#include <cstdint>

using namespace std;



System::System(){
    Cpu c(this);
    cpu =c;
}
void System::testImplementation(){
    int testType;
    
    screen.drawByte(0xF0,0,0);//draws A
    screen.drawByte(0x90,0,1);
    screen.drawByte(0xF0,0,2);
    screen.drawByte(0x90,0,3);
    screen.drawByte(0x90,0,4);

    do{
        screen.updateScreen();
        cout << "\nTest Options:\n\t1) Test opCode\n\t2) Dump CPU state\n\t-1) Exit" << "\nEnter option: ";
        cin >> testType;
        switch(testType){
            case 1:
                int opCode;
                std::cin.unsetf(std::ios::dec);
                std::cin.unsetf(std::ios::hex);
                std::cin.unsetf(std::ios::oct);
                cout << "Input opCode: ";
                cin >> opCode;
                memory.testForceSetNextInstruction(opCode);
                cpu.processNextInstruction();
            break;
            case 2:
                cpu.dumpState();
            break;
        }
        screen.updateScreen();
    }while(testType != -1);
}