//Codigo de Jorge García y Antón Jaureguizar

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void f1(int a) {
    int localVar1 = 10;
    printf("Funcion f1:\n");
    printf("Direccion de parametro: %p\n", (void*)&a);
    printf("Direccion de variable local: %p\n", (void*)&localVar1);
}

void f2(int b) {
    int localVar2 = 20;
    printf("Funcion f2:\n");
    printf("Direccion de parametro: %p\n", (void*)&b);
    printf("Direccion de variable local: %p\n", (void*)&localVar2);
}

int main() {
    printf("PID: %d\n", getpid());
    f1(5);
    f2(15);

    scanf("%*c"); // Pausa para observar las direcciones
    return 0;
}