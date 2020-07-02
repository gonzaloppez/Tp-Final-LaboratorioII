#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include "rlutil.h"
#include "funciones.h"
#include <stdlib.h>
#include "ingreso.h"
#include "fecha.h"
#include "clientes.h"

void recaudacionAnual(){
    system("cls");
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::BLACK);
    recuadro();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    Auto ing;
    int acu1=0;int acu2=0; int acu3=0;int acu4=0;int acu5=0;int acu6=0;int acu7=0;int acu8=0;int acu9=0;int acu10=0;int acu11=0;int acu12=0;;
    int pos=0;
    int anioRecaudacion;
    rlutil::locate(45,9);cout<<"Ingrese año: " ;
    cin>>anioRecaudacion;
    while(ing.leerDeDisco(pos++))
        {
            if(anioRecaudacion==ing.getFecha().getAnio()){


                    if(ing.getFecha().getMes()==01)
                        {
                            acu1+=ing.getImporte();

                        }if(ing.getFecha().getMes()==02){
                                acu2+=ing.getImporte();
                            }if(ing.getFecha().getMes()==03){
                                acu3+=ing.getImporte();
                            }if(ing.getFecha().getMes()==04){
                                acu4+=ing.getImporte();
                            }if(ing.getFecha().getMes()==05){
                                acu5+=ing.getImporte();
                            }if(ing.getFecha().getMes()==06){
                                acu6+=ing.getImporte();
                            }if(ing.getFecha().getMes()==07){
                                acu7+=ing.getImporte();
                            }if(ing.getFecha().getMes()==8){
                                acu8+=ing.getImporte();
                            }if(ing.getFecha().getMes()==9){
                                acu9+=ing.getImporte();
                            }if(ing.getFecha().getMes()==10){
                                acu10+=ing.getImporte();
                            }if(ing.getFecha().getMes()==11){
                                acu11+=ing.getImporte();
                            }if(ing.getFecha().getMes()==12){
                                acu12+=ing.getImporte();
                            }

                    }


               }


                    rlutil::locate(40,11);cout<<"MES";
                    rlutil::locate(65,11);cout<<"Recaudacion";
                    rlutil::locate(28,12);cout<<"------------------------------------------------------------";
                    rlutil::locate(40,13);cout<<"Enero: ";
                    rlutil::locate(65,13);cout<<"$"<<acu1<<endl;
                    rlutil::locate(40,14);cout<<"Febrero: ";
                    rlutil::locate(65,14);cout<<"$"<<acu2<<endl;
                    rlutil::locate(40,15);cout<<"Marzo: ";
                    rlutil::locate(65,15);cout<<"$"<<acu3<<endl;
                    rlutil::locate(40,16);cout<<"Abril: ";
                    rlutil::locate(65,16);cout<<"$"<<acu4<<endl;
                    rlutil::locate(40,17);cout<<"Mayo: ";
                    rlutil::locate(65,17);cout<<"$"<<acu5<<endl;
                    rlutil::locate(40,18);cout<<"Junio: ";
                    rlutil::locate(65,18);cout<<"$"<<acu6<<endl;
                    rlutil::locate(40,19);cout<<"Julio: ";
                    rlutil::locate(65,19);cout<<"$"<<acu7<<endl;
                    rlutil::locate(40,20);cout<<"Agosto: ";
                    rlutil::locate(65,20);cout<<"$"<<acu8<<endl;
                    rlutil::locate(40,21);cout<<"Septiembre: ";
                    rlutil::locate(65,21);cout<<"$"<<acu9<<endl;
                    rlutil::locate(40,22);cout<<"Octubre: ";
                    rlutil::locate(65,22);cout<<"$"<<acu10<<endl;
                    rlutil::locate(40,23);cout<<"Noviembre: ";
                    rlutil::locate(65,23);cout<<"$"<<acu11<<endl;
                    rlutil::locate(40,24);cout<<"Diciembre: ";
                    rlutil::locate(65,24);cout<<"$"<<acu12<<endl;
                    rlutil::locate(40,25);cout<<"----------------------------------";
                    rlutil::setColor(rlutil::GREEN);
                    rlutil::locate(40,26);cout<<"Total: ";
                    rlutil::locate(65,26);cout<<"$"<<acu1+acu2+acu3+acu4+acu5+acu6+acu7+acu8+acu9+acu10+acu11+acu12<<endl;
                    rlutil::anykey();

}


void recaudacionCliente(){

    Auto ing;
    int acu=0;
    int pos=0;
    int busquedaDNI;
    rlutil::locate(41,20);cout<<"Ingrese DNI de cliente: " ;
    cin>>busquedaDNI;
    while(ing.leerDeDisco(pos++))
        {
            if(busquedaDNI==ing.getCliente().getDni()){
                    acu+=ing.getImporte();
                    rlutil::locate(41,23);cout<<"RECAUDACION CLIENTE DNI "<<ing.getCliente().getDni();;
                    rlutil::locate(30,24);cout<<"------------------------------------------------------------";
                    rlutil::locate(35,26);cout<<ing.getCliente().getNombre();
                    rlutil::locate(45,26);cout<<ing.getCliente().getApellido();

               }


        }rlutil::setColor(rlutil::GREEN);
rlutil::locate(65,26);cout<<"Total $"<<acu<<endl;
                    rlutil::anykey();

        }



void recaudacionPorFecha(){

    Auto ing;
    int acu=0;
    int pos=0;
    int d,m,a,d1,m1,a1;
    rlutil::locate(42,20);cout<<"Ingrese rango de fechas:"<<endl;
    rlutil::locate(30,22);cout<<"DIA ";
    cin>>d;
    rlutil::locate(38,22);cout<<"MES ";
    cin>>m;
    rlutil::locate(46,22);cout<<"AÑO: ";
    cin>>a;
    rlutil::locate(58,22);cout<<"DIA ";
    cin>>d1;
    rlutil::locate(66,22);cout<<"MES ";
    cin>>m1;
    rlutil::locate(74,22);cout<<"AÑO: ";
    cin>>a1;
    while(ing.leerDeDisco(pos++))
        {
            if((ing.getFecha().getMes()>=m && ing.getFecha().getMes()<=m1)
               && (ing.getFecha().getAnio()>=a && ing.getFecha().getAnio()<=a1 ))
                {
                acu+=ing.getImporte();
               }
                   }
                   rlutil::setColor(rlutil::GREEN);
                   rlutil::locate(42,26);cout<<"Total recaudado: $"<<acu<<endl;
        rlutil::anykey();
        }

void autosIngresados(){
    Auto ing;
    int acu=0;
    int pos=0;
    int d,m,a,d1,m1,a1;
    rlutil::locate(42,20);cout<<"Ingrese rango de fechas:"<<endl;
    rlutil::locate(30,22);cout<<"DIA ";
    cin>>d;
    rlutil::locate(38,22);cout<<"MES ";
    cin>>m;
    rlutil::locate(46,22);cout<<"AÑO: ";
    cin>>a;
    rlutil::locate(58,22);cout<<"DIA ";
    cin>>d1;
    rlutil::locate(66,22);cout<<"MES ";
    cin>>m1;
    rlutil::locate(74,22);cout<<"AÑO: ";
    cin>>a1;
    while(ing.leerDeDisco(pos++))
        {
            if((ing.getFecha().getMes()>=m && ing.getFecha().getMes()<=m1)
               && (ing.getFecha().getAnio()>=a && ing.getFecha().getAnio()<=a1 ))
                {
                acu++;
               }
            }
            rlutil::setColor(rlutil::GREEN);
                   rlutil::locate(42,26);cout<<"Total autos ingresados: "<<acu<<endl;
        rlutil::anykey();
        }


#endif // REPORTES_H_INCLUDED
