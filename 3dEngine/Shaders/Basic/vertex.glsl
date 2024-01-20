#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 matrixView;
uniform mat4 matrixProjection;

void main()
{
    gl_Position = matrixProjection * matrixView * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}

