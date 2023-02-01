#include <cstdint>

#ifndef SCREEN_H
#define SCREEN_H
class Screen{
    public:
        /**
         * @brief draws a one byte sprite to the screen at position x, y
         * 
         * @param sprite single byte sprite
         * @param x 
         * @param y 
         */
        void drawByte(uint8_t sprite, int x, int y);
    private:
};
#endif