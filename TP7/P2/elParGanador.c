#include <stdio.h>
#include <stdlib.h>

void cargarArreglo(int *arreglo, int tamanio);
void encontrarSubarreglo(int *arreglo, int tamanio ,int *subarreglo );
void mostrarArreglo(int *arreglo, int tamanio) ;
 

int main() {
    system("cls");
    int *arregloInicial , *arregloSalida;
    int tama;

    printf("Ingrese el tamanio del arreglo: ");
    scanf("%d", &tama);

    //arreglo apunta a la direccion de memoria del primer elemento del array dinamico
    //generamos un array dinamico 
    arregloInicial = (int *)malloc(tama * sizeof(int));



    cargarArreglo(arregloInicial, tama);
    encontrarSubarreglo(arregloInicial, tama , arregloSalida );
    mostrarArreglo(arregloSalida, 5);
    

    // Liberar la memoria asignada dinámicamente
    free(arregloInicial);
    
    return 0;
}



// Módulo para cargar el arreglo de entrada
void cargarArreglo(int *arreglo, int tamanio ) {
    int i  ;
  

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < tamanio; i++) {
          scanf("%d", (arreglo + i));
        //scanf("%d", &(arreglo[i]));
       
    }
}

// Módulo para encontrar y mostrar el subarreglo con la suma máxima
void encontrarSubarreglo(int *arreglo, int tamanio ,int *subarreglo ) {
    int sumaMax = 0;
    int posicion1 , posicion2;
    for (int i = 0; i < (tamanio - 1); i++) {
        int sumaActual = arreglo[i] + arreglo[i + 1];
        if (sumaActual > sumaMax) {
            sumaMax = sumaActual;
            posicion1 = i;
            posicion2 = i+1;
        }
    }

    printf("El subarreglo contiguo con la suma maxima es: [ %d , %d ]\n", 
              arreglo[posicion1], arreglo[posicion2]);
    printf("Posicion del primer numero: %d\n", posicion1);
    printf("Posicion del segundo numero: %d\n", posicion2 + 1);
    printf("Suma maxima: %d\n", sumaMax);

    subarreglo[0] = arreglo[posicion1];
    subarreglo[1] = arreglo[posicion2];
    subarreglo[2] = posicion1;
    subarreglo[3] = posicion2;
    subarreglo[4] = sumaMax;
}

// Módulo para mostrar un arreglo
void mostrarArreglo(int *arreglo, int tamanio) {
    printf("Arreglo: [ ");
    for (int i = 0; i < tamanio; i++) {
        printf("%d", arreglo[i]);
        if (i < tamanio - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}