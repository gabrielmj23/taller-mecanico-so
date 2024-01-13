#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <QListWidget>
#include <QProgressBar>
#include <QTableWidget>
#include "Pieza.h"
#include "Vehiculo.h"
#include "EstacionTrabajo.h"
#include "Inventario.h"
using namespace std;

class TallerMecanico
{
private:
    Inventario inventario;
    pthread_mutex_t inventario_mutex;
    vector<EstacionTrabajo> estaciones;
    vector<Vehiculo> estacionamiento;
    int serviciosTerminados;

public:
    // Constructor
    TallerMecanico();
    // Variables de UI
    QProgressBar *barra_progreso;
    QListWidget *lista_repuestos;
    QListWidget *lista_estaciones;
    QTableWidget *tabla_repuestos;
    // Setters de UI
    void setBarraProgreso(QProgressBar *barra_progreso);
    void setListaRepuestos(QListWidget *lista_repuestos);
    void setListaEstaciones(QListWidget *lista_estaciones);
    void setTablaRepuestos(QTableWidget *tabla_repuestos);
    // Getters
    vector<EstacionTrabajo> getEstaciones();
    Inventario &getInventario();
    pthread_mutex_t &getInventarioMutex();
    // Devuelve las estaciones de trabajo por las que tiene que pasar el vehículo las piezas a reemplazar
    map<string, vector<Pieza>> diagnosticar(Vehiculo &v);
    // Recibe un vehículo para hacer su evaluación y operación
    void recibirVehiculo(Vehiculo &v, string falla);
};