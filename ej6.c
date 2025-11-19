/*Crea un programa con las siguientes características:
• Crea una variable global y una variable local al main() de tipo entero.
• Crea dos hilos que reciben como parámetro la variable local del hilo principal.
• Cada hilo define una nueva variable local y la actualiza con el producto de la variable global
y el parámetro recibido por el hilo*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <alloca.h>

int global_var = 5;

void *funcion(void *arg) {
    int var_recibida = *((int *)arg);
    int local_var = var_recibida * global_var;
    printf("Valor en el hilo: %d\n", local_var);
    printf("Direccion de la variable global en el hilo: %p\n", (void *)&global_var);
    printf("Direccion de la variable recibida en el hilo: %p\n", (void *)arg);
    printf("Direccion de la variable local en el hilo: %p\n", (void *)&local_var);

    getchar(); // Pausa para ver las direcciones en el hilo
    printf("Se reserva memoria con malloc en el hilo\n");

    void *malloc1 = malloc(10 * 1024 * 1024); // Reserva 10 MB
    if (malloc1== NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);     
    }
    printf("Dirección devuelta por malloc en el hilo: %p\n", malloc1);
    getchar(); // Pausa para ver el mapa de memoria después de malloc en el hilo

    return NULL;    
}


int main() {

    int main_local_var = 10;
    pthread_t thread1, thread2;

    printf("El PID del proceso es: %d\n", getpid());
    printf("La direccion de la variable global es: %p\n", (void *)&global_var);
    printf("La direccion de la variable local del main es: %p\n", (void *)&main_local_var);

    getchar(); // Pausa para ver el mapa de memoria antes de crear los hilos
    printf("Se crean dos hilos\n");

    if (pthread_create(&thread1, NULL, funcion, (void *)&main_local_var) != 0) {
        perror("Error al crear el hilo 1");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread2, NULL, funcion, (void *)&main_local_var) != 0) {
        perror("Error al crear el hilo 2");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
        
