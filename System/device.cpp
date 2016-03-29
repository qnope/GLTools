#include <stdexcept>
#include <cassert>
#include <GL/glew.h>
#include <iostream>
#include "device.hpp"
#include "contextinitializer.hpp"

void callBack(GLenum source, GLenum type, GLuint id, GLenum severity,
              GLsizei length, const GLchar *message, const void *userParam) {
    std::cerr << message << std::endl;
}

Device::Device(int width, int height, std::string name, bool debug) :
    mInitializer(std::make_unique<ContextInitializer>(debug)),
    mInput(std::make_unique<Input>(width, height)),
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
    }
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if(GLEW_ARB_shader_draw_parameters)
        std::cerr << "lollll"<<std::endl;
}

void Device::update() {
    mInput->update();
}

bool Device::isRunning() const {
    return !mInput->mQuit;
}

void Device::swapBuffers() {
    SDL_GL_SwapWindow(mMainWindow);
}

unsigned Device::width() const {
    return mInput->mWidth;
}

unsigned Device::height() const {
    return mInput->mHeight;
}

Device::~Device() {
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mMainWindow);
}
