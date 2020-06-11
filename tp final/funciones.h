#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string.h>

char contraseniaAcceso[10];

bool generarContrasenia(){
    char con[10];
    cout<<"Ingrese contrasenia: "<<endl;
    cin.ignore();
    cin.getline(con,10);

    strcpy(con,contraseniaAcceso);
    system("pause");
    return true;
}

bool verificacion(char *contraseniaAcceso){
    char contra[10];
    cout<<contraseniaAcceso<<endl;
    cout<<contraseniaAcceso<<endl;
    cout<<contraseniaAcceso<<endl;
    cout<<"Ingrese contraseña para ingresar"<<endl;
    cin.ignore();
    cin.getline(contra,10);
    system("pause");
    if (strcmp(contra,contraseniaAcceso)==0)
    {
        return true;
    }else{
        cout<<"La contraseña no coincide"<<endl;
    return false;
    }
}

bool accederContra(){
        if(verificacion(contraseniaAcceso)){
        return true;
        }else{
        return false;
        }
}





#endif // FUNCIONES_H_INCLUDED
