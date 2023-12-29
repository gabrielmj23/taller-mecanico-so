#pragma once
#include <string>
#include <vector>

using namespace std;



class Servicio {
    private:
        string fechaIni;
        string fechaFin;
        string razon;
        double kmIngreso;
    public:
        Servicio(string fechaIni, string fechaFin, string razon, double kmIngreso);
        string getFechaIni();
        string getFechaFin();
        string getRazon();
        double getKmIngreso();
};

class Vehiculo{
    private:
        string placa;
        bool ubicacion;
        vector<Servicio> servicios;
    public:
        Vehiculo(string placa, bool ubicacion);
        string getPlaca();
        bool getUbicacion();
        vector<Servicio> *getServicios();
        int getNumServicios();
        void setUbicacion(bool ubicacion);
        void agregarServicio(Servicio servicio);
        
};

class Cliente
{
private:
    string nombre;
    string cedula;
    string fechaRegistro;
    string numContacto;
    vector<Vehiculo> vehiculos;

public:
    Cliente(string nombre, string cedula, string fechaRegistro, string numContacto);
    string getNombre();
    string getCedula();
    string getFechaRegistro();
    string getNumContacto();
    vector<Vehiculo> *getVehiculos();
    int getNumVehiculos();
    void agregarVehiculo(Vehiculo vehiculo);
};