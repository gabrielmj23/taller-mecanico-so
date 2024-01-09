#include "ClienteVehiculo.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ClienteVehiculo::ClienteVehiculo(string tipo, string nombre, string hora, string placa)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->hora = hora;
    this->placa = placa;
}

string ClienteVehiculo::getTipo()
{
    return this->tipo;
}

string ClienteVehiculo::getNombre()
{
    return this->nombre;
}

string ClienteVehiculo::getHora()
{
    return this->hora;
}

string ClienteVehiculo::getPlaca()
{
    return this->placa;
}

vector<ClienteVehiculo> ClienteVehiculo::leerClienteVehiculosDeArchivo()
{
    string nombreArchivo = "../../movimientoTaller.bin";
    ifstream archivo(nombreArchivo, ios::binary | ios::in);
    vector<ClienteVehiculo> clienteVehiculos;
    if (archivo.is_open())
    {
        while (true)
        {
            size_t tipoSize, nombreSize, horaSize, placaSize;
            // Leer tipo
            archivo.read(reinterpret_cast<char *>(&tipoSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *tipoBuffer = new char[tipoSize];
            archivo.read(tipoBuffer, tipoSize);
            string tipo(tipoBuffer, tipoSize);
            delete[] tipoBuffer;

            // Leer nombre
            archivo.read(reinterpret_cast<char *>(&nombreSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *nombreBuffer = new char[nombreSize];
            archivo.read(nombreBuffer, nombreSize);
            string nombre(nombreBuffer, nombreSize);
            delete[] nombreBuffer;

            // Leer hora
            archivo.read(reinterpret_cast<char *>(&horaSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *horaBuffer = new char[horaSize];
            archivo.read(horaBuffer, horaSize);
            string hora(horaBuffer, horaSize);
            delete[] horaBuffer;

            // Leer placa
            archivo.read(reinterpret_cast<char *>(&placaSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *placaBuffer = new char[placaSize];
            archivo.read(placaBuffer, placaSize);
            string placa(placaBuffer, placaSize);
            delete[] placaBuffer;

            // Guardar cliente
            ClienteVehiculo clienteV(tipo, nombre, hora, placa);
            clienteVehiculos.push_back(clienteV);
        }
        cout << "Movimientos cargados desde el archivo correctamente.\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura.\n";
    }
    reverse(clienteVehiculos.begin(), clienteVehiculos.end());
    return clienteVehiculos;
}

void ClienteVehiculo::guardarClienteVehiculo(ClienteVehiculo clienteVehiculo)
{
    string nombreArchivo = "../../movimientoTaller.bin";
    ofstream archivo(nombreArchivo, ios::binary | ios::app);

    if (archivo.is_open())
    {
        for (const auto &str : {clienteVehiculo.tipo, clienteVehiculo.nombre, clienteVehiculo.hora, clienteVehiculo.placa})
        {
            size_t len = str.size();
            archivo.write(reinterpret_cast<char *>(&len), sizeof(size_t));
            archivo.write(str.c_str(), len);
        }
        cout << "ClienteVehiculo guardado con éxito\n";
        archivo.close();
    }
    else
    {
        cout << "Error abriendo archivo\n";
    }
}
