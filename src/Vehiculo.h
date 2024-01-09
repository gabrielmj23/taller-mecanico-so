#pragma once
#include <string>
#include <vector>
#include "SistemaVehiculo.h"
using namespace std;

class Vehiculo
{
private:
    string cedulaCliente;
    string placa;
    bool enTaller;
    vector<SistemaVehiculo> sistemas;

public:
    Vehiculo(string cedulaCliente, string placa, vector<SistemaVehiculo> sistemas);
    // Getters
    string getCedulaCliente();
    string getPlaca();
    bool getEnTaller();
    vector<SistemaVehiculo> *getSistemas();
    // Uso general
    void identificar();
    // Comunicación por red
    string serialize();
    static Vehiculo deserialize(const string &s);
    // Archivos
    static vector<Vehiculo> cargarVehiculosDesdeArchivo();
    static void guardarVehiculoEnArchivo(Vehiculo vehiculo);
    int getNumServicios();
};