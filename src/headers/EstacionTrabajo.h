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

public:
    EstacionTrabajo(string nombre);
    string getNombre();
    void *iniciarEstacion();
    void *iniciarTrabajo(void *vehiculo);
    void reemplazarPieza(Pieza p);
};