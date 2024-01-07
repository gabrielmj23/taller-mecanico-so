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

class Servicio
{
private:
    static int nextID; // Esta será compartida por todos los objetos de la clase
    int id;            // Esta será única para cada objeto
    string placaVehiculo;
    string fechaIni;
    string fechaFin;
    string razon;
    double kmIngreso;

public:
    Servicio(string placa, string fechaIni, string fechaFin, string razon, double kmIngreso);
    ~Servicio();
    string getPlacaVehiculo();
    string getFechaIni();
    string getFechaFin();
    string getRazon();
    double getKmIngreso();
    int getId();
    static void decrementarId() { --nextID; }
};

class VehiculoCola {
    public:
    int nroPuesto;
    string placa;
    string hora;
    VehiculoCola(int nroPuesto, string placa, string hora);
};

class Repuesto
{
    public:
        string descripcion;
        int existencia;
        string estado;
        Repuesto(string descripcion, int existencia, string estado);
};

class Estacion {
    public:
        string nombre;
        string placaCarro;
        string tiempoAcu;
        Estacion(string nombre, string placaCarro, string tiempoAcu);
};


#endif // CLASES_H
