#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int *arreglo, int n);
void mostrarArreglo(int *arreglo, int n);
void procedimiento(int *arreglo, int n, int *indice);

int main(){

    int cantidad;
    int indiceEncontrado;
    int *pArreglo;

    printf("\nCuantos numeros desea generar en el arreglo?: ");
    scanf("%d", &cantidad);

    pArreglo = malloc(cantidad * sizeof(int));

    srand(time(NULL));
    
    cargar(pArreglo, cantidad);
    mostrarArreglo(pArreglo, cantidad);
    procedimiento(pArreglo, cantidad, &indiceEncontrado);

    if(indiceEncontrado >= 0){
        printf("\nEl numero que ingreso, si se encuentra en el arreglo. Esta en la posicion %d", indiceEncontrado);
    }else{
        printf("\nNo se encontro en numero en el arreglo.");
    }

    free(pArreglo);

    return 0;
}

void cargar(int *arreglo, int n){

    for(int i = 0; i < n; i++){

        *arreglo = rand() % 1000;
        arreglo++;
    }
    arreglo -= n;

}

void mostrarArreglo(int *arreglo, int n){

    for(int i = 0; i < n; i++){
        printf(" |%d|", *arreglo);
        arreglo++;
    }
    arreglo -= n;
}

void procedimiento(int *arreglo, int n, int *indice){

    int numero;

    printf("\nIngrese un numero: ");
    scanf("%d", &numero);

    for(int i = 0; i < n; i++){

        if(*arreglo == numero){
            *indice = i;
        }

        arreglo++;
    }

   arreglo -= n;
}