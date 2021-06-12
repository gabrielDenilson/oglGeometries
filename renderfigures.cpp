#include "renderfigures.h"

#include <QDebug>

//Inicializa el programa de renderizacion con Direccion de Shaders Nulo
renderFigures::renderFigures()
    //: programaShader(0, 0)
{
}

//Inicializa el programa de renderizacion con direccion de Shaders
renderFigures::renderFigures(const char* vertexPath, const char* fragmentPath)
    //: programaShader(vertexPath, fragmentPath)
{
    initializeOpenGLFunctions();

    configurarBuffers();
}

void renderFigures::generarVertexBuffers()
{
    GLuint nuevoVAO;
    glGenVertexArrays(1, &nuevoVAO);
    vectorVAO.push_back(nuevoVAO);
}

void renderFigures::gengerarBuffers(GLsizei numeroBuffers)
{
    for(int i = 0; i < (int)numeroBuffers; i++){

        GLuint nuevoVBO;

        glGenBuffers(numeroBuffers, &nuevoVBO);

        vectorVBO.push_back(nuevoVBO);
            //imprime asignacion de VBOs en el vector VBOvec
            qDebug() << "vbo " << i << vectorVBO[i];
    }
}

void renderFigures::setBufferSize(int)
{

}

int renderFigures::getBufferSize()
{
    return (int)vectorVBO.size();
}

void renderFigures::configurarBuffers()
{
    //Linea eso(-0.4, 0.4, 0.4, 0.4);
    //setVectorLineas(eso);

//    Linea objeto(-0.5, 0.5, 0.5, -0.5);
//    setVectorLineas(objeto);

    Linea myLinea(-0.5, -0.5, 0.5, 0.5);
    setVectorLineas(myLinea);
    recibirLinea();


    generarVertexBuffers(); //generamos memoria para el VAO en vector VAO

    glBindVertexArray(vectorVAO[0]);
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0,0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    //loop para copiar los Datos al buffer VBOvec
    for(int i = 0; i < (int)vectorVBO.size(); i++){
        glBindBuffer(GL_ARRAY_BUFFER, vectorVBO[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vectorLineas[i].getVectorPosicion()),
                vectorLineas[i].getVectorPosicion().data(), GL_STATIC_DRAW);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void renderFigures::setVectorLineas(Linea nuevaLinea)
{
    numeroLineas++;

    gengerarBuffers(numeroLineas);

    vectorLineas.push_back(nuevaLinea);
    qDebug()<< "numero de lineas : " << vectorLineas.size();
}

void renderFigures::useRender()
{
    programaShader.usar();

    glBindVertexArray(vectorVAO[0]);

    //looop para usar los VBOs
    for(int i = 0; i < (int)vectorVBO.size(); i++){
        glBindVertexBuffer(0, vectorVBO[i], 0, 3*sizeof (float));
        glDrawArrays(GL_LINES, 0, 3);
    }

    update();
}

void renderFigures::recibirLinea()
{
    qDebug() << "se recibio/creo la linea" ;
    numeroLineas++;

    gengerarBuffers(numeroLineas);

    Linea linea(-0.3, -0.4, 0.4, 0.3);
    vectorLineas.push_back(linea);
    qDebug()<< "numero de lineas : " << vectorLineas.size();

    update();
}
