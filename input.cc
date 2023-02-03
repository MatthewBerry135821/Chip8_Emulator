#include "input.h"
#include <SDL.h>
#include <cstdint>
const SDL_Keycode keyboardMap[16] = {SDLK_1,    SDLK_2,     SDLK_3,    SDLK_4,
                                      SDLK_q,    SDLK_w,     SDLK_e,    SDLK_r,
                                      SDLK_a,    SDLK_s,     SDLK_d,    SDLK_f,
                                      SDLK_z,    SDLK_x,     SDLK_c,    SDLK_v,
                                        };

bool *Input::getMappedKeysPressed(){
    //keycodes https://wiki.libsdl.org/SDL2/SDL_Scancode
    uint8_t *keyStates;
    SDL_PumpEvents();
    keyStates = (uint8_t*)SDL_GetKeyboardState(nullptr);
    for(int i = 0;i < 0xF; ++i){
        mappedKeys[i] = keyStates[keyboardMap[i]] == 1;
    }
    return mappedKeys;
}