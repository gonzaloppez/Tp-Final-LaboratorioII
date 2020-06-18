#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

struct Clientes{
    private:
        char nombre[10];
        char apellido[10];
        int dni;
        int telefono;
    public:
        bool cargarCliente();
        void mostrarClientes();
        bool guardarEnDiscoClientes();
        void leerClientesDeDisco();
        void buscarClientesPorDni(int);
};


#endif // CLIENTES_H_INCLUDED
