#include <iostream>
#include <Vehiculo.h>
using namespace std;

Vehiculo::Vehiculo(string cedulaPropietario, string nombrePropietario, string placa, vector<SistemaVehiculo> sistemas)
{
    this->cedulaPropietario = cedulaPropietario;
    this->nombrePropietario = nombrePropietario;
    this->placa = placa;
    this->sistemas = sistemas;
}

void Vehiculo::identificar()
{
    cout << "Cédula propietario: " << cedulaPropietario << "\nPlaca: " << placa << '\n';
}