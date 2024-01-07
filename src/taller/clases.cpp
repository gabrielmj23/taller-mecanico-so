#include "clases.h"

ClienteVehiculo::ClienteVehiculo(string tipo, string nombre, string hora, string placa)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->hora = hora;
    this->placa = placa;
}

VehiculoCola::VehiculoCola(int nroPuesto, string placa, string hora)
{
    this->nroPuesto = nroPuesto;
    this->placa = placa;
    this->hora = hora;
}

Repuesto::Repuesto(string descripcion, int existencia, string estado)
{
    this->descripcion = descripcion;
    this->existencia = existencia;
    this->estado = estado;
}

Estacion::Estacion(string nombre, string placaCarro, string tiempoAcu)
{
    this->nombre = nombre;
    this->placaCarro = placaCarro;
    this->tiempoAcu = tiempoAcu;
}

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
