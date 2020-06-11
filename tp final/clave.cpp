#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include "clave.h"


bool Clave::cambiarClave(){
    bool escribio;
    FILE *p;
    p = fopen("clave.dat","ab");
    if (p==NULL){return false;}
    escribio=fwrite(this,sizeof(Clave),1,p);
    fclose(p);
    return escribio;
}

bool Clave::establecerClave(){
    cout<<"Genere clave de acceso a reportes: ";
    cin>>contra;
    return true;
}

bool Clave::verificarClave(int contras)
    {

        FILE *p;
        p=fopen("clave.dat","rb");
        if(p==NULL){return false;}
        while(fread(this,sizeof(Clave),1,p)==1)
        {

            if(contras==contra)
        {

            return true;
        }else{
            cout<<"Clave incorrecta"<<endl;

            system("pause");
            return false;
        }

        }
        return false;
    }
