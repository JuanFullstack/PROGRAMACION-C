#include <stdio.h>

int main() {

    system("cls");

    char frase[100];
    printf("Ingrese una línea de texto: ");
    fgets(frase, sizeof(frase), stdin);

    // Declarar un puntero punt
    char *punt ;

    // Asignar la dirección inicial del arreglo frase a punt de dos maneras distintas
    punt = frase; // Opción 1
    // punt = &frase[0]; // Opción 2

    // Mostrar la dirección de la variable puntero punt y la dirección de la primera componente del arreglo frase
    printf("Dirección de punt: %p\n", punt);
    printf("Dirección de la primera componente del arreglo frase: %p\n", &frase[0]);

    // Mostrar el contenido de la cuarta celda del arreglo frase
    printf("Contenido de la cuarta celda usando notación de subíndice: %c\n", frase[3]);
    printf("Contenido de la cuarta celda usando notación de puntero con desplazamiento: %c\n", *(punt + 3));

    // Calcular la dirección referenciada por punt + S y mostrar su valor
    int S = 2;
    char *direccion_S = punt + S;
    char valor_S = *direccion_S;
    printf("Dirección referenciada por punt + %d: %p\n", S, direccion_S);
    printf("Valor almacenado en esa dirección: %c\n", valor_S);

    // Mostrar el valor almacenado en punt + 5
    printf("Valor almacenado en punt + 5: %c\n", *(punt + 5));

    // Visualizar cada componente del vector frase de diferentes maneras
    printf("Visualizar cada componente del vector frase:\n");

    // Utilizando notación de punteros con el puntero punt
    while (*punt != '\0') {
        printf("%c ", *punt);
        punt++;
    }

    printf("\n");

    // Reiniciar punt al inicio del arreglo frase
    punt = frase;

    // Mediante subíndices del puntero punt
    int i = 0;
    while (frase[i] != '\0') {
        printf("%c ", punt[i]);
        i++;
    }

    printf("\n");

    return 0;
}