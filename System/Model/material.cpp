#include "material.hpp"

Material::Material(aiMaterial *mtl, TextureManager &textureManager,
                   const std::string &globalPath) {
    aiString texPath;
    if(mtl->GetTexture(aiTextureType_DIFFUSE, 0, &texPath) == AI_SUCCESS) {
        std::string path = texPath.C_Str();

        if(path[0] == '.')
            path.erase(0, 1);

        if(path[0] == '/' || path[0] == '\\')
            path.erase(0, 1);

        for(auto &v : path)
            if(v == '\\')
                v = '/';
        path = globalPath + path;
        handle = textureManager.image2D(path);
    }
}
