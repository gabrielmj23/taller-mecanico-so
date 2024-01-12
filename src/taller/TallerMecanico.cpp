#include "TallerMecanico.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <QString>
#include <pthread.h>
#include "Pieza.h"
#include "SistemaVehiculo.h"
#include "EstacionTrabajo.h"
#include "Vehiculo.h"
using namespace std;

TallerMecanico::TallerMecanico()
{
    this->serviciosTerminados = 0;
    this->inventario = Inventario();
    this->inventario_mutex = PTHREAD_MUTEX_INITIALIZER;
    // Crear estaciones
    this->estaciones = vector<EstacionTrabajo>{
        EstacionTrabajo("Lubricación", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Motor", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Transmisión", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Dirección", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Combustible", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Suspensión", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Frenos", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Seguridad", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Electricidad", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Refrigeración", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo("Intercambio de calor", &this->inventario, &this->inventario_mutex)};
}

map<string, vector<Pieza>> TallerMecanico::diagnosticar(Vehiculo &v)
{
    map<string, vector<Pieza>> piezasPorEstacion;
    for (SistemaVehiculo &sistema : *(v.getSistemas()))
    {
        for (Pieza &pieza : sistema.getPiezas())
        {
            if (pieza.getEstado() == FALLA)
            {
                piezasPorEstacion[sistema.getNombre()].push_back(pieza); // Deja las referencias de las piezas a reemplazar
            }
        }
    }
    return piezasPorEstacion;
}

vector<EstacionTrabajo> TallerMecanico::getEstaciones()
{
    return this->estaciones;
}

Inventario &TallerMecanico::getInventario()
{
    return this->inventario;
}

pthread_mutex_t &TallerMecanico::getInventarioMutex()
{
    return this->inventario_mutex;
}

void TallerMecanico::recibirVehiculo(Vehiculo &v, string falla, QListWidget *lista_repuestos, QListWidget *lista_estaciones, QProgressBar *barra_progreso)
{
    cout << "Recibió vehículo de placa: " << v.getPlaca() << "\n---\n";
    // Asignar piezas basado en la falla
    v.registrarFalla(falla);
    for (int i = 0; i <= 10; i++)
    {
        barra_progreso->setValue(i * 10);
        sleep(1);
    }
    // Diagnosticar
    map<string, vector<Pieza>> piezasPorEstacion = diagnosticar(v);
    for (auto p : piezasPorEstacion)
    {
        lista_estaciones->addItem(QString::fromStdString(p.first));
        cout << "Piezas a reemplazar en Sistema de " << p.first << ":\n";
        for (Pieza &pieza : p.second)
        {
            lista_repuestos->addItem(QString::fromStdString(pieza.getNombre()));
            cout << pieza.getNombre() << "\n";
        }
    }
    // Hacer trabajo
    for (auto p : piezasPorEstacion)
    {
        // Determinar estación de trabajo y trabajar
        for (EstacionTrabajo &e : this->estaciones)
        {
            if (e.getNombre() == p.first)
            {
                cout << "Enviando a estación de " << p.first << "\n";
                e.iniciarEstacion(v, p.second);
                break;
            }
        }
    }
    cout << "Vehículo liberado\n========\n";
}
