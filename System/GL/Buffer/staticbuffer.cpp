#include "staticbuffer.hpp"
#include "System/tools.hpp"
#include <iostream>

StaticBuffer::StaticBuffer(GLsizeiptr size, void *data) {
    mSize = nextPowerOfTwo(size);
    glCreateBuffers(1, &mId);
    glNamedBufferData(mId, mSize, nullptr, GL_STATIC_DRAW);

    if(data != nullptr) {
        glNamedBufferSubData(mId, 0, size, data);
        mOffset = size;
    }

    else
        mOffset = 0;
}

void StaticBuffer::pushData(void *data, GLsizeiptr size) {
    if(mOffset + size > mSize)
        resizeBuffer(mOffset + size);
    glNamedBufferSubData(mId, mOffset, size, data);
    mOffset += size;
}

void StaticBuffer::resizeBuffer(GLsizeiptr size) {
    GLuint newBuffer;

    size = nextPowerOfTwo(size);

    glCreateBuffers(1, &newBuffer);
    glNamedBufferData(newBuffer, size, nullptr, GL_STATIC_DRAW);
    glCopyNamedBufferSubData(mId, newBuffer, 0, 0, mSize);
    glDeleteBuffers(1, &mId);

    mId = newBuffer;
    mSize = size;
}

StaticBuffer::~StaticBuffer() {
    glDeleteBuffers(1, &mId);
}
