#pragma once
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "contextinitializer.hpp"
#include "input.hpp"

class Device
{
public:
    Device(int width, int height, std::string name, bool debug = false);

    bool isRunning() const;

    void update();

    void swapBuffers();

    ~Device();
private:
    std::unique_ptr<ContextInitializer> mInitializer;
    std::unique_ptr<Input> mInput;
    SDL_Window *mMainWindow;
    SDL_GLContext mContext;

    std::string mName;
};
