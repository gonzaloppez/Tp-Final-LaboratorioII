#include <iostream>
using namespace std;
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <locale.h>
#include "marca.h"
#include "menu.h"
#include "ingreso.h"
#include "funciones.h"

/*
int argc, char* argv[]
SDL_Init(SDL_INIT_EVERYTHING);
    cout<<"Ello"<<endl;

    SDL_Window* window;
    window = SDL_CreateWindow("MyWindowTitle", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);

    SDL_Delay(4000);
    SDL_DestroyWindow(window);

    --------------------------------

     SDL_Surface* hello = NULL;
    SDL_Window* screen = NULL;
    int i=0;

    SDL_Init(SDL_INIT_EVERYTHING);

    hello = SDL_LoadBMP("foto.bmp");
    screen = SDL_CreateWindow ( "Mi ventana de juego" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , 640 , 480 , SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL );

    while (true){
        i++;
        SDL_CreateTexture(hello, NULL, screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(2000);

        if(i>5){
            SDL_Quit();
        }


    }
    ------------------------------------------

    SDL_Surface* image = SDL_LoadBMP("foto.BMP");
        if (image == NULL) {
       std::cout << "IMG_Load: " << cout<<"error"<< "\n";
        }


*/

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Spanish");
    while(true){
    system("cls");

    int opcion;
    cout<<"-MENU PRINCIPAL-"<<endl;
    cout<<"*************************"<<endl;
    cout<<" -1 Ingreso al taller  "<<endl;
    cout<<" -2 Ficha cliente  "<<endl;
    cout<<" -3 Clientes  "<<endl;
    cout<<" -4 Vehículos  "<<endl;
    cout<<" -5 Reportes  "<<endl;
    cout<<" -6 Configuraciones  "<<endl;
    cout<<" -0 Salir  "<<endl;
    cout<<"*************************"<<endl;
    cout<<"Ingresar opción: ";
    cin>>opcion;


        switch (opcion){

        case 1:
            if(nuevoIngreso())
                {
                    cout<<"El registro del auto se guardo correctamente"<<endl;
                    system("pause");
                }else {
                cout<<"El registro no se guardo"<<endl;
                system("pause");
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
             }
    }

   }

