#pragma once

#include "System/GL/glresource.hpp"
#include "System/GL/Pipeline/rasterizationstate.hpp"

class Pipeline : public GLResource
{
public:
    Pipeline();

    void attach(GLuint shader);
    void create();
    void bind();

    void setRasterizationState(RasterizationState const &rs);

    ~Pipeline();

private:
    RasterizationState mRasterizationState;
};
