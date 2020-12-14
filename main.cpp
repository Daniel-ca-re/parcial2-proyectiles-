#include <iostream>
#include "proyectil.h"
#include "escenario.h"
#include <array>

using namespace std;

int main()
{
    cout <<"hola, a continuacion se le pediran la informacion sobre los canhones"<<endl;
    cout <<"distancia entre los canhones:"<<endl;
    float d;
    cin >>d;
    cout <<"altura a la que se encuentra el canhon ofensor (sobre el nivel del mar):"<<endl;
    float hD,hO;
    cin >>hO;
    cout <<"altura a la que se encuentra el canhon defensor (sobre el nivel del mar):"<<endl;
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
          <<"3.Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que\nel canhon defensivo sea destruido sin importar si el canhon ofensivo pueda ser destruido.\n\n"
         <<"4.Dado un disparo ofensivo, generar (al menos tres) disparo defensivos que impidan que\nlos canhones defensivo y ofensivo puedan ser destruidos.\n\n"
        <<"5.Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la efectividad/n del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo/n"
        <<"y permitan que el ataque ofensivo sea efectivo.\n\n"
        <<"X.Salir.\n\n:";
        cin >>election;

        if(election=='1')

        {
            cout<<"\n\n\n";
            for (int x=0; x<3 ;x++)
            {
                array <float,2> result;
                result=campo.getOshot(x);
                if(result[0]==-1)
                {
                    cout<<"\n";
                    cout <<"el disparo con la velocidad "<<VO[x]<<"m/s es imposible"<<endl;
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro es:  "<<VO[x]<<"m/s"<<endl;
                    cout <<"el angulo con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"le da  "<<result[1]<<"s despues de que dispara"<<endl;
                    cout<<"\n";
                }
            }
            cout<<"\n\n\n";
        }

        else if(election=='2')

        {
            cout<<"\n\n\n";
            for (int x=0; x<3 ;x++)
            {
                array <float,2> result;
                result=campo.getDshot(x);
                if(result[0]==-1)
                {
                    cout<<"\n";
                    cout <<"el disparo con la velocidad "<<VD[x]<<"m/s es imposible"<<endl;
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro es:  "<<VD[x]<<"m/s"<<endl;
                    cout <<"el angulo con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"le da  "<<result[1]<<"s despues de que dispara"<<endl;
                    cout<<"\n";
                }
            }
            cout<<"\n\n\n";
        }

        else if(election=='3')

        {
            cout<<"\n\n\n";
            for (int x=0; x<3 ;x++)
            {
                array <float,5> result;
                result=campo.getDshotInObase(x);
                if(result[0]==-1)
                {
                    cout<<"\n";
                    cout <<"el canhon ofensor es incapaz de herir al canhon defensor"<<endl;
                    cout<<"\n";
                }
                else if(result[4]==-1)
                {
                    cout<<"\n";
                    cout<<"bala O "<<endl;
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"el disparo con la velocidad "<<VD[x]<<"m/s es incapaz de interceptar a la bala O"<<endl;
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo O con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"la velocidad del diapro D es:  "<<VD[x]<<"m/s"<<endl;
                    cout <<"el angulo D con el que se logra es:  "<<result[3]<<" grados"<<endl;
                    cout <<"lo que se demora en disparar :  "<<result[2]+2<<"s"<<endl;
                    cout <<"lo que se demora en darle desde que se disparo la bola D"<<result[4]<<endl;
                    cout<<"\n";
                }
            }
            cout<<"\n\n\n";
        }

        else if(election=='4')

        {
            cout<<"\n\n\n";
            for (int x=0; x<3 ;x++)
            {
                array <float,5> result;
                result=campo.getDshotInObase2(x);
                if(result[0]==-1)
                {
                    cout<<"\n";
                    cout <<"el canhon ofensor es incapaz de herir al canhon defensor"<<endl;
                    cout<<"\n";
                }
                else if(result[4]==-1)
                {
                    cout<<"\n";
                    cout<<"bala O "<<endl;
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"el disparo con la velocidad "<<VD[x]<<"m/s es incapaz de interceptar a la bala O"<<endl;
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo O con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"la velocidad del diapro D es:  "<<VD[x]<<"m/s"<<endl;
                    cout <<"el angulo D con el que se logra es:  "<<result[3]<<" grados"<<endl;
                    cout <<"lo que se demora en disparar :  "<<result[2]+2<<"s"<<endl;
                    cout <<"lo que se demora en darle desde que se disparo la bola D"<<result[4]<<endl;
                    cout<<"\n";
                }
            }
            cout<<"\n\n\n";
        }
        else if(election=='5')
        {
            cout<<"\n\n\n";
            for (int x=0; x<3 ;x++)
            {
                array <float,8> result;
                result=campo.getOshotInDshot(x);
                if(result[0]==-1)
                {
                    cout<<"\n";
                    cout <<"no existen par de balas D y O que choquen entre si"<<endl;
                    cout<<"\n";
                }
                else if(result[4]==-1)
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo O con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"la velocidad del diapro D es:  "<<result[3]<<"m/s"<<endl;
                    cout <<"el angulo D con el que se logra es:  "<<result[2]<<" grados"<<endl;
                    cout <<"lo que se demora en disparar D:  "<<result[5]+2<<"s"<<endl;
                    cout <<"la bala interceptadora del con la velocidad "<<10*VO[x]<<"es inacapaz de interceptar la bala defensiva"<<endl;
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n";
                    cout <<"la velocidad del diapro O es:  "<<result[1]<<"m/s"<<endl;
                    cout <<"el angulo O con el que se logra es:  "<<result[0]<<" grados"<<endl;
                    cout <<"la velocidad del diapro D es:  "<<result[3]<<"m/s"<<endl;
                    cout <<"el angulo D con el que se logra es:  "<<result[2]<<" grados"<<endl;
                    cout <<"lo que se demora en disparar D:  "<<result[5]+2<<"s"<<endl;
                    cout <<"la bala interceptadora va a "<<10*VO[x]<<"m/s"<<endl;
                    cout <<"la bala interceptadora tiene un angulo de "<<result[4]<<" grados"<<endl;
                    cout <<"la bala interceptadora se lanza "<<3+result[5]+result[6]<<"s despues de la bala ofensiva"<<endl;
                    cout <<"la bala interceptadora detona "<<result[7]<<"s despues de ser lanzada"<<endl;

                    cout<<"\n";
                }
            }
            cout<<"\n\n\n";
        }
        else if(election=='x' || election=='X' )
        {
            break;
        }
        else
        {
            cout <<"eleccion invalida\n\n"<<endl;
        }

    }

}
