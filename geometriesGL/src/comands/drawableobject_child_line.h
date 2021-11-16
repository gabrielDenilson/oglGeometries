#ifndef DRAWABLEOBJECT_CHILD_LINE_H
#define DRAWABLEOBJECT_CHILD_LINE_H

#include "drawableobject_linea.h"

class DrawableObject_Child_Line : public DrawableObject_Linea
{
protected:
    float c_magnitude;
    float c_direction;

public:
    DrawableObject_Child_Line();

};

#endif // DRAWABLEOBJECT_CHILD_LINE_H
