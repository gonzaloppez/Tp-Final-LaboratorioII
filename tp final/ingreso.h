#ifndef INGRESO_H_INCLUDED
#define INGRESO_H_INCLUDED

#include "fecha.h"

class Ingreso{
    private:
    char marca[20];
    char modelo[20];
    char combustible[10];
    char patente[7];
    char falla[50];
    char nombreCliente[30];
    int dni;
    int telefono;
    float km;
    float importe;
    Fecha fe;

    public:
        void cargarIngreso();
        bool guardarIngreso();
        bool buscarPatente(char*);
        void mostrarFichaCliente();


};


#endif // INGRESO_H_INCLUDED
