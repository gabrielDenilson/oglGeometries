#ifndef WIDGETTRAZADO_H
#define WIDGETTRAZADO_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QObject>

#include "trianguloprimitivo.h"

#include "linea.h"
#include "renderfigures.h"

class widgetTrazado: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
protected:
    void initializeGL() ;
    void resizeGL(int w, int h) ;
    void paintGL() ;

    virtual void mousePressEvent(QMouseEvent *event);

public:
    widgetTrazado(QWidget *parent = 0);

    ~widgetTrazado();

    void generarVertexBuffers();

    void gengerarBuffers(GLsizei);

    void setBufferSize(int);

    int getBufferSize();

    void configurarBuffers();

    void setVectorLineas(Linea nuevaLinea);

    void useRender();

    void creacionFigura();


public slots:
    void nuevaLinea();

signals:
    void enviarLinea();

private:
//    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    Shader programaShader;

    int weidthWdg;
    int heigthWdg;

    const char* direccionVertex;
    const char* direccionFragment;

    std::vector<GLuint> vectorVAO;
    std::vector<GLuint> vectorVBO;

    GLsizei numeroLineas = 0;
    std::vector<Linea> vectorLineas;

};

#endif // WIDGETTRAZADO_H
