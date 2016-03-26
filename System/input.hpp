#pragma once

class Device;

class Input
{
    friend Device;
public:
    Input(unsigned width, unsigned height);

    void update();

private:
    unsigned mWidth;
    unsigned mHeight;
    bool mQuit = false;
};
