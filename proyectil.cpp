#include "proyectil.h"
#include "math.h"

proyectil::proyectil()
{

}

proyectil::proyectil(float ipos[2], float ivel[2])
{
    inPOS[0]=ipos[0];
    inPOS[1]=ipos[1];
    inVEL[0]=ivel[0];
    inVEL[1]=ivel[1];
    pos[0]=ipos[0];
    pos[1]=ipos[1];
    vel[0]=ivel[0];
    vel[1]=ivel[1];
    ace[0]=0;
    ace[1]=-9.81;
    tiempo=0;
}

void proyectil::avanza(float t)
{
    pos[1]+=vel[1]*t+(ace[1]/2)*(pow(t,2));
    pos[0]+=vel[0]*t;
    vel[1]+=ace[1]*t;
    vel[0]+=ace[0]*t;
}

void proyectil::set_new_inPOS(float ipos[])
{
    inPOS[0]=ipos[0];
    inPOS[1]=ipos[1];
}

void proyectil::set_new_invel(float ivel[])
{
    inVEL[0]=ivel[0];
    inVEL[1]=ivel[1];
}

void proyectil::get_Started()
{
    pos[0]=inPOS[0];
    pos[1]=inPOS[1];
    vel[0]=inVEL[0];
    vel[1]=inVEL[1];
    tiempo=0;
}
