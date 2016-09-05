#include "abstracttexture.hpp"

AbstractTexture::AbstractTexture(GLenum target, bool mipmap, bool linear) {
    glCreateTextures(target, 1, &mId);

    if(linear) {
        if(mipmap)
            glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        else
            glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(mId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    else {
        if(mipmap)
            glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

        else
            glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(mId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
}

AbstractTexture::operator GLsampler() {
    return mHandle;
}

void AbstractTexture::makeResident() {
    mHandle = glGetTextureHandleARB(mId);
    glMakeTextureHandleResidentARB(mHandle);
}

void AbstractTexture::makeNonResident() {
    mHandle = glGetTextureHandleARB(mId);
    glMakeTextureHandleNonResidentARB(mHandle);
}

AbstractTexture::~AbstractTexture() {
    glDeleteTextures(1, &mId);
}
