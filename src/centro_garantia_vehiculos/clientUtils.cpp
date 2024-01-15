#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "clientUtils.h"
#include <errno.h>
using namespace std;

enum TipoMensaje
{
    NUEVO_CLIENTE,
    VEHICULO_INGRESADO,
};

typedef struct unidad
{
    string cedula;
    string placa;
    string razon;
    int kmIngreso;
} UnidadVehiculo;

bool informarClienteNuevo()
{
    // Crear socket de cliente
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cerr << "Error creando socket\n";
        return false;
    }
    // Conectar a servidor
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PUERTO_SERVER);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "Error conectando al servidor\n";
        return false;
    }
    // Enviar tipo
    TipoMensaje type = NUEVO_CLIENTE;
    if (send(sock, &type, sizeof(type), 0) < 0)
    {
        cerr << "Error enviando tipo de mensaje\n";
        return false;
    }
    // Esperar respuesta
    char buffer[1024];
    while (true)
    {
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0)
        {
            break;
        }
        cout.write(buffer, bytes_received);
    }
    // Cerrar socket
    close(sock);
    return true;
}

void *enviarVehiculo(void *arg)
{
    UnidadVehiculo *u = (UnidadVehiculo *)arg;
    // Crear socket de cliente
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cerr << "Error creando socket\n";
        return NULL;
    }
    // Conectar a servidor
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PUERTO_SERVER);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "Error conectando al servidor\nCodigo: " << errno << "\n";
        return NULL;
    }
    // Enviar tipo
    TipoMensaje type = VEHICULO_INGRESADO;
    if (send(sock, &type, sizeof(type), 0) < 0)
    {
        cerr << "Error enviando tipo de mensaje\n";
        return NULL;
    }
    // Enviar datos
    string datos = u->cedula + "-" + u->placa + "-" + u->razon + "-" + to_string(u->kmIngreso) + '\n';
    if (send(sock, datos.c_str(), datos.size(), 0) < 0)
    {
        cerr << "Error enviando datos\n";
        return NULL;
    }
    // Esperar respuesta
    char buffer[1024];
    while (true)
    {
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0)
        {
            break;
        }
        cout.write(buffer, bytes_received);
    }
    // Cerrar socket
    close(sock);
    return NULL;
}
