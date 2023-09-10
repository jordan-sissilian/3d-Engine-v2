#include "../include/window.hpp"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("3D_Engine");
    setFixedSize(1300, 700);

    // Créez une instance de OpenGLWidget
    OpenGLWidget *glWidget = new OpenGLWidget(this);
    glWidget->setFixedSize(600, 600);

    // Créez une instance de UIWidget
    UIWidget *uiWidget = new UIWidget(this);
    uiWidget->setFixedSize(200, 500);

    // Créez une mise en page horizontale
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(uiWidget);
    layout->addWidget(glWidget);

    // Créez un widget central pour la fenêtre principale
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    // Définissez le widget central de la fenêtre principale
    setCentralWidget(centralWidget);
}
