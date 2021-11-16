#ifndef DRAWABLEOBJECT_PARENT_LINE_H
#define DRAWABLEOBJECT_PARENT_LINE_H

#include "drawableobject_linea.h"



class DrawableObject_Parent_Line : public DrawableObject_Linea
{
protected:
    float p_magnitude;
    float p_direction;

    vector <Punto*> p_puntosChild;
public:
    DrawableObject_Parent_Line();

};

#endif // DRAWABLEOBJECT_PARENT_LINE_H
