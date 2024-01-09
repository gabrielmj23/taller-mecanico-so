#include <string>
#include <sstream>
#include "Pieza.h"
using namespace std;

Pieza::Pieza(string nombre, EstadoPieza estado)
{
    this->nombre = nombre;
    this->estado = estado;
}

string Pieza::getNombre()
{
    return nombre;
}

EstadoPieza Pieza::getEstado()
{
    return this->estado;
}

string Pieza::serialize()
{
    ostringstream oss;
    oss << nombre << '-' << static_cast<int>(estado);
    return oss.str();
}

Pieza Pieza::deserialize(const string &s)
{
    istringstream iss(s);
    string nombre;
    int estado;
    getline(iss, nombre, '-');
    iss >> estado;
    return Pieza(nombre, static_cast<EstadoPieza>(estado));
}
