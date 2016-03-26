#include "texture.hpp"
#include <stdexcept>

Texture::Texture(GLenum target, std::string const &path)
{
    SDL_Surface *surface = IMG_Load(path.c_str());

    if(surface == nullptr)
        throw std::runtime_error(path + " does not opened");

    GLenum format, internalFormat;

    getFormats(surface, internalFormat, format);

    glCreateTextures(target, 1, &mId);
    glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTextureParameteri(mId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLsizei numMipmaps = ((GLsizei)log2(std::max(surface->w, surface->h)) + 1);
    glTextureStorage2D(mId, numMipmaps, internalFormat, surface->w, surface->h);
    glTextureSubImage2D(mId, 0, 0, 0, surface->w, surface->h,
                        format, GL_UNSIGNED_BYTE, surface->pixels);

    glGenerateTextureMipmap(mId);

    mHandle = glGetTextureHandleARB(mId);
    glMakeTextureHandleResidentARB(mHandle);

    SDL_FreeSurface(surface);
}

Texture::operator GLsampler2D() {
    return mHandle;
}

void Texture::getFormats(SDL_Surface *img, GLenum &internalFormat, GLenum &format) {
    if(img->format->BytesPerPixel == 3) {
        internalFormat = GL_RGB8;

        if(img->format->Rmask == 0x000000FF)
            format = GL_RGB;

        else
            format = GL_BGR;
    }

    else {
        internalFormat = GL_RGBA8;

        if(img->format->Rmask == 0x000000FF)
            format = GL_RGBA;

        else
            format = GL_BGRA;
    }
}

Texture::~Texture() {
    glDeleteTextures(1, &mId);
}
