#pragma once

#include "texture.hpp"
#include <unordered_map>

class TextureManager
{
public:
    GLsampler2D image2D(std::string const &path);

private:
    std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;
};
