#pragma once

#include <GL/glew.h>
#include "System/noncopyable.hpp"

class GLResource : NonCopyable {
public:
    operator GLuint() {
        return mId;
    }

protected:
    GLuint mId = 0;
};
