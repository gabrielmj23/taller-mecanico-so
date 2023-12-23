#pragma once
#include <string>
#include <Vehiculo.h>
using namespace std;

class Cliente {
private:
    string nombre;
    string cedula;
    int numCarros;
    string fechaRegistro;
    string numContacto;
    vector<Vehiculo> vehiculos;
};