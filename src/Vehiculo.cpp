#include <iostream>
#include <string>
#include <sstream>
#include <Vehiculo.h>
using namespace std;

Vehiculo::Vehiculo(string cedulaPropietario, string nombrePropietario, string placa, vector<SistemaVehiculo> sistemas)
{
    this->cedulaPropietario = cedulaPropietario;
    this->nombrePropietario = nombrePropietario;
    this->placa = placa;
    this->sistemas = sistemas;
}

string Vehiculo::getPlaca()
{
    return this->placa;
}

vector<SistemaVehiculo> *Vehiculo::getSistemas()
{
    return &(this->sistemas);
}

void Vehiculo::identificar()
{
    cout << "Cédula propietario: " << cedulaPropietario << "\nPlaca: " << placa << '\n';
}

string Vehiculo::serialize()
{
    ostringstream oss;
    oss << cedulaPropietario << '-' << nombrePropietario << '-' << placa << '-';
    for (auto sistema : sistemas)
    {
        oss << sistema.serialize() << ' ';
    }
    return oss.str();
}

Vehiculo Vehiculo::deserialize(const string &s)
{
    istringstream iss(s);
    string cedulaPropietario, nombrePropietario, placa;
    vector<SistemaVehiculo> sistemas;
    getline(iss, cedulaPropietario, '-');
    getline(iss, nombrePropietario, '-');
    getline(iss, placa, '-');
    while (!iss.eof())
    {
        string sistema;
        iss >> sistema;
        sistemas.push_back(SistemaVehiculo::deserialize(sistema));
    }
    return Vehiculo(cedulaPropietario, nombrePropietario, placa, sistemas);
}
