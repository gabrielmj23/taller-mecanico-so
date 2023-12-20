#pragma once
#include <string>
#include <pthread.h>
#include <Vehiculo.h>
using namespace std;

class EstacionTrabajo
{
private:
    string nombre;
    pthread_t hilo_estacion;
    bool trabajando;

public:
    EstacionTrabajo(string nombre);
    string getNombre();
    void iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas);
};