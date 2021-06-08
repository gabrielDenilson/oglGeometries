#include "triangulo.h"

#include <QDebug>

triangulo::triangulo(){
    //arrCoordenadas[0] = 0.3;
}

triangulo::triangulo(float coord[])
{
    for(int i = 0; i < 9; i++){
        arrCoordenadas[i] = coord[i];
    }
}

float triangulo::getCoordenadas(int posicion)
{
    return arrCoordenadas[posicion];
}


QVector<float> triangulo::getCoord()
{
    qDebug()<< "corrdenadas privadas" << Qcoord.size();
    return Qcoord;
}

std::vector<float> triangulo::vectorConvertido()
{
    std::vector <float> esto;
    return esto;
}

