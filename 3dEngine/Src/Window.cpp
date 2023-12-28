
#include "../Include/Window.hpp"

Window::Window(uint32_t height, uint32_t width)
    : Window()
{
    this->height = height;
    this->width = width;
}

Window::Window()
    : height(hauteurJeu), width(largeurJeu), window(nullptr), name(nameGame)
{
    this->loadGLFW();
    this->loadGlad();
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Window::loadGLFW() const
{
    if (!glfwInit())
        throw std::runtime_error("Erreur : Glfw non chargé");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(OpenGLVersion::Major));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(OpenGLVersion::Minor));
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    if (!(this->window = glfwCreateWindow(this->width, this->height, this->name, nullptr, nullptr)))
        throw std::runtime_error("Erreur : Création de la fenêtre GLFW");

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(this->window);

    glfwSetFramebufferSizeCallback(this->window, framebufferSizeCallback);
}

void Window::loadGlad() const
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        throw std::runtime_error("Erreur : Chargement de Glad");
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}