#include "linea.h"

Linea::Linea()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

Linea::Linea(float x1, float y1, float x2, float y2)
    : x1(x1) , y1(y1), x2(x2), y2(y2)
{
}

Linea::Linea(Punto p1, Punto p2)
{
    x1 = p1.getX();
    y1 = p1.getY();
    x2 = p2.getX();
    y2 = p2.getY();
}

void Linea::setX1(float x1)
{
    this->x1 = x1;
}

void Linea::setY1(float y1)
{
    this->y1 = y1;
}

void Linea::setX2(float x2)
{
    this->x2 = x2;
}

void Linea::setY2(float y2)
{
    this->y2 = y2;
}

float Linea::getX1()
{
    return x1;
}

float Linea::getY1()
{
    return y2;
}

float Linea::getX2()
{
    return x2;
}

float Linea::getY2()
{
    return y2;
}

Punto Linea::getPosicionP1()
{
    Punto p1(x1,y1);
    return p1;
}

Punto Linea::getPosicionP2()
{
    Punto p2(x2, y2);
    return p2;
}

std::vector<float> Linea::getVectorPosicion()
{
    std::vector<float> vectorPosicion {x1, y1, 0.0f, x2, y2, 0.0f};
    return vectorPosicion;
}
