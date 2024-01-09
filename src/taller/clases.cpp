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

Estacion::Estacion(string nombre, string placaCarro, string tiempoAcu)
{
    this->nombre = nombre;
    this->placaCarro = placaCarro;
    this->tiempoAcu = tiempoAcu;
}
