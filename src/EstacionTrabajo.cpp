#include <string>
#include <iostream>
#include <pthread.h>
#include <Pieza.h>
#include <unistd.h>
#include <QTableWidget>
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
    QTableWidget *tabla_repuestos;
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
    QTableWidget *tabla_repuestos = u->tabla_repuestos;
    // Reemplazar piezas en el sistema correcto
    for (auto &s : *(v->getSistemas()))
    {
        if (s.getNombre() == nombre)
        {
            for (Pieza &pieza : *piezas)
            {
                // Agregar pieza al inventario si no existe
                pthread_mutex_lock(inventario_mutex);
                if (!inventario->buscarCantidadPiezaPorNombre(pieza.getNombre()))
                {
                    cout << "Agregando pieza " << pieza.getNombre() << " al inventario\n";
                    sleep(5);
                    inventario->agregarPiezas(pieza, 20);
                }
                Pieza p = inventario->sacarPieza(pieza.getNombre());
                // Mostrar en la UI
                map<string, int> stock = inventario->getStock();
                tabla_repuestos->clearContents();
                tabla_repuestos->setRowCount(0);
                int i = 0;
                for (auto p : stock)
                {
                    tabla_repuestos->insertRow(i);
                    tabla_repuestos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.first)));
                    tabla_repuestos->setItem(i, 1, new QTableWidgetItem(QString::number(p.second)));
                    tabla_repuestos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.second == 0 ? "Agotado" : "Disponible")));
                    i++;
                }
                pthread_mutex_unlock(inventario_mutex);
                s.reemplazarPieza(p);
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

void EstacionTrabajo::iniciarEstacion(Vehiculo &v, vector<Pieza> &piezas, QTableWidget *tabla_repuestos)
{
    cout << "Iniciando estación de trabajo: Estación " << nombre << '\n';
    UnidadTrabajo u;
    u.nombreEstacion = nombre;
    u.vehiculo = &v;
    u.piezas = &piezas;
    u.inventario = this->inventario;
    u.inventario_mutex = this->inventario_mutex;
    u.tabla_repuestos = tabla_repuestos;
    pthread_create(&hilo_estacion, nullptr, trabajar, &u);
    this->placa = v.getPlaca();
    this->trabajando = true;
    pthread_join(hilo_estacion, nullptr);
    this->trabajando = false;
}
