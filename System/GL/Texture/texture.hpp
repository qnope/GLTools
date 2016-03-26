#pragma once
#include "System/GL/glresource.hpp"
#include <SDL2/SDL_image.h>
#include <string>

using GLsampler2D = GLuint64;

class Texture : public GLResource
{
public:
    Texture(GLenum target, const std::string &path);

    operator GLsampler2D();

    ~Texture();

private:
    GLuint64 mHandle;
    void getFormats(SDL_Surface *img, GLenum &internalFormat, GLenum &format);
};
