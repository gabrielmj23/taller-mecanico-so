#pragma once
#include <map>
#include <Pieza.h>
using namespace std;

class Inventario
{
private:
    map<string, int> stock;

public:
    // Constructor
    Inventario();
    // Getter
    map<string, int> getStock();
    // Utilidades de inventario
    void agregarPiezas(Pieza p, int cantidad);
    Pieza sacarPieza(string nombre);
    int buscarCantidadPiezaPorNombre(string nombre);
};