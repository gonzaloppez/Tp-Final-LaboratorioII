#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <iostream>
using namespace std;

#include <stdlib.h>


class Marca{
    private:
    char nombre[10];

    public:
        void setNombre(char *);
        char* getNombre();

        bool cargarMarca();
        void mostrarMarca();
        bool guardarEnDiscoMarca();
        bool guardarEnDiscoMarca(int);
        bool leerDeDiscoMarca(int);

};

bool buscarMarca(char *);
bool nuevaMarca();
bool listarMarca();
bool modificarMarca();
int buscarMarcaModificar(char *);

#endif // MARCA_H_INCLUDED
