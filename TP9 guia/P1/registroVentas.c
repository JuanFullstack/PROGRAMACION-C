#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20





// Definición del tipo struct producto
typedef struct {
    char nombre[50];
    float precio_unitario;
    int *cantidad_vendida; // Arreglo para almacenar las cantidades vendidas por mes
} Producto;



void cargarCatalogo( Producto arre[] , int cant_producto );
void mostrarProducto(Producto arre[] , int cant_producto );
void mostrarTodos(Producto arre[] , int cant_producto );
void modificarPrecioUnitario(Producto *arre , int cant_producto);


int main() {

   system("cls");
    int num_producto=0 ;

    printf("\ncuantos productos va a ingresar :\n");
    scanf("%d" , &num_producto);


    Producto *CATEGORIA = (Producto*)malloc(num_producto*sizeof(Producto));
    

    cargarCatalogo( CATEGORIA , num_producto );
    //mostrarProducto(CATEGORIA , num_producto);
   //mostrarTodos( CATEGORIA , num_producto );
   modificarPrecioUnitario(CATEGORIA , num_producto);


    // // Prueba de los módulos del apartado b)
    // printf("\nMostrando información de un producto:\n");
    // mostrarProducto(0);

    // printf("\nMostrando información de todos los productos:\n");
    // mostrarTodosLosProductos();

    // // Prueba de los módulos adicionales
    // modificarPrecioUnitario(0, 15.5);
    // printf("\nProducto 1 - Precio unitario modificado: %.2f\n", catalogo[0].precio_unitario);

    // printf("\nMonto total recaudado por ventas del Producto 1: %.2f\n", montoTotalRecaudado(0));

    // printf("\nIdentificando mes con más ventas para cada producto:\n");
    // mesConMasVentas();

    return 0;
}


// Módulo para cargar el arreglo completo
void cargarCatalogo( Producto *arre , int cant_producto ) {
    srand(time(NULL)); // Inicialización del generador de números aleatorios
    for (int i = 0; i < cant_producto ; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fflush(stdin);
        scanf("%s", arre[i].nombre);
       

        
        printf("Ingrese el precio unitario del producto %d: ", i + 1);
        scanf("%f", &arre[i].precio_unitario);

        // Reserva dinámica y carga de cantidades vendidas aleatorias
        arre[i].cantidad_vendida=(int*)malloc(12*sizeof(int));

        for (int j = 0; j < 12; j++) {
            arre[i].cantidad_vendida[j] = rand() % 96 + 5; // Cantidades aleatorias entre 5 y 100
        }
    }
}

// Módulo para mostrar la información de un producto en particular
void mostrarProducto(Producto *arre , int cant_producto ) {
 int id=0;
   printf("seleccione un producto:\n");
   for (int i = 0; i < cant_producto; i++) {
        printf("%d : %s\n", i+1 , arre[i].nombre);  
    }

     scanf("%d", &id);

    printf("Nombre: %s\n", arre[id-1].nombre);
    printf("Precio Unitario: %.2f\n", arre[id-1].precio_unitario);
    printf("Cantidades Vendidas por Mes:\n");
    for (int i = 0; i < 12; i++) {
        printf("Mes %d: %d\n", i + 1, arre[id-1].cantidad_vendida[i]);
    }
    printf("\n");
}


void mostrarTodos(Producto *arre , int cant_producto ) {
 int id=0;
   printf("ID | NOMBRE | PRECIO \n");
  
   for (int i = 0; i < cant_producto; i++) {
        printf("%d  |  %s    |  %2.f \n", i+1 , arre[i].nombre , arre[i].precio_unitario );  
    }

}



// Módulo para modificar el precio unitario de un producto en particular
void modificarPrecioUnitario(Producto *arre , int cant_producto) {
 int id=0;
   printf("seleccione un producto:\n");
   for (int i = 0; i < cant_producto; i++) {
        printf("%d : %s\n", i+1 , arre[i].nombre);  
    }

     scanf("%d", &id);


     printf("precio actual: %2.f \n", arre[id-1].precio_unitario);
     printf("ingrese nuevo precio : ");
     scanf("%f" ,&arre[id-1].precio_unitario );

     printf("NUEVO precio actual: %2.f \n", arre[id-1].precio_unitario);

 
}

// // Módulo para calcular el monto total recaudado por ventas de un producto en el último año completo
// float montoTotalRecaudado(int index) {
//     float montoTotal = 0;
//     for (int i = 0; i < 12; i++) {
//         montoTotal += catalogo[index].precio_unitario * catalogo[index].cantidad_vendida[i];
//     }
//     return montoTotal;
// }

// // Módulo para identificar el mes con más ventas para cada producto
// void mesConMasVentas() {
//     for (int i = 0; i < CANT_PRODUCTOS; i++) {
//         int maxVentas = catalogo[i].cantidad_vendida[0];
//         int mesMaxVentas = 1;

//         for (int j = 1; j < 12; j++) {
//             if (catalogo[i].cantidad_vendida[j] > maxVentas) {
//                 maxVentas = catalogo[i].cantidad_vendida[j];
//                 mesMaxVentas = j + 1;
//             }
//         }

//         printf("Producto %d - Mes con más ventas: %d (Cantidad: %d)\n", i + 1, mesMaxVentas, maxVentas);
//     }
// }
