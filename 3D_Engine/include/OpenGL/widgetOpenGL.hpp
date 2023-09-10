#ifndef WIDGETOPENGL_HPP
#define WIDGETOPENGL_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    OpenGLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {};

protected:
    // Fonction d'initialisation OpenGL
    void initializeGL() override;

    // Fonction de rendu OpenGLw
    void paintGL() override;

private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer vertexBuffer;
};

#endif
