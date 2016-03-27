#pragma once

#include "System/GL/glresource.hpp"

class StaticBuffer : public GLResource {
public:
    StaticBuffer(GLsizeiptr size, void *data);

    void pushData(void *data, GLsizeiptr size);

    GLsizeiptr offset() const;

    ~StaticBuffer();

private:
    GLsizeiptr mSize;
    GLsizeiptr mOffset;

    void resizeBuffer(GLsizeiptr size);
};
