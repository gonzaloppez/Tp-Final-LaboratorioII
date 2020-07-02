#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

void recuadro();

struct Clientes{
    private:
        char nombre[15];
        char apellido[15];
        int dni;
        int telefono;
        char mail[30];
    public:
        ///sets
        void setNombre(char *);
        void setApellido(char *);
        void setDni(int);
        void setTelefono(int);
        void setMail(char *);
        ///gets
        char* getNombre();
        char* getApellido();
        int getDni();
        int getTelefono();
        char* getMail();

        bool cargarCliente();
        void mostrarClientes();
        void mostrarClientesIngreso();
        bool guardarEnDiscoClientes();
        bool guardarEnDiscoClientes(int);
        bool leerClientesDeDisco(int);

};

///globales
bool nuevoCliente();
void listarClientes();
void buscarCliente();
int buscarPorDni(int);
bool modificarCliente();
bool validarMail(char *);
bool validarDNI(int _dni);

#endif // CLIENTES_H_INCLUDED
