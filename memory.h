#include <string>
#include <cstdint>
#include "cpu.h"

#ifndef MEMORY_H
#define MEMORY_H
class Memory{
    public:
        /**
         * @param name name of file containing program data
         * @return true program loaded 
         * @return false failed to load
         */
        bool loadProgram(std::string name);
        uint16_t loadIntruction(uint16_t memoryLocation);
        void storeByte(uint16_t memoryLocation, uint8_t value);

        void testForceSetNextInstruction(uint16_t opCode);

    private:
        uint8_t data[0xFFF];
};
#endif