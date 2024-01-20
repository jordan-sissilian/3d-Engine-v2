#pragma once

#include "./Shader.hpp"
#include "./Transform.hpp"

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <vector>
#include <string_view>

constexpr const glm::vec3 v3Empty = {0.0f, 0.0f, 0.0f};

struct vertex {
    float x;
    float y;
    float z;

    float u;
    float v;
};

struct triangle {
    vertex tri[3];
};

struct Model3D {
    std::vector<triangle> mesh;

    char *name;
    Transform transform;

    std::vector<triangle> allVertices;

    uint vao;
    uint vboVertices;
    // GLuint ebo; // a faire

    GLuint shaderProgramID;

    Model3D(char *name, const aiMesh *Meshe, GLuint shaderProgramID);
    void Draw(const glm::mat4 &mModel);
    void SetupMesh();
};

class Object {
public:
    std::vector<Model3D *> models;

public:
    Transform transform;
    Shader shaderProgram;

public:
    Object(const char *path = "", const glm::vec3 &position = v3Empty, const float &rotation = 0.f, const float &scale = 1.f);
    ~Object() = default;

    void Draw() const;
};