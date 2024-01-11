#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <QListWidget>
#include <QProgressBar>
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

public:
    // Constructor
    TallerMecanico();
    // Getters
    vector<EstacionTrabajo> getEstaciones();
    // Devuelve las estaciones de trabajo por las que tiene que pasar el vehículo las piezas a reemplazar
    map<string, vector<Pieza>> diagnosticar(Vehiculo &v);
    // Recibe un vehículo para hacer su evaluación y operación
    void recibirVehiculo(Vehiculo &v, string falla, QListWidget *lista_repuestos, QListWidget *lista_estaciones, QProgressBar *barra_progreso);
};