#include <string>
#include <iostream>
#include <pthread.h>
#include <Pieza.h>
#include <EstacionTrabajo.h>
using namespace std;

typedef struct unidad
{
    string nombreEstacion;
    Vehiculo *vehiculo;
    vector<Pieza> *piezas;
} UnidadTrabajo;

void *trabajar(void *unidad)
{
    // Desempacar unidad de trabajo
    UnidadTrabajo *u = (UnidadTrabajo *)unidad;
    string nombre = u->nombreEstacion;
    Vehiculo *v = u->vehiculo;
    vector<Pieza> *piezas = u->piezas;
    // Reemplazar piezas en el sistema correcto
    for (auto &s : *(v->getSistemas()))
    {
        if (s.getNombre() == nombre)
        {
            for (Pieza &pieza : *piezas)
            {
                s.reemplazarPieza(Pieza(pieza.getNombre(), pieza.getDescripcion(), FUNCIONA));
            }
            break;
        }
    }
    return nullptr;
}

EstacionTrabajo::EstacionTrabajo(string nombre)
{
    this->nombre = nombre;
    this->trabajando = false;
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
    pthread_create(&hilo_estacion, nullptr, trabajar, &u);
    this->placa = v.getPlaca();
    this->trabajando = true;
    pthread_join(hilo_estacion, nullptr);
    this->trabajando = false;
}
