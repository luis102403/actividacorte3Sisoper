#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>

#define N 1000000
#define PROCESOS 4
#define SHM_NAME "/shm_suma_total" 

int main() {

    // --- TODO 1: Crear memoria compartida ---
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) { perror("Error en shm_open"); return 1; }

    // 2. Configurar el tamaño
    if (ftruncate(fd, PROCESOS * sizeof(long long)) == -1) { perror("Error en ftruncate"); return 1; }

    // 3. Mapear la memoria
    long long* shm = mmap(NULL, PROCESOS * sizeof(long long), 
                          PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm == MAP_FAILED) { perror("Error en mmap"); return 1; }


    int rango = N / PROCESOS;

    for (int p = 0; p < PROCESOS; p++) {

        pid_t pid = fork();

        if (pid < 0) {
            perror("Error en fork");
            return 1;
        }

        if (pid == 0) {
            // --- PROCESO HIJO ---

            int inicio = p * rango + 1;
            int fin = (p == PROCESOS - 1) ? N : inicio + rango - 1;

            long long suma_parcial = 0;

            // --- TODO 2: Calcular la suma del rango asignado ---
            for (int i = inicio; i <= fin; i++) {
                suma_parcial += i;
            }
            
            printf("Proceso %d calculó suma parcial: %lld\n", p, suma_parcial);

            // --- TODO 3: Guardar en memoria compartida ---
            
            shm[p] = suma_parcial;
            exit(0); 
        }
    }

    // --- TODO 4: Esperar a todos los procesos hijo ---
    for (int i = 0; i < PROCESOS; i++) {
        wait(NULL);
    }

    long long suma_total = 0;

    // --- TODO 5: Acumular resultados desde memoria compartida ---

    for (int i = 0; i < PROCESOS; i++) {
        suma_total += shm[i];
    }

    printf("Suma total = %lld\n", suma_total);
    long long esperada = (long long)N * (N + 1) / 2;
    printf("Suma esperada = %lld\n", esperada);

    // --- TODO 6: Liberar memoria compartida ---
    munmap(shm, PROCESOS * sizeof(long long)); 
    shm_unlink(SHM_NAME); 

    return 0;
}
