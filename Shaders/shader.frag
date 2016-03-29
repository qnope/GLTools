#version 450 core
#extension GL_ARB_texture_query_lod : enable
#extension GL_ARB_bindless_texture : require

layout(binding = 0) uniform Materials {
    sampler2D diffuse[2];
};

layout(location = 0) in vec2 uv;
layout(location = 1) in flat int id;

layout(location = 0) out vec4 outColor;

void main() {
    vec2 uvFlipped = vec2(uv.x, 1 - uv.y);
    outColor = textureLod(diffuse[id], uvFlipped, textureQueryLOD(diffuse[id], uvFlipped).x);
}
