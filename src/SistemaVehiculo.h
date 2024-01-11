#pragma once
#include <string>
#include <vector>
#include "Pieza.h"

using namespace std;

class SistemaVehiculo
{
private:
    string nombre;
    vector<Pieza> piezas;

public:
    // Constructor
    SistemaVehiculo(string nombre, vector<Pieza> piezas);
    // Getters
    string getNombre();
    vector<Pieza> &getPiezas();
    // Setter para el estado de alguna pieza
    void setEstadoPieza(string nombre, EstadoPieza estado);
    // Hace trabajar al sistema
    void *iniciarSistema();
    // Reemplaza una pieza del sistema
    void reemplazarPieza(Pieza p);
    // Serialización para el servidor
    string serialize();
    static SistemaVehiculo deserialize(const string &s);
};