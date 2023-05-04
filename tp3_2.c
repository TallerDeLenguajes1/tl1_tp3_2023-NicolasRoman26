#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 50

int main() {
    char *nombres[MAX_NOMBRES];
    int i;

    printf("Ingrese 5 nombres: \n");

    // reserva de memoria dinámica para cada nombre
    for (i = 0; i < MAX_NOMBRES; i++) {
        nombres[i] = malloc(sizeof(char) * MAX_LONGITUD_NOMBRE);
        scanf("%s",nombres[i]);
    }

    printf("Los nombres ingresados son:\n");

    // impresión de los nombres almacenados
    for (i = 0; i < MAX_NOMBRES; i++) {
        printf("%s\n",nombres[i]);
    }

    // liberación de la memoria reservada
    for (i = 0; i < MAX_NOMBRES; i++) {
        free(nombres[i]);
    }

    return 0;
}
