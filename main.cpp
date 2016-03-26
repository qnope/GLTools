#include <GL/glew.h>
#include "System/GL/Buffer/staticbuffer.hpp"
#include "System/GL/Buffer/dynamicbuffer.hpp"
#include "System/device.hpp"
#include "System/GL/Pipeline/vao.hpp"
#include "System/GL/Pipeline/pipeline.hpp"
#include "System/GL/Pipeline/shadermanager.hpp"
#include "System/GL/Texture/texture.hpp"

struct Material {
    GLsampler2D diffuse;
};

int main(int argc, char *argv[])
{
    Device device(512, 512, "Graphic Engine", true);

    float vertices[] = {-1, -1,
                        -1, 1,
                        1, -1,
                        1, 1};

    float uv[] = {0, 0,
                  0, 1,
                  1, 0,
                  1, 1};

    GLuint index[] = {0, 1, 2, 3};

    StaticBuffer bufferVertices(sizeof vertices, vertices);
    StaticBuffer bufferUv(sizeof uv, uv);
    StaticBuffer bufferIndex(sizeof index, index);
    Vao vao;

    GLuint buffers[] = {bufferVertices, bufferUv};
    GLintptr offsets[] = {0, 0};
    GLsizei strides[] = {2 * sizeof(float), 2 * sizeof(float)};

    vao.enableArray(0);
    vao.enableArray(1);
    vao.attribBinding(0, 0);
    vao.attribBinding(1, 1);
    vao.bindElementBuffer(bufferIndex);
    vao.bindVertexBuffers(0, 2, buffers, offsets, strides);
    vao.format(0, 2, GL_FLOAT, false, 0);
    vao.format(1, 2, GL_FLOAT, false, 0);

    ShaderManager shaderManager;
    Pipeline pipeline;

    pipeline.attach(shaderManager.shader("../Shaders/shader.vert", GL_VERTEX_SHADER));
    pipeline.attach(shaderManager.shader("../Shaders/shader.frag", GL_FRAGMENT_SHADER));

    pipeline.create();

    PipelineState pipelineState;
    pipelineState.blendingState.blendingEnable = true;

    pipeline.setPipelineState(pipelineState);

    Texture texture(GL_TEXTURE_2D, "../Images/img2.png");

    DynamicBuffer materialsBuffer(sizeof(Material), false);

    glClearColor(1, 1, 1, 1);

    while(device.isRunning()) {
        device.update();

        *materialsBuffer.map<Material>() = Material{texture};

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        pipeline.bind();
        glBindVertexArray(vao);
        glBindBufferRange(GL_UNIFORM_BUFFER, 0, materialsBuffer,
                          materialsBuffer.currentOffset(), materialsBuffer.size());
        materialsBuffer.flush(); // Ensure date were wrote just before draw
        glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

        materialsBuffer.roundRobin(); // go to another buffer part

        device.swapBuffers();
    }

    return 0;
}
