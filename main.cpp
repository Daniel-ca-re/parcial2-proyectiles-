#include <iostream>
#include "proyectil.h"
#include "escenario.h"
#include <array>

using namespace std;

int main()
{
    cout <<"hola, a continuacion se le pediran la informacion sobre los canhonmes"<<endl;
    cout <<"distancia entre los canhones:"<<endl;
    float d;
    cin >>d;
    cout <<"altura a la que se encuentra el canhon ofensor (a nivel del mar):"<<endl;
    float hD,hO;
    cin >>hO;
    cout <<"altura a la que se encuentra el canhon defensor (a nivel del mar):"<<endl;
    cin >>hD;
    float VD[3];
    float VO[3];
    cout <<"introdusca las 3 velocidades que tendra disponibles el canhon defensor (seguidas de un ENTER):"<<endl;
    for (int x=0; x<3 ;x++)
    {
        cin >>VD[x];
    }
    cout <<"introdusca las 3 velocidades que tendra disponibles el canhon ofensor (seguidas de un ENTER):"<<endl;
    for (int x=0; x<3 ;x++)
    {
        cin >>VO[x];
    }
    escenario campo(d,hD,hO,VO,VD);
    char election;
    while(true)
    {
        cout <<"elija segun desee \n\n"
            <<"1.Generar disparos (al menos tres) ofensivos que comprometan la integridad del canhon\n defensivo.\n\n"
           <<"2.Generar disparos (al menos tres) defensivos que comprometan la integridad del canhon\n ofensivo.\n\n"
          <<"3.Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que\nel canhon defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido.\n\n"
         <<"4.Dado un disparo ofensivo, generar (al menos tres) disparo defensivos que impidan que\nlos canhones defensivo y ofensivo puedan ser destruidos.\n\n"
        <<"5.Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la efectividad/n del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo/n"
        <<"y permitan que el ataque ofensivo sea efectivo.\n\n"
        <<"X.Salir.\n\n:";
        cin >>election;
        if(election=='1')
        {
            for (int x=0; x<3 ;x++)
            {
                array <float,2> result;
                result=campo.getOshot(x);
                if(result[0]==-1)
                {
                    cout <<"el disparo con la velocidad "<<VO[x]<<"es imposible";
                }
            }
        }
        else if(election=='2')
        {

        }
        else if(election=='3')
        {

        }
        else if(election=='4')
        {

        }
        else if(election=='5')
        {

        }
        else
        {
            cout <<"eleccion invalida\n\n"<<endl;
        }

    }

}
