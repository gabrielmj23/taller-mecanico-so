#pragma once
#include <string>
using namespace std;

enum EstadoPieza
{
    FUNCIONA,
    FALLA
};

class Pieza
{
private:
    string nombre;
    string descripcion;
    EstadoPieza estado;

public:
    Pieza(string nombre, string descripcion, EstadoPieza estado);
    string getNombre();
    string getDescripcion();
    EstadoPieza getEstado();
    string serialize();
    static Pieza deserialize(const string &s);
};