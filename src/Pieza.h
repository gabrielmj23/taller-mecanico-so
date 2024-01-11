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
    EstadoPieza estado;

public:
    // Constructor
    Pieza(string nombre, EstadoPieza estado);
    // Getters
    string getNombre();
    EstadoPieza getEstado();
    // Setters
    void setEstado(EstadoPieza estado);
    // Envío por red
    string serialize();
    static Pieza deserialize(const string &s);
};