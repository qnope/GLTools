#include <GL/glew.h>
#include "System/GL/Buffer/unmappablebuffer.hpp"
#include "System/GL/Buffer/mappablebuffer.hpp"
#include "System/device.hpp"
#include "System/GL/Pipeline/vao.hpp"
#include "System/GL/Pipeline/pipeline.hpp"
#include "System/GL/Pipeline/shadermanager.hpp"
#include "System/GL/Texture/texturemanager.hpp"
#include "System/GL/Texture/framebuffer.hpp"
#include "System/Model/model.hpp"

struct Materials {
    GLsampler2D diffuse[2];
};

int main(int argc, char *argv[])
{
    Device device(800, 600, "Graphic Engine", true);

    float vertices[] = {-1, -1,
                        -1, 1,
                        1, -1,
                        1, 1};

    float uv[] = {0, 0,
                  0, 1,
                  1, 0,
                  1, 1};

    GLuint index[] = {0, 1, 2, 3};

    // Build buffers
    UnmappableBuffer bufferVertices(sizeof vertices, vertices, GL_STATIC_DRAW);
    UnmappableBuffer bufferUv(sizeof uv, uv, GL_STATIC_DRAW);
    UnmappableBuffer bufferIndex(sizeof index, index, GL_STATIC_DRAW);
    Vao vao; // Build VAO

    GLuint buffers[] = {bufferVertices, bufferUv};
    GLintptr offsets[] = {0, 0};
    GLsizei strides[] = {2 * sizeof(float), 2 * sizeof(float)};

    // set VAO for vertices and uv
    vao.enableArray(0);
    vao.enableArray(1);
    vao.attribBinding(0, 0);
    vao.attribBinding(1, 1);
    vao.bindElementBuffer(bufferIndex);
    vao.bindVertexBuffers(0, 2, buffers, offsets, strides);
    vao.format(0, 2, GL_FLOAT, false, 0);
    vao.format(1, 2, GL_FLOAT, false, 0);

    ShaderManager shaderManager;

    // Create the first pipeline to render on one FBO
    Pipeline pipeline;
    pipeline.attach(shaderManager.shader("../Shaders/shader.vert", GL_VERTEX_SHADER));
    pipeline.attach(shaderManager.shader("../Shaders/shader.frag", GL_FRAGMENT_SHADER));
    pipeline.create();

    // Enable alpha blending to render image
    PipelineState pipelineState;
    pipelineState.blendingState.blendingEnable = true;
    pipelineState.blendingState.destFactor = GL_ONE_MINUS_SRC_ALPHA;
    pipelineState.blendingState.srcFactor = GL_SRC_ALPHA;

    // Final pipeline to render the texture's fbo on the screen
    Pipeline final;
    final.attach(shaderManager.shader("../Shaders/final.vert", GL_VERTEX_SHADER));
    final.attach(shaderManager.shader("../Shaders/final.frag", GL_FRAGMENT_SHADER));
    final.create();

    PipelineState finalState;

    TextureManager textureManager;

    GLsampler2D texture = textureManager.image2D("../Images/img2.png");

    MappableBuffer materialsBuffer(sizeof(Materials), true, false);

    glClearColor(1, 1, 1, 1);

    FrameBuffer fbo;

    fbo.addColorRenderTarget(Texture::texture2D(1024, 1024, GL_RGB8));

    while(device.isRunning()) {
        device.update();

        // This part is to render material into a fbo
        *materialsBuffer.map<Materials>() = Materials{texture, fbo.handleColor(0)};
        pipelineState.viewPortState.width = 1024;
        pipelineState.viewPortState.height = 1024;
        pipeline.setPipelineState(pipelineState);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);
        glClear(GL_COLOR_BUFFER_BIT);
        pipeline.bind();
        glBindVertexArray(vao);
        glBindBufferRange(GL_UNIFORM_BUFFER, 0, materialsBuffer,
                          materialsBuffer.currentOffset(), materialsBuffer.size());
        materialsBuffer.flush(); // Ensure date were wrote just before draw
        glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

        materialsBuffer.roundRobin(); // go to another buffer part

        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

        // Here we render the fbo's texture to the screen
        glClear(GL_COLOR_BUFFER_BIT);
        finalState.viewPortState.width = device.width();
        finalState.viewPortState.height = device.height();
        final.setPipelineState(finalState);
        final.bind();
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

        device.swapBuffers();
    }

    return 0;
}
