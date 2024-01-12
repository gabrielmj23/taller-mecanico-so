#include <string>
#include <iostream>
#include <pthread.h>
#include <Pieza.h>
#include <unistd.h>
#include <EstacionTrabajo.h>
#include "Inventario.h"
using namespace std;

typedef struct unidad
{
    string nombreEstacion;
    Vehiculo *vehiculo;
    vector<Pieza> *piezas;
    Inventario *inventario;
    pthread_mutex_t *inventario_mutex;
} UnidadTrabajo;

void *trabajar(void *unidad)
{
    // Desempacar unidad de trabajo
    UnidadTrabajo *u = (UnidadTrabajo *)unidad;
    string nombre = u->nombreEstacion;
    Vehiculo *v = u->vehiculo;
    vector<Pieza> *piezas = u->piezas;
    Inventario *inventario = u->inventario;
    pthread_mutex_t *inventario_mutex = u->inventario_mutex;
    // Reemplazar piezas en el sistema correcto
    for (auto &s : *(v->getSistemas()))
    {
        if (s.getNombre() == nombre)
        {
            for (Pieza &pieza : *piezas)
            {
                // Agregar pieza al inventario si no existe
                if (!inventario->buscarCantidadPiezaPorNombre(pieza.getNombre()))
                {
                    cout << "Agregando pieza " << pieza.getNombre() << " al inventario\n";
                    pthread_mutex_lock(inventario_mutex);
                    sleep(5);
                    inventario->agregarPiezas(pieza, 20);
                    pthread_mutex_unlock(inventario_mutex);
                }
                s.reemplazarPieza(Pieza(pieza.getNombre(), FUNCIONA));
            }
            break;
        }
    }
    sleep(5);
    return nullptr;
}

EstacionTrabajo::EstacionTrabajo(string nombre, Inventario *inventario, pthread_mutex_t *inventario_mutex)
{
    this->nombre = nombre;
    this->trabajando = false;
    this->inventario = inventario;
    this->inventario_mutex = inventario_mutex;
}

string EstacionTrabajo::getNombre()
{
    return this->nombre;
}

string EstacionTrabajo::getPlaca()
{
    return this->placa;
}

bool EstacionTrabajo::getTrabajando()
{
    return this->trabajando;
}

void EstacionTrabajo::iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas)
{
    cout << "Iniciando estación de trabajo: Estación " << nombre << '\n';
    UnidadTrabajo u;
    u.nombreEstacion = nombre;
    u.vehiculo = &v;
    u.piezas = &piezas;
    u.inventario = this->inventario;
    u.inventario_mutex = this->inventario_mutex;
    pthread_create(&hilo_estacion, nullptr, trabajar, &u);
    this->placa = v.getPlaca();
    this->trabajando = true;
    pthread_join(hilo_estacion, nullptr);
    this->trabajando = false;
}
