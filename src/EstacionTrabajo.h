#pragma once
#include <string>
#include <pthread.h>
#include <QTableWidget>
#include <Vehiculo.h>
#include "Inventario.h"
using namespace std;

class EstacionTrabajo
{
private:
    int orden;
    string nombre;
    string placa;
    pthread_t hilo_estacion;
    bool trabajando;
    Inventario *inventario;
    pthread_mutex_t *inventario_mutex;

public:
    // Constructor
    EstacionTrabajo(int orden, string nombre, Inventario *inventario, pthread_mutex_t *inventario_mutex);
    // Getters
    string getNombre();
    string getPlaca();
    bool getTrabajando();
    // Trabajo/Hilos
    void iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas, QTableWidget *tabla_repuestos, QTableWidget *tabla_estaciones);
};