#pragma once

class Input
{
public:
    Input(unsigned width, unsigned height);

    void update();

    bool quit() const;

private:
    unsigned mWidth;
    unsigned mHeight;
    bool mQuit = false;
};
