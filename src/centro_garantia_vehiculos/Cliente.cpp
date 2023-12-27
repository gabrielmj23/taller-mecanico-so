#include "Cliente.h"

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
