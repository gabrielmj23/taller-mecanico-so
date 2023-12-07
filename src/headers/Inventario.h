#pragma once
#include <vector>
#include <Pieza.h>
using namespace std;

class Inventario {
    private:
        vector<Pieza> stock;
    public:
        int buscarCantidadPiezaPorNombre(string nombre); 
};