#include <QApplication>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QVector3D>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();

        QVector3D vertices[] = {
            QVector3D(00.0f, 0.2f, 00.0f),
            QVector3D(-0.2f, -0.2f, 00.0f),
            QVector3D(0.2f, -0.2f, 00.0f)};

        vertexBuffer.create();
        vertexBuffer.bind();
        vertexBuffer.allocate(vertices, sizeof(vertices));

        shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex,"#version 120\n""attribute vec3 aPos;\n""void main()\n""{\n""gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n""}\n");
        shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, "#version 120\n""void main()\n""{\n""gl_FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n""}\n");
        shaderProgram.link();
    }

    void paintGL() override {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer vertexBuffer;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("3D_Engine");
    mainWindow.setFixedSize(1300, 700);

    OpenGLWidget *glWidget = new OpenGLWidget(&mainWindow);
    glWidget->setFixedSize(500, 500);

    QWidget *uiWidget = new QWidget(&mainWindow);
    uiWidget->setFixedSize(100, 100);
    uiWidget->setStyleSheet("background-color: blue;");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(glWidget);
    layout->addWidget(uiWidget);

    QWidget *centralWidget = new QWidget(&mainWindow);
    centralWidget->setLayout(layout);
    centralWidget->setStyleSheet("background-color: red;");

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.show();

    return (app.exec());
}