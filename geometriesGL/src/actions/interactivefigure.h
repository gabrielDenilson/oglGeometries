#ifndef INTERACTIVEFIGURE_H
#define INTERACTIVEFIGURE_H

#include "geometriesGL/src/comands/geometry.h"
#include "geometriesGL/src/comands/compoundgeometry.h"
#include "geometriesGL/src/comands/drawableobject_linea.h"


class InteractiveFigure
{
public:
    InteractiveFigure();

private:
    CompoundGeometry groupShapes;
};

#endif // INTERACTIVEFIGURE_H
