#include <stdio.h>

// Función para verificar si un carácter es una vocal
int esVocal(char c) {
    c = tolower(c); // Convertir a minúscula para comparar con vocales sin importar mayúsculas o minúsculas
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char caracter;
    int diptongos = 0;
    int enDiptongo = 0; // Variable para seguir el estado actual de estar en un diptongo

    printf("Ingrese una frase terminada en punto: ");

    // Leer caracteres de la entrada estándar hasta que se encuentre un punto
    while ((caracter = getchar()) != '.') {
        // Verificar si el carácter es una vocal
        if (esVocal(caracter)) {
            if (enDiptongo == 0) {
                enDiptongo = 1; // Estamos en un diptongo
            }
        } else {
            enDiptongo = 0; // No estamos en un diptongo
        }

        // Si encontramos un espacio o un salto de línea, contamos el diptongo
        if (caracter == ' ' || caracter == '\n') {
            diptongos += enDiptongo;
            enDiptongo = 0; // Resetear el estado
        }
    }

    // Imprimir el resultado
    printf("Cantidad de diptongos: %d\n", diptongos);

    return 0;
}