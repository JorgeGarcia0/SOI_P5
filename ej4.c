
/*Crea un proceso hijo que incluya un malloc y a continuación cambie su imagen con execv a un código 
cualquiera creado por ti. Compara los mapas de memoria del proceso padre y el proceso hijo antes y 
después del malloc y comprueba como el cambio de imagen afecta al mapa de memoria del proceso hijo.*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main () { 
    
    printf("El PID del proceso padre es: %d\n", getpid()); 
    
    pid_t pid = fork(); 
    if (pid < 0) { 
        perror("Error en fork"); 
        exit(EXIT_FAILURE); 
    } 
    else if (pid == 0) { //PROCESO HIJO 
        printf("El PID del proceso hijo es: %d\n", getpid()); 
        printf("\nMapa de memoria antes de malloc.\n");
        getchar(); // Pausa para ver el mapa de memoria antes de malloc en ambos procesos
        
        printf("Se reserva memoria con malloc\n"); 
        void *malloc1 = malloc(10*1024*1024); // Reserva 256 bytes 
        if (malloc1 == NULL) { 
            perror("Error en malloc"); 
            exit(EXIT_FAILURE); 
        } 
        
        printf("Dirección devuelta por malloc: %p\n", malloc1); 
        printf("\nMapa de memoria despues de malloc.\n");
        getchar(); // Pausa para ver el mapa de memoria después de malloc 
        
        printf("Cambiando la imagen del proceso con execv\n"); 
        char *const args[] = {"./hijo", NULL}; 
        execv(args[0], args); 
        perror("Error en execv"); 
        exit(EXIT_FAILURE); 
    
    } else { // Proceso padre 
        wait(NULL); // Espera a que el proceso hijo termine 
        printf("Proceso hijo terminado.\n");
        exit(EXIT_SUCCESS); 
    } 
}