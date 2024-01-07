#pragma once
#include <vector>
#include <Pieza.h>
using namespace std;

class Inventario {
    private:
        vector<Pieza> stock;
    public:
        Inventario(vector<Pieza> stock);
        void agregarPieza(Pieza p);
        Pieza sacarPieza(string nombre);
        int buscarCantidadPiezaPorNombre(string nombre); 
};