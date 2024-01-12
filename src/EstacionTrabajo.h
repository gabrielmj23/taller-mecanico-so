#pragma once
#include <string>
#include <pthread.h>
#include <Vehiculo.h>
#include "Inventario.h"
using namespace std;

class EstacionTrabajo
{
private:
    string nombre;
    string placa;
    pthread_t hilo_estacion;
    bool trabajando;
    Inventario *inventario;
    pthread_mutex_t *inventario_mutex;

public:
    // Constructor
    EstacionTrabajo(string nombre, Inventario *inventario, pthread_mutex_t *inventario_mutex);
    // Getters
    string getNombre();
    string getPlaca();
    bool getTrabajando();
    // Trabajo/Hilos
    void iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas);
};