#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

void cargarMatriz(int matriz[FILAS][COLUMNAS]);
void mostrarMatriz(int matriz[FILAS][COLUMNAS]);
void promedioAnual(int matriz[FILAS][COLUMNAS]);
void valorMaximoMinimo(int matriz[FILAS][COLUMNAS]);

int main(void) 
{
    int matriz[FILAS][COLUMNAS];

    // Semilla para valores aleatorios
    srand(time(NULL));

    cargarMatriz(matriz);

    printf("Valores cargados en la matriz:\n");
    mostrarMatriz(matriz);

    printf("\nPromedio de ganancia por año:\n");
    promedioAnual(matriz);

    printf("\nValor maximo y minimo obtenido:\n");
    valorMaximoMinimo(matriz);

    return 0;
}

void cargarMatriz(int matriz[FILAS][COLUMNAS]) 
{
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            // Genera valores aleatorios entre 10000 y 50000
            matriz[i][j] = 10000 + rand() % 40001;
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS]) 
{
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedioAnual(int matriz[FILAS][COLUMNAS]) 
{
    int i, j;
    int totalPorAño, promedio;

    for (i = 0; i < FILAS; i++) {
        totalPorAño = 0;

        for (j = 0; j < COLUMNAS; j++) {
            totalPorAño += matriz[i][j];
        }

        promedio = totalPorAño / COLUMNAS;
        printf("Año %d: %d\n", i+1, promedio);
    }
}
void valorMaximoMinimo(int matriz[FILAS][COLUMNAS]) 
{
    int i, j;
    int maximo = 0, minimo = 50000, maxY, maxM, minY, minM;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                maxY = i+1;
                maxM = j+1;
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                minY = i+1;
                minM = j+1;
            }
        }
    }

    printf("Valor maximo: %d (Año: %d, Mes: %d)\n", maximo, maxY, maxM);
    printf("Valor minimo: %d (Año: %d, Mes: %d)\n", minimo, minY, minM);
}