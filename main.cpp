#include <iostream>
#include "proyectil.h"
#include "escenario.h"
#include <array>

using namespace std;

int main()
{
    float VD[3]={40,45,70};
    float VO[3]={50,70,90};
    escenario campo(170.5,10,20,VO,VD);
    //array <float,2> infD=campo.getDshot(0);
    //array <float,2> infO=campo.getOshot(0);

    //cout <<infD[0]<<','<<infD[1]<<endl;
    //cout <<infO[0]<<','<<infO[1]<<endl;

    array <float,4> infDO=campo.getDshotInOshot2(2);
    cout <<infDO[0]<<','<<infDO[1]<<','<<infDO[2]<<','<<infDO[3]<<endl;

}
