#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED

#include <stdlib.h>
#include <cstdio>

void copiaDeSeguridadIngreso(Auto *ing){

    FILE *pIngreso,*pAuxIngreso;
    pIngreso = fopen("ingresos.dat","rb");
    if (pIngreso==NULL){ cout<<"No se pudo abrir archivos de ingresos"<<endl; system("pause"); return;}

    pAuxIngreso = fopen("ingresos.bkp","ab");
    if (pAuxIngreso==NULL){ cout<<"No se pudo generar backup de ingresos"<<endl; system("pause"); return;}

    while(fread(&ing,sizeof(Auto),1,pIngreso)==1){
        fwrite(&ing,sizeof(Auto),1,pAuxIngreso);
    }
    fclose(pIngreso);
    fclose(pAuxIngreso);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se realizo el backup correspondiente"<<endl;
    rlutil::anykey();

}

void restaurarBkpIngreso(Auto *ing){

    FILE *pIngreso,*pAuxIngreso;
    pAuxIngreso = fopen("ingresos.bkp","rb");
    if (pAuxIngreso==NULL){ cout<<"No se pudo abrir el archivo de ingresos"<<endl; system("pause"); return;}

    pIngreso = fopen("ingresos.dat","wb");
    if (pIngreso==NULL){ cout<<"No se pudo abrir archivos de ingresos"<<endl; system("pause"); return;}

    while(fread(&ing,sizeof(Auto),1,pAuxIngreso)==1){
        fwrite(&ing,sizeof(Auto),1,pIngreso);
    }
    fclose(pIngreso);
    fclose(pAuxIngreso);
rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se restauro el backup correspondiente"<<endl;
    rlutil::anykey();

}

void copiaDeSeguridadMarca(Marca *m){

    FILE *pMarca,*pAuxMarca;
    pMarca = fopen("marcas.dat","rb");
    if (pMarca==NULL){ cout<<"No se pudo abrir archivos de marcas"<<endl; system("pause"); return;}

    pAuxMarca = fopen("marcas.bkp","ab");
    if (pAuxMarca==NULL){ cout<<"No se pudo generar backup de marcas"<<endl; system("pause"); return;}

    while(fread(&m,sizeof(Marca),1,pMarca)==1){
        fwrite(&m,sizeof(Marca),1,pAuxMarca);
    }
    fclose(pMarca);
    fclose(pAuxMarca);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se realizo el backup correspondiente"<<endl;
    rlutil::anykey();

}

void restaurarBkpMarca(Marca *m){

    FILE *pMarca,*pAuxMarca;
    pAuxMarca = fopen("marcas.bkp","rb");
    if (pAuxMarca==NULL){ cout<<"No se pudo abrir el archivo de marcas"<<endl; system("pause"); return;}

    pMarca = fopen("marcas.dat","wb");
    if (pMarca==NULL){ cout<<"No se pudo abrir archivos de marcas"<<endl; system("pause"); return;}

    while(fread(&m,sizeof(Auto),1,pAuxMarca)==1){
        fwrite(&m,sizeof(Auto),1,pMarca);
    }
    fclose(pMarca);
    fclose(pAuxMarca);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se restauro el backup correspondiente"<<endl;
    rlutil::anykey();
}

void copiaDeSeguridadModelo(Modelo *mod){

    FILE *pModelo,*pAuxModelo;
    pModelo = fopen("modelos.dat","rb");
    if (pModelo==NULL){ cout<<"No se pudo abrir archivos de modelo"<<endl; system("pause"); return;}

    pAuxModelo = fopen("modelos.bkp","ab");
    if (pAuxModelo==NULL){ cout<<"No se pudo generar backup de modelos"<<endl; system("pause"); return;}

    while(fread(&mod,sizeof(Modelo),1,pModelo)==1){
        fwrite(&mod,sizeof(Modelo),1,pAuxModelo);
    }
    fclose(pModelo);
    fclose(pAuxModelo);
    rlutil::setColor(rlutil::GREEN);
     rlutil::locate(40,20);cout<<"Se realizo el backup correspondiente"<<endl;
    rlutil::anykey();

}

void restaurarBkpModelo(Modelo *mod){

    FILE *pModelo,*pAuxModelo;
    pAuxModelo = fopen("modelos.bkp","rb");
    if (pAuxModelo==NULL){ cout<<"No se pudo abrir el archivo de modelos"<<endl; system("pause"); return;}

    pModelo = fopen("modelos.dat","wb");
    if (pModelo==NULL){ cout<<"No se pudo abrir archivos de modelos"<<endl; system("pause"); return;}

    while(fread(&mod,sizeof(Modelo),1,pAuxModelo)==1){
        fwrite(&mod,sizeof(Modelo),1,pModelo);
    }
    fclose(pModelo);
    fclose(pAuxModelo);
rlutil::setColor(rlutil::GREEN);
     rlutil::locate(40,20);cout<<"Se restauro el backup correspondiente"<<endl;
    rlutil::anykey();
}

void copiaDeSeguridadClientes(Clientes *cli){

    FILE *pCliente,*pAuxCliente;
    pCliente = fopen("clientes.dat","rb");
    if (pCliente==NULL){ cout<<"No se pudo abrir archivos de clientes"<<endl; system("pause"); return;}

    pAuxCliente = fopen("clientes.bkp","ab");
    if (pAuxCliente==NULL){ cout<<"No se pudo generar backup de clientes"<<endl; system("pause"); return;}

    while(fread(&cli,sizeof(Clientes),1,pCliente)==1){
        fwrite(&cli,sizeof(Clientes),1,pAuxCliente);
    }
    fclose(pCliente);
    fclose(pAuxCliente);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se realizo el backup correspondiente"<<endl;
    rlutil::anykey();

}

void restaurarBkpCliente(Clientes *cli){

    FILE *pCliente,*pAuxCliente;
    pAuxCliente = fopen("clientes.bkp","rb");
    if (pAuxCliente==NULL){ cout<<"No se pudo abrir el archivo de clientes"<<endl; system("pause"); return;}

    pCliente = fopen("clientes.dat","wb");
    if (pCliente==NULL){ cout<<"No se pudo abrir archivos de clientes"<<endl; system("pause"); return;}

    while(fread(&cli,sizeof(Clientes),1,pAuxCliente)==1){
        fwrite(&cli,sizeof(Clientes),1,pCliente);
    }
    fclose(pCliente);
    fclose(pAuxCliente);
rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se restauro el backup correspondiente"<<endl;
    rlutil::anykey();

}

void copiaDeSeguridad(Auto *ing,Marca *m,Modelo *mod,Clientes *cli){

    FILE *pIngreso,*pAuxIngreso, *pMarca,*pAuxMarca,*pModelo,*pAuxModelo,*pCliente,*pAuxCliente;

    pIngreso = fopen("ingresos.dat","rb");
    if (pIngreso==NULL){ cout<<"No se pudo abrir archivos de ingresos"<<endl; system("pause"); return;}

    pAuxIngreso = fopen("ingresos.bkp","ab");
    if (pAuxIngreso==NULL){ cout<<"No se pudo generar backup de ingresos"<<endl; system("pause"); return;}

    pMarca = fopen("marcas.dat","rb");
    if (pMarca==NULL){ cout<<"No se pudo abrir archivos de marcas"<<endl; system("pause"); return;}

    pAuxMarca = fopen("marcas.bkp","ab");
    if (pAuxMarca==NULL){ cout<<"No se pudo generar backup de marcas"<<endl; system("pause"); return;}

    pModelo = fopen("modelos.dat","rb");
    if (pModelo==NULL){ cout<<"No se pudo abrir archivos de modelo"<<endl; system("pause"); return;}

    pAuxModelo = fopen("modelos.bkp","ab");
    if (pAuxModelo==NULL){ cout<<"No se pudo generar backup de modelos"<<endl; system("pause"); return;}

    pCliente = fopen("clientes.dat","rb");
    if (pCliente==NULL){ cout<<"No se pudo abrir archivos de clientes"<<endl; system("pause"); return;}

    pAuxCliente = fopen("clientes.bkp","ab");
    if (pAuxCliente==NULL){ cout<<"No se pudo generar backup de clientes"<<endl; system("pause"); return;}

    while(fread(&ing,sizeof(Auto),1,pIngreso)==1){
        fwrite(&ing,sizeof(Auto),1,pAuxIngreso);
    }while(fread(&m,sizeof(Marca),1,pMarca)==1){
        fwrite(&m,sizeof(Marca),1,pAuxMarca);
    }while(fread(&mod,sizeof(Modelo),1,pModelo)==1){
        fwrite(&mod,sizeof(Modelo),1,pAuxModelo);
    }while(fread(&ing,sizeof(Clientes),1,pCliente)==1){
        fwrite(&ing,sizeof(Clientes),1,pAuxCliente);
    }

    fclose(pIngreso);
    fclose(pAuxIngreso);
    fclose(pMarca);
    fclose(pAuxMarca);
    fclose(pModelo);
    fclose(pAuxModelo);
    fclose(pCliente);
    fclose(pAuxCliente);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se realizo el backup correspondiente"<<endl;
    rlutil::anykey();
}

void restaurarBkp(Auto *ing,Marca *m,Modelo *mod,Clientes *cli){

    FILE *pIngreso,*pAuxIngreso, *pMarca,*pAuxMarca,*pModelo,*pAuxModelo,*pCliente,*pAuxCliente;

    pAuxIngreso = fopen("ingresos.bkp","rb");
    if (pAuxIngreso==NULL){ cout<<"No se pudo abrir el archivo de ingresos"<<endl; system("pause"); return;}

    pIngreso = fopen("ingresos.dat","wb");
    if (pIngreso==NULL){ cout<<"No se pudo abrir archivos de ingresos"<<endl; system("pause"); return;}
    pAuxMarca = fopen("marcas.bkp","rb");
    if (pAuxMarca==NULL){ cout<<"No se pudo abrir el archivo de marcas"<<endl; system("pause"); return;}

    pMarca = fopen("marcas.dat","wb");
    if (pMarca==NULL){ cout<<"No se pudo abrir archivos de marcas"<<endl; system("pause"); return;}
    pAuxModelo = fopen("modelos.bkp","rb");
    if (pAuxModelo==NULL){ cout<<"No se pudo abrir el archivo de modelos"<<endl; system("pause"); return;}

    pModelo = fopen("modelos.dat","wb");
    if (pModelo==NULL){ cout<<"No se pudo abrir archivos de modelos"<<endl; system("pause"); return;}pAuxCliente = fopen("clientes.bkp","rb");
    if (pAuxCliente==NULL){ cout<<"No se pudo abrir el archivo de clientes"<<endl; system("pause"); return;}

    pCliente = fopen("clientes.dat","wb");
    if (pCliente==NULL){ cout<<"No se pudo abrir archivos de clientes"<<endl; system("pause"); return;}

     while(fread(&ing,sizeof(Auto),1,pAuxIngreso)==1){
        fwrite(&ing,sizeof(Auto),1,pIngreso);
    }while(fread(&m,sizeof(Marca),1,pAuxMarca)==1){
        fwrite(&m,sizeof(Marca),1,pMarca);
    }while(fread(&mod,sizeof(Modelo),1,pAuxModelo)==1){
        fwrite(&mod,sizeof(Modelo),1,pModelo);
    }while(fread(&cli,sizeof(Clientes),1,pAuxCliente)==1){
        fwrite(&cli,sizeof(Clientes),1,pCliente);
    }

    fclose(pIngreso);
    fclose(pAuxIngreso);
    fclose(pMarca);
    fclose(pAuxMarca);
    fclose(pModelo);
    fclose(pAuxModelo);
    fclose(pCliente);
    fclose(pAuxCliente);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40,20);cout<<"Se restauro el backup correspondiente"<<endl;
    rlutil::anykey();
}
#endif // CONFIGURACIONES_H_INCLUDED
