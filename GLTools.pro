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
    System/GL/Texture/texture.cpp \
    System/GL/Pipeline/pipelinestate.cpp \
    System/tools.cpp \
    System/GL/Texture/framebuffer.cpp \
    System/GL/Buffer/unmappablebuffer.cpp \
    System/GL/Buffer/mappablebuffer.cpp \
    System/Model/mesh.cpp \
    System/Model/material.cpp \
    System/Model/modelimporter.cpp \
    System/GL/Texture/texturerepository.cpp \
    System/GL/Pipeline/shaderrepository.cpp

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
    System/GL/Texture/texture.hpp \
    System/GL/Pipeline/pipelinestate.hpp \
    System/tools.hpp \
    System/GL/Texture/framebuffer.hpp \
    System/GL/Buffer/unmappablebuffer.hpp \
    System/GL/Buffer/mappablebuffer.hpp \
    System/Model/mesh.hpp \
    System/Model/material.hpp \
    System/glm.hpp \
    System/Model/modelimporter.hpp \
    System/GL/Texture/texturerepository.hpp \
    System/GL/Pipeline/shaderrepository.hpp

DISTFILES += \
    Shaders/shader.frag \
    Shaders/final.frag \
    Shaders/shader.vert \
    Shaders/final.vert
