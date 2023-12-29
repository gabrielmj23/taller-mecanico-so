#include "Clases.h"
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Cliente:: Cliente object
 *
 * @param nombre
 * @param cedula
 * @param fechaRegistro
 * @param numContacto
 */

// Constructor
Cliente::Cliente(string nombre, string cedula, string fechaRegistro, string numContacto)
    : nombre(nombre), cedula(cedula), fechaRegistro(fechaRegistro), numContacto(numContacto)
{
}

// Getters
string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getCedula()
{
    return cedula;
}

string Cliente::getFechaRegistro()
{
    return fechaRegistro;
}

string Cliente::getNumContacto()
{
    return numContacto;
}

// cuenta la cantidad de vehiculos de un cliente de un arreglo de vehiculos dado
int Cliente::getNumVehiculos(Vehiculo* vehiculos, int tamanio)
{
    
    int c = 0;


    for (int i = 0; i < tamanio; i++)
    {
        Vehiculo vehiculo = vehiculos[i];

        if (vehiculo.getCedulaCliente().compare(this->cedula) == 0)
        {
            c++;
        }
    }

    return c;
}

/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 *
 * @param cedulaPropietario
 * @param placa
 * @param ubicacion
 */
Servicio::Servicio(string placa, string fechaIni, string fechaFin, string razon, double kmIngreso)
{
    this->placaVehiculo = placa;
    this->fechaIni = fechaIni;
    this->fechaFin = fechaFin;
    this->razon = razon;
    this->kmIngreso = kmIngreso;
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

/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 *
 * @param placa
 * @param ubicacion
 * @param servicios
 */

Vehiculo::Vehiculo(string cedulaCliente, string placa, bool ubicacion)
{
    this->cedulaCliente = cedulaCliente;
    this->placa = placa;
    this->ubicacion = ubicacion;
}

string Vehiculo::getCedulaCliente()
{
    return this->cedulaCliente;
}
string Vehiculo::getPlaca()
{
    return this->placa;
}

string Vehiculo::getUbicacion()
{
   return ubicacion? "Dentro del Taller" : "Fuera del Taller";
}

int Vehiculo::getNumServicios(Servicio* servicios, int tamanio)
{

    int c = 0;

    for (int i = 0; i < tamanio; i++)
    {
        Servicio servicio = servicios[i];

        if (servicio.getPlacaVehiculo().compare(this->placa) == 0)
        {
            c++;
        }
    }

    return c;
}
