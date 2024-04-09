#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mezclarCadenas(char *cad1,  char *cad2, int pos);

int main() {
    char *cadena1 = (char *)malloc(100 * sizeof(char)); // Reserva inicial de memoria
    char cadena2[100];
    int posicion;

  

    printf("Ingrese la primera cadena: ");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena: ");
    scanf("%s", cadena2);
    printf("Ingrese la posicion de insercion: ");
    scanf("%d", &posicion);

    if (posicion < 0 || posicion > strlen(cadena1)) {
        printf("La posición de insercion no es valida.\n");
        free(cadena1);
        return 1;
    }

    mezclarCadenas(cadena1, cadena2, posicion);

    // Liberar la memoria asignada dinámicamente
    free(cadena1);

    return 0;
}



// Función para mezclar dos cadenas
void mezclarCadenas(char *cad1,  char *cad2, int pos) {
    int len1 = strlen(cad1);
    int len2 = strlen(cad2);
    int nuevaLongitud = len1 + len2;

    // Ajustar la longitud de cad1 si es necesario
    if (nuevaLongitud > len1) {
        cad1 = (char *)realloc(cad1, nuevaLongitud + 1);
      
    }

    // Desplazar los caracteres en cad1 hacia la derecha para hacer espacio para cad2
    for (int i = len1 - 1; i >= pos; i--) {
        cad1[i + len2] = cad1[i];
    }

    // Insertar cad2 en cad1 a partir de la posición pos
    for (int i = 0; i < len2; i++) {
        cad1[i + pos] = cad2[i];
    }

    // Actualizar la longitud de cad1
    len1 = nuevaLongitud;

    // Imprimir la cadena modificada
    printf("Cadena 1 modificada: %s\n", cad1);
}
