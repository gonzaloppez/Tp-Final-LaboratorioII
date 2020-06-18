#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include "marca.h"

bool Marca::buscarMarca(char *nombreBuscado)
    {

    Marca m;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p==NULL){return false;}
    while(fread(&m,sizeof(Marca),1,p))
    {
        if (strcmp(nombreBuscado,m.nombre)==0)
        {
        fclose(p);
        return true;
        }

    }

    fclose(p);
    return false;

    }

bool Marca::cargarMarca(){
    cout<<"Agregar Marca: ";
    cin.ignore();
    cin.getline(nombre,10);
        if (buscarMarca(nombre))
        {
            cout<<"Marca ya existente"<<endl;
            return false;
        }

    return true;
}

void Marca::mostrarMarca(){
    cout<<nombre;
}

bool Marca::guardarEnDiscoMarca(){
    bool escribio;
    FILE *p;
    p = fopen("marcas.dat","ab");
    if (p==NULL){return false;}
    escribio=fwrite(this,sizeof(Marca),1,p);
    fclose(p);
    return escribio;
}

void Marca::leerDeDiscoMarca(){
    Marca m;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p==NULL){return;}
    while(fread(this,sizeof(Marca),1,p))
    {
        cout<<endl;
        mostrarMarca();
    }
    system("pause");
    fclose(p);

}

