#include <stdio.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

// hago una reserva fija m aunque no use toda ??


int esMatrizIdentidad(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    // Verificar que sea una matriz cuadrada
    if (filas != columnas) {
        return 0;  // No es cuadrada, no puede ser una matriz identidad
    }

    // Verificar la diagonal principal
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == j && matriz[i][j] != 1) {
                return 0;  // No es una matriz identidad
            } else if (i != j && matriz[i][j] != 0) {
                return 0;  // No es una matriz identidad
            }
        }
    }








    return 1; 
}

int main() {
    int filas, columnas;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    int matriz[MAX_FILAS][MAX_COLUMNAS];

    // Ingreso de la matriz por el usuario
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Verificar si la matriz es una matriz identidad
    if (esMatrizIdentidad(matriz, filas, columnas)) {
        printf("La matriz ingresada es una matriz identidad.\n");
    } else {
        printf("La matriz ingresada NO es una matriz identidad.\n");
    }

    return 0;
}