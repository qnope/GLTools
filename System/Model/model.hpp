#pragma once

#include "material.hpp"
#include "mesh.hpp"

class Model
{
public:
    Model(std::string const &path, TextureManager &texManager);

private:
    std::vector<Material> mMaterials;
    std::vector<Mesh> mMeshes;
};
