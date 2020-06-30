#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


#include <stdlib.h>
#include "ingreso.h"

void recaudacionAnual(){
    Auto ing;
    Fecha fe;
    int acu=0;
    int pos=0;
    int anioRecaudacion;
    cout<<"Ingrese año: " ;
    cin>>anioRecaudacion;
    while(ing.leerDeDisco(pos++))
        {
            system("pause");
            if(anioRecaudacion==fe.getAnio()){
                    ing.mostrar();
            }

        }

        system("pause");
}


#endif // REPORTES_H_INCLUDED
