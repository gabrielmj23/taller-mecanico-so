#include "server.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <limits.h>
#include <pthread.h>
#include <queue>
using namespace std;

#define PORT 6060
#define BUFSIZE 4096
#define SOCKETERR (-1)
#define SERVER_BACKLOG 50
#define THREAD_POOL_SIZE 6

// Para la thread pool
pthread_t thread_pool[THREAD_POOL_SIZE];
queue<int *> client_queue;
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

// Para el servidor
typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

void *init_servidor(void *arg)
{
    // Inicializar thread pool
    for (int i = 0; i < THREAD_POOL_SIZE; i++)
    {
        pthread_create(&thread_pool[i], NULL, init_hilo_server, NULL);
    }
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
        // Guardar información de la conexión
        int *pclient = (int *)malloc(sizeof(int));
        *pclient = client_socket;
        pthread_mutex_lock(&queue_mutex);
        client_queue.push(pclient);
        pthread_cond_signal(&queue_cond);
        pthread_mutex_unlock(&queue_mutex);
    }
    return 0;
}

void *manejar_conexion(void *p_client_socket)
{
    int client_socket = *((int *)p_client_socket);
    free(p_client_socket); // Liberar memoria
    char buf[BUFSIZE];
    size_t bytes;
    int msg_size = 0;
    char act_path[PATH_MAX + 1];
    // Leer mensaje del cliente
    while ((bytes = read(client_socket, buf + msg_size, sizeof(buf) - msg_size - 1)) > 0)
    {
        msg_size += bytes;
        if (msg_size > BUFSIZE - 1 || buf[msg_size - 1] == '/')
            break;
    }
    if (bytes == SOCKETERR)
    {
        cout << "Error leyendo mensaje\n";
        exit(1);
    }
    buf[msg_size - 1] = 0; // Caracter de terminación de string
    cout << "PETICIÓN: " << buf << endl;
    write(client_socket, "Hola mundo\n", 12);
    close(client_socket);
    cout << "Conexión cerrada\n";
    return NULL;
}

void *init_hilo_server(void *arg)
{
    while (true)
    {
        pthread_mutex_lock(&queue_mutex);
        if (client_queue.empty())
        {
            pthread_cond_wait(&queue_cond, &queue_mutex);
        }
        if (!client_queue.empty())
        {
            // Existe conexión
            int *pclient = client_queue.front();
            client_queue.pop();
            manejar_conexion(pclient);
        }
        pthread_mutex_unlock(&queue_mutex);
    }
    return NULL;
}
