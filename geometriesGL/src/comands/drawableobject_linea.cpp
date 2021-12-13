#include "drawableobject_linea.h"
//#include <Vec2.h>
#include <geometriesGL/res/Vec2.h>

#include <QDebug>

using namespace crushedpixel;

DrawableObject_Linea::DrawableObject_Linea():
    Color    (1.0f),
    shaderProgram(),
    Sprite   (),
    model (glm::mat4(1.0))
{
    renderable = new cmd_renderizarLineas();
    renderable->setColorLinea(COLORG::LIGHT_STEEL_BLUE);
    renderable->setColorThick(COLORG::LIGHT_STEEL_BLUE);
    //Transformacion por defecto desactivada
    this->transformar= false;
}

DrawableObject_Linea::DrawableObject_Linea(Shader &shaderProgram,
                                           Texture &textura,
                                           glm::vec3 color)
{
    renderable = new cmd_renderizarLineas(shaderProgram, textura, color);
    //Transformacion por defecto desactivada
    this->transformar= false;
    //Atributos de transformacion
}


DrawableObject_Linea::~DrawableObject_Linea()
{

}

void DrawableObject_Linea::draw_Componente_Geometry(QWidget *parent)
{
    renderable->drawOtherLinea(parent);
    renderable->drawLinea(parent);
}

void DrawableObject_Linea::setShader(const Shader &shaderProgram)
{
    //set the shader normally way
//    this->shaderProgram = shaderProgram;
    renderable->setShaderProgram(shaderProgram);
}

void DrawableObject_Linea::setTexture(Texture *textureProgram)
{
    //set the texture normally way
    renderable->setTextureProgram(textureProgram);
}

void DrawableObject_Linea::setCamera(Camera2D *viewMatrix)
{
    //For now only set camera's position with the projection view
    this->setMVP(viewMatrix->getVPmatrix());
}

Shader DrawableObject_Linea::getShader()
{
//    return renderable->getShaderProgram();
}

Camera2D DrawableObject_Linea::getCamera()
{
//    return cameraLinea;
}

void DrawableObject_Linea::setStartPoint(Punto *firstPoint, Geometry *, QWidget *parent)
{
    setPuntoInicial(firstPoint, parent);
}

void DrawableObject_Linea::setEndPoint(Punto *endPoint, Geometry *, QWidget *parent)
{
    setPuntoFinal(endPoint, parent);
}

void DrawableObject_Linea::setDirectPosition(float x1, float y1, float x2, float y2)
{
    this->renderable->receiveDirectPostion(x1, y1, x2, y2);
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

float roundX;


void DrawableObject_Linea::setPuntoInicial(Punto *puntoInicial, QWidget *parent)
{
    float roundX = puntoInicial->getX();
    float roundY = puntoInicial->getY();

    crushedpixel::Vec2 aux{roundX, roundY};
    roundPoint = crushedpixel::Vec2Maths::round(aux, 1);

    qDebug() << "RoundPoint  x:"<< roundPoint.x << " y: " << roundPoint.y ;

    Punto puntoNuevo{roundPoint.x, roundPoint.y};
    //set the valor of inicial point on CMD-lineas classs
    renderable->setPuntoInicial(&puntoNuevo, parent);

    renderable->setFirstPointThick(&puntoNuevo, parent);
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
