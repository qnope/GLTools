#pragma once
#include <vector>
#include "abstracttexture.hpp"

class FrameBuffer : public GLResource
{
public:
    FrameBuffer();

    void addColorRenderTarget(std::unique_ptr<AbstractTexture> &&colorBuffer);
    void changerDepthStencilBuffer(std::unique_ptr<AbstractTexture> &&depthStencilBuffer,
                                   bool depth, bool stencil);

    GLuint64 handleColor(std::size_t i);
    GLuint64 handleDepth();

    ~FrameBuffer();

private:
    std::vector<std::unique_ptr<AbstractTexture>> mColorBuffers;
    std::unique_ptr<AbstractTexture> mDepthStencilBuffer;
};
