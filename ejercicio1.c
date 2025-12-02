#include <stdio.h>
#include <pthread.h>

// Definición de la estructura 
typedef struct {
    int inicio;
    int fin;
} Rango;

void* imprimir_rango(void* arg) {
    // TODO 1: recibir los datos enviados al hilo
    Rango* r = (Rango*)arg; // Casteamos el argumento a puntero de Rango
    
    for (int i = r->inicio; i <= r->fin; i++) {
        printf("%d ", i);
    }
    
    printf("\n"); 
    
    pthread_exit(NULL); 
}

int main() {

    pthread_t hilos[3];
    // TODO 2: completar rangos
    Rango rangos[3] = {
        {1, 5},
        {6, 10},
        {11, 15}
    };

    // TODO 3: crear los hilos usando pthread_create
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&hilos[i], NULL, imprimir_rango, &rangos[i]) != 0) {
            perror("Error al crear el hilo");
            return 1;
        }
    }

    // TODO 4: sincronizar usando pthread_join
    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL); 
    }

    printf("\nTodos los hilos han terminado.\n");
    return 0;
}
