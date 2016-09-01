#include <iostream>
#include <stdexcept>
#include <cassert>
#include <GL/glew.h>
#include "device.hpp"
#include "contextinitializer.hpp"

void callBack(GLenum source, GLenum type, GLuint id, GLenum severity,
              GLsizei length, const GLchar *message, const void *userParam) {
    std::cerr << message << std::endl;
}

Device::Device(int width, int height, std::string name, bool debug) :
    mInitializer(std::make_unique<ContextInitializer>(debug)),
    mName(std::move(name)) {
    mMainWindow = SDL_CreateWindow(mName.c_str(),
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   width, height,
                                   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(mMainWindow == nullptr)
        throw std::runtime_error(std::string("Unable to create Window : ") +
                                 SDL_GetError());

    mContext = SDL_GL_CreateContext(mMainWindow);
    assert(mContext);

    glewExperimental = true;
    assert(glewInit() == GLEW_OK);

    if(debug) {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(callBack, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE,
                              0, nullptr, true);
    }
}

void Device::assignInput(std::shared_ptr<AbstractInput> input) {
    mInputs.push_back(input);
}

void Device::updateInputs() {
    SDL_Event event;

    while(SDL_PollEvent(&event))
        for(auto &input : mInputs)
            input->update(event);
}

void Device::swapBuffers() {
    SDL_GL_SwapWindow(mMainWindow);
}

Device::~Device() {
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mMainWindow);
}
