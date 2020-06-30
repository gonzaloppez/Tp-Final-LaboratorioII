#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "modelo.h"

void Modelo::setNombre(char *_nombre){
    strcpy(nombre,_nombre);
}
char* Modelo::getNombre(){
    return nombre;
}
///--------------------------------------------

bool Modelo::cargarModelo(){
    while(true){
cin.ignore();
    cout<<"Agregar Modelo: ";
    cin.getline(nombre,10);
    if(nombre[0]!='\0'){
        if (buscarModelo(nombre))
        {
            cout<<"Modelo ya existente"<<endl;
            system("pause");
            return false;
        }else {return true;}


}
else{
            cout<<"Favor de colocar un modelo válido"<<endl;
            system("pause");
        }
    }
}

bool buscarModelo(char *nombreBuscado){

    Modelo mod;
    FILE *p;
    p = fopen("modelos.dat","rb");
    if (p==NULL){return false;}
    while(fread(&mod,sizeof(Modelo),1,p))///Aca
    {
        if (strcmp(nombreBuscado,mod.getNombre())==0)
        {
        fclose(p);
        return true;
        }

    }
    fclose(p);
    return false;
    }

void Modelo::mostrarModelo(){
    cout<<nombre;
}

bool Modelo::guardarEnDiscoModelo(){
    bool escribio;
    FILE *p;
    p = fopen("modelos.dat","ab");
    if (p==NULL){return false;}
    escribio=fwrite(this,sizeof(Modelo),1,p);
    fclose(p);
    return escribio;
}

bool Modelo::leerDeDiscoModelo(int pos){
    bool resultado = false;
    FILE *p;
    p = fopen("modelos.dat","rb");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Modelo), SEEK_SET);
        resultado = fread(this, sizeof(Modelo), 1, p);
    }
    fclose(p);
    return resultado;
    }

void Modelo::guardarEnDiscoModelo(int pos){

    FILE *p;
    p = fopen("modelos.dat","rb+");
    if (p == NULL){
        return ;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Modelo), SEEK_SET);
    fwrite(this, sizeof(Modelo), 1, p);
    }
    fclose(p);

        }

///---------------------------------------
bool nuevoModelo(){
         Modelo mod;
    if (mod.cargarModelo()){
        if (mod.guardarEnDiscoModelo()){
            return true;
        }
    }
    return false;
}

bool listarModelo(){

    Modelo mod;
    int i = 0;
    system("cls");
    cout << "Listado de Modelos" << endl;
    cout << "------------------------" << endl;
    cout<<endl;
    cout << "MODELOS"<<endl;
    cout<<endl;

    while(mod.leerDeDiscoModelo(i++)){
    cout << mod.getNombre()<<endl;
    }
    cin.ignore();
    system("pause");

}





int buscarModeloModificar(char *nombreBuscado){

     Modelo mod;
    int i=0;
    FILE *p;
    p = fopen("modelos.dat","rb");
    if (p==NULL){return false;}
    while(fread(&mod,sizeof(Modelo),1,p))
    {
        if (strcmp(nombreBuscado,mod.getNombre())==0)
        {
        fclose(p);
        return i;
        }
        i++;
    }

    fclose(p);
    return -1;
}




bool modificarModelo(){

    system("cls");
    char nombre[10];
    char nombres[10];
    int pos;
    Modelo mod;
    listarModelo();
    cin.ignore();
    cout << "Ingrese modelo que desea modificar: ";
    cin.getline(nombre,10);
     if(buscarModelo(nombre)==false)
        {
        return false;
        }
    pos = buscarModeloModificar(nombre);
    if (pos >= 0){
         cin.ignore();
         while(true){
       cout << "Ingrese el modelo modificado: ";
        cin.getline(nombres,10);
        if(nombres[0]!='\0'){
               mod.setNombre(nombres);
               mod.guardarEnDiscoModelo(pos);
               break;
                }else {
                    cout<<"Modelo ingresado invalido"<<endl;
                    system("pause");
              }
        }
        return true;
    }
}



