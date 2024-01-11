#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Vehiculo.h"
#include "Servicio.h"
using namespace std;

#define RANDOM_FUNC rand() % 5 ? FALLA : FUNCIONA

Vehiculo::Vehiculo(string cedulaCliente, string placa)
{
    this->cedulaCliente = cedulaCliente;
    this->placa = placa;
    this->enTaller = false;
    // GENERA SISTEMAS BASADO EN EL MODELO DEL TOYOTA COROLLA

    // Sistema de lubricación
    SistemaVehiculo lubricacion("Lubricación", vector<Pieza>{
                                                   Pieza("Aceite", FUNCIONA),
                                                   Pieza("Bomba de aceite", FUNCIONA),
                                                   Pieza("Filtro de aceite", FUNCIONA),
                                                   Pieza("Carter de aceite", FUNCIONA),
                                                   Pieza("Cojinetes", FUNCIONA),
                                                   Pieza("Árboles de levas", FUNCIONA),
                                                   Pieza("Válvulas", FUNCIONA),
                                                   Pieza("Tapón de drenaje", FUNCIONA)});

    // Sistema de motor
    SistemaVehiculo motor("Motor", vector<Pieza>{
                                       Pieza("Cilindros", FUNCIONA),
                                       Pieza("Pistones", FUNCIONA),
                                       Pieza("Válvulas", FUNCIONA),
                                       Pieza("Cigüeñal", FUNCIONA),
                                       Pieza("Bielas", FUNCIONA)});

    // Sistema de transmisión
    SistemaVehiculo transmision("Transmisión", vector<Pieza>{
                                                   Pieza("Caja de cambios", FUNCIONA),
                                                   Pieza("Embrague", FUNCIONA),
                                                   Pieza("Árbol de transmisión", FUNCIONA),
                                                   Pieza("Diferencial", FUNCIONA),
                                                   Pieza("Palieres", FUNCIONA),
                                               });

    // Sistema de dirección
    SistemaVehiculo direccion("Dirección", vector<Pieza>{
                                               Pieza("Volante", FUNCIONA),
                                               Pieza("Caja de dirección", FUNCIONA),
                                               Pieza("Barra de acoplamiento", FUNCIONA),
                                               Pieza("Brazos de dirección", FUNCIONA),
                                               Pieza("Neumáticos direccionales", FUNCIONA),
                                           });

    // Sistema de combustible
    SistemaVehiculo combustible("Combustible", vector<Pieza>{
                                                   Pieza("Tanque de combustible", FUNCIONA),
                                                   Pieza("Bomba de combustible", FUNCIONA),
                                                   Pieza("Filtro de combustible", FUNCIONA),
                                                   Pieza("Inyectores", FUNCIONA),
                                                   Pieza("Regulador de presión", FUNCIONA),
                                               });

    // Sistema de suspensión
    SistemaVehiculo suspension("Suspensión", vector<Pieza>{
                                                 Pieza("Amortiguadores", FUNCIONA),
                                                 Pieza("Muelle helicoidal", FUNCIONA),
                                                 Pieza("Barra de torsión", FUNCIONA),
                                             });

    // Sistema de frenos
    SistemaVehiculo frenos("Frenos", vector<Pieza>{
                                         Pieza("Pedal de freno", FUNCIONA),
                                         Pieza("Asistencia de freno", FUNCIONA),
                                         Pieza("Discos ventilados", FUNCIONA),
                                         Pieza("Discos sólidos", FUNCIONA),
                                         Pieza("Pastillas de freno", FUNCIONA),
                                         Pieza("Tambor de freno", FUNCIONA),
                                         Pieza("Zapatas de freno", FUNCIONA),
                                     });

    // Sistema de seguridad
    SistemaVehiculo seguridad("Seguridad", vector<Pieza>{
                                               Pieza("Cinturones de seguridad", FUNCIONA),
                                               Pieza("Airbags", FUNCIONA),
                                               Pieza("Cierre centralizado", FUNCIONA),
                                               Pieza("Alarma", FUNCIONA),
                                               Pieza("Sensores de estacionamiento", FUNCIONA),
                                               Pieza("Control de estabilidad", FUNCIONA),
                                           });

    // Sistema eléctrico
    SistemaVehiculo electrico("Electricidad", vector<Pieza>{
                                                  Pieza("Batería", FUNCIONA),
                                                  Pieza("Sistema de encendido", FUNCIONA),
                                                  Pieza("Sistema de iluminación", FUNCIONA),
                                                  Pieza("Tablero de control", FUNCIONA)});

    // Sistema de refrigeración
    SistemaVehiculo refrigeracion("Refrigeración", vector<Pieza>{
                                                       Pieza("Compresor", FUNCIONA),
                                                       Pieza("Ventilador", FUNCIONA),
                                                       Pieza("Condensador", FUNCIONA),
                                                       Pieza("Termostato", FUNCIONA),
                                                       Pieza("Evaporador", FUNCIONA),
                                                   });

    // Sistema de intercambio de calor
    SistemaVehiculo intercambioCalor("Intercambio de calor", vector<Pieza>{
                                                                 Pieza("Radiador", FUNCIONA),
                                                                 Pieza("Refrigerante", FUNCIONA),
                                                             });
    // Integrar sistemas en el vector del vehículo
    vector<SistemaVehiculo> sistemas = {lubricacion, motor, transmision, direccion, combustible, suspension, frenos, seguridad, electrico, refrigeracion, intercambioCalor};
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

void Vehiculo::setEnTaller(bool enTaller)
{
    this->enTaller = enTaller;
}

void Vehiculo::identificar()
{
    cout << "Cédula propietario: " << cedulaCliente << "\nPlaca: " << placa << '\n';
}

void Vehiculo::registrarFalla(string falla)
{
    if (falla == "Ruidos por suspensión")
    {
        // La falla indica un desgaste en el sistema de suspensión
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Suspensión")
            {
                vector<Pieza> piezasSuspension = sistemas[i].getPiezas();
                for (Pieza &p : piezasSuspension)
                {
                    p.setEstado(RANDOM_FUNC);
                }
            }
        }
    }
    else if (falla == "Acelera de forma brusca")
    {
        // La falla se encuentra en los inyectores y regulador del sistema de combustible
        // También puede estar en el motor
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Combustible")
            {
                vector<Pieza> piezasCombustible = sistemas[i].getPiezas();
                for (Pieza &p : piezasCombustible)
                {
                    if (p.getNombre() == "Inyectores" || p.getNombre() == "Regulador de presión")
                    {
                        p.setEstado(FALLA);
                    }
                }
            }
            else if (sistemas[i].getNombre() == "Motor")
            {
                vector<Pieza> piezasMotor = sistemas[i].getPiezas();
                for (Pieza &p : piezasMotor)
                {
                    p.setEstado(RANDOM_FUNC);
                }
            }
        }
    }
    else if (falla == "Se escuchan chirridos y se detiene el vehículo")
    {
        // La falla se encuentra en el sistema de transmisión
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Transmisión")
            {
                vector<Pieza> piezasTransmision = sistemas[i].getPiezas();
                for (Pieza &p : piezasTransmision)
                {
                    p.setEstado(RANDOM_FUNC);
                }
            }
        }
    }
    else if (falla == "Embrague resbaladizo")
    {
        // La falla es localizada en el embrague del sistema de transmisión
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Transmisión")
            {
                vector<Pieza> piezasTransmision = sistemas[i].getPiezas();
                for (Pieza &p : piezasTransmision)
                {
                    if (p.getNombre() == "Embrague")
                    {
                        p.setEstado(FALLA);
                    }
                }
            }
        }
    }
    else if (falla == "Arranque lento")
    {
        // Falla en el motor, revisar todo el sistema
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Motor")
            {
                vector<Pieza> piezasMotor = sistemas[i].getPiezas();
                for (Pieza &p : piezasMotor)
                {
                    p.setEstado(RANDOM_FUNC);
                }
            }
        }
    }
    else if (falla == "Bolsas de aire defectuosas")
    {
        // Falla en los airbags Toyota del sistema de seguridad
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Seguridad")
            {
                vector<Pieza> piezasSeguridad = sistemas[i].getPiezas();
                for (Pieza &p : piezasSeguridad)
                {
                    if (p.getNombre() == "Airbags")
                    {
                        p.setEstado(FALLA);
                    }
                }
            }
        }
    }
    else if (falla == "Desvío de dirección")
    {
        // Verificar estado del volante y caja de dirección
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Dirección")
            {
                vector<Pieza> piezasDireccion = sistemas[i].getPiezas();
                for (Pieza &p : piezasDireccion)
                {
                    if (p.getNombre() == "Volante" || p.getNombre() == "Caja de dirección")
                    {
                        p.setEstado(FALLA);
                    }
                }
            }
        }
    }
    else if (falla == "Ruido al frenar")
    {
        // Desgaste de pastillas de freno, pero se debe revisar todo el sistema
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Frenos")
            {
                vector<Pieza> piezasFrenos = sistemas[i].getPiezas();
                for (Pieza &p : piezasFrenos)
                {
                    if (p.getNombre() == "Pastillas de freno")
                    {
                        p.setEstado(FALLA);
                    }
                    else
                    {
                        p.setEstado(RANDOM_FUNC);
                    }
                }
            }
        }
    }
    else if (falla == "Fuga de refrigerante")
    {
        // Verificar radiador y refrigerante del vehículo
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Intercambio de calor")
            {
                vector<Pieza> piezasRefrigeracion = sistemas[i].getPiezas();
                for (Pieza &p : piezasRefrigeracion)
                {
                    p.setEstado(FALLA);
                }
            }
        }
    }
    else if (falla == "El seguro de la puerta se desactiva inesperadamente")
    {
        // La falla puede encontrarse en los sistemas eléctrico o de seguridad
        for (int i = 0; i < sistemas.size(); i++)
        {
            if (sistemas[i].getNombre() == "Electricidad")
            {
                vector<Pieza> piezasElectricidad = sistemas[i].getPiezas();
                for (Pieza &p : piezasElectricidad)
                {
                    p.setEstado(RANDOM_FUNC);
                }
            }
            else if (sistemas[i].getNombre() == "Seguridad")
            {
                vector<Pieza> piezasSeguridad = sistemas[i].getPiezas();
                for (Pieza &p : piezasSeguridad)
                {
                    if (p.getNombre() == "Cierre centralizado")
                    {
                        p.setEstado(FALLA);
                    }
                }
            }
        }
    }
    else
    {
        cout << "FALLA NO RECONOCIDA\n";
    }
}

string Vehiculo::serialize()
{
    ostringstream oss;
    oss << cedulaCliente << '-' << placa;
    return oss.str();
}

Vehiculo Vehiculo::deserialize(const string &s)
{
    istringstream iss(s);
    string cedulaCliente, placa;
    vector<SistemaVehiculo> sistemas;
    getline(iss, cedulaCliente, '-');
    getline(iss, placa, '-');
    return Vehiculo(cedulaCliente, placa);
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
            Vehiculo vehiculo(cedula, placa);
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
