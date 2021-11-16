#include "cmd_renderizarpunto.h"

#include <QDebug>

cmd_renderizarPunto::cmd_renderizarPunto() :  puntoCords(0.0 , 0.0f),
                                              colorPunto(glm::vec3()),
                                              colorThick(glm::vec3(0.0, 0.0, 0.0)),
                                              thick(1.0)
{
    initializeOpenGLFunctions();
    this->nombreCmd = "renderLine";
    //Shader and  Texture is not initialized... will be in the teclaration de ParentCompound
    //Inicializa la memoria para una linea
    initBuffers();
    initOtherBuffers();

}

void cmd_renderizarPunto::setShaderProgram(const Shader &newShader)
{
    this->shader_Renderiza_Punto = newShader;
}

void cmd_renderizarPunto::setTextureProgram(Texture *newTexture)
{
    this->texture_Renderiza_Punto = newTexture;
}

void cmd_renderizarPunto::setColorLinea(glm::vec3 color)
{
    this->colorPunto = color;
}

void cmd_renderizarPunto::setPunto(Punto nuevoPunto)
{
    this->puntoCords = nuevoPunto;
}

void cmd_renderizarPunto::initBuffers()
{
    glGenVertexArrays(1, &this->PuntoVAO);

    glBindVertexArray(PuntoVAO);
        glGenBuffers(1, &PuntoVBO);
        glBindBuffer(GL_ARRAY_BUFFER, PuntoVBO);

            glBufferData(GL_ARRAY_BUFFER, sizeof(Punto), nullptr, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof (float), (void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void cmd_renderizarPunto::initOtherBuffers()
{
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, &this->thickVAO);
        glGenBuffers(1, &this->thickVBO);
        glGenBuffers(1, &this->thickEBO);

      glBindVertexArray(this->thickVAO);

        glBindBuffer(GL_ARRAY_BUFFER, this->thickVBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 10, nullptr, GL_DYNAMIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->thickEBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

      glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void cmd_renderizarPunto::drawPunto(QWidget *parent)
{

}

void cmd_renderizarPunto::drawOtherPunto(QWidget *parent)
{
    this->shader_Renderiza_Punto.Use();

    this->shader_Renderiza_Punto.SetMatrix4("MVP", m_MVP);
    //Enviamos el color
    this->shader_Renderiza_Punto.SetVector3f("spriteColor", colorThick);

    glBindVertexArray(this->thickVAO);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    parent->update();

    glDisable(GL_BLEND);

    glBindVertexArray(0);
    this->shader_Renderiza_Punto.release();
}

void cmd_renderizarPunto::actualizarVBOPunto(QWidget *parent)
{
    glBindBuffer(GL_ARRAY_BUFFER, this->thickVBO);
    //el tipo de memoria, offset = empieza en 0, tamaño de datos, datos
    glBufferSubData(GL_ARRAY_BUFFER, 0, verticesRectangle.size() * sizeof(float), verticesRectangle.data());
    parent->update();
}

void cmd_renderizarPunto::actualizarVBOThick(QWidget *parent)
{

}

void cmd_renderizarPunto::receiveDirectPostion(float x1, float y1, float x2, float y2)
{

}

void cmd_renderizarPunto::setPuntoPosition(Punto *puntoInicial, QWidget *parent)
{
    this->puntoCords = *puntoInicial;
    this->setGenerateCordsThick();
    this->actualizarVBOPunto(parent);
}

float cmd_renderizarPunto::getThick() const
{
    return this->thick;
}

void cmd_renderizarPunto::setThick(float value)
{
    this->thick = value;
}

void cmd_renderizarPunto::setGenerateCordsThick()
{
    float x = this->puntoCords.getX();
    float y = this->puntoCords.getY();
    float thicky = this->thick / 2;

    float xcoord;
    float ycoord;
    qDebug() << x <<" xpunto" << y << " ypunto   " << thick << " thickpunto";

    xcoord = x - this->thick; verticesRectangle.push_back(xcoord);
    ycoord = y + this->thick; verticesRectangle.push_back(ycoord);

    xcoord = x + this->thick; verticesRectangle.push_back(xcoord);
    ycoord = y + this->thick; verticesRectangle.push_back(ycoord);

    xcoord = x + this->thick; verticesRectangle.push_back(xcoord);
    ycoord = y - this->thick; verticesRectangle.push_back(ycoord);

    xcoord = x - this->thick; verticesRectangle.push_back(xcoord);
    ycoord = y - this->thick; verticesRectangle.push_back(ycoord);

    int taa = verticesRectangle.size();
    for(int i = 0 ; i < taa; i++){
        qDebug() << verticesRectangle.at(i);
    }
}

void cmd_renderizarPunto::setColorThick(glm::vec3 color)
{
    this->colorThick = color;
}

glm::mat4 cmd_renderizarPunto::getMVP() const
{
    return this->m_MVP;
}

void cmd_renderizarPunto::setMVP(const glm::mat4 &MVP)
{
    this->m_MVP = MVP;
}
