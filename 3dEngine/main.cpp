#include "./include/Core/Window.hpp"

#include <soil2/SOIL2.h>
#include <random>

int main(void)
{
    Window window = Window();

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window.window)) {
        if (glfwGetKey(window.window, GLFW_KEY_SPACE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window.window, true);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }
    return (0);
}
