#include <cstdint>
#include <SDL.h>
#include <iostream>
#include "screen.h"

using namespace std;



Screen::Screen(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        cout << "Initialization failed with error: " << SDL_GetError() << endl;
    }
    window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        cout << "could not open window" << endl;
    }
    
    screenSurface = SDL_GetWindowSurface(window);
    pixels = (uint32_t *)screenSurface->pixels;
}

Screen::~Screen(){
    void SDL_Quit(void);
}

void Screen::drawByte(uint8_t sprite, int x, int y){
    for(int i=0; i<8;++i){
        int color;
        color = ((sprite >> i) & 1)*255;
        drawPixel(color, x, y);
        x += 1;
    }
}
void Screen::drawPixel(int color, int x, int y){
    x = x * SCREEN_SCALE;
    y = y * SCREEN_SCALE;

    for(int j=0; j<SCREEN_SCALE;++j){
        for(int k=0; k<SCREEN_SCALE;++k){
            pixels[(x+j)+(y+k)*SCREEN_WIDTH] ^= SDL_MapRGB(screenSurface->format, color, color, color);
        }
    }
}
void Screen::updateScreen(){
    SDL_UpdateWindowSurface(window);
}