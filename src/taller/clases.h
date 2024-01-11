#ifndef CLASES_H
#define CLASES_H
#include <string>
#include <vector>
using namespace std;

class VehiculoCola
{
public:
    int nroPuesto;
    string placa;
    string hora;
    VehiculoCola(int nroPuesto, string placa, string hora);
};

#endif // CLASES_H
