#version 450 core

#extension GL_ARB_shader_draw_parameters : enable

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec2 inUv;

layout(location = 0) out vec2 uv;
layout(location = 1) out flat int id;

void main() {
    gl_Position = vec4(inPos, 0, 1);
    id = gl_DrawIDARB;
    uv = inUv;
}

