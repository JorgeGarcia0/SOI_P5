//Codigo de Jorge García y Antón Jaureguizar

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("NUEVO PROGRAMA: PID=%d\n", getpid());
    printf("Mapa de memoria después de execv.\n");
    getchar();
    return 0;
}
