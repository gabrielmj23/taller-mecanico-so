#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Servicio.h"
using namespace std;

Servicio::Servicio(string placa, string fechaIni, string fechaFin, string razon, int kmIngreso)
{
    this->placaVehiculo = placa;
    this->fechaIni = fechaIni;
    this->fechaFin = fechaFin;
    this->razon = razon;
    this->kmIngreso = kmIngreso;
}

string Servicio::getPlacaVehiculo()
{
    return this->placaVehiculo;
}

string Servicio::getFechaIni()
{
    return this->fechaIni;
}

string Servicio::getFechaFin()
{
    return this->fechaFin;
}

string Servicio::getRazon()
{
    return this->razon;
}

int Servicio::getKmIngreso()
{
    return this->kmIngreso;
}

vector<Servicio> Servicio::cargarServiciosDesdeArchivo(string placa)
{
    string nombreArchivo = "../../" + placa + "_servicios.bin";
    ifstream archivo(nombreArchivo, ios::binary | ios::in);
    vector<Servicio> servicios;
    if (archivo.is_open())
    {
        while (true)
        {
            size_t placaSize, fechaIniSize, fechaFinSize, razonSize, kmIngresoSize;
            // Leer placa
            archivo.read(reinterpret_cast<char *>(&placaSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *placaBuffer = new char[placaSize];
            archivo.read(placaBuffer, placaSize);
            string cedula(placaBuffer, placaSize);
            delete[] placaBuffer;

            // Leer fechaIni
            archivo.read(reinterpret_cast<char *>(&fechaIniSize), sizeof(size_t));
            char *fechaIniBuffer = new char[fechaIniSize];
            archivo.read(fechaIniBuffer, fechaIniSize);
            string fechaIni(fechaIniBuffer, fechaIniSize);
            delete[] fechaIniBuffer;

            // Leer fechaFin
            archivo.read(reinterpret_cast<char *>(&fechaFinSize), sizeof(size_t));
            char *fechaFinBuffer = new char[fechaFinSize];
            archivo.read(fechaFinBuffer, fechaFinSize);
            string fechaFin(fechaFinBuffer, fechaFinSize);
            delete[] fechaFinBuffer;

            // Leer razon
            archivo.read(reinterpret_cast<char *>(&razonSize), sizeof(size_t));
            char *razonBuffer = new char[razonSize];
            archivo.read(razonBuffer, razonSize);
            string razon(razonBuffer, razonSize);
            delete[] razonBuffer;

            // Leer kmIngreso
            archivo.read(reinterpret_cast<char *>(&kmIngresoSize), sizeof(size_t));
            char *kmIngresoBuffer = new char[kmIngresoSize];
            archivo.read(kmIngresoBuffer, kmIngresoSize);
            string kmIngreso_str(kmIngresoBuffer, kmIngresoSize);
            delete[] kmIngresoBuffer;
            int kmIngreso = stoi(kmIngreso_str);

            // Guardar vehículo
            Servicio servicio(placa, fechaIni, fechaFin, razon, kmIngreso);
            servicios.push_back(servicio);
        }
        cout << "Servicios cargados desde el archivo correctamente.\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura -> SERVICIOS.\n";
    }
    return servicios;
}

void Servicio::guardarServicioEnArchivo(Servicio servicio)
{
    string nombreArchivo = "../../" + servicio.getPlacaVehiculo() + "_servicios.bin";
    ofstream archivo(nombreArchivo, ios::binary | ios::app);

    if (archivo.is_open())
    {
        for (const auto &str : {servicio.getPlacaVehiculo(), servicio.getFechaIni(), servicio.getFechaFin(), servicio.getRazon(), to_string(servicio.getKmIngreso())})
        {
            size_t len = str.size();
            archivo.write(reinterpret_cast<char *>(&len), sizeof(len));
            archivo.write(str.c_str(), len);
        }
        cout << "Servicio guardado con éxito\n";
        archivo.close();
    }
    else
    {
        cout << "Error abriendo archivo\n";
    }
}
