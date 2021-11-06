#include "drawableobject_cuadrado.h"

DrawableObject_Cuadrado::DrawableObject_Cuadrado():
    Color    (1.0f),
    shaderProgram(),
    Sprite   (),
    model (glm::mat4(1.0))
{
    lineaA = new cmd_renderizarLineas();
    lineaB = new cmd_renderizarLineas();
    lineaC = new cmd_renderizarLineas();
    lineaD = new cmd_renderizarLineas();
    this->transformation = false;
}

DrawableObject_Cuadrado::DrawableObject_Cuadrado(Shader &shaderProgram, Texture &texture, glm::vec3 color) {
    this->shaderProgram = shaderProgram;
    this->Sprite = texture;
    this->Color = color;
    this->transformation = false;
    this->lineaA = new cmd_renderizarLineas(this->shaderProgram, this->Sprite, this->Color);
    this->lineaB = new cmd_renderizarLineas(this->shaderProgram, this->Sprite, this->Color);
    this->lineaC = new cmd_renderizarLineas(this->shaderProgram, this->Sprite, this->Color);
    this->lineaD = new cmd_renderizarLineas(this->shaderProgram, this->Sprite, this->Color);
}

DrawableObject_Cuadrado::~DrawableObject_Cuadrado()
{

}

void DrawableObject_Cuadrado::draw_Componente_Geometry()
{
    lineaA->drawLinea();
    lineaB->drawLinea();
    lineaC->drawLinea();
    lineaD->drawLinea();
}

void DrawableObject_Cuadrado::setShader(const Shader &shaderCompound)
{
    lineaA->setShaderProgram(shaderCompound);
    lineaB->setShaderProgram(shaderCompound);
    lineaC->setShaderProgram(shaderCompound);
    lineaD->setShaderProgram(shaderCompound);
}

void DrawableObject_Cuadrado::setTexture(Texture *textureCompound)
{
    lineaA->setTextureProgram(textureCompound);
    lineaB->setTextureProgram(textureCompound);
    lineaC->setTextureProgram(textureCompound);
    lineaD->setTextureProgram(textureCompound);
}

void DrawableObject_Cuadrado::setCamera(Camera2D *viewMatrix)
{
    this->setMVP(viewMatrix->getViewProjectionMatrix());
}

void DrawableObject_Cuadrado::setColor(glm::vec3 color)
{
    this->Color = color;
    lineaA->setColorLinea(Color);
    lineaB->setColorLinea(Color);
    lineaC->setColorLinea(Color);
    lineaD->setColorLinea(Color);
}

void DrawableObject_Cuadrado::setThick(float thick)
{
    lineaA->setThick(thick);
}

void DrawableObject_Cuadrado::setColorThick(glm::vec3 color)
{

    lineaA->setColorThick(color);
}

void DrawableObject_Cuadrado::setPuntoA(Punto *puntoA, QWidget *parent)
{
    A = puntoA;
        //set LineaA and LineaB with the new point
        lineaA->setPuntoInicial(A, parent);
        lineaB->setPuntoInicial(A, parent);
}

void DrawableObject_Cuadrado::setPuntoB(Punto *puntoB, QWidget *parent)
{
    B = puntoB;
       //set LineaA and LineaB with the new point
       lineaA->setPuntoFinal(B, parent);
       lineaD->setPuntoFinal(B, parent);
}

void DrawableObject_Cuadrado::setPuntoC(Punto *puntoC, QWidget *parent)
{
    C = puntoC;
    //set LineaC and LineaD with the new point
    lineaC->setPuntoInicial(C, parent);
    lineaD->setPuntoInicial(C, parent);
}

void DrawableObject_Cuadrado::setPuntoD(Punto *puntoD, QWidget *parent)
{
    D = puntoD;
    //set LineaC and LineaD with the new point
    lineaC->setPuntoFinal(D, parent);
    lineaB->setPuntoFinal(D, parent);
}

Punto *DrawableObject_Cuadrado::getPuntoA()
{
    return A;
}

Punto *DrawableObject_Cuadrado::getPuntoB()
{
    return B;
}

Punto *DrawableObject_Cuadrado::getPuntoC()
{
    return C;
}

Punto *DrawableObject_Cuadrado::getPuntoD()
{
    return D;
}


glm::mat4 DrawableObject_Cuadrado::getMVP() const
{
    lineaA->getMVP();
    lineaB->getMVP();
    lineaC->getMVP();
    lineaD->getMVP();
}

void DrawableObject_Cuadrado::setMVP(const glm::mat4 &MVP)
{
    lineaA->setMVP(MVP);
    lineaB->setMVP(MVP);
    lineaC->setMVP(MVP);
    lineaD->setMVP(MVP);
}
