// PENDIENTE: Elaborar utilizando threads con posix (pthreads)
#include <iostream>
#include <string>
#include <thread>
#include <SistemaVehiculo.h>
using namespace std;
int main() {
	// Declarar sistemas
	SistemaVehiculo motor("Sistema de Motor", {});
	// Declarar resto de sistemas…
	// Abrir hilos de sistemas
	thread motorThread(&SistemaVehiculo::iniciarSistema, &motor);
	// Abrir hilos del resto…
	// Hacer trabajo…
	// Cerrar
}
