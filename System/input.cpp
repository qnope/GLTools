#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "input.hpp"

Input::Input(unsigned width, unsigned height) :
    mWidth(width), mHeight(height) {

}

void Input::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_WINDOWEVENT) {
            if(event.window.event == SDL_WINDOWEVENT_CLOSE)
                mQuit = true;

            if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                mWidth = event.window.data1;
                mHeight = event.window.data2;
                mResized = true;
            }

            else
                mResized = false;
        }
    }
}
