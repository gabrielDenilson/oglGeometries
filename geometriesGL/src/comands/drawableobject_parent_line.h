#ifndef DRAWABLEOBJECT_PARENT_LINE_H
#define DRAWABLEOBJECT_PARENT_LINE_H

#include "drawableobject_linea.h"
#include "drawableobject_punto.h"



class DrawableObject_Parent_Line : public DrawableObject_Linea
{
protected:
    DrawableObject_Punto *ptrPunto;
    DrawableObject_Punto *ptrPuntoFinal;

    float p_magnitude;
    float p_direction;

    vector <Punto*> p_puntosChild;
public:
    DrawableObject_Parent_Line();

    void draw_Componente_Geometry(QWidget *parent) override;

    void setShader(const Shader &shaderProgram) override;

    void setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent) override;
    void setEndPoint(Punto *endPoint, Geometry *child, QWidget *parent) override;

};

#endif // DRAWABLEOBJECT_PARENT_LINE_H
