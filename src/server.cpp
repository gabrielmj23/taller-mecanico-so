#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <limits.h>
using namespace std;

#define PORT 6060
#define BUFSIZE 4096
#define SOCKETERR (-1)
#define SERVER_BACKLOG 1

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

void manejar_conexion(int client_socket);

int main()
{
    int server_socket, client_socket, addr_size;
    SA_IN server_addr, client_addr;
    // Crear socket TCP
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKETERR)
    {
        cout << "Error creando socket\n";
        exit(1);
    }
    // Conectar socket a puerto
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (SA *)&server_addr, sizeof(server_addr)) == SOCKETERR)
    {
        cout << "Error conectando socket a puerto\n";
        exit(1);
    }
    // Escuchar
    if (listen(server_socket, SERVER_BACKLOG) == SOCKETERR)
    {
        cout << "Error escuchando\n";
        exit(1);
    }
    while (true)
    {
        cout << "Esperando...\n";
        // Aceptar conexión y trabajar
        addr_size = sizeof(SA_IN);
        if ((client_socket = accept(server_socket, (SA *)&client_addr, (socklen_t *)&addr_size)) == SOCKETERR)
        {
            cout << "Error aceptando conexión\n";
            exit(1);
        }
        cout << "Conexión aceptada\n";
        manejar_conexion(client_socket);
    }
    return 0;
}

void manejar_conexion(int client_socket)
{
    char buf[BUFSIZE];
    size_t bytes;
    int msg_size = 0;
    char act_path[PATH_MAX + 1];
    // Leer mensaje del cliente
    while ((bytes = read(client_socket, buf + msg_size, sizeof(buf) - msg_size - 1)) > 0)
    {
        msg_size += bytes;
        if (msg_size > BUFSIZE - 1 || buf[msg_size - 1] == '\n')
            break;
    }
    if (bytes == SOCKETERR)
    {
        cout << "Error leyendo mensaje\n";
        exit(1);
    }
    buf[msg_size - 1] = 0;
    cout << "PETICIÓN: " << buf << endl;
    write(client_socket, "Hola mundo\n", 12);
    close(client_socket);
    cout << "Conexión cerrada\n";
}