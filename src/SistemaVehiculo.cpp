#include <iostream>
#include <string>
#include <sstream>
#include <SistemaVehiculo.h>
using namespace std;

SistemaVehiculo::SistemaVehiculo(string nombre, vector<Pieza> piezas)
{
    this->nombre = nombre;
    this->piezas = piezas;
}

string SistemaVehiculo::getNombre()
{
    return nombre;
}

vector<Pieza> &SistemaVehiculo::getPiezas()
{
    return this->piezas;
}

void SistemaVehiculo::setEstadoPieza(string nombre, EstadoPieza estado)
{
    for (int i = 0; i < piezas.size(); i++)
    {
        if (piezas[i].getNombre() == nombre)
        {
            piezas[i].setEstado(estado);
            return;
        }
    }
}

void *SistemaVehiculo::iniciarSistema()
{
    cout << "Iniciando sistema: Sistema de " << nombre << '\n';
    return nullptr;
}

void SistemaVehiculo::reemplazarPieza(Pieza p)
{
    for (int i = 0; i < piezas.size(); i++)
    {
        if (piezas[i].getNombre() == p.getNombre())
        {
            piezas[i] = p;
            cout << "Pieza reemplazada: " << p.getNombre() << '\n';
            return;
        }
    }
}

string SistemaVehiculo::serialize()
{
    ostringstream oss;
    oss << nombre << '-';
    for (int i = 0; i < piezas.size(); i++)
    {
        oss << piezas[i].serialize() << ' ';
    }
    return oss.str();
}

SistemaVehiculo SistemaVehiculo::deserialize(const string &s)
{
    istringstream iss(s);
    string nombre;
    vector<Pieza> piezas;
    getline(iss, nombre, '-');
    while (!iss.eof())
    {
        string pieza;
        iss >> pieza;
        piezas.push_back(Pieza::deserialize(pieza));
    }
    return SistemaVehiculo(nombre, piezas);
}
