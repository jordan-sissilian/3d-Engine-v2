#pragma once

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include <iostream>
#include <stdexcept>

constexpr const char* nameGame = " ";
constexpr const uint32_t hauteurJeu = 768;
constexpr const uint32_t largeurJeu = 1366;

enum class OpenGLVersion : int {
    Major = 3,
    Minor = 3
};

class Window {
private:
    const char* name{nameGame};
    uint32_t height{hauteurJeu};
    uint32_t width{largeurJeu};

public:
    mutable GLFWwindow* window;

public:
    Window();
    Window(uint32_t height, uint32_t width);
    ~Window();

private:
    void initializeGLFW();
    void initializeWindow();
    void initializeGlad();
    void cleanup();

public:
    void createWindow() const;
    void configureWindow() const;
    void swapBuffers() const;
    void pollEvents() const;
};
