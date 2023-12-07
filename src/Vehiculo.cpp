#include <iostream>
#include <Vehiculo.h>
using namespace std;

void Vehiculo::identificar() {
    cout << "Cédula propietario: " << cedula_propietario << "\nPlaca: " << placa << '\n';
}