#pragma once

#include "System/GL/glresource.hpp"

/**
 * @brief The MappableBuffer class
 *
 * This buffer use the n buffering with robin count
 */
class MappableBuffer : public GLResource
{
public:
    MappableBuffer(GLsizeiptr size, unsigned roundRobin, bool write = true, bool read = false);

    template<typename T>
    T *map() {
        return (T*)(mPtr + mSize * mIndex);
    }

    GLintptr currentOffset();

    GLsizeiptr size();

    /**
     * @brief flush
     *
     * Ensure data wrote by the client will be visible by the server
     */
    void flush();

    /**
     * @brief round robin
     *
     * Perform the round robin on buffer
     */
    void performRoundRobin();

    ~MappableBuffer();

private:
    unsigned mIndex; //!< 0, 1, 2 ... n-1 : n buffering
    unsigned mRoundRobin;
    GLsizeiptr mSize;
    GLsizeiptr mTotalSize; //!< size * roundRobin
    char *mPtr;
};
