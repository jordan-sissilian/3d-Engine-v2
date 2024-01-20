#pragma once

#define GL_SILENCE_DEPRECATION

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"

#include <filesystem>
#include <string>
#include <stdexcept>

#include <fstream>
#include <sstream>


class Shader {
public:
    Shader();
    ~Shader();
    
    void loadFragmentShader(const std::filesystem::path& fragmentPath);
    void loadVertexShader(const std::filesystem::path& vertexPath);
    const void link() const;
    const uint getShaderProgram() const;

private:
    const std::string readShaderFile(const std::filesystem::path& filePath) const;

private:
    GLint vertexShader;
    GLint fragmentShader;
    std::string vertexPath_;
    std::string fragmentPath_;
    unsigned int programID;
};