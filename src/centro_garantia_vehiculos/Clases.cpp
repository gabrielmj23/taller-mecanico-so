#include "Clases.h"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 *
 * @param cedulaPropietario
 * @param placa
 * @param ubicacion
 */

int Servicio::nextID = 1;

Servicio::Servicio(string placa, string fechaIni, string fechaFin, string razon, double kmIngreso)
    : id(nextID++), placaVehiculo(placa), fechaIni(fechaIni), fechaFin(fechaFin), razon(razon), kmIngreso(kmIngreso) {}
Servicio::~Servicio()
{
    decrementarId();
}

int Servicio::getId()
{
    return this->id;
}

string Servicio::getPlacaVehiculo()
{
    return this->placaVehiculo;
}

string Servicio::getFechaIni()
{
    return this->fechaIni;
}

string Servicio::getFechaFin()
{
    return this->fechaFin;
}

string Servicio::getRazon()
{
    return this->razon;
}

double Servicio::getKmIngreso()
{
    return this->kmIngreso;
}
