#include "../Include/Transform.hpp"
#include "../Include/Window.hpp"

Transform::Transform(const glm::vec3 &Pos, const float &Rot, const float &Sca)
    : pos(Pos), rot(Rot), sca(Sca) { }

const glm::vec3 Transform::GetPosition() const
{
    return this->pos;
}

const float Transform::GetRotation() const
{
    return this->rot;
}

const float Transform::GetScale() const
{
    return (this->sca);
}

void Transform::SetPosition(const glm::vec3 &newPos)
{
    this->pos = newPos;
    glm::mat4 modelMatrix{1.0f};
    this->modelMatrix *= glm::translate(modelMatrix, this->pos);
}

void Transform::SetRotation(const float &newRot, const Axe &AxeDest)
{
    this->rot += newRot;
    glm::mat4 modelMatrix{1.0f};

    const std::map<Axe, std::pair<float, glm::vec3>> axisData = {
        {Axe::X, {this->rot, Axe_X}},
        {Axe::Y, {this->rot, Axe_Y}},
        {Axe::Z, {this->rot, Axe_Z}}
    };

    auto it = axisData.find(AxeDest);
    if (it != axisData.end()) {
        const auto &[AxeRotation, Axe] = it->second;
        this->modelMatrix *= glm::rotate(modelMatrix, glm::radians(AxeRotation), Axe);
    }
}

void Transform::SetScale(const float &newSca)
{
    this->sca = newSca;
    glm::mat4 modelMatrix{1.0f};
    this->modelMatrix *= glm::scale(modelMatrix, glm::vec3(this->sca));
}

const glm::mat4& Transform::getModelMatrix() const
{
    return this->modelMatrix;
}

void Transform::setModelMatrix(const glm::mat4 &model)
{
    this->modelMatrix = model;
}