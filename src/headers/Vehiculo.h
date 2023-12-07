#pragma once
#include <string>
using namespace std;

class Vehiculo {
    private:
        string cedula_propietario;
        string placa;
    public:
        void identificar();
};