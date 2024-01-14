#include <map>
#include <string>
#include <vector>
#include <deque>
#include <pthread.h>
#include <iostream>
#include <QListWidget>
#include <QProgressBar>
#include <QTableWidget>
#include <QLabel>
#include "Pieza.h"
#include "Vehiculo.h"
#include "EstacionTrabajo.h"
#include "Inventario.h"
using namespace std;

typedef struct vehiAtendido
{
    string cedula;
    string horaEntrada;
    string placa;
    string razon;
} VehiculoAtendido;

typedef struct vehiCola
{
    Vehiculo *vehiculo;
    string falla;
    string horaEntrada;
} VehiculoCola;

class TallerMecanico
{
private:
    // Inventario de repuestos
    Inventario inventario;
    pthread_mutex_t inventario_mutex;
    // Estaciones de trabajo
    vector<EstacionTrabajo> estaciones;
    // Estacionamiento
    deque<VehiculoCola> estacionamiento;

public:
    // Constructor
    TallerMecanico();
    // Servicios realizados
    int serviciosTerminados;
    deque<VehiculoAtendido> vehiculos_atendidos;
    // Para las condiciones de carrera
    pthread_mutex_t estacionamiento_mutex;
    pthread_cond_t estacionamiento_cond;
    pthread_mutex_t ui_mutex;
    // Variables de UI
    QProgressBar *barra_progreso;
    QListWidget *lista_repuestos;
    QListWidget *lista_estaciones;
    QTableWidget *tabla_repuestos;
    QTableWidget *tabla_atendidos;
    QTableWidget *tabla_estaciones;
    QTableWidget *tabla_cola;
    QLabel *label_servicios_terminados;
    QLabel *label_cola;
    // Setters de UI
    void setBarraProgreso(QProgressBar *barra_progreso);
    void setListaRepuestos(QListWidget *lista_repuestos);
    void setListaEstaciones(QListWidget *lista_estaciones);
    void setTablaRepuestos(QTableWidget *tabla_repuestos);
    void setTablaAtendidos(QTableWidget *tabla_atendidos);
    void setTablaEstaciones(QTableWidget *tabla_estaciones);
    void setTablaCola(QTableWidget *tabla_cola);
    void setLabelServiciosTerminados(QLabel *label_servicios_terminados);
    void setLabelCola(QLabel *label_cola);
    // Getters
    vector<EstacionTrabajo> getEstaciones();
    deque<VehiculoCola> &getEstacionamiento();
    Inventario &getInventario();
    pthread_mutex_t &getInventarioMutex();
    VehiculoCola sacarVehiculoCola();
    // Devuelve las estaciones de trabajo por las que tiene que pasar el vehículo las piezas a reemplazar
    map<string, vector<Pieza>> diagnosticar(Vehiculo &v);
    // Recibe un vehículo para hacer su evaluación y operación
    void recibirVehiculo(Vehiculo &v, string falla);
};
