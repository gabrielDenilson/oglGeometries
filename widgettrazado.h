#ifndef WIDGETTRAZADO_H
#define WIDGETTRAZADO_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>

#include "trianguloprimitivo.h"
#include "renderfigures.h"

class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
public:
    widgetTrazado(QWidget *parent = 0);
    ~widgetTrazado();

protected:
    void initializeGL() ;
    void resizeGL(int w, int h) ;
    void paintGL() ;

private:
    trianguloPrimitivo* myTriangle;
    renderFigures* renderizado;
};

#endif // WIDGETTRAZADO_H
