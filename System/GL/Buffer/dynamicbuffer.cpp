#include "dynamicbuffer.hpp"
#include <GL/glew.h>

DynamicBuffer::DynamicBuffer(GLsizeiptr size, bool read) :
    mIndex(0) {
    glCreateBuffers(1, &mId);

    GLint alignmentUniform, alignmentShaderStorage, alignment;
    glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &alignmentUniform);
    glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &alignmentShaderStorage);

    alignment = (alignmentUniform > alignmentShaderStorage) ? alignmentUniform : alignmentShaderStorage;

    // We're going to align data on alignment bytes
    if(size % alignment != 0) {
        size = size + (alignment - (size % alignment));
    }

    mSize = size;
    mTotalSize = size * 3;

    GLbitfield flags = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT;

    if(read)
        flags |= GL_MAP_READ_BIT;

    glNamedBufferStorage(mId, mTotalSize, nullptr,
                         flags);

    flags |= GL_MAP_FLUSH_EXPLICIT_BIT;

    mPtr = (char*)glMapNamedBufferRange(mId, 0, mTotalSize, flags);
}

GLintptr DynamicBuffer::currentOffset() {
    return mSize * mIndex;
}

GLsizeiptr DynamicBuffer::size() {
    return mSize;
}

void DynamicBuffer::roundRobin() {
    mIndex = (mIndex + 1) % 3;
}

void DynamicBuffer::flush() {
    glFlushMappedNamedBufferRange(mId, mSize * mIndex, mSize);
}

DynamicBuffer::~DynamicBuffer() {
    glDeleteBuffers(1, &mId);
}
