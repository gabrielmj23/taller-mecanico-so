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
    Vehiculo(string cedulaCliente, string placa);
    // Getters
    string getCedulaCliente();
    string getPlaca();
    bool getEnTaller();
    vector<SistemaVehiculo> *getSistemas();
    // Setters
    void setEnTaller(bool enTaller);
    // Uso general
    void identificar();
    // Establece las piezas no funcionales dependiendo de la falla especificada
    void registrarFalla(string falla);
    // Comunicación por red
    string serialize();
    static Vehiculo deserialize(const string &s);
    // Archivos
    static vector<Vehiculo> cargarVehiculosDesdeArchivo();
    static void guardarVehiculoEnArchivo(Vehiculo vehiculo);
    int getNumServicios();
};