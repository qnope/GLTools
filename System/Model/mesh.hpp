#pragma once

#include <assimp/mesh.h>
#include <GL/glew.h>
#include "System/glm.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};

struct Mesh {
    Mesh(aiMesh const *mesh);

    unsigned materialIndex;
    unsigned numberVertex;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
};
