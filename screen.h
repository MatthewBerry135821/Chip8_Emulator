#include <cstdint>

#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_SCALE 8
#define SCREEN_WIDTH 64*SCREEN_SCALE
#define SCREEN_HEIGHT 32*SCREEN_SCALE
class Screen{
    public:
        Screen();
        ~Screen();
        /**
         * @brief draws a one byte sprite to the screen at position x, y
         * 
         * @param sprite single byte sprite
         * @param x 
         * @param y 
         */
        void drawByte(uint8_t sprite, int x, int y);
        void drawPixel(int color, int x, int y);
        void initiateScreen();
        void updateScreen();
    private:
        SDL_Window *window;
        SDL_Surface *screenSurface;
        uint32_t *pixels;
};
#endif