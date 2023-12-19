#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <pthread.h>
#include <EstacionTrabajo.h>
#include <Vehiculo.h>
#include <SistemaVehiculo.h>
#include <Pieza.h>
using namespace std;

#define RANDOM_FUNC rand() % 2 ? FUNCIONA : FALLA

Vehiculo crearCorolla(string cedula, string nombre, string placa)
{
    // Sistema de lubricación
    SistemaVehiculo lubricacion("Lubricación", vector<Pieza>{
                                                   Pieza("Aceite", "Toyota Genuine Motor Oil", RANDOM_FUNC),
                                                   Pieza("Bomba de aceite", "Bomba de 4 cilindros", RANDOM_FUNC),
                                                   Pieza("Filtro de aceite", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Carter de aceite", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Cojinetes", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Árboles de levas", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Válvulas", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Tapón de drenaje", "Sin descripción", RANDOM_FUNC)});

    // Sistema de motor
    SistemaVehiculo motor("Motor", vector<Pieza>{
                                       Pieza("Cilindros", "4 unidades, de 1800 c.c", RANDOM_FUNC),
                                       Pieza("Pistones", "4 unidades", RANDOM_FUNC),
                                       Pieza("Válvulas", "16 unidades de tipo DOHC", RANDOM_FUNC),
                                       Pieza("Cigüeñal", "Sin descripción", RANDOM_FUNC),
                                       Pieza("Bielas", "Sin descripción", RANDOM_FUNC)});

    // Sistema de transmisión
    SistemaVehiculo transmision("Transmision", vector<Pieza>{
                                                   Pieza("Caja de cambios", "Caja automática CVT", RANDOM_FUNC),
                                                   Pieza("Embrague", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Árbol de transmisión", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Diferencial", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Palieres", "Sin descripción", RANDOM_FUNC),
                                               });

    // Sistema de dirección
    SistemaVehiculo direccion("Dirección", vector<Pieza>{
                                               Pieza("Volante", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Caja de dirección", "Caja electro-asistida", RANDOM_FUNC),
                                               Pieza("Barra de acoplamiento", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Brazos de dirección", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Neumáticos direccionales", "Sin descripción", RANDOM_FUNC),
                                           });

    // Sistema de combustible
    SistemaVehiculo combustible("Combustible", vector<Pieza>{
                                                   Pieza("Tanque de combustible", "De 50 litros", RANDOM_FUNC),
                                                   Pieza("Bomba de combustible", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Filtro de combustible", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Inyectores", "Sin descripción", RANDOM_FUNC),
                                                   Pieza("Regulador de presión", "Sin descripción", RANDOM_FUNC),
                                               });

    // Sistema de suspensión
    SistemaVehiculo suspension("Suspension", vector<Pieza>{
                                                 Pieza("Amortiguadores", "De gas", RANDOM_FUNC),
                                                 Pieza("Muelle helicoidal", "De tipo MacPherson", RANDOM_FUNC),
                                                 Pieza("Barra de torsión", "Para la suspensión trasera", RANDOM_FUNC),
                                             });

    // Sistema de frenos
    SistemaVehiculo frenos("Frenos", vector<Pieza>{
                                         Pieza("Pedal de freno", "Sin descripción", RANDOM_FUNC),
                                         Pieza("Asistencia de freno", "ABS + EBD + BA", RANDOM_FUNC),
                                         Pieza("Discos ventilados", "Para los frenos delanteros", RANDOM_FUNC),
                                         Pieza("Discos sólidos", "Para los frenos traseros", RANDOM_FUNC),
                                         Pieza("Pastillas de freno", "Sin descripción", RANDOM_FUNC),
                                         Pieza("Tambor de freno", "Sin descripción", RANDOM_FUNC),
                                         Pieza("Zapatas de freno", "Sin descripción", RANDOM_FUNC),
                                     });

    // Sistema de seguridad
    SistemaVehiculo seguridad("Seguridad", vector<Pieza>{
                                               Pieza("Cinturones de seguridad", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Airbags", "Frontales y laterales", RANDOM_FUNC),
                                               Pieza("Cierre centralizado", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Alarma", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Sensores de estacionamiento", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Control de estabilidad", "De tipo ESP", RANDOM_FUNC),
                                           });

    // Sistema eléctrico
    SistemaVehiculo electrico("Eléctrico", vector<Pieza>{
                                               Pieza("Batería", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Sistema de encendido", "Sin descripción", RANDOM_FUNC),
                                               Pieza("Sistema de iluminación", "Con luces LED", RANDOM_FUNC),
                                               Pieza("Tablero de control", "De tipo analógico", RANDOM_FUNC)});

    // Sistema de refrigeración
    SistemaVehiculo refrigeracion("Refrigeración", vector<Pieza>{
                                                       Pieza("Compresor", "Sin descripción", RANDOM_FUNC),
                                                       Pieza("Ventilador", "Sin descripción", RANDOM_FUNC),
                                                       Pieza("Condensador", "Sin descripción", RANDOM_FUNC),
                                                       Pieza("Termostato", "Sin descripción", RANDOM_FUNC),
                                                       Pieza("Evaporador", "Sin descripción", RANDOM_FUNC),
                                                   });

    // Sistema de intercambio de calor
    SistemaVehiculo intercambioCalor("Intercambio de calor", vector<Pieza>{
                                                                 Pieza("Radiador", "Sin descripción", RANDOM_FUNC),
                                                                 Pieza("Refrigerante", "Toyota Super Long Life Coolant", RANDOM_FUNC),
                                                             });

    // Integrar sistemas en el vector del vehículo
    vector<SistemaVehiculo> sistemas = {lubricacion, motor, transmision, direccion, combustible, suspension, frenos, seguridad, electrico, refrigeracion, intercambioCalor};

    // Construir y devolver
    return Vehiculo(cedula, nombre, placa, sistemas);
}

class TallerMecanico
{
private:
	vector<EstacionTrabajo> estaciones;
	vector<Vehiculo> estacionamiento;
	int serviciosTerminados;

public:
	TallerMecanico()
	{
		this->serviciosTerminados = 0;
	}
};

int main()
{
	TallerMecanico taller = TallerMecanico();
	cout << "Taller iniciado:\n";
	while (true)
	{
		cout << "1. Nuevo vehículo\n2. Salir\n";
		int opcion;
		cin >> opcion;
		if (opcion == 2)
			break;
		cout << "Cedula, nombre, placa:\n";
		string cedula, nombre, placa;
		cin >> cedula >> nombre >> placa;
		Vehiculo v = crearCorolla(cedula, nombre, placa);
	}
	return 0;
}
