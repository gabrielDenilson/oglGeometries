#ifndef TRIANGULOPRIMITIVO_H
#define TRIANGULOPRIMITIVO_H

#include <QOpenGLBuffer>
#include <QOpenGLExtraFunctions> //necesario para heredar las funciones de openGL
#include <QOpenGLVertexArrayObject>

class trianguloPrimitivo: public QOpenGLExtraFunctions
{
public:

    //coordenadas
    float coordEstaticas[9];

    QVector <float> coordDinamicas;

    //funciones
    trianguloPrimitivo();

    //Unimos las variables de memoria al programa
    void usoDeMemorias();

    //realizamos operaciones para calcular los vertices
    void calcularCoordenadas();

    //inicializamos los programas de vertices
    void inicializaShaderCodigo();

    void renderTriangulo();
private:
    unsigned int VAO, VBO, shaderProgram;

    unsigned int vertexShader, fragmentShader;

    const char* vertexCodigo;
    const char* fragmentCodigo;

};

#endif // TRIANGULOPRIMITIVO_H
