#include "punto.h"

Punto::Punto()
{
    x = 0;
    y = 0;
}

Punto::Punto(float x, float y)
    :x(x), y(y)
{
}

Punto::~Punto()
{

}

void Punto::setX(float x)
{
    this->x = x;
}

void Punto::setY(float y)
{
    this->y = y;
}

float Punto::getX()
{
    return x;
}

float Punto::getY()
{
    return y;
}

std::vector<float> Punto::getVectorPosicion()
{
    std::vector<float>vectorPosicion{x, y};
    return vectorPosicion;
}
