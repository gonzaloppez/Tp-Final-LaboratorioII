#include <iostream>
using namespace std;
#include <stdlib.h>
#include "rlutil.h"
#include <ctime>
#include "fecha.h"

void Fecha::setDia(int d){
        dia=d;
}

void Fecha::setMes(int m){
        mes=m;
}

void Fecha::setAnio(int a){
        anio=a;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}


bool Fecha::cargar(){
    rlutil::locate(47,18);cout<< "Dia: ";
    cin>>dia;
    rlutil::locate(55,18);cout<< "Mes: ";
    cin>>mes;
    rlutil::locate(63,18);cout<< "año: ";
    cin>>anio;
        if (validarFecha(dia,mes,anio)==true){
        return true;
    }else{
        rlutil::setColor(rlutil::RED);
        rlutil::locate(47,19);cout<<"FECHA INVALIDA"<<endl;
        rlutil::anykey();
        return false;}
}

void Fecha::mostrar(){

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}




bool validarFecha(int dia, int mes, int anio){

     switch ( mes )
    {
    case  1 :
    case  3 :
    case  5 :
    case  7 :
    case  8 :
    case 10 :
    case 12 :
        if ( dia >= 1 && dia <= 31 )
        {

            return true;
        }
        else
        {

            return false;
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia >= 1 && dia <= 30 )
            {

                return true;
            }

            else
            {

                return false;
            }
            break;

        case  2 :
            if( anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0 )
            {
                if ( dia >= 1 && dia <= 29 )
                {

                    return true;
                }
                else if ( dia >= 1 && dia <= 28 )
                {

                    return true;
                }
                else
                {

                    return false;
                }


            }
            else
            {

                return false;
            }
        }

    }
    return true;
}

/*Fecha::Fecha(){

    time_t timestamp;
    timestamp = time(NULL);
    tm *f;
    f = localtime(&timestamp);
    dia = f->tm_mday;
    mes = f->tm_mon +1;
    anio = f->tm_year +1900;

}*/
