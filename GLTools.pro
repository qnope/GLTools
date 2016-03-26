TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    System/device.cpp \
    System/contextinitializer.cpp \
    System/input.cpp \
    System/GL/Buffer/dynamicbuffer.cpp \
    System/GL/Pipeline/vao.cpp \
    System/GL/Pipeline/pipeline.cpp \
    System/GL/Pipeline/shader.cpp \
    System/GL/Pipeline/shadermanager.cpp \
    System/GL/Buffer/staticbuffer.cpp \
    System/GL/Texture/texture.cpp \
    System/GL/Pipeline/pipelinestate.cpp \
    System/tools.cpp \
    System/GL/Texture/rendertarget.cpp \
    System/GL/Texture/framebuffer.cpp

LIBS += -lSDL2 -lGLEW -lGL -lSDL2_image

HEADERS += \
    System/device.hpp \
    System/contextinitializer.hpp \
    System/input.hpp \
    System/GL/Buffer/dynamicbuffer.hpp \
    System/GL/glresource.hpp \
    System/GL/Pipeline/vao.hpp \
    System/GL/Pipeline/pipeline.hpp \
    System/GL/Pipeline/shader.hpp \
    System/noncopyable.hpp \
    System/GL/Pipeline/shadermanager.hpp \
    System/GL/Buffer/staticbuffer.hpp \
    System/GL/Texture/texture.hpp \
    System/GL/Pipeline/pipelinestate.hpp \
    System/tools.hpp \
    System/GL/Texture/rendertarget.hpp \
    System/GL/Texture/framebuffer.hpp
