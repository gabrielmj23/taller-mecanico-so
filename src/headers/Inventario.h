#pragma once
#include <vector>
#include <Pieza.h>
using namespace std;

class Inventario {
    private:
        vector<Pieza> stock;
    public:
        Inventario(vector<Pieza> stock);
        int buscarCantidadPiezaPorNombre(string nombre); 
};