#ifndef RENDERFIGURES_H
#define RENDERFIGURES_H

#include <QOpenGLExtraFunctions>

#include "shader.h"
#include "triangulo.h"

class renderFigures : protected QOpenGLExtraFunctions
{
public:
    renderFigures(const char*, const char*);

    void leerTriangulo();

    void configurarBuffers();

    void useRender();

    Shader programaShader;

private:
    int dimension;

    //float vertices[];

    unsigned int VBO, VAO;

    const char* direccionVertex;
    const char* direccionFragment;
};

#endif // RENDERFIGURES_H
