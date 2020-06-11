#include <iostream>
using namespace std;
#include "autos.h"

void Auto::agregarAuto(){
    cout<<"Ingresar Marca: ";
    cin.getline(marca,10);
    cout<<"Ingresar modelo: ";
    cin.getline(modelo,10);
    cin.ignore();
}

void Auto::mostrarAuto(){
    cout<<marca<<endl;
    cout<<modelo<<endl;
}

