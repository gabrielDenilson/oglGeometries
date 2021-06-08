#include "linea.h"

Linea::Linea(std::vector<float> posicionOin, std::vector<float> posicionPin)
    : posicionO(posicionOin), posicionP(posicionPin)
{
    /*  USAdo para establecer valores atomicos en variables particulares
    posicionXi = posicionO[0];
    posicionXj = posicionO[1];
    posicionYi = posicionO[0];
    posicionYj = posicionO[1];
    */
}

std::vector<float> Linea::getPosicionO()
{
    return posicionO;
}

std::vector<float> Linea::getPosicionP()
{
    return posicionP;
}

void Linea::setPosicionO(std::vector<float> newPosicionO)
{
    posicionO = std::move(newPosicionO);
}

void Linea::setPosicionP(std::vector<float> newPosicionP)
{
    posicionP = std::move(newPosicionP);
}

