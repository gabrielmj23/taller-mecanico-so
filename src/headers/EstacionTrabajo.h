#pragma once
#include <string>
#include <Vehiculo.h>
using namespace std;

class EstacionTrabajo
{
private:
    string nombre;

public:
    EstacionTrabajo(string nombre);
    string getNombre();
    void *iniciarEstacion();
    void *iniciarTrabajo(void *vehiculo);
    void reemplazarPieza(Pieza p);
};