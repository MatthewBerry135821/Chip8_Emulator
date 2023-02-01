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
    do{
        cout << "what do test?\n\t1) opCoce\n\t2>dump CPU state\n\t-1)exit" << endl << endl;
        cin >> testType;
        switch(testType){
            case 1:
                int opCode;
                std::cin.unsetf(std::ios::dec);
                std::cin.unsetf(std::ios::hex);
                std::cin.unsetf(std::ios::oct);
                cout << "what opCode test? ";
                cin >> opCode;
                memory.testForceSetNextInstruction(opCode);
                cpu.processNextInstruction();
            break;
            case 2:
                cpu.dumpState();
            break;
        }
    }while(testType != -1);
}