#ifndef ESCENARIO_H
#define ESCENARIO_H
#include "proyectil.h"
#include <array>
#include "iostream"


class escenario
{
private:
    proyectil balaD;
    proyectil balaO;

    float delayO;
    float delayD;

    float radDO;
    float radD;
    float radO;

    float velO[3];
    float velD[3];

public:
    escenario();
    escenario(float dist,float hD,float hO,float VO [3], float VD[3]);
    std::array <float,2> getDshot(int);
    std::array <float,2> getOshot(int);
};

#endif // ESCENARIO_H
