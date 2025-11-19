//Codigo de Jorge García y Antón Jaureguizar
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var_global1 = 10;
char var_global2 = 'A';
float var_global3;
int array_global[5] = {1, 2, 3, 4, 5};

void main() {

    printf("El PID del proceso es: %d\n", getpid());
    int var_local1 = 20;
    double var_local2 = 6.28;
    int array_3d[10][10][10];
    
    printf("Dirección de la función main: %p\n", (void*)main);
    printf("Dirección de var_global1: %p\n", (void*)&var_global1);
    printf("Dirección de var_global2: %p\n", (void*)&var_global2);
    printf("Dirección de var_global3: %p\n", (void*)&var_global3);
    printf("Dirección de array_global: %p\n", (void*)array_global);
    printf("Dirección de var_local1: %p\n", (void*)&var_local1);
    printf("Dirección de var_local2: %p\n", (void*)&var_local2);
    printf("Dirección de array_3d: %p\n", (void*)array_3d);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                array_3d[i][j][k] = 1; 
            }
        }
    }

    printf("\nOrden de almacenamiento del array 3D en memoria:\n");
    printf("%p\n", &array_3d[0][0][0]);
    printf("%p\n", &array_3d[0][0][1]);
    printf("%p\n", &array_3d[0][1][0]);
    
    scanf("%*c"); // Pausa para ver las direcciones antes de imprimir el orden

}

