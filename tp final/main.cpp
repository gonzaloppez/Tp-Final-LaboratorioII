#include <iostream>
using namespace std;
#include <stdlib.h>
#include "marca.h"
#include "menu.h"
#include "ingreso.h"
#include "funciones.h"

int main()
{
    while(true){
    int opcion;
    cout<<"-MENU PRINCIPAL-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Ingreso al taller  "<<endl;
    cout<<" -2 Ficha cliente  "<<endl;
    cout<<" -3 Clientes  "<<endl;
    cout<<" -4 Vehiculos  "<<endl;
    cout<<" -5 Insumos  "<<endl;
    cout<<" -6 Reportes  "<<endl;
    cout<<" -7 Configuraciones  "<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingresar opcion: ";
    cin>>opcion;


        switch (opcion){

        case 1:
            int opc;
            Ingreso alta;
            alta.cargarIngreso();
            cout<<"Presione 1 para guardar ingreso : ";
            cin>>opc;
            if(opc==1)
            {
                if(alta.guardarIngreso()==true)
                {
                    cout<<"El ingreso se guardo correctamente, para revisarlo vaya a ficha del cliente"<<endl;
                    system("pause");
                    system("cls");
                }else{
                    cout<<"ATENCION, el registro no se grabo"<<endl;
                    system("pause");
                }
            }
        break;
        case 2:
            char pat[7];
            cout<<"Ingrese patente para visualizar ficha del cliente: ";
            cin.ignore();
            cin.getline(pat,7);
            if(alta.buscarPatente(pat)==true){
                alta.mostrarFichaCliente();
            }else{
                cout<<"Patente no existe"<<endl;
                system("pause");
            }
        break;
        case 3:

        break;
        case 4:
            system("cls");
            menuAuto();
            system("cls");
        break;
        case 5:

        break;
        case 6:
            int contras;
            Clave c;
            cout<<"Ingrese la clave de acceso a los reportes: ";
            cin>>contras;
            if(c.verificarClave(contras))
            {
                cout<<"Aceeso autorizado"<<endl;
                system("pause");
                menuReportes();
            }

        break;
        case 7:
            menuConfiguracion();
        break;
        case 0:
            return 0;
        break;
             }
    }

}



