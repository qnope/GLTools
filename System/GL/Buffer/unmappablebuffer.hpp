#pragma once

#include "System/GL/glresource.hpp"

class UnmappableBuffer : public GLResource {
public:
    UnmappableBuffer(GLsizeiptr size, void *data, GLenum usage);

    void pushData(void *data, GLsizeiptr size);

    GLsizeiptr offset() const;

    ~UnmappableBuffer();

private:
    GLsizeiptr mSize;
    GLsizeiptr mOffset;
    GLenum mUsage;

    void resizeBuffer(GLsizeiptr size);
};
