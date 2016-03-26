#pragma once

#include "System/GL/glresource.hpp"

class StaticBuffer : public GLResource {
public:
    StaticBuffer(GLsizeiptr size, void *data);

    ~StaticBuffer();
};
