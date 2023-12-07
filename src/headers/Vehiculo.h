#pragma once
#include <string>
#include <vector>
#include <SistemaVehiculo.h>
using namespace std;

class Vehiculo {
    private:
        string cedula_propietario;
        string placa;
        vector<SistemaVehiculo> sistemas;
    public:
        Vehiculo(string cedula_propietario, string placa, vector<SistemaVehiculo> sistemas);
        void identificar();
};