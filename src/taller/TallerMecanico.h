#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Pieza.h"
#include "Vehiculo.h"
#include "EstacionTrabajo.h"
using namespace std;

class TallerMecanico
{
private:
    vector<EstacionTrabajo> estaciones;
    vector<Vehiculo> estacionamiento;
    int serviciosTerminados;

    // Devuelve las estaciones de trabajo por las que tiene que pasar el vehículo las piezas a reemplazar
    map<string, vector<Pieza>> diagnosticar(Vehiculo &v);

public:
    // Constructor
    TallerMecanico();
    // Getters
    vector<EstacionTrabajo> getEstaciones();
    // Recibe un vehículo para hacer su evaluación y operación
    void recibirVehiculo(Vehiculo &v, string falla);
};