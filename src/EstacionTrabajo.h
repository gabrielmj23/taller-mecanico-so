#pragma once
#include <string>
#include <pthread.h>
#include <Vehiculo.h>
using namespace std;

class EstacionTrabajo
{
private:
    string nombre;
    string placa;
    pthread_t hilo_estacion;
    bool trabajando;

public:
    // Constructor
    EstacionTrabajo(string nombre);
    // Getters
    string getNombre();
    string getPlaca();
    bool getTrabajando();
    // Trabajo/Hilos
    void iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas);
};