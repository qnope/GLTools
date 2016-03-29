#pragma once
#include "System/GL/glresource.hpp"
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>

using GLsampler2D = GLuint64;

class Texture : public GLResource
{
public:
    Texture();

    void parameter();

    operator GLsampler2D();

    ~Texture();

public:
    static std::unique_ptr<Texture> loadImage2D(std::string const &path);

private:
    GLuint64 mHandle;
    static void getFormats(SDL_Surface *img, GLenum &internalFormat, GLenum &format);
};
