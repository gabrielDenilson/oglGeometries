#include "widgettrazado.h"

#include "renderfigures.h"

#include <QMouseEvent>
#include <QDebug>

widgetTrazado::widgetTrazado(QWidget *parent)
    : QOpenGLWidget(parent),
      weidthWdg(0),
      heigthWdg(0)
{
}

widgetTrazado::~widgetTrazado()
{
}

void widgetTrazado::generarVertexBuffers()
{
    GLuint nuevoVAO;
    glGenVertexArrays(1, &nuevoVAO);
    vectorVAO.push_back(nuevoVAO);
}

void widgetTrazado::gengerarBuffers(GLsizei numeroBuffers)
{
    for(int i = 0; i < (int)numeroBuffers; i++){

        GLuint nuevoVBO;

        glGenBuffers(numeroBuffers, &nuevoVBO);

        vectorVBO.push_back(nuevoVBO);
            //imprime asignacion de VBOs en el vector VBOvec
            qDebug() << "vbo " << i << vectorVBO[i];
    }
}

void widgetTrazado::setBufferSize(int)
{

}

int widgetTrazado::getBufferSize()
{
    return (int)vectorVBO.size();
}

void widgetTrazado::configurarBuffers()
{
//    Linea eso = {-0.5,0.5,0.0,0.0};
//    vectorLineas.push_back(eso);
//    Linea aquello = {0.5,0.5,0.5,-0.5};
//    vectorLineas.push_back(aquello);

    generarVertexBuffers(); //generamos memoria para el VAO en vector VAO
    glBindVertexArray(vectorVAO[0]);

    gengerarBuffers(1);
//    glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[0]);
//    glBufferData(GL_ARRAY_BUFFER,vectorLineas.size() * sizeof(Linea), &vectorLineas[0], GL_DYNAMIC_DRAW);

//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof (float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Linea) * 10, nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof (float), (void*)0);

    qDebug() <<"tamaño de linea: " << sizeof(Linea);
    qDebug() <<"tamaño de vector linea: "<<vectorLineas.size() * sizeof(Linea);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void widgetTrazado::setVectorLineas(Linea nuevaLinea)
{
    numeroLineas++;

    vectorLineas.push_back(nuevaLinea);
    qDebug()<< "numero de lineas : " << vectorLineas.size();
}

void widgetTrazado::useRender()
{

}

void widgetTrazado::creacionFigura()
{
}


void widgetTrazado::initializeGL()
{
    initializeOpenGLFunctions();
    configurarBuffers();
    programaShader.setVertexDireccion("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/vertexShader.vs");
    programaShader.setFragmentDireccion("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/fragmentShader.fs");
    programaShader.configurarShaders();

}

void widgetTrazado::resizeGL(int w, int h)
{
    weidthWdg = w;
    heigthWdg = h;

}

void widgetTrazado::paintGL()
{
    Linea esto = {0.9,0.3,0.2,0.2};
    vectorLineas.push_back(esto);
    Linea aquello = {-0.9,-0.3,0.2,-0.2};
    vectorLineas.push_back(aquello);
    float doslineas[] = {-0.5, -0.5,
                          0.0,  0.0,
                          0.5,  0.5,
                          0.5, -0.5,
                          0.0,  0.8,
                          0.8,  0.8 };

    glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[0]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vectorLineas.size() * sizeof (Linea), &vectorLineas[0]);

    glBindVertexArray(vectorVAO[0]);


    programaShader.usar();
    glDrawArrays(GL_LINES, 0, 6);

    programaShader.release();

}

void widgetTrazado::mousePressEvent(QMouseEvent *event)
{
    float normalizedX = -1.0 + 2.0 * (float)event->x() / weidthWdg;
    float normalizedY = 1.0 - 2.0 * (float)event->y() / heigthWdg;
    if(event->button() == Qt::LeftButton){
        qDebug() << normalizedX;
        qDebug() << normalizedY;

    }
}

//SLOTS
void widgetTrazado::nuevaLinea()
{
    qDebug() << "Nueva linea se ha dibujado";
}
