#ifndef LINEA_H
#define LINEA_H

#include <vector>

class Linea
{
public:
    Linea(std::vector<float>, std::vector<float>);

    std::vector<float> getPosicionO();
    std::vector<float> getPosicionP();
    void setPosicionO(std::vector<float>);
    void setPosicionP(std::vector<float>);

private:
    float posicionXi;
    float posicionXj;
    float posicionYi;
    float posicionYj;

    std::vector<float> posicionO;
    std::vector<float> posicionP;

};

#endif // LINEA_H
