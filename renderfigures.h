#ifndef RENDERFIGURES_H
#define RENDERFIGURES_H

#include <QObject>
#include <QGLWidget>
#include <QOpenGLExtraFunctions>

#include "externshader.h"
#include "triangulo.h"
#include "linea.h"

class renderFigures : public QWidget , protected QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    renderFigures();

    renderFigures(const char*, const char*);

    void generarVertexBuffers();

    void gengerarBuffers(GLsizei);

    void setBufferSize(int);

    int getBufferSize();

    void configurarBuffers();

    void setVectorLineas(Linea nuevaLinea);

    void useRender();

    ExternShader programaShader;

public slots:
    void recibirLinea();


private:
    const char* direccionVertex;
    const char* direccionFragment;

    std::vector<GLuint> vectorVAO;
    std::vector<GLuint> vectorVBO;

    GLsizei numeroLineas = 0;
    std::vector<Linea> vectorLineas;
};

#endif // RENDERFIGURES_H
