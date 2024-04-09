#include <stdio.h>


int main() {

system("cls");
    // Declarar e inicializar un arreglo de enteros
  char arreglo[] = {'p', 'e', 'd', 'r', 'o', '\0'};


    // Acceder y mostrar los elementos del arreglo como caracteres
    for (int i = 0; i < 6; ++i) {
        printf("%c ", arreglo[i]);
    }

    return 0;
}