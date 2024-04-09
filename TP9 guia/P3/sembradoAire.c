#include <stdio.h>
#include <string.h>

// Definición de la estructura para los datos de la especie

struct {
        char razon_social[100];
        char telefono[20];
    } typedef datosCliente;

    struct {
        char nombre[50];
        char apellido[50];
    } typedef infoempleados;

struct {
        datosCliente datosCliente ;
        infoempleados empleado;
        int cantidad;
    } typedef pedidos; 



 struct {
    char nombre_cientifico[100];
    int categoria ;
    int nombre_vulgar;
    int stock;
    float precio;
    int num_pedidos;
    pedidos info ;
} typedef EspecieArbol;

// Declaración del arreglo de especies de árboles
#define MAX_ESPECIES 20
EspecieArbol especies[MAX_ESPECIES];

// Función para mostrar todos los árboles/especies disponibles
void mostrarTodosLosArboles() {
    printf("___________ Árboles Disponibles _____________\n");
    for (int i = 0; i < MAX_ESPECIES; i++) {
        if (strcmp(especies[i].nombre_cientifico, "") != 0) {
            printf("Nombre científico: %s\n", especies[i].nombre_cientifico);
            printf("Categoría: %s\n", especies[i].categoria);
            printf("Nombre vulgar: %s\n", especies[i].nombre_vulgar);
            printf("Stock: %d\n", especies[i].stock);
            printf("Precio: %.2f\n", especies[i].precio);
            printf("\n");
        }
    }
}

// Función para mostrar árboles/especies según stock
void mostrarArbolesSegunStock(int limiteStock) {
    printf("___________ Árboles con Stock Inferior a %d _____________\n", limiteStock);
    for (int i = 0; i < MAX_ESPECIES; i++) {
        if (strcmp(especies[i].nombre_cientifico, "") != 0 && especies[i].stock < limiteStock) {
            printf("Nombre científico: %s\n", especies[i].nombre_cientifico);
            printf("Categoría: %s\n", especies[i].categoria);
            printf("Nombre vulgar: %s\n", especies[i].nombre_vulgar);
            printf("Stock: %d\n", especies[i].stock);
            printf("Precio: %.2f\n", especies[i].precio);
            printf("\n");
        }
    }
}

// Función para mostrar todos los pedidos e indicar el monto a cobrar a cada cliente
void mostrarTodosLosPedidos() {
    printf("___________ Todos los Pedidos _____________\n");
    for (int i = 0; i < MAX_ESPECIES; i++) {
        if (strcmp(especies[i].nombre_cientifico, "") != 0 && especies[i].num_pedidos > 0) {
            printf("Especie: %s\n", especies[i].nombre_cientifico);
            printf("Pedidos:\n");
            float montoTotal = 0;
            for (int j = 0; j < especies[i].num_pedidos; j++) {
                printf("Cliente: %s, Teléfono: %s\n", especies[i].pedidos[j].razon_social,
                       especies[i].pedidos[j].telefono);
                printf("Empleado: %s %s\n", especies[i].pedidos[j].empleado_nombre,
                       especies[i].pedidos[j].empleado_apellido);
                printf("Cantidad: %d\n", especies[i].pedidos[j].cantidad);
                float montoPedido = especies[i].pedidos[j].cantidad * especies[i].precio;
                montoTotal += montoPedido;
                printf("Monto a cobrar: %.2f\n", montoPedido);
                printf("\n");
            }
            printf("Monto total a cobrar por la especie: %.2f\n\n", montoTotal);
        }
    }
}

// Función para agregar pedidos a una especie
void agregarPedidosAEspecie(int indiceEspecie) {
    if (especies[indiceEspecie].stock <= 0) {
        printf("No hay stock disponible para la especie %s.\n", especies[indiceEspecie].nombre_cientifico);
        return;
    }

    printf("Ingrese la cantidad de pedidos para la especie %s: ", especies[indiceEspecie].nombre_cientifico);
    int cantidadPedidos;
    scanf("%d", &cantidadPedidos);

    // Verificar si hay suficiente stock
    if (cantidadPedidos > especies[indiceEspecie].stock) {
        printf("No hay suficiente stock disponible para la cantidad de pedidos ingresada.\n");
        return;
    }

    // Actualizar el stock y agregar los pedidos
    especies[indiceEspecie].stock -= cantidadPedidos;
    especies[indiceEspecie].num_pedidos += cantidadPedidos;

    // Obtener datos del pedido
    for (int i = 0; i < cantidadPedidos; i++) {
        printf("Ingrese la razón social del cliente %d: ", i + 1);
        scanf("%s", especies[indiceEspecie].pedidos[i].razon_social);

        printf("Ingrese el teléfono del cliente %d: ", i + 1);
        scanf("%s", especies[indiceEspecie].pedidos[i].telefono);

        printf("Ingrese el nombre del empleado que vende %d: ", i + 1);
        scanf("%s", especies[indiceEspecie].pedidos[i].empleado_nombre);

        printf("Ingrese el apellido del empleado que vende %d: ", i + 1);
        scanf("%s", especies[indiceEspecie].pedidos[i].empleado_apellido);

        especies[indiceEspecie].pedidos[i].cantidad = 1; // Puedes modificar según tus necesidades
    }

    printf("Pedidos agregados exitosamente para la especie %s.\n", especies[indiceEspecie].nombre_cientifico);
}

// Función para actualizar el stock de una especie
void actualizarStockEspecie(int indiceEspecie) {
    printf("Ingrese la cantidad a restar al stock actual para la especie %s: ", especies[indiceEspecie].nombre_cientifico);
    int cantidad;
    scanf("%d", &cantidad);

    // Verificar que el valor ingresado no sea inferior a los pedidos vigentes
    if (cantidad < especies[indiceEspecie].num_pedidos) {
        printf("La cantidad ingresada es inferior a los pedidos vigentes. No se puede actualizar el stock.\n");
        return;
    }

    especies[indiceEspecie].stock -= cantidad;
    printf("Stock actualizado exitosamente para la especie %s.\n", especies[indiceEspecie].nombre_cientifico);
}

// Función para actualizar el precio de una especie
void actualizarPrecioEspecie(int indiceEspecie) {
    printf("Ingrese el nuevo precio para la especie %s: ", especies[indiceEspecie].nombre_cientifico);
    scanf("%f", &especies[indiceEspecie].precio);
    printf("Precio actualizado exitosamente para la especie %s.\n", especies[indiceEspecie].nombre_cientifico);
}

int main() {
    int opcion;
    int indiceEspecie;

    do {
        printf("___________ Gestión de operaciones _____________\n");
        printf("01. Mostrar todos los árboles/especies disponibles.\n");
        printf("02. Mostrar árboles/especies según stock.\n");
        printf("03. Mostrar todos los pedidos.\n");
        printf("04. Agregar pedidos a una especie.\n");
        printf("05. Actualizar stock de una especie.\n");
        printf("06. Actualizar el precio de una especie.\n");
        printf("07. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarTodosLosArboles();
                break;
            case 2:
                printf("Ingrese el límite de stock: ");
                int limiteStock;
                scanf("%d", &limiteStock);
                mostrarArbolesSegunStock(limiteStock);
                break;
            case 3:
                mostrarTodosLosPedidos();
                break;
            case 4:
                printf("Ingrese el índice de la especie a la cual agregar pedidos: ");
                scanf("%d", &indiceEspecie);
                agregarPedidosAEspecie(indiceEspecie);
                break;
            case 5:
                printf("Ingrese el índice de la especie a la cual actualizar el stock: ");
                scanf("%d", &indiceEspecie);
                actualizarStockEspecie(indiceEspecie);
                break;
            case 6:
                printf("Ingrese el índice de la especie a la cual actualizar el precio: ");
                scanf("%d", &indiceEspecie);
                actualizarPrecioEspecie(indiceEspecie);
                break;
            case 7:
                printf("Saliendo del programa. Hasta luego.\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 7);

    return 0;
}
