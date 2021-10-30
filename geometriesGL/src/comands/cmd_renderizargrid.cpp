#include "cmd_renderizargrid.h"

#include <QDebug>

cmd_renderizarGrid::cmd_renderizarGrid()
{

}

cmd_renderizarGrid::cmd_renderizarGrid(string nombreLinea)
{

}

cmd_renderizarGrid::cmd_renderizarGrid(Shader &shader, Texture& texture, glm::vec3 color)
{
    initializeOpenGLFunctions();

    this->shader_Renderiza_Grid = shader;
    this->texture_Renderiza_Grid = texture;
    this->colorGrid = color;
    //Inicializa la memoria para Grid
    initBuffers();
}

void cmd_renderizarGrid::setColorPoints(glm::vec3 color)
{
    this->colorGrid = color;
}

void cmd_renderizarGrid::initBuffers(){

    this->setVectorPointsGrid(this->Vertices);

    glGenVertexArrays(1, &gridVAO);

    glBindVertexArray(gridVAO);

    glGenBuffers(1, &gridVBO);

    glBindBuffer(GL_ARRAY_BUFFER, gridVBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void cmd_renderizarGrid::setVectorPointsGrid(std::vector<glm::vec2> &points){
    Vertices.clear();

    //Generate points in the plane XZ with distance of 1 unit
    float X = 0;
    float Y = 0;
    float Distance = 1;

    int N = 300;


    for (int j = 0; j <= N; j++) {
        for(int i = 0; i <=N; i++){
//            Punto coord;
//            coord.setX( X+(j*Distance) );
//            coord.setY( Y+(i*Distance) );
//            Vertices.push_back(coord);
            glm::vec2 puntito(X+(j*Distance), Y+(i*Distance));
            points.push_back(puntito);

        }
    }

    for(int i = 0; i <= (int)points.size()+1; i++){
        float x = points[i].x;
        float y = points[i].y;
//        qDebug() << i << "x:" << x << " y:" << y;
    }
}

void cmd_renderizarGrid::drawGrid(){
    shader_Renderiza_Grid.Use();

    // retrieve the matrix uniform locations
    this->shader_Renderiza_Grid.SetMatrix4("MVP", m_MVP);

    //Enviamos el color
    this->shader_Renderiza_Grid.SetVector3f("spriteColor", this->colorGrid);

    glBindVertexArray(gridVAO);
    glDrawArrays(GL_POINTS, 0, Vertices.size());
    glBindVertexArray(0);
}


glm::mat4 cmd_renderizarGrid::getMVP() const
{
    return m_MVP;
}

void cmd_renderizarGrid::setMVP(const glm::mat4 &MVP)
{
    m_MVP = MVP;
}
