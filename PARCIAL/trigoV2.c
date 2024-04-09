void mostrarSegun(Datos *id, int cant){

    char buscarMarca[MAX], buscarModelo[MAX];
    float buscarKm; 

    printf("\nIngrese la marca que desea buscar: ");
    fflush(stdin);
    gets(buscarMarca);

    printf("\nIngrese el modelo que desea buscar: ");
    gets(buscarModelo);

    for(int i = 0; i < cant; i++){

        if(strcmp(id[i].marca, buscarMarca) == 0 && strcmp(id[i].modelo, buscarModelo) == 0){

            printf("\nIngrese hasta cuantos km hechos, desea buscar: ");
            fflush(stdin);
            scanf("%f", &buscarKm);

            for(int k = 0; k < id[i].stock; k++){

                if(id[i].unidades[k].km <= buscarKm){

                    printf("\nCodigo del vehiculo: %s", id[i].codigo);
                    printf("\nMarca: %s", id[i].marca);
                    printf("\nModelo: %s", id[i].modelo);
                    printf("\nStock: %d", id[i].stock);
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