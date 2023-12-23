#pragma once
#include <string>
#include <Vehiculo.h>
using namespace std;

class Cliente {
private:
    string nombre;
    string cedula;
    string fechaRegistro;
    string numContacto;
    vector<Vehiculo> vehiculos;
public:
    Cliente(string nombre, string cedula, string fechaRegistro, string numContacto);

    int getNumVehiculos(){
        return vehiculos.size();
    }


    void mostrarCliente();
};