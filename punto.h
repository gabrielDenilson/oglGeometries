#ifndef PUNTO_H
#define PUNTO_H

#include <vector>
class Punto
{
public:
    Punto();
    Punto(float, float);

    void setX(float);
    void setY(float);

    float getX();
    float getY();

    std::vector<float> getVectorPosicion();

private:
    float x;
    float y;
};

#endif // PUNTO_H
