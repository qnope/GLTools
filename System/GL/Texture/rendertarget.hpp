#pragma once

#include "System/GL/glresource.hpp"
#include <memory>

class RenderTarget : public GLResource
{
public:
    RenderTarget();

    void parameter();

    ~RenderTarget();

public:
    static std::unique_ptr<RenderTarget> texture2D(GLuint w, GLuint h,
                                                   GLenum internalFormat);
};
