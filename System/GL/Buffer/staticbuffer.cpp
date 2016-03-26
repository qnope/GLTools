#include "staticbuffer.hpp"

StaticBuffer::StaticBuffer(GLsizeiptr size, void *data) {
    glCreateBuffers(1, &mId);
    glNamedBufferData(mId, size, data, GL_STATIC_DRAW);
}

StaticBuffer::~StaticBuffer() {
    glDeleteBuffers(1, &mId);
}
