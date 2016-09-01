#pragma once
#include <unordered_map>
#include "texture.hpp"

class TextureRepository
{
public:
    GLsampler image2D(std::string const &path);

private:
    std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;
};
