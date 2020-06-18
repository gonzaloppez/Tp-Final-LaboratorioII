#include <iostream>
using namespace std;
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include "ingreso.h"
#include "fecha.h"

bool Ingreso::buscarPatente(char *pat){

    system("cls");
    FILE *p;
    p = fopen("ingresos.dat","rb");
    if (p==NULL){return false;}
    while(fread(this,sizeof(Ingreso),1,p))
    {
        if(strcmp(pat,patente)==0)
        {
            fclose(p);
            return true;
        }
    }
     fclose(p);
    return false;

}


void Ingreso::mostrarFichaCliente(){
    system("cls");
    cout<<"MARCA: "<<marca<<endl;
    cout<<"MODELO: "<<modelo<<endl;
    cout<<"COMBUSTIBLE: "<<combustible<<endl;
    cout<<"PATENTE: "<<patente<<endl;
    cout<<"FALLA DEL AUTO: "<<falla<<endl;
    cout<<"CLIENTE: "<<nombreCliente<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<"KM: "<<km<<endl;
    cout<<"IMPORTE: "<<importe<<endl;
    cout<<"FECHA DE INGRESO AL TALLER: ";
    fe.mostrar();
    system("pause");
    system("cls");
}

bool Ingreso::guardarIngreso(){
    FILE *p;
    p = fopen("ingresos.dat","ab");
    if(p==NULL){cout<<"No se pudo abrir archivo"<<endl; return false;}
    fwrite(this,sizeof(Ingreso),1,p);
    fclose(p);
    return true;
}

void Ingreso::cargarIngreso(){
    system("cls");

    cout<<"Ingresar Marca: ";
    cin.ignore();
    cin.getline(marca,20);

    cout<<"Ingresar Modelo: ";
    cin.getline(modelo,20);

    cout<<"Ingresar combustible: ";
    cin.getline(combustible,10);

    cout<<"Ingresar patente: ";
    cin.getline(patente,7);

    cout<<"Falla del auto: ";
    cin.getline(falla,50);

    cout<<"Cliente del auto: ";
    cin.getline(nombreCliente,30);
    cin.ignore();

    cout<<"DNI: ";
    cin>>dni;

    cout<<"Telefono: ";
    cin>>telefono;

    cout<<"Ingresar cantidad de KM: ";
    cin>>km;

    cout<<"Ingrese importe cobrado: $";
    cin>>importe;
    system("pause");

    cout<<"Fecha de ingreso: ";
    fe.cargar();

   }

