#ifndef CLASES_H
#define CLASES_H
#include <string>
#include <vector>

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

class VehiculoCola {
    public:
    int nroPuesto;
    string placa;
    string hora;
    VehiculoCola(int nroPuesto, string placa, string hora);
};

class Estacion {
    public:
        string nombre;
        string placaCarro;
        string tiempoAcu;
        Estacion(string nombre, string placaCarro, string tiempoAcu);
};


#endif // CLASES_H
