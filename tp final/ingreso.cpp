#include <iostream>
using namespace std;
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include "rlutil.h"
#include "ingreso.h"
#include "marca.h"
#include "modelo.h"
#include "fecha.h"



///SETS
void Auto::setMarca(char *_marca){
    strcpy(_marca,marca);
}

void Auto::setModelo(char *_modelo){
    strcpy(_modelo,modelo);
}



void Auto::setCombustible(char *_combustible){
    strcpy(_combustible,combustible);

}

void Auto::setPatente(char *_patente){
strcpy(_patente,patente);
}

void Auto::setFalla(char *_falla){
strcpy(_falla,falla);
}

void Auto::setKm(float _km){
    _km = km;
}

void Auto::setImporte(float _importe){
    _importe = importe;
}

///GETS

char* Auto::getMarca(){
    return marca;
}

char* Auto::getModelo(){
    return modelo;
}

char* Auto::getCombustible(){
    return combustible;
}
char* Auto::getPatente(){
    return patente;
}
char* Auto::getFalla(){
    return falla;
}
int   Auto::getDni(){
    return dni;
}
char   Auto::getNombre(){
    return nombre;
}
char   Auto::getApellido(){
    return apellido;
}

float Auto::getKm(){
    return km;
}
float Auto::getImporte(){
    return importe;
}



void buscarPatente(char *pat){

    Auto ing;
    int exp=0;
    system("cls");
    FILE *p;
    p = fopen("ingresos.dat","rb");
    if (p==NULL){return ;}
    while(fread(&ing,sizeof(Auto),1,p))
    {
        if(strcmp(pat,ing.getPatente())==0)
        {

            ing.mostrar();
        }
    }
     system("pause");
     fclose(p);
        }


void Auto::mostrar(){

    Clientes cli = getCliente();
    cout<<endl;
    cout<<endl;
    cout << setw(40)<<"               ";cout << "FICHA TECNICA CLIENTE PATENTE "<<patente<< endl;
    cout << setw(35)<<"               ";cout << "----------------------------------------------" << endl;
    cout<<endl;
    cout << left;
    cout<<"                         INGRESO AL TALLER: ";
    fe.mostrar();
    cout<<endl;
    cout << setw(25)<<"               ";
    cout << setw(15)<<"NOMBRE: ";
    cout << setw(15)<<"APELLIDO: ";
    cout << setw(10)<<"DNI: ";
    cout << setw(15)<<"TELEFONO: ";
    cout << setw(30)<<"MAIL: "<<endl;

    cout << setw(25)<<"               ";
    cout << setw(15)<<cli.getNombre();
    cout << setw(15)<<cli.getApellido();
    cout << setw(10)<<cli.getDni();
    cout << setw(15)<<cli.getTelefono();
    cout << setw(30)<<cli.getMail();

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << setw(25)<<"               ";
    cout<<"              MARCA: "<<marca<<"          MODELO: "<<modelo<<endl;
    cout<<endl;
    cout<<endl;
    cout << setw(25)<<"               ";
    cout<<"   COMBUSTIBLE: "<<combustible<<"                 KM: "<<km<<"                     IMPORTE: "<<importe;
    cout<<endl;
    cout<<endl;
    cout<<"                         FALLA DEL AUTO: "<<falla<<endl;
    cout<<endl;
     cout<<"                                                                           "<<endl;
    cout<<endl;

}

bool Auto::guardarIngreso(){
    FILE *p;
    p = fopen("ingresos.dat","ab");
    if(p==NULL){cout<<"No se pudo abrir archivo"<<endl; return false;}
    fwrite(this,sizeof(Auto),1,p);
    fclose(p);
    return true;
}

bool Auto::cargarIngreso(){

    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    Modelo mod;
    Marca m;

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(42,8);cout<<"DATOS DEL INGRESO VEHICULAR"<<endl;
    cout<<endl;
    rlutil::locate(47,9);cout<<"Marca : ";
    cin.ignore();
    cin.getline(marca,20);
    if(buscarMarca(marca)==false)
        {
        return false;
        }

    rlutil::locate(47,10);cout<<"Modelo: ";
    cin.getline(modelo,20);
    if(buscarModelo(modelo)==false)
        {
        return false;
        }

    rlutil::locate(47,11);cout<<"Combustible: ";
    cin.getline(combustible,10);
    if (combustible[0]=='\0')
    {
        return false;
    }

    rlutil::locate(47,12);cout<<"Patente: ";
    cin.getline(patente,7);
    if (patente[0]=='\0')
    {
        return false;
    }


    rlutil::locate(47,13);cout<<"Falla: ";
    cin.getline(falla,50);
    if (falla[0]=='\0')
    {
        return false;
    }


    int pos;
    rlutil::locate(47,14);cout<<"DNI: ";
    cin>>dni;
    pos = buscarPorDni(dni);
    if (pos < 0){
        return false;
    }

    rlutil::locate(47,15);cout<<"Cantidad de KM: ";
    cin>>km;
    if (km<=0)
    {
        return false;
    }

    rlutil::locate(47,16);cout<<"Importe cobrado: $";
    cin>>importe;
    if (importe<=0)
    {
        return false;
    }


    rlutil::locate(47,17);cout<<"Fecha de ingreso: "<<endl;
    if(fe.cargar()==false){
        return false;
    }
    return true;
   }

bool Auto::leerDeDisco(int pos){

    bool resultado = false;
    FILE *p;
    p = fopen("ingresos.dat","rb");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Auto), SEEK_SET);
        resultado = fread(this, sizeof(Auto), 1, p);
    }
    fclose(p);
    return resultado;
    }

bool Auto::leerDeDiscoDni(int busquedaDNI){

    FILE *p;
    p = fopen("ingresos.dat","rb");
    if (p == NULL){
        return false;
    }
    while(fread(this, sizeof(Auto), 1, p)){
          if(busquedaDNI==getDni())
            {
                return true;
            }
        fclose(p);
    }
    fclose(p);
    return false;
    }

bool nuevoIngreso(){
    Auto ing;
        if(ing.cargarIngreso()){
            if(ing.guardarIngreso()){
                return true;
            }
        }
}

  void buscarIngreso(){
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    char pat[7];
    int pos;
    rlutil::locate(35,8);cout << "INGRESE PATENTE PARA BUSCAR LA FICHA TECNICA: ";
    cin.ignore();
    cin.getline(pat,7);
    buscarPatente(pat);
}

Clientes Auto::getCliente(){
    Clientes cli;
    int pos;
    pos = buscarPorDni(dni);
    if (pos >= 0){
        cli.leerClientesDeDisco(pos);
    }
    else{
    }
    return cli;
}


Fecha Auto::getFecha()
{
    return fe;
}
