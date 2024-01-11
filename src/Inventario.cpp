#include <string>
#include <vector>
#include <map>
#include "Inventario.h"
#include "Pieza.h"
using namespace std;

Inventario::Inventario()
{
    vector<string> PIEZAS_COROLLA = {
        "Aceite",
        "Bomba de aceite",
        "Filtro de aceite",
        "Carter de aceite",
        "Cojinetes",
        "Árboles de levas",
        "Válvulas",
        "Tapón de drenaje",
        "Cilindros",
        "Pistones",
        "Válvulas",
        "Cigüeñal",
        "Bielas",
        "Caja de cambios",
        "Embrague",
        "Árbol de transmisión",
        "Diferencial",
        "Palieres",
        "Volante",
        "Caja de dirección",
        "Barra de acoplamiento",
        "Brazos de dirección",
        "Neumáticos direccionales",
        "Tanque de combustible",
        "Bomba de combustible",
        "Filtro de combustible",
        "Inyectores",
        "Regulador de presión",
    };

    map<string, int> m{};
    // Stock inicial del taller
    for (string nombre : PIEZAS_COROLLA)
    {
        m[nombre] = 10;
    }
    this->stock = m;
}

map<string, int> Inventario::getStock()
{
    return stock;
}

void Inventario::agregarPiezas(Pieza p, int cantidad)
{
    stock[p.getNombre()] += cantidad;
}

Pieza Inventario::sacarPieza(string nombre)
{
    if (!stock[nombre])
        return Pieza("No existe", FUNCIONA);
    stock[nombre]--;
    return Pieza(nombre, FUNCIONA);
}

int Inventario::buscarCantidadPiezaPorNombre(string nombre)
{
    return stock[nombre];
}