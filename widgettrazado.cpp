#include "widgettrazado.h"

#include "renderfigures.h"

#include <QMouseEvent>
#include <QDebug>

widgetTrazado::widgetTrazado(QWidget *parent)
    : QOpenGLWidget(parent),
      weidthWdg(0),
      heigthWdg(0)
{
    this->setMouseTracking(true);
    clickIzquierdoPress = false;
//    Linea prueba {-1, -1, 1, 1};
//    vectorLineas.push_back(prueba);
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

int widgetTrazado::getBufferSize()
{
    return (int)vectorVBO.size();
}

void widgetTrazado::configurarBuffers()
{
    generarVertexBuffers(); //generamos memoria para el VAO en vector VAO
    glBindVertexArray(vectorVAO[0]);

    gengerarBuffers(1);

    glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Linea) * 90, nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof (float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

//------------Actualiza el buffer de lineas ---------------
void widgetTrazado::actualizarVBOLineas()
{
    glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[0]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vectorLineas.size() * sizeof (Linea), &vectorLineas[0]);

    update();
//    qDebug()<< "Se agrego una linea : " << vectorLineas.size();
}

//------------ Envia una nueva linea al vector <Linea> ----------
void widgetTrazado::setVectorLineas(Linea nuevaLinea)
{
    vectorLineas.push_back(nuevaLinea);
}

void widgetTrazado::renderLinea(Linea render, float x2, float y2)
{
    render.setX2(x2);
    render.setY2(y2);
    vectorLineas.back() = render;

}

//-------------- No definido ------------------------
void widgetTrazado::useRender()
{
}

//-------------- No definido ------------------------
void widgetTrazado::creacionFigura()
{
}

Punto widgetTrazado::normalizarMousePress(QPoint posicion)
{
    Punto normalizedPosicion;
    float x,y;

    x = -1.0 + 2.0 * (float)posicion.x() / weidthWdg;
    normalizedPosicion.setX(x);

    y = 1.0 - 2.0 * (float)posicion.y() / heigthWdg;
    normalizedPosicion.setY(y);

    return normalizedPosicion;
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
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vectorVAO[0]);


    programaShader.usar();
    glDrawArrays(GL_LINES, 0, 1000);

    programaShader.release();

}

// -------------- MOUSE PRUEBA ---------------
int mouseContador = 0;
float ultimaPosX;
float ultimaPosY;
Linea paraAgregar;
//--------------------------------------------
void widgetTrazado::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        ultimaPosX = mousePosicion.getX();
        ultimaPosY = mousePosicion.getY();
        mouseContador++;
    }


    if(event->button()==0x00000001 && mouseContador == 1){
//        paraAgregar.setX1(mousePosicion.getX());
//        paraAgregar.setY1(mousePosicion.getY());
                paraAgregar.setX1(ultimaPosX);
                paraAgregar.setY1(ultimaPosY);
        paraAgregar.setX2(ultimaPosX);
        paraAgregar.setY2(ultimaPosY);

        setVectorLineas(paraAgregar);
        actualizarVBOLineas();

    } else if(mouseContador == 2){
        paraAgregar.setX2(ultimaPosX);
        paraAgregar.setY2(ultimaPosY);
        actualizarVBOLineas();
        mouseContador = 0;

    }
}

//-------------- MOVIMIENTO DE MOUSE -----------------
void widgetTrazado::mouseMoveEvent(QMouseEvent *event)
{
    mousePosicion = normalizarMousePress(event->pos());

    if(mouseContador ==1){
        renderLinea(paraAgregar, mousePosicion.getX(), mousePosicion.getY());
        actualizarVBOLineas();

    }
}

//----------------------SLOTS-----------------------
void widgetTrazado::nuevaLinea()
{
    //Linea de prueba
    Linea esto = {-1, 1, 1, -1};
    setVectorLineas(esto);
    actualizarVBOLineas();
}
