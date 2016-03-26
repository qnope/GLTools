#pragma once
#include "shader.hpp"
#include <memory>
#include <unordered_map>
#include <tuple>

class ShaderManager {
public:
    GLuint shader(std::string const &path, GLenum type);
    
private:
    std::unordered_map<std::string, std::unique_ptr<Shader>> mShaders;
};

