#pragma once
#include <GL/glew.h>

struct ColorState {
    bool rMask = true;
    bool gMask = true;
    bool bMask = true;
    bool aMask = true;
};

struct DepthStencilState {
    bool depthMask = true;
    GLenum depthFunc = GL_LESS;
};

struct BlendingState {
    bool blendingEnable = false;
};

struct PipelineState
{
    void perform() const;

    ColorState colorState;
    DepthStencilState depthStencilState;
    BlendingState blendingState;
};

