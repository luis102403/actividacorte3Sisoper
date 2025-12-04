******Respuestas a las preguntas teóricas ejercicio 1****

**¿Qué diferencia principal existe entre un proceso y un hilo?**
La principal diferencia radica en la memoria. Un proceso es una instancia de un programa en ejecución con su propio espacio de memoria 
independiente (código, datos, heap, stack). Un hilo (o thread) es la unidad de ejecución dentro de un proceso; 
los hilos de un mismo proceso comparten el espacio de memoria (variables globales, heap) y recursos (archivos abiertos), 
aunque cada uno tiene su propia pila (stack) y registros. Debido a esto, los hilos son más "ligeros" y rápidos de crear que los procesos.

**¿Qué sucede cuando dos hilos comparten una variable global sin sincronización?**
Ocurre una condición de carrera (race condition). El resultado final de la variable depende del orden impredecible en que el planificador 
del sistema operativo alterna la ejecución de los hilos. Esto puede llevar a datos corruptos, inconsistencias o comportamientos erráticos
del programa.

**¿Qué función se usa para esperar la finalización de un hilo?**
pthread_join(hilo, NULL);
Se usa para:

- Esperar que el hilo termine.
- Evitar que el programa finalice antes de que los hilos impriman todo.

**¿Qué técnica usaría para evitar condiciones de carrera?**
Se utilizan mecanismos de sincronización. El más común es el Mutex (Exclusión Mutua), que permite bloquear una sección crítica de código 
para que solo un hilo pueda acceder a la variable compartida a la vez. Otras técnicas incluyen semáforos, variables de condición o el uso 
de operaciones atómicas


****respuestas a las preguntas ejercicio #2****
¿Por qué este ejercicio es paralelo y no solo concurrente?
Es paralelo porque los 4 procesos ejecutan simultáneamente en diferentes núcleos del CPU. Cada proceso realiza trabajo real al mismo tiempo que los otros.
Concurrencia: Múltiples tareas progresan 
Paralelismo: Múltiples tareas ejecutan simultáneamente (múltiples CPUs)
En un sistema con 4+ núcleos, los 4 procesos corren verdaderamente en paralelo.

2. ¿Diferencia entre fork() y pthread_create()?

| fork()                                                        | pthread_create()                                   |
| ------------------------------------------------------------- | -------------------------------------------------- |
| Crea procesos independientes.                                 | Crea hilos dentro del mismo proceso.               |
| Cada proceso tiene **su propio espacio de memoria**.          | Todos los hilos comparten la misma memoria.        |
| Es más pesado y lento.                                        | Es más liviano y rápido.                           |
| Requiere mecanismos explícitos de comunicación (pipes, shm…). | Comparten variables globales sin necesidad de IPC. |


**¿Por qué se necesita memoria compartida y no una variable global?**

Porque después de hacer un fork(), el sistema operativo duplica el espacio de memoria. Si usaras una variable global normal int suma, el hijo tendría una 
copia de esa variable. Si el hijo modifica su copia, la variable del padre no se entera y permanece en 0. La memoria compartida (mmap) es necesaria para
crear una zona física de RAM que ambos procesos puedan ver y modificar.

**¿Qué función se usa para esperar a un proceso hijo?**
Se usa la función wait(NULL) (espera a cualquiera de los hijos) o waitpid() (espera a un hijo específico por su ID).





