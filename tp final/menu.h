#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "marca.h"
#include "clave.h"
#include "clientes.h"

void menuConfiguracion(){

    while(true){
    system("cls");
    int opcionConf;
    cout<<"-MENU Vehiculos-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Realizar Backup  "<<endl;
    cout<<" -2 Restaurar backup  "<<endl;
    cout<<" -3 Generar contrasenia "<<endl;
    cout<<" -0 Salir"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcionConf;

    switch(opcionConf)
    {


    case 1:
        break;
    case 2:
            break;
        case 3:
            Clave c;
            if(c.establecerClave()==true)
            {

                if(c.cambiarClave())
                {
                  cout<<"La clave ha sido modificada y guardada con exito"<<endl;
                    system("pause");
                }else {
                cout<<"La clave no ha sido modificada"<<endl;
                system("pause");
                }
                }

            break;
        case 0:
            return;
            break;
}
}
}

void menuAuto(){

while(true){
    system("cls");
    int opc;
    cout<<"-MENU Vehiculos-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Agregar Marca  "<<endl;
    cout<<" -2 Agregar Modelo  "<<endl;
    cout<<" -3 Ver marcas   "<<endl;
    cout<<" -3 Ver modelos   "<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";

    cin>>opc;

       switch(opc){

        case 1:

            Marca m;
            if(m.cargarMarca())
            {
                if(m.guardarEnDiscoMarca()){
                cout<<"Se agrego marca"<<endl;
                system("pause");
            }
                            }
            break;
        case 2:
            break;
        case 3:
             m.leerDeDiscoMarca();
            break;
        case 0:
            return;
            break;
    }

}

}

void menuReportes(){

    cout<<"Bienvenido a la matrix"<<endl;
system("pause");
}

void menuClientes(){

while(true){
    system("cls");
    int opc;
    cout<<"-MENU CLIENTES-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Agregar Clientes  "<<endl;
    cout<<" -2 Buscar Clientes  "<<endl;
    cout<<" -3 Ver todos los clientes"<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";

    cin>>opc;

       switch(opc){

        case 1:
            Clientes clien;
            if(clien.cargarCliente())
                {
                    if(clien.guardarEnDiscoClientes())
                    {
                        cout<<"Se guardo cliente en disco"<<endl;
                        system("pause");
                    }else{
                        cout<<"No se pudo guardar registro en disco"<<endl;
                    }
                }else{
                    cout<<"Error al ingresar alguno de los campos"<<endl;
                    }
            break;
        case 2:
            int dniBuscar;
            cout<<"Ingrese DNI del cliente a buscar:";
            cin>>dniBuscar;
            clien.buscarClientesPorDni(dniBuscar);
            break;
        case 3:
            cout<<"LISTADO DE CLIENTES"<<endl;
            clien.leerClientesDeDisco();

            break;
        case 0:
            return;
            break;
    }

}

}


 ///listarArchivoMarca();
    ///Marca m;
    ///for (int i=0;i<2;i++){
    ///    system("cls");
    ///m.agregarMarca();
    ///m.guardarEnDiscoMarca();

    ///}


#endif // MENU_H_INCLUDED
