#pragma once

#include "System/GL/glresource.hpp"

/**
 * @brief The DynamicBuffer class
 *
 * This buffer use the triple buffering with robin count
 */
class DynamicBuffer : public GLResource
{
public:
    DynamicBuffer(GLsizeiptr size, bool read = false);

    template<typename T>
    T *map() {
        return (T*)(mPtr + mSize * mIndex);
    }

    GLintptr currentOffset();


    GLsizeiptr size();

    /**
     * @brief flush
     *
     * Ensure data wrote by the client be visible by the server
     */
    void flush();

    /**
     * @brief round robin
     *
     * Perform the round robin on buffer
     */
    void roundRobin();

    ~DynamicBuffer();

private:
    unsigned mIndex; //!< 0, 1, 2 : triple buffering
    GLsizeiptr mSize;
    GLsizeiptr mTotalSize; //!< size * 3
    char *mPtr;
};
