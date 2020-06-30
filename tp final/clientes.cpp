#include <iostream>
using namespace std;

#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "clientes.h"



void Clientes::setNombre(char *_nombre){
    strcpy(nombre,_nombre);
}
void Clientes::setApellido(char *_apellido){
    strcpy(apellido,_apellido);
}
void Clientes::setDni(int _dni){
    dni = _dni;
}
void Clientes::setTelefono(int _telefono){
    telefono=_telefono;
}
void Clientes::setMail(char *_mail){
    strcpy(mail,_mail);
}
char* Clientes::getNombre(){
    return nombre;
}
char* Clientes::getApellido(){
    return apellido;
}
int Clientes::getDni(){
    return dni;
}
int Clientes::getTelefono(){
    return telefono;
}
char* Clientes::getMail(){
    return mail;
}


bool nuevoCliente(){

    Clientes cli;
    if (cli.cargarCliente()){
        if (cli.guardarEnDiscoClientes()){
            return true;
        }
    }
    return false;
}

void listarClientes(){
    Clientes cli;
    int i = 0;
    system("cls");
    cout << "Listado de Clientes" << endl;
    cout << "------------------------" << endl;
    cout<<endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(15) << "Apellido";
    cout << setw(10) << "DNI";
    cout << setw(15) << "Telefono";
    cout << setw(30) << "Mail" << endl;

    while(cli.leerClientesDeDisco(i++)){
        cout << setw(15) << cli.getNombre();
        cout << setw(15) << cli.getApellido();
        cout << setw(10) << cli.getDni();
        cout << setw(15) << cli.getTelefono();
        cout << setw(30) << cli.getMail();
        cout << endl;
    }
    cin.ignore();
    system("pause");
}

bool validarMail(char *);

bool modificarCliente(){
    system("cls");

    int _dni;
    int pos;
    int opcion;
    cout << "Ingrese DNI del cliente: ";
    cin >> _dni;
    pos = buscarPorDni(_dni);
    if (pos >= 0){
        system("cls");
        Clientes cli;
        cli.leerClientesDeDisco(pos);
        cli.mostrarClientes();
    }else {
    cout<<"No existe cliente con ese DNI"<<endl;
    system("pause");
    return false;
}

        cout << endl;
        cout<<"Que desea modificar :"<<endl;
        cout<<"1 - Nombre" <<endl;
        cout<<"2 - Apellido" <<endl;
        cout<<"3 - DNI" <<endl;
        cout<<"4 - Telefono" <<endl;
        cout<<"5 - Mail" <<endl;
        cout<<"6 - Volver al menu anterior"<<endl;
        cout<<"OPCION: ";
        cin>>opcion;

        switch(opcion)
        {   Clientes cli;
        char nombre[15];
            case 1:
                while(true){
            cin.ignore();
            cout << "Nombre: ";
            cin.getline(nombre,15);

            if (nombre[0]!='\0')
            {
              break;
            }
            cout<<"Favor de ingresar un nombre válido!"<<endl;
            }


            cli.setNombre(nombre);
            if (cli.guardarEnDiscoClientes(pos)){
                                return true;
            }
            else{

                return false;
            }
        break;
            case 2:

            char apellido[15];
            while(true){
            cin.ignore();
            cout << "Apellido: ";

            cin.getline(apellido,15);
            if (apellido[0]!='\0')
            {

              break;
                }
                    cout<<"Favor de ingresar un apellido válido!"<<endl;
                }

            cli.setApellido(apellido);
            if (cli.guardarEnDiscoClientes(pos)){

                return true;
            }
            else{

                return false;
            }
                break;
            case 3:
                 int dni;
            cout << "DNI: ";
            cin>>dni;
            cli.setDni(dni);
            if (cli.guardarEnDiscoClientes(pos)){

                return true;
            }
            else{

                return false;
            }
                break;
            case 4:
                int tel;
            cout << "Telefono: ";
            cin>>tel;
            cli.setTelefono(tel);
            if (cli.guardarEnDiscoClientes(pos)){

                return true;
            }
            else{

                return false;
            }
                break;
            case 5:
            char mail[30];
            while(true){
                cin.ignore();
                cout << "Mail: ";
                cin.getline(mail,30);
                if(validarMail(mail)==true){
                cli.setMail(mail);
                break;
                }}
            if (cli.guardarEnDiscoClientes(pos)){

            return true;
            break;
            }
            else{

                return false;
                break;
            }


                break;
            case 6:
                return false;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                system("pause");
                break;
        }

   return false;
}



int buscarPorDni(int dni){

    Clientes cli;
    int i = 0;
    while(cli.leerClientesDeDisco(i)){
        if (cli.getDni() == dni){
            return i;
        }
        i++;
    }
    return -1;
}

void Clientes::mostrarClientes(){

    system("cls");
    cout << "Clientes" << endl;
    cout << "------------------------" << endl;
    cout<<endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(15) << "Apellido";
    cout << setw(10) << "DNI";
    cout << setw(15) << "Telefono";
    cout << setw(30) << "Mail";
    cout<<endl;
    cout << setw(15)  << nombre;
    cout << setw(15) << apellido;
    cout << setw(10) << dni;
    cout << setw(15) << telefono;
    cout << setw(30) << mail;
    cout << endl;
    system("pause");
}

void Clientes::mostrarClientesIngreso(){

    cout <<"Nombre: "<<nombre<<endl;
    cout <<"Apellido: "<<apellido<<endl;
    cout <<"DNI: "<<dni<<endl;
    cout <<"Telefono: "<<telefono<<endl;
    cout <<"Mail: "<<mail<<endl;
}

void buscarCliente(){
    system("cls");
    int dni;
    int pos;
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;
    pos = buscarPorDni(dni);
    if (pos >= 0){
        system("cls");
        Clientes cli;
        cli.leerClientesDeDisco(pos);
        cli.mostrarClientes();
    }
    else{
       cout<<"No existe el cliente"<<endl;
    }
    //anykey();
}

bool validarMail(char *mail)
{

    int tam;
    int contadorArrobas=0;
    tam=strlen(mail);
    for (int i=0; i<tam; i++)
    {

        if((mail[i]>=1 && mail[i]<=45) || (mail[i]>=58 && mail[i]<=63) || (mail[i]>=91 && mail[i]<=94) || (mail[i]>=123 && mail[i]<=249))
        {
            cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
            return false;
        }
        if (mail[0]=='@' || mail[0]=='.')
        {
            cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
            return false;
        }

        if (mail[i]=='@')
        {
            if((mail[i-1]>=1 && mail[i-1]<=48) || (mail[i-1]>=58 && mail[i-1]<=64) || (mail[i-1]>=91 && mail[i-1]<=96) || (mail[i-1]>=123 && mail[i-1]<=255) &&
                    (mail[i+1]>=1 && mail[i+1]<=48) || (mail[i+1]>=58 && mail[i+1]<=64) || (mail[i+1]>=91 && mail[i+1]<=96) || (mail[i+1]>=123 && mail[i+1]<=255) )
            {
                cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
                return false;
            }

        }
        if(mail[i]=='.')
        {
            if(mail[i-1]=='.' || mail[i+1]=='.')
            {
                cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
                return false;
            }
        }
        if (mail[i]=='@')
        {
            contadorArrobas=contadorArrobas+1;
            if (contadorArrobas==2)
            {
                cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
                return false;
            }

        }


    }
    if (contadorArrobas==0)
    {
        cout<<"El email ingresado es incorrecto , por favor ingreselo con el siguiente formato name@example.com"<<endl;
        return false;
    }
    return true;

}

bool Clientes::cargarCliente(){


    while(true){

    cout<<"Ingresar Nombre: ";
    cin.ignore();
    cin.getline(nombre,15);
    if (nombre[0]!='\0')
    {
              break;
    }
        cout<<"Favor de ingresar un nombre válido!"<<endl;
    }

    while(true){
    cout<<"Ingresar Apellido: ";
    cin.getline(apellido,15);
    if (apellido[0]!='\0')
    {
              break;
    }
        cout<<"Favor de ingresar un apellido válido!"<<endl;
    }

    while(true){
    cout<<"Ingresar mail: ";

    cin.getline(mail,30);
    if(validarMail(mail)==true){
        break;
        }
     }

    while(true){
    cin.ignore();
    cout<<"Ingrese DNI sin puntos: ";
    cin>>dni;
    if(dni>5000000 && dni<99999999){
        break;
    }
    cout<<"Favor de ingresar un DNI valido"<<endl;
    }


    cout<<"Ingrese teléfono sin espacios: ";
    cin>>telefono;
    return true;
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

bool Clientes::guardarEnDiscoClientes(int pos){

    bool resultado = false;
    FILE *p;
    p = fopen("clientes.dat","rb+");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Clientes), SEEK_SET);
        resultado = fwrite(this, sizeof(Clientes), 1, p);
    }
    fclose(p);
    return resultado;

}

bool Clientes::leerClientesDeDisco(int pos){

    bool resultado = false;
    FILE *p;
    p = fopen("clientes.dat","rb");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Clientes), SEEK_SET);
        resultado = fread(this, sizeof(Clientes), 1, p);
    }
    fclose(p);
    return resultado;
    }
