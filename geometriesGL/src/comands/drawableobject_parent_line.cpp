#include "drawableobject_parent_line.h"



DrawableObject_Parent_Line::DrawableObject_Parent_Line()
{
    renderable->setColorLinea({0.0f, 0.0f, 1.0f});
    renderable->setColorThick(COLORG::BLUE);
    model = glm::mat4(1.0f);

    ptrPunto = new DrawableObject_Punto;
    ptrPuntoFinal = new DrawableObject_Punto;

    ptrPunto->setColorThick(COLORG::RED);
    ptrPuntoFinal->setColorThick(COLORG::RED);
//    ptrPunto->setShader(renderable->getShaderProgram());
}

void DrawableObject_Parent_Line::draw_Componente_Geometry(QWidget *parent)
{
    ptrPunto->setMVP(renderable->getMVP());
    ptrPuntoFinal->setMVP(renderable->getMVP());

    ptrPunto->drawPunto(parent);
    ptrPuntoFinal->drawPunto(parent);

    //RENDERIZADO DE LINEA
    renderable->drawOtherLinea(parent);
    renderable->drawLinea(parent);

}

void DrawableObject_Parent_Line::setShader(const Shader &shaderProgram)
{
    this->shaderProgram = shaderProgram;
    renderable->setShaderProgram(shaderProgram);
    ptrPunto->renderable->setShaderProgram(shaderProgram);
    ptrPuntoFinal->renderable->setShaderProgram(shaderProgram);
}

void DrawableObject_Parent_Line::setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent)
{
    setPuntoInicial(firstPoint, parent);
    ptrPunto->setStartPoint(firstPoint, nullptr, parent);
}

void DrawableObject_Parent_Line::setEndPoint(Punto *endPoint, Geometry *child, QWidget *parent)
{
    setPuntoFinal(endPoint, parent);
    ptrPuntoFinal->setStartPoint(endPoint, nullptr, parent);
}
