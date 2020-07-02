#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include "rlutil.h"
#include <iomanip>
#include "modelo.h"

void Modelo::setNombre(char *_nombre){
    strcpy(nombre,_nombre);
}
char* Modelo::getNombre(){
    return nombre;
}

void Modelo::setID(char *_ID){
    strcpy(_ID,ID);
}
char* Modelo::getID(){
    return ID;
}
///--------------------------------------------

bool Modelo::cargarModelo(){
    while(true){
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(45,9);cout<<"AGREGAR MODELO: ";
    rlutil::locate(40,10);cout << "-------------------------" << endl;
    rlutil::locate(44,12);cout<<"NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,10);
        if(validarNombreApellido(nombre)){
        if (buscarModelo(nombre))
        {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(42,14);cout<<"MODELO EXISTENTE"<<endl;
            rlutil::anykey();
        }else {
              return true;
            }

        }else{
            rlutil::setColor(rlutil::RED);
           rlutil::locate(42,14); cout<<"FAVOR DE COLOCAR UN MODELO VALIDO"<<endl;
            rlutil::anykey();
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
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    Modelo mod;
    int i = 0;
    rlutil::locate(48,9);cout << "LISTADO DE MODELOS" << endl;
    rlutil::locate(45,11);cout<< "------------------------" << endl;

    while(mod.leerDeDiscoModelo(i++)){
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(45,12+i);cout << mod.getNombre()<<endl;
    }
    cin.ignore();
    rlutil::anykey();

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
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    char nombre[10];
    char nombres[10];
    int pos;
    Modelo mod;
    while(true){
    rlutil::setColor(rlutil::WHITE);
    cin.ignore();
    rlutil::locate(40,9);cout << "INGRESE EL MODELO QUE DESEA MODIFICAR: ";
    cin.getline(nombre,10);
    if(validarNombreApellido(nombre)){
     if(buscarModelo(nombre)==false)
        {
         rlutil::setColor(rlutil::RED);
        rlutil::locate(45,13);cout<<"MODELO INGRESADA NO EXISTE"<<endl;
        rlutil::anykey();
        }else{break;}
    }else{
        rlutil::setColor(rlutil::RED);
        rlutil::locate(43,13);cout<<"FAVOR DE COLOCAR UN MODELO VALIDO"<<endl;
        rlutil::anykey();
        }
}
    pos = buscarModeloModificar(nombre);
    if (pos >= 0){
         cin.ignore();
         while(true){
       rlutil::locate(40,11);cout << "INGRESE MODIFICACION: ";
        cin.getline(nombres,10);
        if(validarNombreApellido(nombres)){
               mod.setNombre(nombres);
               mod.guardarEnDiscoModelo(pos);
               break;
                }else {
                    cout<<"MODELO INGRESADO INVALIDO"<<endl;
                    system("pause");
              }
        }

        return true;
    }
    }




