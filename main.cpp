#include <iostream>
#include "proyectil.h"
#include "escenario.h"
#include <array>

using namespace std;

int main()
{
    float VD[3]={20,40,60};
    float VO[3]={15,45,55};
    escenario campo(170.5,10,20,VO,VD);
    array <float,2> infD=campo.getDshot(2);
    array <float,2> infO=campo.getOshot(1);

    cout <<infD[0]<<','<<infD[1]<<endl;
    cout <<infO[0]<<','<<infO[1]<<endl;

}
