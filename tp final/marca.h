#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <iostream>
using namespace std;
#include <stdlib.h>

class Marca{
    private:
    char nombre[10];
    public:
        bool agregarMarca();
        void mostrarMarca();
        bool guardarEnDiscoMarca();
        void leerDeDiscoMarca();
        bool buscarMarca(char*);
};




#endif // MARCA_H_INCLUDED
