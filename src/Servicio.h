#pragma once
#include <string>
using namespace std;

class Servicio
{
private:
    string placaVehiculo;
    string fechaIni;
    string fechaFin;
    string razon;
    int kmIngreso;

public:
    // Constructor
    Servicio(string placa, string fechaIni, string fechaFin, string razon, int kmIngreso);
    // Getters
    string getPlacaVehiculo();
    string getFechaIni();
    string getFechaFin();
    string getRazon();
    int getKmIngreso();
    // Archivos
    static vector<Servicio> cargarServiciosDesdeArchivo(string placa);
    static void guardarServicioEnArchivo(Servicio servicio);
};
