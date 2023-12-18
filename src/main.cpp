#include <iostream>
#include <string>
#include <pthread.h>
#include <SistemaVehiculo.h>
using namespace std;

class TallerMecanico
{
private:
	vector<SistemaVehiculo> sistemas;
	vector<pthread_t> hilosTaller;

public:
	TallerMecanico()
	{
		// Declarar sistemas
		SistemaVehiculo lubricacion("Lubricación", {});
		SistemaVehiculo motor("Motor", {});
		SistemaVehiculo transmision("Transmisión", {});
		SistemaVehiculo direccion("Dirección", {});
		SistemaVehiculo combustible("Combustible", {});
		SistemaVehiculo suspension("Suspensión", {});
		SistemaVehiculo frenos("Frenos", {});
		SistemaVehiculo seguridad("Seguridad", {});
		SistemaVehiculo electrico("Eléctrico", {});
		SistemaVehiculo refrigeracionDeCabina("Refrigeración de cabina", {});
		SistemaVehiculo intercambiadorDeCalor("Intercambiador de calor", {});
		// Agregar piezas a sistemas
		this->sistemas = {lubricacion, motor, transmision, direccion, combustible, suspension, frenos, seguridad, electrico, refrigeracionDeCabina, intercambiadorDeCalor};
	}

	void iniciarTaller()
	{
		for (int i = 0; i < sistemas.size(); i++)
		{
			pthread_t hilo;
			pthread_create(&hilo, NULL, [](void* arg) -> void* {
				SistemaVehiculo* sistema = static_cast<SistemaVehiculo*>(arg);
				sistema->iniciarSistema();
				return nullptr;
			}, &sistemas[i]);
			hilosTaller.push_back(hilo);
		}
		for (auto hilo : hilosTaller)
		{
			pthread_join(hilo, NULL);
		}
	}

	void reemplazarPieza(Pieza p)
	{
		for (int i = 0; i < sistemas.size(); i++)
		{
			sistemas[i].reemplazarPieza(p);
		}
	}
};

int main()
{
	TallerMecanico taller = TallerMecanico();
	taller.iniciarTaller();
	return 0;
}
