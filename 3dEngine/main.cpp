
#include "./Include/Window.hpp"
#include "./Include/Camera.hpp"
#include "./Include/Objet.hpp"

#include <iostream>
#include <vector>

int main(void)
{
    Window window;
    Object obj{"./3dEngine/Res/map/Sol.obj"};
    Camera *mcamera = new Camera(&obj.shaderProgram);

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window.window)) {
        if (glfwGetKey(window.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window.window, true);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        mcamera->control(&window);

        obj.Draw();

        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    return 0;
}