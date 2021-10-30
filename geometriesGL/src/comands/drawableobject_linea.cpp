#include "drawableobject_linea.h"

DrawableObject_Linea::DrawableObject_Linea():
    Color    (1.0f),
    shaderProgram(),
    Sprite   (),
    model (glm::mat4(1.0))
{

}

DrawableObject_Linea::DrawableObject_Linea(Shader &shaderProgram, Texture &textura, glm::vec3 color)
{
    renderable = new cmd_renderizarLineas(shaderProgram, textura, color);
    //Transformacion por defecto desactivada
    this->transformar= false;
    //Atributos de transformacion
}


DrawableObject_Linea::~DrawableObject_Linea()
{

}

void DrawableObject_Linea::draw_Componente_Geometry()
{
    renderable->drawOtherLinea();
    renderable->drawLinea();
}

void DrawableObject_Linea::transformarLinea(glm::vec2 position, glm::vec2 size, float rotation)
{

}

void DrawableObject_Linea::setColorLinea(glm::vec3 color)
{
    this->Color = color;
    renderable->setColorLinea(this->Color);
}

void DrawableObject_Linea::setThick(float thick)
{
    renderable->setThick(thick);
}

void DrawableObject_Linea::setColorThick(glm::vec3 color)
{
    renderable->setColorThick(color);
}

Punto DrawableObject_Linea::getPuntoInicial()
{
    //retorna el valor original de la Linea clase
    return renderable->lineaCords.getPosicionP1();
}

void DrawableObject_Linea::setPuntoInicial(Punto *puntoInicial, QWidget *parent)
{
    //set the valor of inicial point on CMD-lineas classs
    renderable->setPuntoInicial(puntoInicial, parent);

    renderable->setFirstPointThick(puntoInicial, parent);
}

Punto DrawableObject_Linea::getPuntoFinal()
{
    //retorna el valor original de la Linea clase
    return renderable->lineaCords.getPosicionP2();
}

void DrawableObject_Linea::setPuntoFinal(Punto *puntoFinal, QWidget *parent)
{
    //set the valor of inicial point on CMD-lineas classs
    renderable->setPuntoFinal(puntoFinal, parent);

    renderable->setLastPointThick(puntoFinal, parent);
}

void DrawableObject_Linea::drawLine()
{

}

void DrawableObject_Linea::setMVP(const glm::mat4 &MVP)
{
    renderable->setMVP(MVP);
}

glm::mat4 DrawableObject_Linea::getMVP(){
    return renderable->getMVP();
}
