TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    System/device.cpp \
    System/contextinitializer.cpp \
    System/input.cpp \
    System/GL/Pipeline/vao.cpp \
    System/GL/Pipeline/pipeline.cpp \
    System/GL/Pipeline/shader.cpp \
    System/GL/Pipeline/shadermanager.cpp \
    System/GL/Texture/texture.cpp \
    System/GL/Pipeline/pipelinestate.cpp \
    System/tools.cpp \
    System/GL/Texture/rendertarget.cpp \
    System/GL/Texture/framebuffer.cpp \
    System/GL/Buffer/unmappablebuffer.cpp \
    System/GL/Buffer/mappablebuffer.cpp \
    System/GL/Texture/texturemanager.cpp \
    System/Model/model.cpp \
    System/Model/mesh.cpp \
    System/Model/material.cpp

LIBS += -lSDL2 -lGLEW -lGL -lSDL2_image -lassimp

HEADERS += \
    System/device.hpp \
    System/contextinitializer.hpp \
    System/input.hpp \
    System/GL/glresource.hpp \
    System/GL/Pipeline/vao.hpp \
    System/GL/Pipeline/pipeline.hpp \
    System/GL/Pipeline/shader.hpp \
    System/noncopyable.hpp \
    System/GL/Pipeline/shadermanager.hpp \
    System/GL/Texture/texture.hpp \
    System/GL/Pipeline/pipelinestate.hpp \
    System/tools.hpp \
    System/GL/Texture/rendertarget.hpp \
    System/GL/Texture/framebuffer.hpp \
    System/GL/Buffer/unmappablebuffer.hpp \
    System/GL/Buffer/mappablebuffer.hpp \
    System/GL/Texture/texturemanager.hpp \
    System/Model/model.hpp \
    System/Model/mesh.hpp \
    System/Model/material.hpp \
    System/glm.hpp

DISTFILES += \
    Shaders/shader.frag \
    Shaders/final.frag \
    Shaders/shader.vert \
    Shaders/final.vert
