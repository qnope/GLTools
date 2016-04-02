#version 450 core
#extension GL_ARB_bindless_texture : require

layout(location = 0) in vec2 uv;
layout(location = 0) out vec4 color;

layout(binding = 0) uniform Materials {
    sampler2D diffuse[2];
};

void main() {
    color = texture(diffuse[1], uv);
}

