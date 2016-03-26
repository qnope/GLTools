#include "input.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>

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
                glViewport(0, 0, event.window.data1, event.window.data2);
            }
        }
    }
}

bool Input::quit() const {
    return mQuit;
}
