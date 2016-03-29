#include "mappablebuffer.hpp"
#include <GL/glew.h>
#include <cassert>

MappableBuffer::MappableBuffer(GLsizeiptr size, bool write, bool read) :
    mIndex(0) {
    assert(write | read);
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

    GLbitfield flags = GL_MAP_PERSISTENT_BIT;

    if(read)
        flags |= GL_MAP_READ_BIT;

    if(write)
        flags |= GL_MAP_WRITE_BIT;

    glNamedBufferStorage(mId, mTotalSize, nullptr,
                         flags);

    if(write)
        flags |= GL_MAP_FLUSH_EXPLICIT_BIT;

    mPtr = (char*)glMapNamedBufferRange(mId, 0, mTotalSize, flags);
}

GLintptr MappableBuffer::currentOffset() {
    return mSize * mIndex;
}

GLsizeiptr MappableBuffer::size() {
    return mSize;
}

void MappableBuffer::roundRobin() {
    mIndex = (mIndex + 1) % 3;
}

void MappableBuffer::flush() {
    glFlushMappedNamedBufferRange(mId, mSize * mIndex, mSize);
}

MappableBuffer::~MappableBuffer() {
    glDeleteBuffers(1, &mId);
}