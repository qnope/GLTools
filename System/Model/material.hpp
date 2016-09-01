#pragma once

#include <assimp/material.h>
#include "System/glm.hpp"
#include "System/GL/Texture/texturerepository.hpp"

struct Material {
    Material(aiMaterial *mtl, TextureRepository &textureManager, std::string const &globalPath);

    glm::vec3 color;
    GLsampler handle;
    bool useTexture;
};
