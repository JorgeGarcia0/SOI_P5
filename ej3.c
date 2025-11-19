//Codigo de Jorge García y Antón Jaureguizar

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    printf("El PID del proceso es: %d\n", getpid());
    scanf("%*c"); // Pausa para ver el mapa de memoria antes de malloc+

    printf("Se reserva poca memoria con un mallc\n");
    void *malloc1 = malloc(128); // Reserva 128 bytes
    if (malloc1 == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
    }
    printf("Dirección devuelta por malloc1: %p\n", malloc1);

    scanf("%*c"); // Pausa para ver el mapa de memoria después de malloc1
    free(malloc1);

    printf("Se reserva mucha memoria con un malloc\n");
    void *malloc2 = malloc(10 * 1024 * 1024); // Reserva 10 MB
    if (malloc2 == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);     
    }
    printf("Dirección devuelta por malloc2: %p\n", malloc2);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de malloc2

    printf("Se hacen dos llamadas a malloc de diferentes tamaños\n");
    void *malloc3 = malloc(256); // Reserva 256 bytes
    if (malloc3 == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
    }
    void *malloc4 = malloc(1024); // Reserva 1024 bytes
    if (malloc4 == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
    }
    printf("Dirección devuelta por malloc3: %p\n", malloc3);
    printf("Dirección devuelta por malloc4: %p\n", malloc4);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de malloc3 y malloc4
    

    printf("Se reserva memoria con alloca\n");
    void *alloca_mem = alloca(1024); // Reserva 1 KB con alloca
    printf("Dirección devuelta por alloca: %p\n", alloca_mem);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de alloca



    printf("Se reserva memoria con malloc y luego se hace un realloc\n");
    void *malloc5 = malloc(512); // Reserva 512 bytes
    if (malloc5 == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
    }
    printf("Dirección devuelta por malloc5: %p\n", malloc5);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de malloc5
    void *realloc_mem = realloc(malloc5, 2048); // Cambia el tamaño a 2 KB
    if (realloc_mem == NULL) {
        perror("Error en realloc");
        free(malloc5);
        exit(EXIT_FAILURE);
        }
    printf("Dirección devuelta por realloc: %p\n", realloc_mem);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de realloc

    void *realloc_mem2 = realloc(realloc_mem, 10 * 1024*1024); // Cambia el tamaño a 10 MB
    if (realloc_mem2 == NULL) {
        perror("Error en realloc");
        free(realloc_mem);
        exit(EXIT_FAILURE);
    }
    printf("Dirección devuelta por realloc2: %p\n", realloc_mem2);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de realloc2

    
    printf("Se reserva espacio para 1000 doubles con malloc\n");
    double *malloc_doubles = (double *)malloc(1000 * sizeof(double));
    if (malloc_doubles == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
        }

    int tamaño=sizeof(malloc_doubles);
    printf("Dirección devuelta por malloc_doubles: %p\n", (void*)malloc_doubles);
    printf("El tamaño del puntero devuelto por malloc es: %d bytes\n", tamaño);
    
    scanf("%*c"); // Pausa para ver el mapa de memoria después de malloc_doubles

    printf("Se cambia la dirección del puntero antes de llamar a free\n");
    double *original_malloc_doubles = malloc_doubles;
    malloc_doubles+=500; // Cambia la dirección del puntero
    printf("Nueva dirección del puntero malloc_doubles: %p\n", (void*)malloc_doubles);
    scanf("%*c"); // Pausa para ver el mapa de memoria después de cambiar la dirección

    
    free(malloc2);
    free(malloc3);
    free(malloc4);
    free(realloc_mem2);
    free(original_malloc_doubles);
}