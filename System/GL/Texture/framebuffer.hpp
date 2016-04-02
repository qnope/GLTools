#pragma once
#include "texture.hpp"
#include <vector>

class FrameBuffer : public GLResource
{
public:
    FrameBuffer();

    void addColorRenderTarget(std::unique_ptr<Texture> &&colorBuffer);
    void changerDepthStencilBuffer(std::unique_ptr<Texture> &&depthStencilBuffer,
                                   bool depth, bool stencil);

    GLuint64 handleColor(std::size_t i);
    GLuint64 handleDepth();

    ~FrameBuffer();

private:
    std::vector<std::unique_ptr<Texture>> mColorBuffers;
    std::unique_ptr<Texture> mDepthStencilBuffer;
};
