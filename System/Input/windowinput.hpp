#pragma once
#include "abstractinput.hpp"

class WindowInput : public AbstractInput {
public:
    WindowInput(unsigned width, unsigned height);

    bool isRunning() const {
        return !mQuit;
    }

    unsigned width() const {
        return mWidth;
    }

    unsigned height() const {
        return mHeight;
    }

    void update(SDL_Event const &event);

    ~WindowInput() = default;

private:
    bool mQuit = false;
    unsigned mWidth = 0;
    unsigned mHeight = 0;
};
