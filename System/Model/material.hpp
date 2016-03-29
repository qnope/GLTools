#pragma once

#include <assimp/material.h>
#include "System/GL/Texture/texturemanager.hpp"

struct Material {
    Material(aiMaterial *mtl, TextureManager &textureManager, std::string const &globalPath);

    GLsampler2D handle;
};
