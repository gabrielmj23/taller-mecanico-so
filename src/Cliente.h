#pragma once
#include <string>
#include <vector>
#include "Vehiculo.h"
using namespace std;

class Cliente
{
private:
    string nombre;
    string cedula;
    string fechaRegistro;
    string numContacto;

public:
    Cliente(string nombre, string cedula, string fechaRegistro, string numContacto);
    // Getters
    string getNombre();
    string getCedula();
    string getFechaRegistro();
    string getNumContacto();
    int getNumVehiculos(vector<Vehiculo> &vehiculos);
    // Archivos
    static vector<Cliente> cargarClientesDesdeArchivo();
    static void guardarClienteEnArchivo(Cliente cliente);
};
