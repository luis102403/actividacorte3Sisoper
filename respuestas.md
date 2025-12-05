**Respuestas a las preguntas teóricas ejercicio 1**

**¿Qué diferencia principal existe entre un proceso y un hilo?**
La principal diferencia radica en la memoria. Un proceso es una instancia de un programa en ejecución con su propio espacio de memoria 
independiente. Un hilo es la unidad de ejecución dentro de un proceso; los hilos de un mismo proceso comparten el espacio de memoria  y recursos, 
aunque cada uno tiene su propia pila y registros. Debido a esto, los hilos son más ligeros y rápidos de crear que los procesos.

**¿Qué sucede cuando dos hilos comparten una variable global sin sincronización?**.

Ocurre una condición de carrera (race condition). El resultado final de la variable depende del orden impredecible en que el planificador 
del sistema operativo alterna la ejecución de los hilos. Esto puede llevar a generan errores difíciles de reproducir.


**¿Qué función se usa para esperar la finalización de un hilo?**

pthread_join(hilo, NULL);
Se usa para:

- Esperar que el hilo termine.
- Evitar que el programa finalice antes de que los hilos impriman todo.

**¿Qué técnica usaría para evitar condiciones de carrera?**

Se utilizan mecanismos de sincronización. El más común es el Mutex, que permite bloquear una sección crítica de código 
para que solo un hilo pueda acceder a la variable compartida a la vez. tambien exiten otros vistos en clase como semáforos, variables de condición  y tambien el uso de operaciones atómicas


**Respuestas a las preguntas ejercicio #2**

**¿Por qué este ejercicio es paralelo y no solo concurrente?**
Es paralelo porque los 4 procesos ejecutan simultáneamente en diferentes núcleos del CPU. Cada proceso realiza trabajo real al mismo tiempo que los otros.
Concurrencia: Múltiples tareas progresan 
Paralelismo: Múltiples tareas ejecutan simultáneamente (múltiples CPUs)
En un sistema con 4+ núcleos, los 4 procesos corren verdaderamente en paralelo.

**¿Diferencia entre fork() y pthread_create()?**

| fork()                                                        | pthread_create()                                   |
| ------------------------------------------------------------- | -------------------------------------------------- |
| Crea procesos independientes.                                 | Crea hilos dentro del mismo proceso.               |
| Cada proceso tiene su propio espacio de memoria.              | Todos los hilos comparten la misma memoria.        |
| Es más pesado y lento.                                        | Es más liviano y rápido.                           |
| Requiere mecanismos explícitos de comunicación (pipes, shm…). | Comparten variables globales sin necesidad de IPC. |


**¿Por qué se necesita memoria compartida y no una variable global?**

Cuando usamos fork() para crear procesos hijos, cada proceso hijo recibe una copia independiente de todo el espacio de memoria del proceso padre. Esto significa que las variables globales no son compartidas entre el padre y los hijos.
Cuando usamos fork():

- El proceso hijo recibe una copia del espacio de memoria del padre
- Las variables globales son independientes en cada proceso
- Modificar una variable en el hijo NO afecta al padre

**¿Qué función se usa para esperar a un proceso hijo?**
Se usa la función: 
- wait(NULL) (espera a cualquiera de los hijos) 
- waitpid() (espera a un hijo específico por su ID).





