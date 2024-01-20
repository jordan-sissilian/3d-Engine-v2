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
    try {
        this->initializeGLFW();
        this->initializeWindow();
        this->initializeGlad();
        glfwSwapInterval(1);
    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}

Window::~Window()
{
    this->cleanup();
}

static void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::initializeGLFW()
{
    if (!glfwInit())
        throw std::runtime_error("Erreur : GLFW n'a pas pu être initialisé.");
}

void Window::initializeWindow()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(OpenGLVersion::Major));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(OpenGLVersion::Minor));
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    this->window = glfwCreateWindow(this->width, this->height, this->name, nullptr, nullptr);
    if (!this->window)
        throw std::runtime_error("Error : GLFW.");

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, framebufferSizeCallback);
}

void Window::initializeGlad()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        throw std::runtime_error("Error : Glad.");
}

void Window::cleanup()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}
