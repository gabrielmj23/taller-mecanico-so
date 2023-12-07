#include <iostream>
#include <string>
#include <SistemaVehiculo.h>
using namespace std;

string SistemaVehiculo::getNombre() {
    return nombre;
}

void SistemaVehiculo::iniciarSistema() {
    cout << "Iniciando sistema: " << nombre << '\n';
}

void SistemaVehiculo::reemplazarPieza(Pieza p) {
    for (int i = 0; i < piezas.size(); i++) {
        if (piezas[i].getNombre() == p.getNombre()) {
            piezas[i] = p;
            cout << "Pieza reemplazada: " << p.getNombre() << '\n';
            return;
        }
    }
}