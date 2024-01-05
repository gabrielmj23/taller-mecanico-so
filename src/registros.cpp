#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct RegistroServicio
{
    string fecha;
    string servicioRealizado;
};

class Vehiculo
{
private:
    string placa;
    vector<RegistroServicio> registrosServicios;

public:
    void agregarServicio(const string &fecha, const string &servicio);
    const vector<RegistroServicio> &obtenerRegistrosServicios() const;
    void setPlaca(const string &nuevoValor);
    const string &getPlaca() const;
    void guardarServiciosEnArchivo() const;
    void cargarServiciosDesdeArchivo();
};

void Vehiculo::setPlaca(const string &nuevoValor)
{
    placa = nuevoValor;
}

const string &Vehiculo::getPlaca() const
{
    return placa;
}

void Vehiculo::agregarServicio(const string &fecha, const string &servicio)
{
    RegistroServicio nuevoRegistro;
    nuevoRegistro.fecha = fecha;
    nuevoRegistro.servicioRealizado = servicio;
    registrosServicios.push_back(nuevoRegistro);
}

const vector<RegistroServicio> &Vehiculo::obtenerRegistrosServicios() const
{
    return registrosServicios;
}

// Dentro de la función guardarServiciosEnArchivo
void Vehiculo::guardarServiciosEnArchivo() const
{
    string nombreArchivo = placa + "_servicios.bin";
    ofstream archivo(nombreArchivo, ios::binary | ios::app); // Cambio aquí a ios::app

    if (archivo.is_open())
    {
        for (const auto &registro : registrosServicios)
        {
            size_t fechaSize = registro.fecha.size();
            size_t servicioSize = registro.servicioRealizado.size();

            // Escribir tamaño de la fecha y la fecha
            archivo.write(reinterpret_cast<const char *>(&fechaSize), sizeof(size_t));
            archivo.write(registro.fecha.c_str(), fechaSize);

            // Escribir tamaño del servicio y el servicio
            archivo.write(reinterpret_cast<const char *>(&servicioSize), sizeof(size_t));
            archivo.write(registro.servicioRealizado.c_str(), servicioSize);
        }

        archivo.close();
        cout << "Servicios guardados en el archivo correctamente.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo para escritura.\n";
    }
}

// Dentro de la función cargarServiciosDesdeArchivo
void Vehiculo::cargarServiciosDesdeArchivo()
{
    string nombreArchivo = placa + "_servicios.bin";
    ifstream archivo(nombreArchivo, ios::binary | ios::in);

    if (archivo.is_open())
    {
        registrosServicios.clear(); // Limpiar el vector antes de cargar datos

        while (true)
        {
            size_t fechaSize, servicioSize;

            // Leer tamaño de la fecha
            archivo.read(reinterpret_cast<char *>(&fechaSize), sizeof(size_t));
            if (archivo.eof())
            {
                break;
            }

            // Leer la fecha
            char *fechaBuffer = new char[fechaSize];
            archivo.read(fechaBuffer, fechaSize);
            string fecha(fechaBuffer, fechaSize);
            delete[] fechaBuffer;

            // Leer tamaño del servicio
            archivo.read(reinterpret_cast<char *>(&servicioSize), sizeof(size_t));

            // Leer el servicio
            char *servicioBuffer = new char[servicioSize];
            archivo.read(servicioBuffer, servicioSize);
            string servicio(servicioBuffer, servicioSize);
            delete[] servicioBuffer;

            RegistroServicio registro;
            registro.fecha = fecha;
            registro.servicioRealizado = servicio;

            registrosServicios.push_back(registro);
        }

        cout << "Servicios cargados desde el archivo correctamente.\n";
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para lectura.\n";
    }
}