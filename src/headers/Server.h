#pragma once
#include <mutex>
#include <pthread.h>
#include <queue>
#include <vector>
using namespace std;

class Server {
    private:
        int num_threads = 10;           // Cantidad de hilos para el pool
        vector<pthread_t> v_hilos; // Vector de hilos
        mutex mtx_tareas;          // Mutex para tareas
        mutex mtx_respuestas;      // Mutex para respuestas
    public:
};