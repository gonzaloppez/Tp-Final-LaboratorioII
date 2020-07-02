#ifndef MODELO_H_INCLUDED
#define MODELO_H_INCLUDED
#include <iostream>
using namespace std;

#include <stdlib.h>


class Modelo{
    private:
    char nombre[10];
    char ID[3];

    public:
        void  setNombre(char *);
        char* getNombre();
        void  setID(char *);
        char* getID();

        bool cargarModelo();
        void mostrarModelo();
        bool guardarEnDiscoModelo();
        void guardarEnDiscoModelo(int);
        bool leerDeDiscoModelo(int);

};

bool nuevoModelo();
bool listarModelo();
bool modificarModelo();
bool buscarModelo(char *);
int buscarModeloModificar(char *);
void recuadro();
bool validarNombreApellido(char*);


#endif // MODELO_H_INCLUDED
