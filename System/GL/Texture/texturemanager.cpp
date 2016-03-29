#include "texturemanager.hpp"

GLsampler2D TextureManager::image2D(const std::string &path) {
    if(mTextures.find(path) == mTextures.end())
        mTextures.emplace(path, Texture::loadImage2D(path));
    return *mTextures[path];
}
