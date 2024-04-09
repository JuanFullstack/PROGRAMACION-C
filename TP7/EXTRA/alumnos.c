#include <stdio.h>
#include <stdlib.h>

// Función para cargar las notas de los alumnos
void cargarNotas(float **notas, int alumnos, int materias) {
    for (int i = 0; i < materias; i++) {
        for (int j = 0; j < alumnos; j++) {
            printf("Ingrese la nota de la materia %d para el alumno %d: ", i, j);
            scanf("%f", &notas[i][j]);
        }
    }
}

// Función para calcular el promedio y la nota más alta de cada materia
void calcularPromedio(float **notas, int alumnos, int materias, float *promedios, float *mayorNotas) {
    for (int i = 0; i < materias; i++) {
        promedios[i] = 0;
        mayorNotas[i] = notas[i][0];

        for (int j = 0; j < alumnos; j++) {
            promedios[i] += notas[i][j];

            if (notas[i][j] > mayorNotas[i]) {
                mayorNotas[i] = notas[i][j];
            }
        }

        promedios[i] /= alumnos;
    }
}

int main() {
    int numMaterias = 4; // Cantidad de materias
    int numAlumnos;

    printf("Ingrese la cantidad de alumnos en el curso: ");
    scanf("%d", &numAlumnos);

    float **notas = (float **)malloc(numMaterias * sizeof(float *));
    if (notas == NULL) {
        printf("Error de asignación de memoria.\n");
        return 1;
    }

    for (int i = 0; i < numMaterias; i++) {
        notas[i] = (float *)malloc(numAlumnos * sizeof(float));
        if (notas[i] == NULL) {
            printf("Error de asignación de memoria.\n");
            return 1;
        }
    }

    float *promedios = (float *)malloc(numMaterias * sizeof(float));
    if (promedios == NULL) {
        printf("Error de asignación de memoria.\n");
        return 1;
    }

    float *mayorNotas = (float *)malloc(numMaterias * sizeof(float));
    if (mayorNotas == NULL) {
        printf("Error de asignación de memoria.\n");
        return 1;
    }

    cargarNotas(notas, numAlumnos, numMaterias);
    calcularPromedio(notas, numAlumnos, numMaterias, promedios, mayorNotas);

    for (int i = 0; i < numMaterias; i++) {
        printf("Promedio de la materia %d: %.2f\n", i, promedios[i]);
        printf("Nota más alta de la materia %d: %.2f\n", i, mayorNotas[i]);
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < numMaterias; i++) {
        free(notas[i]);
    }
    free(notas);
    free(promedios);
    free(mayorNotas);

    return 0;
}
