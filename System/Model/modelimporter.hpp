#pragma once

#include "material.hpp"
#include "mesh.hpp"

class ModelImporter
{
public:
    ModelImporter(std::string const &path, TextureRepository &texManager);

private:
    std::vector<Material> mMaterials;
    std::vector<Mesh> mMeshes;
};
