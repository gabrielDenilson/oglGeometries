#include "focmaths.h"

OGGEOM::FocMaths::FocMaths()
{

}

float OGGEOM::FocMaths::lessDedimalsFromFloat(float &value, int numberDecimal){
    float result = 0;
    float temp = value;
    int i = 0;
    while(i < numberDecimal){
        temp = temp * 10;
        i++;
    }
    result = temp;
    return result;
}
