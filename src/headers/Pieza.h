#pragma once
#include <string>
using namespace std;

class Pieza {
    private:
        string nombre;
    public:
        Pieza(string nombre);
        string getNombre();
};