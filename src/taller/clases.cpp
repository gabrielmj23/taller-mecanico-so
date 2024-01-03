#include "clases.h"

ClienteVehiculo::ClienteVehiculo(string tipo, string nombre, string hora, string placa) {
    this->tipo = tipo;
    this->nombre = nombre;
    this->hora = hora;
    this->placa = placa;
}

VehiculoCola::VehiculoCola(int nroPuesto, string placa, string hora) {
    this->nroPuesto = nroPuesto;
    this->placa = placa;
    this->hora = hora;
}

Repuesto::Repuesto(string descripcion, int existencia, string estado) {
    this->descripcion = descripcion;
    this->existencia = existencia;
    this->estado = estado;
}

Estacion::Estacion(string nombre, string placaCarro, string tiempoAcu) {
    this->nombre = nombre;
    this->placaCarro = placaCarro;
    this->tiempoAcu = tiempoAcu;
}


/**
 * @brief Construct a new Cliente:: Cliente object
 *
 * @param nombre
 * @param cedula
 * @param fechaRegistro
 * @param numContacto
 */

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

// cuenta la cantidad de vehiculos de un cliente de un arreglo de vehiculos dado
int Cliente::getNumVehiculos(vector<Vehiculo> vehiculos)
{
    
    int c = 0;


    for (int i = 0; i < vehiculos.size(); i++)
    {
        Vehiculo vehiculo = vehiculos[i];

        if (vehiculo.getCedulaCliente().compare(this->cedula) == 0)
        {
            c++;
        }
    }

    return c;
}


/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 *
 * @param cedulaPropietario
 * @param placa
 * @param ubicacion
 */

int Servicio::nextID = 1;

Servicio::Servicio(string placa, string fechaIni, string fechaFin, string razon, double kmIngreso) 
    : id(nextID++), placaVehiculo(placa), fechaIni(fechaIni), fechaFin(fechaFin), razon(razon), kmIngreso(kmIngreso) {}
Servicio::~Servicio()
{
    decrementarId();
}


int Servicio::getId()
{
    return this->id;
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

double Servicio::getKmIngreso()
{
    return this->kmIngreso;
}

/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 *
 * @param placa
 * @param ubicacion
 * @param servicios
 */

Vehiculo::Vehiculo(string cedulaCliente, string placa, bool ubicacion)
{
    this->cedulaCliente = cedulaCliente;
    this->placa = placa;
    this->ubicacion = ubicacion;
    this->servicios = vector<Servicio>();
}

string Vehiculo::getCedulaCliente()
{
    return this->cedulaCliente;
}
string Vehiculo::getPlaca()
{
    return this->placa;
}

string Vehiculo::getUbicacion()
{
   return ubicacion? "Dentro del Taller" : "Fuera del Taller";
}

int Vehiculo::getNumServicios(vector<Servicio> servicios)
{


    int c = 0;

    for (int i = 0; i < servicios.size(); i++)
    {
        Servicio servicio = servicios[i];

        if (servicio.getPlacaVehiculo().compare(this->placa) == 0)
        {
            c++;
        }
    }

    return c;
}



