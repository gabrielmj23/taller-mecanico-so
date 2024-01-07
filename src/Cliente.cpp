#include "Cliente.h"
#include "Vehiculo.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// Constructor
Cliente::Cliente(string nombre, string cedula, string fechaRegistro, string numContacto)
    : nombre(nombre), cedula(cedula), fechaRegistro(fechaRegistro), numContacto(numContacto)
{
}

// Getters
string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getCedula()
{
    return cedula;
}

string Cliente::getFechaRegistro()
{
    return fechaRegistro;
}

string Cliente::getNumContacto()
{
    return numContacto;
}

// Cuenta la cantidad de vehiculos de un cliente de un arreglo de vehiculos dado
int Cliente::getNumVehiculos(vector<Vehiculo> &vehiculos)
{
    int c = 0;
    for (Vehiculo v : vehiculos)
    {
        if (v.getCedulaCliente().compare(this->cedula) == 0)
        {
            c++;
        }
    }
    return c;
}

vector<Cliente> Cliente::cargarClientesDesdeArchivo()
{
    string nombreArchivo = "clientes.bin";
    ifstream archivo(nombreArchivo, ios::binary | ios::in);
    vector<Cliente> clientes;
    if (archivo.is_open())
    {
        while (true)
        {
            size_t nombreSize, cedulaSize, fechaRegistroSize, numContactoSize;
            // Leer nombre
            archivo.read(reinterpret_cast<char *>(&nombreSize), sizeof(size_t));
            if (archivo.eof())
                break;
            char *nombreBuffer = new char[nombreSize];
            archivo.read(nombreBuffer, nombreSize);
            string nombre(nombreBuffer, nombreSize);
            delete[] nombreBuffer;

            // Leer cedula
            archivo.read(reinterpret_cast<char *>(&cedulaSize), sizeof(size_t));
            char *cedulaBuffer = new char[cedulaSize];
            archivo.read(cedulaBuffer, cedulaSize);
            string cedula(cedulaBuffer, cedulaSize);
            delete[] cedulaBuffer;

            // Leer fecha de registro
            archivo.read(reinterpret_cast<char *>(&fechaRegistroSize), sizeof(size_t));
            char *fechaRegistroBuffer = new char[fechaRegistroSize];
            archivo.read(fechaRegistroBuffer, fechaRegistroSize);
            string fechaRegistro(fechaRegistroBuffer, fechaRegistroSize);
            delete[] fechaRegistroBuffer;

            // Leer número de contacto
            archivo.read(reinterpret_cast<char *>(&numContactoSize), sizeof(size_t));
            char *numContactoBuffer = new char[numContactoSize];
            archivo.read(numContactoBuffer, numContactoSize);
            string numContacto(numContactoBuffer, numContactoSize);
            delete[] numContactoBuffer;

            // Guardar cliente
            Cliente cliente(nombre, cedula, fechaRegistro, numContacto);
            clientes.push_back(cliente);
        }
        cout << "Clientes cargados desde el archivo correctamente.\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura.\n";
    }
    return clientes;
}

void Cliente::guardarClienteEnArchivo(Cliente cliente)
{
    string nombreArchivo = "clientes.bin";
    ofstream archivo(nombreArchivo, ios::binary | ios::app);

    if (archivo.is_open())
    {
        for (const auto &str : {cliente.nombre, cliente.cedula, cliente.fechaRegistro, cliente.numContacto})
        {
            size_t len = str.size();
            archivo.write(reinterpret_cast<char *>(&len), sizeof(len));
            archivo.write(str.c_str(), len);
        }
        cout << "Cliente guardado con éxito\n";
        archivo.close();
    }
    else
    {
        cout << "Error abriendo archivo\n";
    }
}
