#include <iostream>
using namespace std;
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

bool Clientes::cargarCliente(){

    cout<<"Ingresar Nombre: ";
    cin.ignore();
    cin.getline(nombre,10);

    cout<<"Ingresar Apellido: ";
    cin.getline(apellido,10);

    cout<<"DNI: ";
    cin>>dni;
    cin.ignore();

    cout<<"Telefono: ";
    cin>>telefono;
    return true;
}

void Clientes::mostrarClientes(){

    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
}

bool Clientes::guardarEnDiscoClientes(){
    bool escribio;
    FILE *p;
    p = fopen("clientes.dat","ab");
    if (p==NULL){ return false;}
    escribio=fwrite(this,sizeof(Clientes),1,p);
    fclose(p);
    return escribio;
}

void Clientes::leerClientesDeDisco(){

    FILE *p;
    p = fopen("clientes.dat","rb");
    if (p==NULL){ return ;}
    while(fread(this,sizeof(Clientes),1,p))
    {
        mostrarClientes();
        cout<<endl<<endl;
    }
    system("pause");
    fclose(p);
    }

void Clientes::buscarClientesPorDni(int dniBuscar){

    FILE *p;
    p = fopen("clientes.dat","rb");
    if (p==NULL){ return ;}
    while(fread(this,sizeof(Clientes),1,p))
    {
        if(dniBuscar==dni)
        {
            mostrarClientes();
            system("pause");
        }

    }
    system("pause");
    fclose(p);
    }
