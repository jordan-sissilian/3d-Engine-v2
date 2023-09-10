#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QApplication>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QPushButton>
#include <QOpenGLBuffer>
#include <QVector3D>

#include "./OpenGL/widgetOpenGL.hpp"
#include "./uiWidget.hpp"

class Window : public QMainWindow
{

public:
    Window(QWidget *parent = nullptr);
};

#endif