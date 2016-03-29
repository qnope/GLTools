#version 450 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec2 inUv;

layout(location = 0) out vec2 uv;

void main() {
    gl_Position = vec4(inPos, 0, 1);
    uv = inUv;
}
