#ifndef WIDGETTRAZADO_H
#define WIDGETTRAZADO_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QObject>

#include "trianguloprimitivo.h"

#include "linea.h"
#include "punto.h"
#include "renderfigures.h"
#include "geometriesGL/src/comands/geometry.h"

class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
protected:
    void initializeGL() ;
    void resizeGL(int w, int h) ;
    void paintGL() ;
    ~widgetTrazado();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

public:
    widgetTrazado(QWidget *parent = 0);

    Punto normalizarMousePress(QPoint posicion);

public slots:
    void nuevaLinea();

signals:
    void enviarLinea();

private:
    int weidthWdg; //ancho de Widget
    int heigthWdg; //ancho de Widget Opengl
    Punto mousePosicion;
    bool clickIzquierdoPress;

    //!Creacion de un Componente Geometrico: Revisar patron AbstractFactory
    Geometry *geometryTreeCompound;

};

#endif // WIDGETTRAZADO_H
