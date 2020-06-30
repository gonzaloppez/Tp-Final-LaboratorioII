#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "marca.h"

void Marca::setNombre(char *_nombre){
    strcpy(nombre,_nombre);
}
char* Marca::getNombre(){
    return nombre;
}

///--------------------------------------------

bool Marca::cargarMarca(){
    while(true){
cin.ignore();
    cout<<"Agregar Marca: ";

    cin.getline(nombre,10);
    if(nombre[0]!='\0'){
        if (buscarMarca(nombre))
        {
            cout<<"Marca ya existente"<<endl;
            system("pause");
            return false;
        }else {return true;}

        }else{
            cout<<"Favor de colocar una marca válida"<<endl;
            system("pause");
        }
    }
}

bool buscarMarca(char *nombreBuscado){

    Marca m;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p==NULL){return false;}
    while(fread(&m,sizeof(Marca),1,p))
    {
        if (strcmp(nombreBuscado,m.getNombre())==0)
        {
        fclose(p);
        return true;
        }

    }

    fclose(p);
    return false;

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

bool Marca::leerDeDiscoMarca(int pos){
    bool resultado = false;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Marca), SEEK_SET);
        resultado = fread(this, sizeof(Marca), 1, p);
    }
    fclose(p);
    return resultado;
    }

bool Marca::guardarEnDiscoMarca(int pos){

    bool resultado = false;
    FILE *p;
    p = fopen("marcas.dat","rb+");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Marca), SEEK_SET);
        resultado = fwrite(this, sizeof(Marca), 1, p);
    }
    fclose(p);
    return resultado;

}

///---------------------------------------
bool nuevaMarca(){
         Marca m;
    if (m.cargarMarca()){
        if (m.guardarEnDiscoMarca()){
            return true;
        }
    }
    return false;
}

bool listarMarca(){

    Marca m;
    int i = 0;
    system("cls");
    cout << "Listado de Marcas" << endl;
    cout << "------------------------" << endl;
    cout<<endl;
    cout << "MARCAS"<<endl;
    cout<<endl;

    while(m.leerDeDiscoMarca(i++)){
    cout << m.getNombre()<<endl;
    }
    cin.ignore();
    system("pause");

}

int buscarMarcaModificar(char *nombreBuscado){
    Marca m;
    int i=0;
    FILE *p;
    p = fopen("marcas.dat","rb");
    if (p==NULL){return false;}
    while(fread(&m,sizeof(Marca),1,p))
    {
        if (strcmp(nombreBuscado,m.getNombre())==0)
        {
        fclose(p);
        return i;
        }
        i++;
    }

    fclose(p);
    return false;
}

bool modificarMarca(){

    system("cls");
    char nombre[10];
     char nombres[10];
    int pos;
    Marca m;
    listarMarca();
    cin.ignore();
    cout << "Ingrese marca que desea modificar: ";
    cin.getline(nombre,10);
     if(buscarMarca(nombre)==false)
        {
        return false;
        }
    pos = buscarMarcaModificar(nombre);
    if (pos >= 0){
         cin.ignore();
         while(true){
       cout << "Ingrese la marca modificada: ";
        cin.getline(nombres,10);
        if(nombres[0]!='\0'){
               m.setNombre(nombres);
               m.guardarEnDiscoMarca(pos);
               break;
                }else {
                    cout<<"Marca ingresada inválida"<<endl;
                    system("pause");
              }
        }
        return true;
    }
}

