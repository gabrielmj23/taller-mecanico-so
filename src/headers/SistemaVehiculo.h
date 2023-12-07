#pragma once
#include <string>
#include <vector>
#include <Pieza.h>
using namespace std;

class SistemaVehiculo {
    private:
        string nombre;
        vector<Pieza> piezas;
    public:
        SistemaVehiculo(string nombre, vector<Pieza> piezas);
        string getNombre();
        void iniciarSistema();
        void reemplazarPieza(Pieza p);
};