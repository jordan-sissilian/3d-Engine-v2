#include "../Include/Objet.hpp"

#include <iostream>

void Model3D::Draw(const glm::mat4 &model)
{
    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->vboVertices);

    glUseProgram(this->shaderProgramID);
    glUniformMatrix4fv(this->transform.modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model * this->transform.getModelMatrix()));

    glDrawArrays(GL_TRIANGLES, 0, this->mesh.size() * 3);
}

void Model3D::SetupMesh()
{
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, this->vboVertices);
    glBufferData(GL_ARRAY_BUFFER, this->mesh.size() * sizeof(triangle), this->mesh.data(), GL_STATIC_DRAW); //&mesh[0]
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)offsetof(vertex, u));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    this->transform.modelMatrixLocation = glGetUniformLocation(this->shaderProgramID, "model");
}

Model3D::Model3D(char *name, const aiMesh *Meshe, GLuint shaderProgramID)
    : name(name), shaderProgramID(shaderProgramID)
{
    if (Meshe) {
        for (unsigned int j = 0; j < Meshe->mNumFaces; j++) {
            const aiFace face = Meshe->mFaces[j];
            triangle newMesh;

            for (unsigned int k = 0; k < face.mNumIndices; k++) {
                aiVector3D vertex = Meshe->mVertices[face.mIndices[k]];
                struct vertex newVertex;
                newVertex.x = vertex.x;
                newVertex.y = vertex.y;
                newVertex.z = vertex.z;
                newMesh.tri[k] = newVertex;
            }
            this->mesh.push_back(newMesh);
        }
    }
    this->SetupMesh();
}

Object::Object(const char *path, const glm::vec3 &position, const float &rotation, const float &scale)
    : transform(position, rotation, scale)
{
    this->shaderProgram.loadVertexShader("./3dEngine/Shaders/Basic/vertex.glsl");
    this->shaderProgram.loadFragmentShader("./3dEngine/Shaders/Basic/fragment.glsl");
    this->shaderProgram.link();

    this->transform.modelMatrixLocation = glGetUniformLocation(this->shaderProgram.getShaderProgram(), "model");

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, (aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices));

    for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
        const char *_name = scene->mMeshes[i]->mName.C_Str();
        Model3D *model = new Model3D{strcpy(new char[strlen(_name) + 1], _name), scene->mMeshes[i], this->shaderProgram.getShaderProgram()};
        this->models.push_back(model);
    }
}

void Object::Draw() const
{
    for (Model3D* model : this->models) {
       model->Draw(this->transform.getModelMatrix());
    }
}