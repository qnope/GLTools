#pragma once
#include "rendertarget.hpp"
#include <vector>

class FrameBuffer : public GLResource
{
public:
    FrameBuffer();

    void addColorRenderTarget(std::unique_ptr<RenderTarget> &&colorBuffer);
    void changerDepthStencilBuffer(std::unique_ptr<RenderTarget> &&depthStencilBuffer,
                                   bool depth, bool stencil);

    void bindTextures(GLuint firstColorBuffer,
                      GLuint firstBinding,
                      GLuint number) const;

    void bindDepth(GLuint binding) const;

    ~FrameBuffer();

private:
    std::vector<std::unique_ptr<RenderTarget>> mColorBuffers;
    std::unique_ptr<RenderTarget> mDepthStencilBuffer;
};
