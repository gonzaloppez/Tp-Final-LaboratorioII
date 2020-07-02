#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "ingreso.h"
#include "marca.h"
#include "clientes.h"
#include "modelo.h"
#include "configuraciones.h"
#include "reportes.h"
#include "funciones.h"

void menuConfiguracion(){

    while(true){
    system("cls");
    int opcionConf;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(47,9);cout<<"-MENU CLIENTES-"<<endl;
    rlutil::locate(42,10);cout<<"****************************"<<endl;
    rlutil::locate(42,11);cout<<"*   1- Realizar backup     *"<<endl;
    rlutil::locate(42,12);cout<<"*   2- Restaurar backup    *"<<endl;
    rlutil::locate(42,13);cout<<"*   0- Salir               *"<<endl;
    rlutil::locate(42,14);cout<<"****************************"<<endl;
    rlutil::locate(47,15);cout<<"Ingresar opción: ";
    cin>>opcionConf;

    switch(opcionConf)
    {


    case 1:
            while(true){
            system("cls");
            int opcbkp;
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::BLACK);
            recuadro();
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(47,9);cout<<"-MENU BAKCUP-"<<endl;
            rlutil::locate(42,10);cout<<"****************************"<<endl;
            rlutil::locate(42,11);cout<<"*   1- Ingresos al taller  *"<<endl;
            rlutil::locate(42,12);cout<<"*   2- Marcas              *"<<endl;
            rlutil::locate(42,13);cout<<"*   3- Modelos             *"<<endl;
            rlutil::locate(42,14);cout<<"*   4- Clientes            *"<<endl;
            rlutil::locate(42,15);cout<<"*   5- Todos los archivos  *"<<endl;
            rlutil::locate(42,16);cout<<"*   0- Volver              *"<<endl;
            rlutil::locate(42,17);cout<<"****************************"<<endl;
            rlutil::locate(47,18);cout<<"Ingresar opción: ";
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
            case 0:
                return;
                break;
                    default:
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47,18);cout<<"Opción incorrecta   "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
                }
                }

        break;
    case 2:
        while(true)
        {
            system("cls");
            int opcRes;
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::BLACK);
            recuadro();
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(47,9);cout<<"-MENU RESTAURACION-"<<endl;
            rlutil::locate(42,10);cout<<"****************************"<<endl;
            rlutil::locate(42,11);cout<<"*   1- Ingresos al taller  *"<<endl;
            rlutil::locate(42,12);cout<<"*   2- Marcas              *"<<endl;
            rlutil::locate(42,13);cout<<"*   3- Modelos             *"<<endl;
            rlutil::locate(42,14);cout<<"*   4- Clientes            *"<<endl;
            rlutil::locate(42,15);cout<<"*   5- Todos los archivos  *"<<endl;
            rlutil::locate(42,16);cout<<"*   0- Volver              *"<<endl;
            rlutil::locate(42,17);cout<<"****************************"<<endl;
            rlutil::locate(47,18);cout<<"Ingresar opción: ";
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
            case 0:
                return;
                break;
            default:
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47,18);cout<<"Opción incorrecta   "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
            }


            }

            break;
         case 0:
            return;
            break;
        default:
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47,15);cout<<"Opción incorrecta   "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
}
}
}

void menuVehiculo(){

while(true){
    system("cls");
    int opc;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(47,9);cout<<"-MENU AUTO-"<<endl;
    rlutil::locate(42,10);cout<<"****************************"<<endl;
    rlutil::locate(42,11);cout<<"*   1- Agregar marca       *"<<endl;
    rlutil::locate(42,12);cout<<"*   2- Agregar modelo      *"<<endl;
    rlutil::locate(42,13);cout<<"*   3- Ver marcas          *"<<endl;
    rlutil::locate(42,14);cout<<"*   4- Ver modelos         *"<<endl;
    rlutil::locate(42,15);cout<<"*   5- Modificar marca     *"<<endl;
    rlutil::locate(42,16);cout<<"*   6- Modificar modelo    *"<<endl;
    rlutil::locate(42,17);cout<<"*   0- Volver              *"<<endl;
    rlutil::locate(42,18);cout<<"****************************"<<endl;
    rlutil::locate(47,19);cout<<"Ingresar opción: ";
    cin>>opc;


       switch(opc){

        case 1:
             if(nuevaMarca())
                {
                    rlutil::setColor(rlutil::GREEN);
                    rlutil::locate(38,14);cout<<"LA MARCA SE GUARDO CORRECTAMENTE"<<endl;
                    rlutil::anykey();
                }else {
                    rlutil::setColor(rlutil::RED);
                rlutil::locate(40,14);cout<<"LA MARCA NO PUDO GUARDARSE"<<endl;
                rlutil::anykey();
                }
            break;
        case 2:
            if(nuevoModelo())
                {
                     rlutil::setColor(rlutil::GREEN);
                    rlutil::locate(38,14);cout<<"EL MODELO SE GUARDO CORRECTAMENTE"<<endl;
                    rlutil::anykey();
                }else {
                    rlutil::setColor(rlutil::GREEN);
                rlutil::locate(38,14);cout<<"EL MODELO NO PUDO GUARDARSE"<<endl;
                rlutil::anykey();
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
                rlutil::setColor(rlutil::GREEN);
                 rlutil::locate(40,13);cout<<" LA MARCA SE MODIFICO CORRECTAMENTE       "<<endl;
                  rlutil::anykey();
                }else {
                    rlutil::setColor(rlutil::RED);
                rlutil::locate(43,14);cout<<"LA MARCA NO PUDO MODIFICARSE"<<endl;
                  rlutil::anykey();
                }
            break;
        case 6:
             if(modificarModelo()==true)
                {
                 rlutil::setColor(rlutil::GREEN);
                 rlutil::locate(40,13);cout<<"EL MODELO SE MODIFICO CORRECTAMENTE       "<<endl;
                 rlutil::anykey();
                }else{
                     rlutil::setColor(rlutil::GREEN);
                rlutil::locate(40,13);cout<<"EL MODELO NO PUDO MODIFICARSE"<<endl;
                 rlutil::anykey();
                }
            break;
        case 0:
            return ;
            break;
        default:
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47,19);cout<<"Opción incorrecta   "<<endl;
            rlutil::setColor(rlutil::BLACK);

    }
}
}

void menuClientes(){

while(true){
    system("cls");
    int opc;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(47,9);cout<<"-MENU CLIENTES-"<<endl;
    rlutil::locate(42,10);cout<<"****************************"<<endl;
    rlutil::locate(42,11);cout<<"*   1- Agregar clientes    *"<<endl;
    rlutil::locate(42,12);cout<<"*   2- Buscar clientes     *"<<endl;
    rlutil::locate(42,13);cout<<"*   3- Ver clientes        *"<<endl;
    rlutil::locate(42,14);cout<<"*   4- Editar cliente      *"<<endl;
    rlutil::locate(42,15);cout<<"*   0- Volver              *"<<endl;
    rlutil::locate(42,16);cout<<"****************************"<<endl;
    rlutil::locate(47,17);cout<<"Ingresar opción: ";

    cin>>opc;

       switch(opc){

        case 1:
            if(nuevoCliente())
                {
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                 rlutil::locate(38,15);cout<<"El registro de cliente se guardo correctamente "<<endl;
                  rlutil::anykey();
                }else {

                rlutil::setColor(rlutil::RED);
                rlutil::locate(39,15);cout<<"El cliente no se guardo"<<endl;
                rlutil::anykey();
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
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate(40,32);cout<<"CLIENTE MODIFICADO CON EXITO"<<endl;
                    rlutil::anykey();
                }else {
                    rlutil::setColor(rlutil::RED);
                rlutil::locate(40,32);cout<<"NO SE MODIFICO CLIENTE"<<endl;
                    rlutil::anykey();
                }
            break;
        case 0:
            return;
            break;
        default:
                rlutil::setColor(rlutil::RED);
            rlutil::locate(47,17);cout<<"Opción incorrecta  "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
    }

}

}

void menuReportes(){

while(true){
    system("cls");
    int opc;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(50,9);cout<<"-MENU REPORTES-"<<endl;
    rlutil::locate(42,10);cout<<"********************************"<<endl;
    rlutil::locate(42,11);cout<<"*   1- Recaudación anual       *"<<endl;
    rlutil::locate(42,12);cout<<"*   2- Recaudación por cliente *"<<endl;
    rlutil::locate(42,13);cout<<"*   3- Recaudación por fecha   *"<<endl;
    rlutil::locate(42,14);cout<<"*   4- Cantidad de ingresos    *"<<endl;
    rlutil::locate(42,15);cout<<"*   5- Volver                  *"<<endl;
    rlutil::locate(42,16);cout<<"********************************"<<endl;
    rlutil::locate(47,17);cout<<"Ingresar opción: ";

    cin>>opc;

       switch(opc){

        case 1:
            recaudacionAnual();
            break;
        case 2:
            recaudacionCliente();
            break;
        case 3:
            recaudacionPorFecha();
            break;
        case 4:
            autosIngresados();
            break;
        case 0:
            return;
            break;
        default:
                rlutil::setColor(rlutil::RED);
            rlutil::locate(47,17);cout<<"Opción incorrecta  "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
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
