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
#include "geometriesGL/src/actions/interactivefigure.h"


class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    virtual void wheelEvent(QWheelEvent *event) override;

    virtual void keyPressEvent(QKeyEvent *event) override;

public:
    widgetTrazado(QWidget *parent = 0);
    ~widgetTrazado();

    float getTime();

    void start_End_Draw_State(QMouseEvent *event, TIPO tipoDibujo); ///Suma y resta el conatadorMouse envia event a InteractiveFigure

public slots:
    void draw_object(bool, TIPO tipoDibujo);

signals:
    void enviarLinea();

private:
    int weidthWdg; //ancho de Widget
    int heigthWdg; //ancho de Widget Opengl
    Punto mousePosicion;

    //!Creacion de un Componente Geometrico: Revisar patron AbstractFactory
    InteractiveFigure *sceneGroup;

    bool signal_draw;// autoriza el dibujo de cualquier figura
    TIPO DRAW_STATE;
    Camera2D *camera;

    // timing
    float deltaTime = 0.0f;	// time between current frame and last frame
    float lastFrame = 0.0f;
    QTime time;

};

#endif // WIDGETTRAZADO_H
