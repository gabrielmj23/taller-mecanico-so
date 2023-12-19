#include <string>
#include <iostream>
#include <Pieza.h>
#include "EstacionTrabajo.h"
using namespace std;

EstacionTrabajo::EstacionTrabajo(string nombre)
{
    this->nombre = nombre;
}

string EstacionTrabajo::getNombre()
{
    return this->nombre;
}

void *EstacionTrabajo::iniciarEstacion()
{
    cout << "Iniciando estación de trabajo: Estación " << nombre << '\n';
    
    return nullptr;
}

void *EstacionTrabajo::iniciarTrabajo(void *vehiculo)
{
    return nullptr;
}

void EstacionTrabajo::reemplazarPieza(Pieza p)
{
}
