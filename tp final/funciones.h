#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string.h>

void recuadro(){
  int x=0;
  for(x=1;x<=120;x++)
  {
    gotoxy(x,1);printf("_");
    gotoxy(x,5);printf("_");
    gotoxy(100,4);printf("JM CUSTOME GARAGE ");

    if(x<=24)
    {
      gotoxy(1,5);printf("_");
      gotoxy(120,5);printf("_");
    }
  }

}

bool validarNombreApellido(char *nombre){
if (nombre[0]!='\0')
    {
              return true;
    }else{
        return false;
    }

    }

bool validarDNI(int _dni){
    if(_dni>5000000 && _dni<99999999)
    {
        return true;
    }else{
    return false;
    }
}

void presentacion(){

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    rlutil::setColor(rlutil::RED);
    cout<<"                 "<<"*********************************************************************************"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"                 "<<"*    $$$$$$$$$$$$   $$$$$$$$$    $$       $$         $$$$$$$$   $$$$$$$$$       *"<<endl;
    cout<<"                 "<<"*        $$$        $$     $$    $$       $$         $$         $$     $$       *"<<endl;
    cout<<"                 "<<"*        $$$        $$     $$    $$       $$         $$$$$$$$   $$     $$       *"<<endl;
    cout<<"                 "<<"*        $$$        $$$$$$$$$    $$       $$         $$$$$$$$   $$$$$$$         *"<<endl;
    cout<<"                 "<<"*        $$$        $$     $$    $$       $$         $$         $$     $$       *"<<endl;
    cout<<"                 "<<"*        $$$        $$     $$    $$$$$$$$ $$$$$$$$   $$$$$$$$   $$     $$       *"<<endl;
    rlutil::setColor(rlutil::RED);
    cout<<"                 "<<"********************************************************************Gonzalo Lopez"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                                    ";rlutil::anykey();




}

#endif // FUNCIONES_H_INCLUDED
