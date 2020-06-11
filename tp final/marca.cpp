#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include "marca.h"


bool Marca::buscarMarca(char *nombreBuscado)
{

    int i=0;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p==NULL)
        {
            cout<<"No se pudo abrir archivo";
            return -2;
        }
        while(fread(this,sizeof(Marca),1,p))
        {
        if (strcmp(nombreBuscado,nombre)==0)
        {
        fclose(p);
        return i;
        }
    i++;
    }
    fclose(p);
    return -1;
}

bool Marca::agregarMarca(){
    int i;
    cin.ignore();
    cout<<"Ingresar Nombre: ";
    cin.getline(nombre,20);
    cin.ignore();
    i = buscarMarca(nombre);
    if (i>=0)
    {
        cout<<"Marca ya existente"<<endl;
        system("pause");
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
    cout<<"Marcas disponibles:"<<endl;
    while(fread(this,sizeof(Marca),1,p))
    {
        cout<<endl;
        mostrarMarca();

        }
    system("pause");
    fclose(p);
}

