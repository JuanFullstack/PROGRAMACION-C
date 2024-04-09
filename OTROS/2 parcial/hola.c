#include <stdio.h>
#include <stdlib.h>

struct
{
    int cant;
    int cantPre[12];
    int **historial;
} typedef libro;

int main()
{
    int **punt;
    int cantSt, cantUs;

    punt = (int *)malloc(12 * sizeof(int));
    for (int i = 0; i < cantUs; i++)
    {
        punt[i] = (int **)malloc(cantUs * sizeof(int *));
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < cantUs; j++)
        {
            punt[i][j] = i * j;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        free(punt[i]);
    }

    free(punt);

    libro LIBRO;
    LIBRO.cant = 45;
    LIBRO.historial = (int *)malloc(12 * sizeof(int));

    for (int i = 0; i < cantUs; i++)
    {
        LIBRO.historial[i] = (int **)malloc(cantUs * sizeof(int *));
    }

    for (int i = 0; i < cantUs; i++)
    {
        LIBRO.historial[i] = (int **)realloc(LIBRO.historial[i], cantUs * sizeof(int *));
    }

    for (int i = 0; i < cantUs; i++)
    {
        free(LIBRO.historial[i]);
    }

    free(LIBRO.historial);
    
    return 0;
}