#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Vehiculo.h"
#include "Servicio.h"
using namespace std;

Vehiculo::Vehiculo(string cedulaCliente, string placa, vector<SistemaVehiculo> sistemas)
{
    this->cedulaCliente = cedulaCliente;
    this->placa = placa;
    this->enTaller = false;
    this->sistemas = sistemas;
}

string Vehiculo::getCedulaCliente()
{
    return this->cedulaCliente;
}

string Vehiculo::getPlaca()
{
    return this->placa;
}

bool Vehiculo::getEnTaller()
{
    return this->enTaller;
}

vector<SistemaVehiculo> *Vehiculo::getSistemas()
{
    return &(this->sistemas);
}

void Vehiculo::identificar()
{
    cout << "Cédula propietario: " << cedulaCliente << "\nPlaca: " << placa << '\n';
}

string Vehiculo::serialize()
{
    ostringstream oss;
    oss << cedulaCliente << '-' << placa << '-';
    for (auto sistema : sistemas)
    {
        oss << sistema.serialize() << ' ';
    }
    return oss.str();
}

Vehiculo Vehiculo::deserialize(const string &s)
{
    istringstream iss(s);
    string cedulaCliente, placa;
    vector<SistemaVehiculo> sistemas;
    getline(iss, cedulaCliente, '-');
    getline(iss, placa, '-');
    while (!iss.eof())
    {
        string sistema;
        iss >> sistema;
        sistemas.push_back(SistemaVehiculo::deserialize(sistema));
    }
    return Vehiculo(cedulaCliente, placa, sistemas);
}

vector<Vehiculo> Vehiculo::cargarVehiculosDesdeArchivo()
{
    string nombreArchivo = "../../vehiculos.bin";
    ifstream archivo(nombreArchivo, ios::binary | ios::in);
    vector<Vehiculo> vehiculos;
    if (archivo.is_open())
    {
        while (true)
        {
            size_t cedulaSize, placaSize;
            // Leer cédula
            archivo.read(reinterpret_cast<char *>(&cedulaSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *cedulaBuffer = new char[cedulaSize];
            archivo.read(cedulaBuffer, cedulaSize);
            string cedula(cedulaBuffer, cedulaSize);
            delete[] cedulaBuffer;

            // Leer placa
            archivo.read(reinterpret_cast<char *>(&placaSize), sizeof(size_t));
            char *placaBuffer = new char[placaSize];
            archivo.read(placaBuffer, placaSize);
            string placa(placaBuffer, placaSize);
            delete[] placaBuffer;

            // Guardar vehículo
            Vehiculo vehiculo(cedula, placa, {});
            vehiculos.push_back(vehiculo);
        }
        cout << "Vehículos cargados desde el archivo correctamente.\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura -> VEHÍCULOS.\n";
    }
    return vehiculos;
}

void Vehiculo::guardarVehiculoEnArchivo(Vehiculo vehiculo)
{
    string nombreArchivo = "../../vehiculos.bin";
    ofstream archivo(nombreArchivo, ios::binary | ios::app);

    if (archivo.is_open())
    {
        for (const auto &str : {vehiculo.cedulaCliente, vehiculo.placa})
        {
            size_t len = str.size();
            archivo.write(reinterpret_cast<char *>(&len), sizeof(len));
            archivo.write(str.c_str(), len);
        }
        cout << "Vehículo guardado con éxito\n";
        archivo.close();
    }
    else
    {
        cout << "Error abriendo archivo\n";
    }
}

int Vehiculo::getNumServicios()
{
    vector<Servicio> serviciosVehiculo = Servicio::cargarServiciosDesdeArchivo(this->placa);
    return serviciosVehiculo.size();
}
