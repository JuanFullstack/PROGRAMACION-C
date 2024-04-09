#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>




int main(  )
{
 
 // Definir una matriz de tamaño 2x3
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Recorrer la matriz utilizando punteros puros
    printf("Recorriendo la matriz con punteros puros:\n");
    
    int *p = matriz;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", *p);
        }
        p++;
        printf("\n");
    }







 return 0;
}



