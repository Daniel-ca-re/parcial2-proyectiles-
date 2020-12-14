#include "escenario.h"
#include "proyectil.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>
#include <list>

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
    for (float angO=90;angO<180;angO+=0.01)
    {

        velocidad[0]=velO[i]*cos(3.1416*(angO/180));
        velocidad[1]=velO[i]*sin(3.1416*(angO/180));
        balaO.set_new_invel(velocidad);
        balaO.get_Started();
        while(balaO.pos[1]>=0)
        {

            balaO.avanza(0.01);
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
    for (float angD=0;angD<90;angD+=0.01)
    {

        velocidad[0]=velD[i]*cos(3.1416*(angD/180));
        velocidad[1]=velD[i]*sin(3.1416*(angD/180));
        balaD.set_new_invel(velocidad);
        balaD.get_Started();
        while(balaD.pos[1]>=0)
        {

            balaD.avanza(0.01);
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


std::array<float,5> escenario::getDshotInOshot(int i)
//retorna la informacion angO,velO, defase, angD y tiempo
{
    using namespace std;
    list <int> idnt={0,1,2};
    while(idnt.size()!=0)
    {
        auto I= idnt.begin();
        srand(time(NULL));
        int n=rand()%idnt.size();
        advance(I,n);
        array <float,2> infSO =getOshot(*I);

        if(infSO[1]+infSO[2]==-2)
        {
            idnt.erase(I);
        }
        else
        {
            float tlim=balaO.tiempo;
            for(float desfaExtra=0;desfaExtra<tlim;desfaExtra+=0.1)
            {
                float velocidad[2];
                for (float angD=0;angD<90;angD+=0.01)
                {

                    velocidad[0]=velD[i]*cos(3.1416*(angD/180));
                    velocidad[1]=velD[i]*sin(3.1416*(angD/180));
                    balaD.set_new_invel(velocidad);
                    balaD.get_Started();
                    balaO.get_Started();
                    balaO.avanza(delayD+desfaExtra);
                    while(balaD.pos[1]>=0)
                    {

                        balaD.avanza(0.01);
                        balaO.avanza(0.01);
                        if( sqrt( pow(balaD.getinPOS()[0]-balaO.pos[0],2)+ pow(balaD.getinPOS()[1]-balaO.pos[1],2) )>radO
                                && sqrt( pow(balaD.pos[0]-balaO.pos[0],2)+ pow(balaD.pos[1]-balaO.pos[1],2) )<radD
                                && sqrt( pow(balaD.getinPOS()[0]-balaD.pos[0],2)+ pow(balaD.getinPOS()[1]-balaD.pos[1],2) )>radD)
                        {
                            std::array<float,5> a={infSO[0],velO[*I],desfaExtra,angD,balaD.tiempo};
                            return a;
                        }
                    }
                }
            }
            std::array<float,5> a={infSO[0],velO[*I],-1,-1,-1};
            return a;

        }


    }
    array <float,5> result={-1,-1,-1,-1,-1};
    return result;

}

std::array<float,5> escenario::getDshotInOshot2(int i)
//retorna la informacion angO,velO, defase, angD y tiempo
{
    using namespace std;
    list <int> idnt={0,1,2};
    while(idnt.size()!=0)
    {
        auto I= idnt.begin();
        srand(time(NULL));
        int n=rand()%idnt.size();
        advance(I,n);
        array <float,2> infSO =getOshot(*I);

        if(infSO[1]+infSO[2]==-2)
        {
            idnt.erase(I);
        }
        else
        {
            float tlim=balaO.tiempo;
            for(float desfaExtra=0;desfaExtra<tlim;desfaExtra+=0.1)
            {
                float velocidad[2];
                for (float angD=0;angD<90;angD+=0.01)
                {

                    velocidad[0]=velD[i]*cos(3.1416*(angD/180));
                    velocidad[1]=velD[i]*sin(3.1416*(angD/180));
                    balaD.set_new_invel(velocidad);
                    balaD.get_Started();
                    balaO.get_Started();
                    balaO.avanza(delayD+desfaExtra);
                    while(balaD.pos[1]>=0)
                    {

                        balaD.avanza(0.01);
                        balaO.avanza(0.01);
                        if( sqrt( pow(balaD.getinPOS()[0]-balaO.pos[0],2)+ pow(balaD.getinPOS()[1]-balaO.pos[1],2) )>radO
                                && sqrt( pow(balaD.getinPOS()[0]-balaD.pos[0],2)+ pow(balaD.getinPOS()[1]-balaD.pos[1],2) )>radD
                                && sqrt( pow(balaD.pos[0]-balaO.pos[0],2)+ pow(balaD.pos[1]-balaO.pos[1],2) )<radD
                                && sqrt( pow(balaO.getinPOS()[0]-balaD.pos[0],2)+ pow(balaO.getinPOS()[1]-balaD.pos[1],2) )>radD
                                )
                        {
                            std::array<float,5> a={infSO[0],velO[*I],desfaExtra,angD,balaD.tiempo};
                            return a;
                        }
                    }
                }
            }
            std::array<float,5> a={infSO[0],velO[*I],-1,-1,-1};
            return a;

        }

    }
    array <float,5> result={-1,-1,-1,-1,-1};
    return result;

}

std::array<float, 8> escenario::getOshotInDshot(int i)
//angO, velO, angD, velD, angI, desfase1, defase2 y tiempo
{
    using namespace std;
    list <int> idnt={0,1,2};
    while(idnt.size()!=0)
    {
        auto I= idnt.begin();
        srand(time(NULL));
        int n=rand()%idnt.size();
        advance(I,n);
        array <float,5> inf =getDshotInOshot2(*I);

        if(inf[4]==-1)
        {
            idnt.erase(I);
        }
        else
        {
            float tlim=balaD.tiempo;
            for(float desfaExtra=0;desfaExtra<tlim;desfaExtra+=0.1)
            {
                float velocidad[2];
                for (float angO2=90;angO2<180;angO2+=0.01)
                {

                    velocidad[0]=velO[i]*cos(3.1416*(angO2/180))*10;
                    velocidad[1]=velO[i]*sin(3.1416*(angO2/180))*10;
                    balaI.set_new_invel(velocidad);
                    balaD.get_Started();
                    balaO.get_Started();
                    balaI.get_Started();
                    balaO.avanza(delayD+inf[2]+delayO+desfaExtra);
                    balaD.avanza(delayO+desfaExtra);
                    while(balaI.tiempo+desfaExtra<tlim)
                    {

                        balaD.avanza(0.01);
                        balaO.avanza(0.01);
                        balaI.avanza(0.01);
                        if( sqrt( pow(balaD.pos[0]-balaO.pos[0],2)+ pow(balaD.pos[1]-balaO.pos[1],2) )>radD
                                && sqrt( pow(balaD.pos[0]-balaI.pos[0],2)+ pow(balaD.pos[1]-balaI.pos[1],2) )<radI)
                        {
                            std::array<float,8> a={inf[0],inf[1],inf[3],velD[*I],angO2,inf[2],desfaExtra,balaI.tiempo};
                            return a;
                        }
                    }
                }
            }
            std::array<float,8> a={inf[0],inf[1],inf[3],velD[*I],-1,inf[2],-1,-1};
            return a;

        }

    }
    array <float,8> result={-1,-1,-1,-1,-1,-1,-1,-1};
    return result;
}
