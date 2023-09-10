#include "../../include/OpenGL/widgetOpenGL.hpp"

// Fonction d'initialisation OpenGL
void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    // Définition de données de sommets pour un triangle
    QVector3D vertices[] = {
        QVector3D(00.0f, 0.2f, 00.0f),
        QVector3D(-0.2f, -0.2f, 00.0f),
        QVector3D(0.2f, -0.2f, 00.0f)};

    // Création et allocation d'un tampon de sommets OpenGL
    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(vertices, sizeof(vertices));

    // Chargement et compilation des shaders OpenGL
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                          "#version 120\n"
                                          "attribute vec3 aPos;\n"
                                          "void main()\n"
                                          "{\n"
                                          "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                          "}\n");
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                          "#version 120\n"
                                          "void main()\n"
                                          "{\n"
                                          "gl_FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
                                          "}\n");
    shaderProgram.link();
}

// Fonction de rendu OpenGL
void OpenGLWidget::paintGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.bind();
    vertexBuffer.bind();

    int vertexLocation = shaderProgram.attributeLocation("aPos");
    shaderProgram.enableAttributeArray(vertexLocation);
    shaderProgram.setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    shaderProgram.disableAttributeArray(vertexLocation);

    vertexBuffer.release();
    shaderProgram.release();
}