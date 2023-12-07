#include <string>
#include <Pieza.h>
using namespace std;

Pieza::Pieza(string nombre) {
    this->nombre = nombre;
}

string Pieza::getNombre() {
    return nombre;
}