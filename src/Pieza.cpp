#include <string>
#include <sstream>
#include <Pieza.h>
using namespace std;

Pieza::Pieza(string nombre, string descripcion, EstadoPieza estado)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->estado = estado;
}

string Pieza::getNombre()
{
    return nombre;
}

string Pieza::getDescripcion()
{
    return descripcion;
}

EstadoPieza Pieza::getEstado()
{
    return this->estado;
}

string Pieza::serialize()
{
    ostringstream oss;
    oss << nombre << '-' << descripcion << '-' << static_cast<int>(estado);
    return oss.str();
}

Pieza Pieza::deserialize(const string &s)
{
    istringstream iss(s);
    string nombre, descripcion;
    int estado;
    getline(iss, nombre, '-');
    getline(iss, descripcion, '-');
    iss >> estado;
    return Pieza(nombre, descripcion, static_cast<EstadoPieza>(estado));
}
