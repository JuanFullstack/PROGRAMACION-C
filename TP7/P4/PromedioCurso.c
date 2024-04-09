#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarNotas(float *notas, int alumnos);
float calcularPromedio(float *notas, int alumnos, float *promedio);

int main() {
    int alumnos;

    printf("Ingrese la cantidad de alumnos en el curso: ");
    scanf("%d", &alumnos);

    if (alumnos <= 0) {
        printf("La cantidad de alumnos debe ser mayor que cero.\n");
        return 1;
    }

    float *notas = (float *)malloc(alumnos * sizeof(float));

    cargarNotas(notas, alumnos);

    float promedio;
    float mejorNota = calcularPromedio(notas, alumnos, &promedio);

    printf("Notas de los alumnos:\n");
    for (int i = 0; i < alumnos; i++) {
        printf("Alumno %d: %.2f\n", i + 1, notas[i]);
    }

    printf("Promedio del curso: %.2f\n", promedio);
    printf("Mejor nota: %.2f\n", mejorNota);

    // Liberar la memoria asignada dinámicamente
    free(notas);

    return 0;
}



// Función para simular las notas
void cargarNotas(float *notas, int alumnos) {
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios
    for (int i = 0; i < alumnos; i++) {
        notas[i] = (float)(rand() % 1001) / 100; // Genera números aleatorios con 2 decimales entre 0 y 10
    }
}

// Función que calcula y guarda el promedio, además retorna la mejor nota
float calcularPromedio(float *notas, int alumnos, float *promedio) {
    float suma = 0.0;
    float mejorNota = 0.0;

    int  mesa = 25 ;



    for (int i = 0; i < alumnos; i++) {
        suma += notas[i];
        if (notas[i] > mejorNota) {
            mejorNota = notas[i];
        }
    }

    *promedio = suma / alumnos;
    return mejorNota;
}