#include "widgettrazado.h"

#include "renderfigures.h"

widgetTrazado::widgetTrazado(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //initializeOpenGLFunctions(); //no corre aqui
}

widgetTrazado::~widgetTrazado()
{

}

void widgetTrazado::initializeGL()
{
    initializeOpenGLFunctions();

    myTriangle = new trianguloPrimitivo();
    renderizado = new renderFigures
            ("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/vertexShader.vs",
           "C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/fragmentShader.fs");

}

void widgetTrazado::resizeGL(int w, int h)
{
    int weidth, heigth;

    weidth = w;
    heigth = h;

}

void widgetTrazado::paintGL()
{
    renderizado->useRender();

    myTriangle->renderTriangulo();

}
