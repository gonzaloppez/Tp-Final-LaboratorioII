#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "ingreso.h"
#include "marca.h"
#include "clave.h"
#include "clientes.h"
#include "modelo.h"
#include "configuraciones.h"
#include "reportes.h"

void menuConfiguracion(){

    while(true){
    system("cls");
    int opcionConf;
    cout<<"-MENU CONFIGURACION-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Realizar Backup  "<<endl;
    cout<<" -2 Restaurar backup  "<<endl;
    cout<<" -3 Generar contraseña "<<endl;
    cout<<" -0 Salir"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcionConf;

    switch(opcionConf)
    {


    case 1:
            while(true){
            system("cls");
            int opcbkp;
            cout<<"-Realizar backup-"<<endl;
            cout<<"*************************"<<endl;
            cout<<" -1 Ingresos al taller  "<<endl;
            cout<<" -2 Marcas"<<endl;
            cout<<" -3 Modelos"<<endl;
            cout<<" -4 Clientes"<<endl;
            cout<<" -5 Todos los archivos"<<endl;
            cout<<" -6 Volver al menu"<<endl;
            cout<<"*************************"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcbkp;
            switch(opcbkp){
            case 1:
                Auto ing;
                copiaDeSeguridadIngreso(&ing);
                break;
            case 2:
                Marca m;
                copiaDeSeguridadMarca(&m);
                break;
            case 3:
                Modelo mod;
                copiaDeSeguridadModelo(&mod);
                break;
            case 4:
                Clientes cli;
                copiaDeSeguridadClientes(&cli);
                break;
            case 5:
                {

                Auto ing;
                Marca m;
                Modelo mod;
                Clientes cli;
                copiaDeSeguridad(&ing,&m,&mod,&cli);
                }
                break;
            case 6:
                return;
                break;
                }
                }

        break;
    case 2:
        while(true)
        {
            system("cls");
            int opcRes;
            cout<<"-Restaurar backup-"<<endl;
            cout<<"*************************"<<endl;
            cout<<" -1 Ingresos al taller"<<endl;
            cout<<" -2 Marcas"<<endl;
            cout<<" -3 Modelos"<<endl;
            cout<<" -4 Clientes "<<endl;
            cout<<" -5 Todos los archivos"<<endl;
            cout<<" -6 Volver al menu anterior"<<endl;
            cout<<"*************************"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcRes;
            switch(opcRes){
            case 1:
                Auto ing;
                restaurarBkpIngreso(&ing);
                break;
            case 2:
                Marca m;
                restaurarBkpMarca(&m);
                break;
            case 3:
                Modelo mod;
                restaurarBkpModelo(&mod);
                break;
            case 4:
                Clientes cli;
                restaurarBkpCliente(&cli);
                break;
            case 5:{
                Auto ing;
                Marca m;
                Modelo mod;
                Clientes cli;
                restaurarBkp(&ing,&m,&mod,&cli);
                }
                break;
            case 6:
                return;
                break;
            }


            }

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

void menuVehiculo(){

while(true){
    system("cls");
    int opc;
    cout<<"-MENU Vehículos-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Agregar Marca  "<<endl;
    cout<<" -2 Agregar Modelo  "<<endl;
    cout<<" -3 Ver marcas   "<<endl;
    cout<<" -4 Ver modelos   "<<endl;
    cout<<" -5 Modificar marca  "<<endl;
    cout<<" -6 Modificar modelos   "<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";

    cin>>opc;

       switch(opc){

        case 1:
             if(nuevaMarca())
                {
                    cout<<"La marca se guardo correctamente"<<endl;
                    system("pause");
                }else {
                cout<<"La marca no pudo guardarse"<<endl;
                system("pause");
                }
            break;
        case 2:
            if(nuevoModelo())
                {
                    cout<<"El modelo se guardo correctamente"<<endl;
                    system("pause");
                }else {
                cout<<"El modelo no pudo guardarse"<<endl;
                system("pause");
                }
            break;
        case 3:
             listarMarca();
            break;
         case 4:
             listarModelo();
            break;
        case 5:
             if(modificarMarca()==true)
                {
                 cout<<"La marca se modifico correctamente"<<endl;
                 system("pause");
                }else {
                cout<<"La marca no pudo modificarse"<<endl;
                 system("pause");
                }
            break;
        case 6:
             if(modificarModelo()==true)
                {
                 cout<<"El modelo se modifico correctamente"<<endl;
                 system("pause");
                }else{
                cout<<"El modelo no pudo modificarse"<<endl;
                 system("pause");
                }
            break;

        case 0:
            return;
            break;
    }
}
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
    cout<<" -4 Editar cliente"<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opción: ";

    cin>>opc;

       switch(opc){

        case 1:
            if(nuevoCliente())
                {
                    cout<<"El cliente se guardo correctamente"<<endl;
                    system("pause");
                }else {
                cout<<"El cliente no se guardo"<<endl;
                system("pause");
                }
            break;
        case 2:
            buscarCliente();
            break;
        case 3:
            listarClientes();
            break;
        case 4:
            if(modificarCliente()==true)
                {
                cout<<"El cliente se modifico correctamente"<<endl;
                    system("pause");
                }else {
                cout<<"El cliente no pudo ser modificado"<<endl;
                    system("pause");
                }
            break;
        case 0:
            return;
            break;
    }

}

}

void menuReportes(){

while(true){
    system("cls");
    int opc;
    cout<<"-MENU REPORTES-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Recaudacion Anual  "<<endl;
    cout<<" -2 Recaudacion por cliente"<<endl;
    cout<<" -3 Cantidad de autos ingresados por fecha "<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingrese una opcion: ";

    cin>>opc;

       switch(opc){

        case 1:
            recaudacionAnual();
            break;
        case 2:
            break;
        case 3:
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
