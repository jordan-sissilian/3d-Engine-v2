#pragma once

#define GL_SILENCE_DEPRECATION

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

#include <map>

constexpr const glm::vec3 Axe_X = {1.0f, 0.0f, 0.0f};
constexpr const glm::vec3 Axe_Y = {0.0f, 1.0f, 0.0f};
constexpr const glm::vec3 Axe_Z = {0.0f, 0.0f, 1.0f};

enum class Axe : int {
    X = 1,
    Y = 0,
    Z = -1
};

class Transform {
private:
    glm::mat4 position{0.0f};
    glm::mat4 rotation{0.0f};
    float scale{1};

    glm::vec3 pos;
    float rot;
    float sca;

    glm::mat4 modelMatrix{1.0f};

public:
    GLint modelMatrixLocation;

public:
    Transform() = default;
    Transform(const glm::vec3 &Pos, const float &Rot, const float &Sca);

    const glm::vec3 GetPosition() const;
    const float GetRotation() const;
    const float GetScale() const;
    void SetPosition(const glm::vec3 &newPos);
    void SetRotation(const float &angleRot, const Axe &AxeDest);
    void SetScale(const float &newSca);

    const glm::mat4 &getModelMatrix() const;
    void setModelMatrix(const glm::mat4 &model);
};

