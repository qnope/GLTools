#include "texture.hpp"
#include <stdexcept>

Texture::Texture()
{

}


Texture::operator GLsampler() {
    return mHandle;
}

void Texture::parameter() {
    glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTextureParameteri(mId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(mId, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTextureParameteri(mId, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTextureParameteri(mId, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Texture::makeResident() {
    mHandle = glGetTextureHandleARB(mId);
    glMakeTextureHandleResidentARB(mHandle);
}

std::unique_ptr<Texture> Texture::loadImage2D(const std::string &path) {
    std::unique_ptr<Texture> texture = std::make_unique<Texture>();

    SDL_Surface *surface = IMG_Load(path.c_str());

    if(surface == nullptr)
        throw std::runtime_error(path + " does not opened");

    GLenum format, internalFormat;

    getFormats(surface, internalFormat, format);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture->mId);

    texture->parameter();

    GLsizei numMipmaps = ((GLsizei)log2(std::max(surface->w, surface->h)) + 1);
    glTextureStorage2D(*texture, numMipmaps, internalFormat, surface->w, surface->h);
    glTextureSubImage2D(*texture, 0, 0, 0, surface->w, surface->h,
                        format, GL_UNSIGNED_BYTE, surface->pixels);

    glGenerateTextureMipmap(*texture);

    texture->makeResident();

    SDL_FreeSurface(surface);

    return texture;
}

std::unique_ptr<Texture> Texture::texture2D(GLuint w, GLuint h,
                                            GLenum internalFormat) {
    auto rt = std::make_unique<Texture>();

    glCreateTextures(GL_TEXTURE_2D, 1, &rt->mId);
    rt->parameter();
    glTextureStorage2D(rt->mId, 1, internalFormat, w, h);
    rt->makeResident();

    return rt;
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
