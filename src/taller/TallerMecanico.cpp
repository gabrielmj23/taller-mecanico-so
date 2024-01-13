#include "TallerMecanico.h"
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <QString>
#include <QTableWidgetItem>
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
        EstacionTrabajo(0, "Lubricación", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(1, "Motor", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(2, "Transmisión", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(3, "Dirección", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(4, "Combustible", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(5, "Suspensión", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(6, "Frenos", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(7, "Seguridad", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(8, "Electricidad", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(9, "Refrigeración", &this->inventario, &this->inventario_mutex),
        EstacionTrabajo(10, "Intercambio de calor", &this->inventario, &this->inventario_mutex)};
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

void TallerMecanico::setBarraProgreso(QProgressBar *barra_progreso)
{
    this->barra_progreso = barra_progreso;
}

void TallerMecanico::setListaRepuestos(QListWidget *lista_repuestos)
{
    this->lista_repuestos = lista_repuestos;
}

void TallerMecanico::setListaEstaciones(QListWidget *lista_estaciones)
{
    this->lista_estaciones = lista_estaciones;
}

void TallerMecanico::setTablaRepuestos(QTableWidget *tabla_repuestos)
{
    this->tabla_repuestos = tabla_repuestos;
}

void TallerMecanico::setTablaAtendidos(QTableWidget *tabla_atendidos)
{
    this->tabla_atendidos = tabla_atendidos;
}

void TallerMecanico::setTablaEstaciones(QTableWidget *tabla_estaciones)
{
    this->tabla_estaciones = tabla_estaciones;
}

void TallerMecanico::setLabelServiciosTerminados(QLabel *label_servicios_terminados)
{
    this->label_servicios_terminados = label_servicios_terminados;
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

void TallerMecanico::recibirVehiculo(Vehiculo &v, string falla)
{
    cout << "Recibió vehículo de placa: " << v.getPlaca() << "\n---\n";
    // Registrar en tabla de vehículos atendidos
    tabla_atendidos->clearContents();
    tabla_atendidos->setRowCount(0);
    time_t now = std::time(nullptr);
    tm *now_tm = std::localtime(&now);
    char time_str[6];
    strftime(time_str, sizeof(time_str), "%H:%M", now_tm);
    string time_string(time_str);
    vehiculos_atendidos.push_front(VehiculoAtendido{v.getCedulaCliente(), time_string, v.getPlaca(), falla});
    for (int i = 0; i < vehiculos_atendidos.size(); i++)
    {
        tabla_atendidos->insertRow(i);
        tabla_atendidos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(vehiculos_atendidos[i].cedula)));
        tabla_atendidos->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vehiculos_atendidos[i].horaEntrada)));
        tabla_atendidos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vehiculos_atendidos[i].placa)));
        tabla_atendidos->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(vehiculos_atendidos[i].razon)));
    }
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
                e.iniciarEstacion(v, p.second, this->tabla_repuestos, this->tabla_estaciones);
                // Actualizar tabla de estaciones
                tabla_estaciones->clearContents();
                tabla_estaciones->setRowCount(0);
                for (int i = 0; i < estaciones.size(); i++)
                {
                    tabla_estaciones->insertRow(i);
                    tabla_estaciones->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(estaciones[i].getNombre())));
                    tabla_estaciones->setItem(i, 1, new QTableWidgetItem(estaciones[i].getTrabajando() ? "Trabajando" : "Libre"));
                    tabla_estaciones->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(estaciones[i].getPlaca())));
                }
                break;
            }
        }
    }
    // Registrar servicio terminado
    serviciosTerminados++;
    label_servicios_terminados->setText("Servicios Completados: " + QString::number(serviciosTerminados));
    cout << "Vehículo liberado\n========\n";
}
