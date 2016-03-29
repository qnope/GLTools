#version 450 core

layout(location = 0) in vec2 uv;
layout(location = 0) out vec4 color;

layout(binding = 0) uniform sampler2D tex;

void main() {
    color = texture(tex, uv);
}

