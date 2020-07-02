#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include "rlutil.h"
#include "marca.h"
#include "menu.h"
#include "ingreso.h"
#include "funciones.h"




int main()
{

    presentacion();
    setlocale(LC_ALL, "Spanish");
    while(true){
    system("cls");
    int opcion;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(47,9);cout<<"-MENU PRINCIPAL-"<<endl;
    rlutil::locate(42,10);cout<<"****************************"<<endl;
    rlutil::locate(42,11);cout<<"*   1- INGRESO AL TALLER   *"<<endl;
    rlutil::locate(42,12);cout<<"*   2- FICHA TECNICA       *"<<endl;
    rlutil::locate(42,13);cout<<"*   3- CLIENTES            *"<<endl;
    rlutil::locate(42,14);cout<<"*   4- VEHICULOS           *"<<endl;
    rlutil::locate(42,15);cout<<"*   5- REPORTES            *"<<endl;
    rlutil::locate(42,16);cout<<"*   6- CONFIGURACIONES     *"<<endl;
    rlutil::locate(42,17);cout<<"*   0- Salir               *"<<endl;
    rlutil::locate(42,18);cout<<"****************************"<<endl;
    rlutil::locate(47,19);cout<<"INGRESAR OPCION: ";
    cin>>opcion;


        switch (opcion){

        case 1:
                if(nuevoIngreso())
                {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(40,20);cout<<"El registro del auto se guardo correctamente"<<endl;
                rlutil::anykey();
                }else {
                rlutil::setColor(rlutil::RED);
                rlutil::locate(47,19);cout<<"REGISTRO INCORRECTO  "<<endl;
                rlutil::locate(45,20);cout<<"El registro no se guardo"<<endl;
                rlutil::anykey();
                }
break;
        case 2:
            buscarIngreso();
        break;
        case 3:
            system("cls");
            menuClientes();
        break;
        case 4:
            system("cls");
            menuVehiculo();
            system("cls");
        break;
        case 5:
            menuReportes();
        break;
        case 6:
            menuConfiguracion();
        break;
        case 0:
            return 0;
        break;
        default:
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47,19);cout<<"Opción incorrecta  "<<endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::BLACK);
             }
    }

   }

