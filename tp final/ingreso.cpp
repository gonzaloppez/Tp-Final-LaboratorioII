#include <iostream>
using namespace std;
#include <cstdio>
#include <stdlib.h>
#include <string.h>
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

float Auto::getKm(){
    return km;
}
float Auto::getImporte(){
    return importe;
}


void buscarPatente(char *pat){
    Auto ing;
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


    cout<<"MARCA: "<<marca<<endl;
    cout<<"MODELO: "<<modelo<<endl;
    cout<<"COMBUSTIBLE: "<<combustible<<endl;
    cout<<"PATENTE: "<<patente<<endl;
    cout<<"FALLA DEL AUTO: "<<falla<<endl;
    Clientes cli = getCliente();
    cout<<"CLIENTE: "<<cli.getNombre()<<", "<<cli.getApellido()<<endl;///
    cout<<"DNI: "<<cli.getDni()<<endl;///
    cout<<"TELEFONO: "<<cli.getTelefono()<<endl;///
    cout<<"KM: "<<km<<endl;
    cout<<"IMPORTE: "<<importe<<endl;
    cout<<"FECHA DE INGRESO AL TALLER: ";
    fe.mostrar();
    cout<<"--------------------------------------------------"<<endl;

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
    Modelo mod;
    Marca m;

    cout<<"Ingresar Marca: ";
    cin.ignore();
    cin.getline(marca,20);
    if(buscarMarca(marca)==false)
        {
        return false;
        }

    cout<<"Ingresar Modelo: ";
    cin.getline(modelo,20);
    if(buscarModelo(modelo)==false)
        {
        return false;
        }

    cout<<"Ingresar combustible: ";
    cin.getline(combustible,10);
    if (combustible[0]=='\0')
    {
        return false;
    }

    cout<<"Ingresar patente: ";
    cin.getline(patente,7);
    if (patente[0]=='\0')
    {
        return false;
    }

    cout<<"Falla del auto: ";
    cin.getline(falla,50);
    if (falla[0]=='\0')
    {
        return false;
    }
    cin.ignore();

    int pos;
    cout<<"DNI: ";
    cin>>dni;
    pos = buscarPorDni(dni);
    if (pos >= 0){
        Clientes cli;
        cli.leerClientesDeDisco(pos);
        cli.mostrarClientesIngreso();
    }else{
        return false;
    }

    cout<<"Ingresar cantidad de KM: ";
    cin>>km;
    if (km<=0)
    {
        return false;
    }

    cout<<"Ingrese importe cobrado: $";
    cin>>importe;
    if (importe<=0)
    {
        return false;
    }
    system("pause");

    cout<<"Fecha de ingreso: "<<endl;
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
    char pat[7];
    int pos;
    cout << "Ingrese patente para buscar ficha: ";
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


