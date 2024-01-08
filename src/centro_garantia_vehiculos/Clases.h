#pragma once
#include <string>
#include <vector>

using namespace std;

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
