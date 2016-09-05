#pragma once
#include <memory>
#include <string>
#include <SDL2/SDL_image.h>
#include "System/GL/glresource.hpp"

using GLsampler = GLuint64;

class AbstractTexture : public GLResource
{
public:
    AbstractTexture(GLenum target, bool mipmap, bool linear);

    void makeResident();
    void makeNonResident();

    operator GLsampler();

    virtual ~AbstractTexture();

private:
    GLuint64 mHandle;
};
