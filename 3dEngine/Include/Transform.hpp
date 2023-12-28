#pragma once

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"

constexpr const glm::vec3 Axe_X = {1.0f, 0.0f, 0.0f};
constexpr const glm::vec3 Axe_Y = {0.0f, 1.0f, 0.0f};
constexpr const glm::vec3 Axe_Z = {0.0f, 0.0f, 1.0f};

class Transform {
private:
    glm::vec3 position{0};
    glm::vec3 rotation{0};
    glm::vec3 scale{1};

    glm::mat4 modelMatrix{1.0f};
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

public:
    Transform() = default;
    Transform(const glm::vec3 &Pos, const glm::vec3 &Rot, const glm::vec3 &Sca);

    glm::vec3 GetPosition() const;
    glm::vec3 GetRotation() const;
    glm::vec3 GetScale() const;
    inline void SetPosition(const glm::vec3 &newPos);
    inline void SetRotation(const glm::vec3 &newRot);
    inline void SetScale(const glm::vec3 &newSca);

    const glm::mat4& getModelMatrix() const;
    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;

    void updateModelMatrix();
    void setViewMatrix(const glm::mat4 &view);
    void setProjectionMatrix(const glm::mat4 &projection);
};