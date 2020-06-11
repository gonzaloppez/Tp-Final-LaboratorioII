#ifndef CLAVE_H_INCLUDED
#define CLAVE_H_INCLUDED

class Clave{
    private:
    int contra;
    public:
        bool establecerClave();
        bool cambiarClave();
        bool verificarClave(int);
};


#endif // CLAVE_H_INCLUDED
