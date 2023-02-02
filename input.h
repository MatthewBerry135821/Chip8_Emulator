#include <cstdint>
#include <SDL.h>

#ifndef INPUT_H
#define INPUT_H
class Input{
    public:
        bool *getMappedKeysPressed();//keys will be mapped for the chip8 keyboard to work with keyboards.
    private:
        bool mappedKeys[16];//keys 0-F in chip8 layout
};
#endif