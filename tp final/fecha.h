#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED



class Fecha{
    private:
    int dia, mes, anio;
    public:
        //Fecha();
        bool cargar();
        void mostrar();
       ///sets
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        ///gets
        int getDia();
        int getMes();
        int getAnio();
};


bool validarFecha(int,int,int);


#endif // FECHA_H_INCLUDED
