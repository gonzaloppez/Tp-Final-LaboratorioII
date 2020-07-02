#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "rlutil.h"
#include "marca.h"

void Marca::setNombre(char *_nombre){
    strcpy(nombre,_nombre);
}
char* Marca::getNombre(){
    return nombre;
}

void Marca::setID(char *_ID){
    strcpy(ID,_ID);
}

char* Marca::getID(){
    return ID;
}

///--------------------------------------------

bool Marca::cargarMarca(){


    while(true){
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
   /* cout<<"Ingrese ID de marca: ";
    cin.ignore();
    cin.getline(ID,4);*/

    rlutil::locate(45,9);cout<<"AGREGAR MARCA: ";
    rlutil::locate(40,10);cout << "-------------------------" << endl;

    rlutil::locate(44,12);cout<<"NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,10);
        if(validarNombreApellido(nombre)){
        if (buscarMarca(nombre))
        {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(42,14);cout<<"Marca ya existente"<<endl;
            rlutil::anykey();
        }else {
              return true;
            }

        }else{
            rlutil::setColor(rlutil::RED);
           rlutil::locate(42,14); cout<<"FAVOR DE COLOCAR UNA MARCA VALIDA"<<endl;
            rlutil::anykey();
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
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    Marca m;
    int i = 0;
    rlutil::locate(48,9);cout << "LISTADO DE MARCAS" << endl;
    rlutil::locate(45,11);cout<< "------------------------" << endl;
    while(m.leerDeDiscoMarca(i++)){
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(45,12+i);cout << m.getNombre()<<endl;
    }
    cin.ignore();
    rlutil::anykey();

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
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    char nombre[10];
    char nombres[10];
    int pos;
    Marca m;
    while(true){
    rlutil::setColor(rlutil::WHITE);
    cin.ignore();
    rlutil::locate(40,9);cout << "INGRESE LA MARCA QUE DESEA MODIFICAR: ";
    cin.getline(nombre,10);
     if(validarNombreApellido(nombre)){
        if(buscarMarca(nombre)==false)
            {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate(45,13);cout<<"MARCA INGRESADA NO EXISTE"<<endl;
                    rlutil::anykey();

                }else{break;}
        }else{
        rlutil::setColor(rlutil::RED);
                    rlutil::locate(43,13);cout<<"FAVOR DE COLOCAR UNA MARCA VALIDA"<<endl;
                    rlutil::anykey();
        }
}
    pos = buscarMarcaModificar(nombre);
    if (pos >= 0){
         cin.ignore();
         while(true){
       rlutil::locate(40,11);cout << "INGRESE LA MODIFICACION: ";
        cin.getline(nombres,10);
        if(validarNombreApellido(nombres)){
               m.setNombre(nombres);
               m.guardarEnDiscoMarca(pos);
               break;
                 }else {
                    cout<<"MARCA INGRESADA INVALIDA"<<endl;
                    system("pause");
              }
        }
        return true;

}

}
