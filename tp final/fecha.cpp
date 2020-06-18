#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>
#include "fecha.h"

void Fecha::cargar(){
    cout<< "Dia: ";
    cin>>dia;
    cout<< "Mes: ";
    cin>>mes;
    cout<< "Anio: ";
    cin>>anio;
}

void Fecha::mostrar(){

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
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
