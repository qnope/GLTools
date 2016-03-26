#include "rendertarget.hpp"

RenderTarget::RenderTarget()
{

}

void RenderTarget::parameter() {
    glTextureParameteri(mId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(mId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(mId, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTextureParameteri(mId, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTextureParameteri(mId, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

std::unique_ptr<RenderTarget> RenderTarget::texture2D(GLuint w, GLuint h,
                                                      GLenum internalFormat) {
    auto rt = std::make_unique<RenderTarget>();

    glCreateTextures(GL_TEXTURE_2D, 1, &rt->mId);
    rt->parameter();
    glTextureStorage2D(rt->mId, 1, internalFormat, w, h);

    return rt;
}

RenderTarget::~RenderTarget() {
    glDeleteTextures(1, &mId);
}
