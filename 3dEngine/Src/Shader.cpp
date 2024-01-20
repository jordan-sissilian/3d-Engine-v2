#include "../Include/Shader.hpp"

#include <iostream>

Shader::Shader() {
    this->programID = glCreateProgram();
}

Shader::~Shader() {
    glDeleteProgram(this->programID);
}

const std::string Shader::readShaderFile(const std::filesystem::path& filePath) const {
    std::ifstream shaderFile(filePath);

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    return (shaderStream.str());
}


void Shader::loadVertexShader(const std::filesystem::path& vertexPath) {
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    this->vertexPath_ = vertexPath.string();
    static std::string vertexCode = readShaderFile(vertexPath);
    const char *sourceCode = vertexCode.c_str();
    glShaderSource(this->vertexShader, 1, &sourceCode, nullptr);
    glCompileShader(this->vertexShader);

    GLint success;
    glGetProgramiv(this->vertexShader, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog;
        glGetProgramInfoLog(this->vertexShader, 512, NULL, &infoLog);
        std::cout << "ERROR::SHADER_VERTEX::PROGRAM::LINKING_FAILED : " << infoLog << std::endl;
    }
}

void Shader::loadFragmentShader(const std::filesystem::path& fragmentPath) {
    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    this->fragmentPath_ = fragmentPath.string();
    static std::string fragmentCode = readShaderFile(fragmentPath);
    const char *sourceCode = fragmentCode.c_str();
    glShaderSource(this->fragmentShader, 1, &sourceCode, nullptr);
    glCompileShader(this->fragmentShader);

    GLint success;
    glGetProgramiv(this->fragmentShader, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog;
        glGetProgramInfoLog(this->fragmentShader, 512, NULL, &infoLog);
        std::cout << "ERROR::SHADER_FRAGMENT::PROGRAM::LINKING_FAILED : " << infoLog << std::endl;
    }
}

const void Shader::link() const {

    glAttachShader(this->programID, this->vertexShader);
    glAttachShader(this->programID, this->fragmentShader);
    glLinkProgram(this->programID);

    GLint success;
    glGetProgramiv(this->programID, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog;
        glGetProgramInfoLog(this->programID, 512, NULL, &infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED : " << infoLog << std::endl;
    }
}

const uint Shader::getShaderProgram() const {
    return (this->programID);
}
