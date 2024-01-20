#pragma once

#include "./Shader.hpp"
#include "./Window.hpp"

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

class Camera
{
public:
	Camera(Shader *shader);
	~Camera();

	void load();
	void mouseControl(Window *window);
	void control(Window *window);

private:
	Shader *mshader;

	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	GLuint matrixViewLocation;
	glm::mat4 matrixView = glm::mat4(1.f);

	GLuint matrixProjectionLocation;
	glm::mat4 matrixProjection = glm::mat4(1.f);

private:
	glm::vec3 direction;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 1366.0f / 2.0;
	float lastY = 768.0 / 2.0;
	float fov = 45.0f;
};

