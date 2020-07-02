#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <iostream>
using namespace std;


#include <stdlib.h>

void recuadro();
bool validarNombreApellido(char*);

class Marca{
    private:
    char nombre[10];
    char ID[4];


    public:
        void setNombre(char *);
        char* getNombre();

        void setID(char *);
        char* getID();

        bool cargarMarca();
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
