#include "drawableobject_punto.h"
#include <QDebug>

DrawableObject_Punto::DrawableObject_Punto() :
      Color (0.0f)
    , shaderProgram()
    , Sprite()
    , model(glm::mat4(1.0))
{

    renderable = new cmd_renderizarPunto();
    renderable->setColorThick(glm::vec3(0.0f, 0.0f, 0.0f));

}

DrawableObject_Punto::~DrawableObject_Punto()
{

}

void DrawableObject_Punto::draw_Componente_Geometry(QWidget *parent)
{
    drawPunto(parent);

}

void DrawableObject_Punto::setShader(const Shader &shaderProgram)
{
    renderable->setShaderProgram(shaderProgram);
}

void DrawableObject_Punto::setTexture(Texture *textureProgram)
{
    renderable->setTextureProgram(textureProgram);
}

void DrawableObject_Punto::setCamera(Camera2D *viewMatrix)
{
    this->setMVP(viewMatrix->getVPmatrix());
}

vector<Punto> &DrawableObject_Punto::get_points_area()
{
    qDebug() << renderable->getPuntosArea().size() <<" HOLA000000000000000";

    return renderable->getPuntosArea();
}

void DrawableObject_Punto::setColorPunto(glm::vec3 color)
{
    renderable->setColorThick(color);
}

void DrawableObject_Punto::setStartPoint(Punto *firstPoint, Geometry *, QWidget *parent)
{
    renderable->setPuntoPosition(firstPoint, parent);
}

void DrawableObject_Punto::setEndPoint(Punto *, Geometry *, QWidget *)
{

}

void DrawableObject_Punto::setDirectPosition(float x, float y)
{
    renderable->receiveDirectPostion(x, y);
}

void DrawableObject_Punto::setThick(float thick)
{
    renderable->setThick(thick);
}

void DrawableObject_Punto::setColorThick(glm::vec3 color)
{
    renderable->setColorThick(color);
}

void DrawableObject_Punto::drawPunto(QWidget *parent)
{
    renderable->drawOtherPunto(parent);
}

void DrawableObject_Punto::setMVP(const glm::mat4 &MVP)
{
    renderable->setMVP(MVP);
}

glm::mat4 DrawableObject_Punto::getMVP()
{
    return renderable->getMVP();
}

