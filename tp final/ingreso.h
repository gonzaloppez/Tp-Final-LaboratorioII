#ifndef INGRESO_H_INCLUDED
#define INGRESO_H_INCLUDED
#include "marca.h"
#include "modelo.h"
#include "clientes.h"
#include "fecha.h"


class Auto{
    private:
    char marca[10];
    char modelo[10];
    char combustible[10];
    char patente[7];
    char falla[50];
    int dni;
    Clientes cli;
    float km;
    float importe;
    Fecha fe;

    public:
        ///SETS
        void setMarca(char *);
        void setModelo(char *);
        void setCombustible(char *);
        void setPatente(char *);
        void setFalla(char *);
        void setKm(float);
        void setImporte(float);

        ///GETS
        char* getMarca();
        char* getModelo();
        char* getCombustible();
        char* getPatente();
        char* getFalla();


        int getDni();
        float getKm();
        float getImporte();
        Clientes getCliente();
        bool cargarIngreso();
        bool guardarIngreso();
        void mostrar();
        bool leerDeDisco(int);


};

bool nuevoIngreso();
void buscarIngreso();
void buscarPatente(char*);

#endif // INGRESO_H_INCLUDED
