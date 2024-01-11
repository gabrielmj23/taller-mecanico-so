#include "TallerMecanico.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Pieza.h"
#include "SistemaVehiculo.h"
#include "EstacionTrabajo.h"
#include "Vehiculo.h"
using namespace std;

TallerMecanico::TallerMecanico()
{
    this->serviciosTerminados = 0;
    // Crear estaciones
    this->estaciones = vector<EstacionTrabajo>{
        EstacionTrabajo("Lubricación"),
        EstacionTrabajo("Motor"),
        EstacionTrabajo("Transmisión"),
        EstacionTrabajo("Dirección"),
        EstacionTrabajo("Combustible"),
        EstacionTrabajo("Suspensión"),
        EstacionTrabajo("Frenos"),
        EstacionTrabajo("Seguridad"),
        EstacionTrabajo("Electricidad"),
        EstacionTrabajo("Refrigeración"),
        EstacionTrabajo("Intercambio de calor")};
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

void TallerMecanico::recibirVehiculo(Vehiculo &v, string falla)
{
    cout << "Recibió vehículo de placa: " << v.getPlaca() << "\n---\n";
    // Asignar piezas basado en la falla
    v.registrarFalla(falla);
    // Diagnosticar
    map<string, vector<Pieza>> piezasPorEstacion = diagnosticar(v);
    for (auto p : piezasPorEstacion)
    {
        cout << "Piezas a reemplazar en Sistema de " << p.first << ":\n";
        for (Pieza &pieza : p.second)
        {
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
