#ifndef CLASES_H
#define CLASES_H
#include <string>

using namespace std;

// Aquí van las declaraciones de tus clases
class ClienteVehiculo {
    public:
        string tipo;
        string nombre;
        string hora;
        string placa;
        ClienteVehiculo(string tipo, string nombre, string hora, string placa);
};

#endif // CLASES_H
