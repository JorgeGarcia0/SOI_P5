/*Analiza un proceso que incluya llamadas al sistema malloc y free (comprueba que las llamadas
han tenido éxito). Examina el mapa de memoria antes y después de la ejecución de malloc, e
identifica la zona de memoria dinámica que has creado para diferentes tamaños de la reserva.
Comprueba si con free se libera toda la zona reservada por el malloc. Haz la misma prueba si
luego se ejecuta otro malloc. Ten en cuenta los consejos comentados más adelante para completar
el informe

 Comprueba que se crean zonas diferentes cuando se reserva poca o mucha memoria con malloc.
• Comprueba si al hacer dos llamadas a malloc se crean zonas de memoria separadas para cada
malloc considerando diferentes tamaños de memoria.
• Comprueba que ocurre al hacer una reserva de memoria con la llamada al sistema alloca frente
a la utilización de malloc.
• Comprueba que ocurre si se reserva memoria con malloc y posteriormente se hace un realloc.
Ajusta el tamaño del realloc para comprobar que la zona de memoria reservada puede crecer.
Comprueba si la respuesta depende de la cantidad de memoria reservada.
• Finalmente, usa la función malloc para reservar espacio para 1000 doubles. Aplica la función
sizeof al puntero devuelto por malloc. ¿Qué es lo que proporciona? Comprueba que sucede si
se cambia la dirección del puntero devuelto por malloc (por ejemplo, incrementándolo) antes de
llamar a free.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>/*Analiza un proceso que incluya llamadas al sistema malloc y free (comprueba que las llamadas
han tenido éxito). Examina el mapa de memoria antes y después de la ejecución de malloc, e
identifica la zona de memoria dinámica que has creado para diferentes tamaños de la reserva.
Comprueba si con free se libera toda la zona reservada por el malloc. Haz la misma prueba si
luego se ejecuta otro malloc. Ten en cuenta los consejos comentados más adelante para completar
el informe

 Comprueba que se crean zonas diferentes cuando se reserva poca o mucha memoria con malloc.
• Comprueba si al hacer dos llamadas a malloc se crean zonas de memoria separadas para cada
malloc considerando diferentes tamaños de memoria.
• Comprueba que ocurre al hacer una reserva de memoria con la llamada al sistema alloca frente
a la utilización de malloc.
• Comprueba que ocurre si se reserva memoria con malloc y posteriormente se hace un realloc.
Ajusta el tamaño del realloc para comprobar que la zona de memoria reservada puede crecer.
Comprueba si la respuesta depende de la cantidad de memoria reservada.
• Finalmente, usa la función malloc para reservar espacio para 1000 doubles. Aplica la función
sizeof al puntero devuelto por malloc. ¿Qué es lo que proporciona? Comprueba que sucede si
se cambia la dirección del puntero devuelto por malloc (por ejemplo, incrementándolo) antes de
llamar a free.
*/

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