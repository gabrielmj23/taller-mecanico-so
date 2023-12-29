#pragma once
#include <string>
#include <vector>

using namespace std;

class Servicio {
    private:
        string placa;
        string fechaIni;
        string fechaFin;
        string razon;
        double kmIngreso;
    public:
        Servicio(string placa, string fechaIni, string fechaFin, string razon, double kmIngreso);
        string getPlaca();
        string getFechaIni();
        string getFechaFin();
        string getRazon();
        double getKmIngreso();
};

class Vehiculo{
    private:
        string cedulaCliente;
        string placa;
        bool ubicacion;
    public:
        Vehiculo(string cedulaCliente, string placa, bool ubicacion);
        string getCedulaCliente();
        string getPlaca();
        string getUbicacion();
        void setUbicacion(bool ubicacion);
};

class Cliente
{
private:
    string nombre;
    string cedula;
    string fechaRegistro;
    string numContacto;

public:
    Cliente(string nombre, string cedula, string fechaRegistro, string numContacto);
    string getNombre();
    string getCedula();
    string getFechaRegistro();
    string getNumContacto();
    int getNumVehiculos(Vehiculo* vehiculos, int tamanio); 
};