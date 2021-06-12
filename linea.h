#ifndef LINEA_H
#define LINEA_H

#include <vector>

#include "punto.h"


class Linea
{
public:
    Linea();
    Linea(float x1, float y1, float x2, float y2);
    Linea(Punto, Punto);

    void setX1(float);
    void setY1(float);
    void setX2(float);
    void setY2(float);

    float getX1();
    float getY1();
    float getX2();
    float getY2();

    Punto getPosicionP1();
    Punto getPosicionP2();

    std::vector<float> getVectorPosicion();
private:
    float x1;
    float y1;
    float x2;
    float y2;
};

#endif // LINEA_H
