#include "Clases.h"

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
    : nombre(nombre), cedula(cedula), fechaRegistro(fechaRegistro), numContacto(numContacto) {
    vehiculos = vector<Vehiculo>();
}

// Getters
string Cliente::getNombre() {
    return nombre;
}

string Cliente::getCedula() {
    return cedula;
}

string Cliente::getFechaRegistro() {
    return fechaRegistro;
}

string Cliente::getNumContacto() {
    return numContacto;
}

vector<Vehiculo> *Cliente::getVehiculos() {
    return &vehiculos;
}

int Cliente::getNumVehiculos() {
    return vehiculos.size();
}

void Cliente::agregarVehiculo(Vehiculo vehiculo) {
    vehiculos.push_back(vehiculo);
}


/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 * 
 * @param cedulaPropietario 
 * @param placa 
 * @param ubicacion 
 */
Servicio::Servicio(string fechaIni, string fechaFin, string razon, double kmIngreso) {
    this->fechaIni = fechaIni;
    this->fechaFin = fechaFin;
    this->razon = razon;
    this->kmIngreso = kmIngreso;
}

string Servicio::getFechaIni() {
    return this->fechaIni;
}

string Servicio::getFechaFin() {
    return this->fechaFin;
}

string Servicio::getRazon() {
    return this->razon;
}

double Servicio::getKmIngreso() {
    return this->kmIngreso;
}



/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 * 
 * @param placa 
 * @param ubicacion 
 * @param servicios 
 */

Vehiculo::Vehiculo( string placa, bool ubicacion) {
    this->placa = placa;
    this->ubicacion = ubicacion;
    this->servicios = vector<Servicio>();
}

string Vehiculo::getPlaca() {
    return this->placa;
}

bool Vehiculo::getUbicacion() {
    return this->ubicacion;
}

vector<Servicio> *Vehiculo::getServicios() {
    return &(this->servicios);
}

int Vehiculo::getNumServicios() {
    return servicios.size();
}

void Vehiculo::agregarServicio(Servicio servicio) {
    servicios.push_back(servicio);
}

