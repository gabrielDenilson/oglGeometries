#ifndef WIDGETTRAZADO_H
#define WIDGETTRAZADO_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QObject>
#include <QTime>

#include "trianguloprimitivo.h"

#include "linea.h"
#include "punto.h"
#include "renderfigures.h"
#include "geometriesGL/src/comands/geometry.h"
#include "geometriesGL/src/actions/camera2d.h"

class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    ~widgetTrazado();

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    virtual void wheelEvent(QWheelEvent *event) override;

    virtual void keyPressEvent(QKeyEvent *event) override;

public:
    widgetTrazado(QWidget *parent = 0);

    Punto normalizarMousePress(QPoint posicion);

    float getTime();

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

    Camera2D camera;
    float lastX ;
    float lastY ;
    bool firstMouse;
    // timing
    float deltaTime = 0.0f;	// time between current frame and last frame
    float lastFrame = 0.0f;
    QTime time;

};

#endif // WIDGETTRAZADO_H
