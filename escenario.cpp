#include "escenario.h"
#include "proyectil.h"
#include "math.h"

escenario::escenario()
{

}

escenario::escenario(float dist, float hD, float hO, float VO[3], float VD[3])
{
    float array [2]={0,0};
    proyectil BD(array,array);
    balaD=BD;
    float array2 [2]={dist,hO-hD};
    proyectil BO(array2,array);
    balaO=BO;
    balaI=BO;
    radD=0.025*dist;
    radO=0.05*dist;
    radI=0.005*dist;
    delayD=2;
    delayO=1;
    for (int i=0;i<4;i++)
    {
        velD[i]=VD[i];
        velO[i]=VO[i];
    }

}

std::array<float,2> escenario::getOshot(int i)
{
    float velocidad[2];
    for (float angO=90;angO<180;angO+=0.001)
    {

        velocidad[0]=velO[i]*cos(3.1416*(angO/180));
        velocidad[1]=velO[i]*sin(3.1416*(angO/180));
        balaO.set_new_invel(velocidad);
        balaO.get_Started();
        while(balaO.pos[1]>=0)
        {

            balaO.avanza(0.001);
            if( sqrt( pow(balaD.getinPOS()[0]-balaO.pos[0],2)+ pow(balaD.getinPOS()[1]-balaO.pos[1],2) )<radO )
            {
                std::array<float,2> a={angO,balaO.tiempo};
                return a;
            }
        }
    }
    std::array<float,2> a={-1,-1};
    return a;
}

std::array<float,2> escenario::getDshot(int i)
{
    float velocidad[2];
    for (float angD=0;angD<90;angD+=0.001)
    {

        velocidad[0]=velD[i]*cos(3.1416*(angD/180));
        velocidad[1]=velD[i]*sin(3.1416*(angD/180));
        balaD.set_new_invel(velocidad);
        balaD.get_Started();
        while(balaD.pos[1]>=0)
        {

            balaD.avanza(0.001);
            if( sqrt( pow(balaO.getinPOS()[0]-balaD.pos[0],2)+ pow(balaO.getinPOS()[1]-balaD.pos[1],2) )<radD )
            {
                std::array<float,2> a={angD,balaD.tiempo};
                return a;
            }
        }
    }
    std::array<float,2> a={-1,-1};
    return a;
}
