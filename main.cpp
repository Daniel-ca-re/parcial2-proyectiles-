#include <iostream>
#include "proyectil.h"

using namespace std;

int main()
{
    float pos[]={50,10};
    float vel[]={11,5};
    proyectil bala1(pos,vel);
    bala1.avanza(5);
    cout <<'('<<bala1.pos[0]<<','<<bala1.pos[1]<<')'<<endl;
    bala1.avanza(3);
    cout <<'('<<bala1.pos[0]<<','<<bala1.pos[1]<<')'<<endl;

}
