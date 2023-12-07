#include <iostream>
#include <Vehiculo.h>
using namespace std;

Vehiculo::Vehiculo(string cedula_propietario, string placa, vector<SistemaVehiculo> sistemas) {
    this->cedula_propietario = cedula_propietario;
    this->placa = placa;
    this->sistemas = sistemas;
}

void Vehiculo::identificar() {
    cout << "Cédula propietario: " << cedula_propietario << "\nPlaca: " << placa << '\n';
}