#pragma once

#include "./Transform.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <vector>
#include <string_view>

struct Mesh {
    std::vector<float> vertices;        // Coordonnées des sommets (par exemple, x, y, z, x, y, z, ...)
    std::vector<float> normals;         // Normales des sommets (par exemple, nx, ny, nz, nx, ny, nz, ...)
    std::vector<float> textureCoords;   // Coordonnées de texture des sommets (par exemple, u, v, u, v, ...)
    std::vector<unsigned int> indices;  // Indices des faces (par exemple, 0, 1, 2, 2, 3, 0, ...)
};

struct Texture {
    std::string_view filePath;
    int width{0};                       // Largeur de la texture
    int height{0};                      // Hauteur de la texture
    unsigned int textureID{0};          // Identifiant de la texture OpenGL
};

struct Material {
    glm::vec3 ambientColor;             // Couleur ambiante
    glm::vec3 diffuseColor;             // Couleur diffuse
    glm::vec3 specularColor;            // Couleur spéculaire
    float shininess{0.0f};              // Exposant de brillance
};

struct Model3D {
    Mesh mesh;
    Texture texture;
    Material material;

    Model3D() = default;
    Model3D(const Mesh &mesh, const Texture &texture, const Material &material);
};

class Object {
private:
    Model3D model;
    Transform transform;

public:
    Object(const Model3D &model, const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale);
    ~Object() = default;

    void InitializeFromAssimpMesh(const aiMesh *assimpMesh, const aiMaterial *assimpMaterial);

    void UpdateAnimation(float deltaTime);
    void Draw() const;
};
