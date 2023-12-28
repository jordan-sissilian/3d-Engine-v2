
#include "../Include/Transform.hpp"

Transform::Transform(const glm::vec3 &Pos, const glm::vec3 &Rot, const glm::vec3 &Sca)
    : position(Pos), rotation(Rot), scale(Sca) {
    this->modelMatrix = glm::translate(this->modelMatrix, this->position);
    this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(this->rotation.x), Axe_X);
    this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(this->rotation.y), Axe_Y);
    this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(this->rotation.z), Axe_Z);
    this->modelMatrix = glm::scale(this->modelMatrix, this->scale);
}

glm::vec3 Transform::GetPosition() const
{
    return (this->position);
}

glm::vec3 Transform::GetRotation() const
{
    return (this->rotation);
}

glm::vec3 Transform::GetScale() const
{
    return (this->scale);
}

void Transform::SetPosition(const glm::vec3 &newPos)
{
    this->position = newPos;
    this->updateModelMatrix();
}

void Transform::SetRotation(const glm::vec3 &newRot)
{
    this->rotation = newRot;
    this->updateModelMatrix();
}

void Transform::SetScale(const glm::vec3 &newSca)
{
    this->scale = newSca;
    this->updateModelMatrix();
}

const glm::mat4& Transform::getModelMatrix() const
{
    return (this->modelMatrix);
}

const glm::mat4& Transform::getViewMatrix() const
{
    return (this->viewMatrix);
}

const glm::mat4& Transform::getProjectionMatrix() const
{
    return (this->projectionMatrix);
}

void Transform::setViewMatrix(const glm::mat4 &view)
{
    this->viewMatrix = view;
}

void Transform::setProjectionMatrix(const glm::mat4 &projection)
{
    this->projectionMatrix = projection;
}
