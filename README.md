Respuestas a las preguntas teóricas ejercicio 1

¿Qué diferencia principal existe entre un proceso y un hilo? 
La principal diferencia radica en la memoria. Un proceso es una instancia de un programa en ejecución con su propio espacio de memoria 
independiente (código, datos, heap, stack). Un hilo (o thread) es la unidad de ejecución dentro de un proceso; 
los hilos de un mismo proceso comparten el espacio de memoria (variables globales, heap) y recursos (archivos abiertos), 
aunque cada uno tiene su propia pila (stack) y registros. Debido a esto, los hilos son más "ligeros" y rápidos de crear que los procesos.

¿Qué sucede cuando dos hilos comparten una variable global sin sincronización? 
Ocurre una condición de carrera (race condition). El resultado final de la variable depende del orden impredecible en que el planificador 
del sistema operativo alterna la ejecución de los hilos. Esto puede llevar a datos corruptos, inconsistencias o comportamientos erráticos
del programa.

¿Qué función se usa para esperar la finalización de un hilo? 
La función es pthread_join. Esta función bloquea al hilo que la llama (usualmente el hilo principal o main) hasta que el hilo especificado 
como argumento termine su ejecución.

¿Qué técnica usaría para evitar condiciones de carrera? 
Se utilizan mecanismos de sincronización. El más común es el Mutex (Exclusión Mutua), que permite bloquear una sección crítica de código 
para que solo un hilo pueda acceder a la variable compartida a la vez. Otras técnicas incluyen semáforos, variables de condición o el uso 
de operaciones atómicas
