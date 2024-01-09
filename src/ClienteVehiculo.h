#pragma once
#include <string>
#include <vector>
using namespace std;

class ClienteVehiculo
{
private:
    string tipo;
    string nombre;
    string hora;
    string placa;

public:
    // Constructor
    ClienteVehiculo(string tipo, string nombre, string hora, string placa);
    // Getters
    string getTipo();
    string getNombre();
    string getHora();
    string getPlaca();
    // Uso de archivos
    static vector<ClienteVehiculo> leerClienteVehiculosDeArchivo();
    static void guardarClienteVehiculo(ClienteVehiculo clienteVehiculo);
};