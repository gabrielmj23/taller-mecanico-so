#include <string>
#include <Inventario.h>
using namespace std;

int Inventario::buscarCantidadPiezaPorNombre(string nombre) {
    int cuenta = 0;
    for (auto p: stock) 
        if (p.getNombre() == nombre) cuenta++;
    return cuenta;
}