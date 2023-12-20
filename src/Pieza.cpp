#include <string>
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
