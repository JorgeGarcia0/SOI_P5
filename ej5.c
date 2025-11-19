//Codigo de Jorge García y Antón Jaureguizar

#include <stdio.h>
#include <math.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main() {

    printf("El PID del proceso es: %d\n", getpid()); 

    double x = sin(1.0);
    printf("%f\n", x);

    getchar(); // Pausa para ver el mapa de memoria
    
    return 0;
}
