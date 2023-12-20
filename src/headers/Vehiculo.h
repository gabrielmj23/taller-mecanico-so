#pragma once
#include <string>
#include <vector>
#include <SistemaVehiculo.h>
using namespace std;

class Vehiculo
{
private:
    string cedulaPropietario;
    string nombrePropietario;
    string placa;
    vector<SistemaVehiculo> sistemas;

public:
    Vehiculo(string cedulaPropietario, string nombrePropietario, string placa, vector<SistemaVehiculo> sistemas);
    string getPlaca();
    vector<SistemaVehiculo> *getSistemas();
    void identificar();
};