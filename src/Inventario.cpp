#include <string>
#include <Inventario.h>
using namespace std;

Inventario::Inventario(vector<Pieza> stock)
{
    this->stock = stock;
}

void Inventario::agregarPieza(Pieza p)
{
    stock.push_back(p);
}

Pieza Inventario::sacarPieza(string nombre)
{
    for (int i = 0; i < stock.size(); i++)
    {
        if (stock[i].getNombre() == nombre)
        {
            Pieza ret = stock[i];
            stock.erase(stock.begin() + i);
            return ret;
        }
    }
    return Pieza("No existe", "No existe", FUNCIONA);
}

int Inventario::buscarCantidadPiezaPorNombre(string nombre)
{
    int cuenta = 0;
    for (auto p : stock)
        if (p.getNombre() == nombre)
            cuenta++;
    return cuenta;
}