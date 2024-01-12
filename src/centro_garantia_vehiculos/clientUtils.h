#pragma once
#include <string>
using namespace std;
#define PUERTO_SERVER 7070

// Informa al servidor que debe actualizar la lista de clientes
bool informarClienteNuevo();

// Envía al servidor un vehículo para su diagnóstico y reparación
bool enviarVehiculo(string cedula, string placa, string razon, int kmIngreso);