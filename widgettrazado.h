#ifndef WIDGETTRAZADO_H
#define WIDGETTRAZADO_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QObject>

#include "trianguloprimitivo.h"

#include "linea.h"
#include "punto.h"
#include "renderfigures.h"

class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
protected:
    void initializeGL() ;
    void resizeGL(int w, int h) ;
    void paintGL() ;

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

public:
    widgetTrazado(QWidget *parent = 0);

    ~widgetTrazado();

    void generarVertexBuffers();
    void gengerarBuffers(GLsizei numeroBuffers);

    void configurarBuffers();

    void actualizarVBOLineas();

    void setVectorLineas(Linea nuevaLinea);

    void renderLinea(Linea render, float x2, float y2);

    int getBufferSize();

    void useRender();

    void creacionFigura();

    Punto normalizarMousePress(QPoint posicion);


public slots:
    void nuevaLinea();

signals:
    void enviarLinea();

private:
//    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    ExternShader programaShader;

    int weidthWdg;
    int heigthWdg;

    const char* direccionVertex;
    const char* direccionFragment;

    std::vector<GLuint> vectorVAO;
    std::vector<GLuint> vectorVBO;

    GLsizei numeroLineas = 0;
    Punto mousePosicion;
    bool clickIzquierdoPress;
    std::vector<Linea> vectorLineas;

};

#endif // WIDGETTRAZADO_H
