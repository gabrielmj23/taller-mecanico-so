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

// Función para escuchar al estacionamiento y atender a los vehículos de ahí
void *operarTaller(void *arg)
{
    TallerMecanico *taller = (TallerMecanico *)arg;
    while (true)
    {
        pthread_mutex_lock(&taller->estacionamiento_mutex);
        while (taller->getEstacionamiento().empty())
        {
            pthread_cond_wait(&taller->estacionamiento_cond, &taller->estacionamiento_mutex);
        }
        // Hay vehículos en el estacionamiento
        VehiculoCola vehic = taller->sacarVehiculoCola();
        // Registrar en tabla de vehículos atendidos
        pthread_mutex_lock(&taller->ui_mutex);
        taller->tabla_atendidos->clearContents();
        taller->tabla_atendidos->setRowCount(0);
        taller->vehiculos_atendidos.push_front(VehiculoAtendido{vehic.vehiculo->getCedulaCliente(), vehic.horaEntrada, vehic.vehiculo->getPlaca(), vehic.falla});
        for (int i = 0; i < taller->vehiculos_atendidos.size(); i++)
        {
            taller->tabla_atendidos->insertRow(i);
            taller->tabla_atendidos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(taller->vehiculos_atendidos[i].cedula)));
            taller->tabla_atendidos->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(taller->vehiculos_atendidos[i].horaEntrada)));
            taller->tabla_atendidos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(taller->vehiculos_atendidos[i].placa)));
            taller->tabla_atendidos->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(taller->vehiculos_atendidos[i].razon)));
        }
        // Asignar piezas basado en la falla
        Vehiculo copiaVehiculo(vehic.vehiculo->getCedulaCliente(), vehic.vehiculo->getPlaca());
        copiaVehiculo.registrarFalla(vehic.falla);
        for (int i = 0; i <= 10; i++)
        {
            taller->barra_progreso->setValue(i * 10);
            sleep(1);
        }
        // Diagnosticar
        map<string, vector<Pieza>> piezasPorEstacion = taller->diagnosticar(copiaVehiculo);
        for (auto &p : piezasPorEstacion)
        {
            taller->lista_estaciones->addItem(QString::fromStdString(p.first));
            cout << "Piezas a reemplazar en Sistema de " << p.first << ":\n";
            for (Pieza &pieza : p.second)
            {
                taller->lista_repuestos->addItem(QString::fromStdString(pieza.getNombre()));
            }
        }
        sleep(2);
        pthread_mutex_unlock(&taller->ui_mutex);
        // Hacer trabajo
        for (auto &p : piezasPorEstacion)
        {
            // Determinar estación de trabajo y trabajar
            for (EstacionTrabajo &e : taller->getEstaciones())
            {
                if (e.getNombre() == p.first)
                {
                    cout << "Enviando a estación de " << p.first << "\n";
                    e.iniciarEstacion(copiaVehiculo, p.second, taller->tabla_repuestos, taller->tabla_estaciones);
                    break;
                }
            }
        }
        // Registrar servicio terminado
        taller->serviciosTerminados++;
        pthread_mutex_lock(&taller->ui_mutex);
        taller->label_servicios_terminados->setText("Servicios Completados: " + QString::number(taller->serviciosTerminados));
        pthread_mutex_unlock(&taller->ui_mutex);
        cout << "Vehículo liberado\n========\n";
        pthread_mutex_unlock(&taller->estacionamiento_mutex);
    }
    return NULL;
}

TallerMecanico::TallerMecanico()
{
    this->serviciosTerminados = 0;
    this->inventario = Inventario();
    this->inventario_mutex = PTHREAD_MUTEX_INITIALIZER;
    this->estacionamiento_mutex = PTHREAD_MUTEX_INITIALIZER;
    this->estacionamiento_cond = PTHREAD_COND_INITIALIZER;
    this->ui_mutex = PTHREAD_MUTEX_INITIALIZER;
    // Crear estaciones
    this->estaciones = vector<EstacionTrabajo>{
        EstacionTrabajo(0, "Lubricación", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(1, "Motor", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(2, "Transmisión", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(3, "Dirección", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(4, "Combustible", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(5, "Suspensión", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(6, "Frenos", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(7, "Seguridad", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(8, "Electricidad", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(9, "Refrigeración", &this->inventario, &this->inventario_mutex, &this->ui_mutex),
        EstacionTrabajo(10, "Intercambio de calor", &this->inventario, &this->inventario_mutex, &this->ui_mutex)};
    // Iniciar trabajo
    pthread_t hiloTaller;
    pthread_t hiloTaller2;
    pthread_create(&hiloTaller, nullptr, operarTaller, (void *)this);
    pthread_create(&hiloTaller, nullptr, operarTaller, (void *)this);
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

void TallerMecanico::setTablaCola(QTableWidget *tabla_cola)
{
    this->tabla_cola = tabla_cola;
}

void TallerMecanico::setLabelServiciosTerminados(QLabel *label_servicios_terminados)
{
    this->label_servicios_terminados = label_servicios_terminados;
}

void TallerMecanico::setLabelCola(QLabel *label_cola)
{
    this->label_cola = label_cola;
}

vector<EstacionTrabajo> TallerMecanico::getEstaciones()
{
    return this->estaciones;
}

deque<VehiculoCola> &TallerMecanico::getEstacionamiento()
{
    return this->estacionamiento;
}

Inventario &TallerMecanico::getInventario()
{
    return this->inventario;
}

pthread_mutex_t &TallerMecanico::getInventarioMutex()
{
    return this->inventario_mutex;
}

VehiculoCola TallerMecanico::sacarVehiculoCola()
{
    VehiculoCola v = this->estacionamiento.front();
    this->estacionamiento.pop_front();
    return v;
}

void TallerMecanico::recibirVehiculo(Vehiculo &v, string falla)
{
    cout << "Recibió vehículo de placa: " << v.getPlaca() << "\n---\n";
    // Obtener hora de entrada (hh:mm)
    time_t now = std::time(nullptr);
    tm *now_tm = std::localtime(&now);
    char time_str[6];
    strftime(time_str, sizeof(time_str), "%H:%M", now_tm);
    string time_string(time_str);
    // Agregar vehículo a estacionamiento
    pthread_mutex_lock(&this->estacionamiento_mutex);
    this->estacionamiento.push_back(VehiculoCola{&v, falla, time_string});
    cout << "Entra a estacionamiento" << '\n';
    // Reflejar en la UI
    pthread_mutex_lock(&this->ui_mutex);
    this->label_cola->setText("Vehículos en Espera: " + QString::number(this->estacionamiento.size()));
    this->tabla_cola->clearContents();
    this->tabla_cola->setRowCount(0);
    for (int i = 0; i < this->estacionamiento.size(); i++)
    {
        tabla_cola->insertRow(i);
        tabla_cola->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        tabla_cola->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(this->estacionamiento[i].vehiculo->getPlaca())));
        tabla_cola->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(this->estacionamiento[i].falla)));
        tabla_cola->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(this->estacionamiento[i].horaEntrada)));
    }
    pthread_mutex_unlock(&this->ui_mutex);
    // Indicar al hilo que hay trabajo
    pthread_cond_signal(&this->estacionamiento_cond);
    pthread_mutex_unlock(&this->estacionamiento_mutex);
}
