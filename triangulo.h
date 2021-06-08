#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <QVector>

class triangulo
{
public:
    triangulo();

    triangulo(float[]);

    float getCoordenadas(int);

    QVector <float>getCoord();

    std::vector<float> vectorConvertido();

private:
    float arrCoordenadas[9] = {-0.5f, -0.5f, 0.0f,
                               0.5f, -0.5f, 0.0f,
                               0.0f,  0.5f, 0.0f };

    QVector <float> Qcoord;
};

#endif // TRIANGULO_H
