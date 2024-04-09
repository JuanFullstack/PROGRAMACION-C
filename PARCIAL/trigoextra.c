#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//Estructuras

struct{
    int anio;
    float km;
    float precio;
}typedef UnidadesDisponibles;

struct{
    char codigo[MAX];
    char marca[MAX];
    char modelo[MAX];
    int stock;
    UnidadesDisponibles *unidades;
}typedef Datos;

//Funciones 

void mostrarSegun(Datos *id);

int main(){

    UnidadesDisponibles toyota[2] = {
        {2023, 15000, 17000000},
        {2020, 130000, 7000000}
    };

    UnidadesDisponibles *pToyota = toyota;

    UnidadesDisponibles renault[2] = {
        {2021, 12000, 5000000},
        {2020, 1000, 25000000}
    };

    UnidadesDisponibles *pRenault = renault;

    Datos misDatos[2] = {
        {"abcdef", "Toyota", "Ethios", 2, pToyota},
        {"ghijkl", "Renault", "Clio", 2, pRenault}
    };

    mostrarSegun(misDatos);

    return 0;
}

void mostrarSegun(Datos *id){

    char buscarMarca[MAX], buscarModelo[MAX];
    float buscarKm; 

    printf("\nIngrese la marca que desea buscar: ");
    fflush(stdin);
    gets(buscarMarca);

    printf("\nIngrese el modelo que desea buscar: ");
    gets(buscarModelo);

    for(int i = 0; i < 2; i++){

        if(strcmp(id[i].marca, buscarMarca) == 0 && strcmp(id[i].modelo, buscarModelo) == 0){

            printf("\nIngrese hasta cuantos km hechos, desea buscar: ");
            fflush(stdin);
            scanf("%f", &buscarKm);

            for(int k = 0; k < id[i].stock; k++){

                if(id[i].unidades[k].km <= buscarKm){

                    printf("\nCodigo del vehiculo: %s", id[i].codigo);
                    printf("\nMarca: %s", id[i].marca);
                    printf("\nModelo: %s", id[i].modelo);
                    //printf("\nStock: %d", id[i].stock); No muestro el stock porque me es irrelevante al cliente
                    printf("\nAnio: %d", id[i].unidades[k].anio);
                    printf("\nKm: %.2f Km", id[i].unidades[k].km);
                    printf("\nPrecio: $%.2f", id[i].unidades[k].precio);
                    printf("\n");

                }
            }
        }else{
            printf("\nNo se encontraron datos coincidentes");
        }
    }
}