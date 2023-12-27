#pragma once
#include <string>
#include <vector>
using namespace std;

class Vehiculo{
    private :
        string cedulaPropietario;
        string nombrePropietario;
        string placa;
};

class Cliente
{
private:
    string nombre;
    string cedula;
    string fechaRegistro;
    string numContacto;
    vector<Vehiculo> vehiculos;

public:
    Cliente(string nombre, string cedula, string fechaRegistro, string numContacto);
    string getNombre();
    string getCedula();
    string getFechaRegistro();
    string getNumContacto();
    vector<Vehiculo> *getVehiculos();
    int getNumVehiculos();
};