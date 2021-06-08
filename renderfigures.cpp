#include "renderfigures.h"

#include <QDebug>
renderFigures::renderFigures(const char* vertexPath, const char* fragmentPath)
    : programaShader(vertexPath, fragmentPath)
{
    initializeOpenGLFunctions();

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBOline);
    glGenVertexArrays(1,&VAOline);

    //leerTriangulo();
    configurarBuffers();
}

void renderFigures::leerTriangulo()
{
    QVector<float> verticesTriangulos{-0.5f, -0.5f, 0.0f,
                                       0.5f, -0.5f, 0.0f,
                                       0.0f,  0.5f, 0.0f };


}

void renderFigures::configurarBuffers()
{
    /*float vertic[] = {
        -0.5f, -0.5f, 0.0f,
         1.0f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };*/

    Linea objeto(-0.5, 0.5, 0.5, -0.5);

    //qDebug() << "float sizeof = " << sizeof(vertic);
    //qDebug() << "float const void* = " << vertic ;

//    float vertic[9];

//    for(int i = 0; i < 9; i++){
//        float dato = objeto.getCoordenadas(i);
//        vertic[i] = dato;
//    }
    std::vector<float> vertic {objeto.getVectorPosicion()};

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertic), vertic.data(), GL_STATIC_DRAW);

    //POSITION ATRIBUTE

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
        // note that this is allowed, the call to glVertexAttribPointer registered VBO
        //as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    //glBindVertexArray(0);

    //LINEA
    Linea myLinea(-0.5, -0.5, 0.5, 0.5);

    std::vector<float> verticesLineas {myLinea.getVectorPosicion(),};

    //glBindVertexArray(VAOline);
    glBindBuffer(GL_ARRAY_BUFFER, VBOline);
    glBufferData(GL_ARRAY_BUFFER, sizeof (verticesLineas), verticesLineas.data(), GL_STATIC_DRAW);
        //set vbo's data interpreted
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof (float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void renderFigures::useRender()
{
    programaShader.usar();

    //glBindVertexArray(VAOline);
    glBindVertexArray(VAO);


    glDrawArrays(GL_LINES, 0, 3);
}
