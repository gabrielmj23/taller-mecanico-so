#include <mutex>
#include <pthread.h>
#include <queue>
#include <vector>

class Server
{
private:
    int num_threads = 10;           // Cantidad de hilos para el pool
    std::vector<pthread_t> v_hilos; // Vector de hilos
    std::mutex mtx_tareas;          // Mutex para tareas
    std::mutex mtx_respuestas;      // Mutex para respuestas
public:
};