#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <array>


class proyectil
{

private:
    float inVEL[2];
    float ace[2];
    float inPOS[2];
public:
    float pos[2];
    float vel[2];
    float tiempo;
    proyectil();
    proyectil(float ipos[2],float ivel[2]);
    void avanza(float t);
    void set_new_inPOS(float ipos[2]);
    void set_new_invel(float ivel[2]);
    void get_Started();
    std:: array <float,2> getinPOS();


};

#endif // PROYECTIL_H
