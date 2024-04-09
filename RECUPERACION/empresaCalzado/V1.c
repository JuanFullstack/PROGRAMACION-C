#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*1) Empresa vende calzados de deporte y tiene 4 sucursales (Concepcion, Yerba Buena, Capital, Alberdi):

- Modelo (Dione, California, Mirror y 1 más)
- Categoría (urbano, trekking, zapato, ojota)
- Precio
- Stock de fabrica
- Sucursal (nombre, stock)

La estructura principal y la sucursal tienen que ser punteros.

a) Modulo para mostrar los modelos disponibles según una categoría ingresada.
b) Modulo para controlar los modelos de las sucursales, el que tenga menos a 10 pares, debe realizar una reparacion(? de stock 
(ingresada por el usuario), se debe sumar el stock de la sucursal y bajar del stock de fabrica, controlar que el dato ingresado sea menor o igual al stock de fabrica.

-----
2) Cargar un arreglo con números aleatorios del 0 al 999. Hacer un procedimiento que calcule cual es el número mayor. Mostrar en el programa (no en el modulo) el elemento obtenido.
Usar notación de punteros para avanzar sobre el arreglo.*/



;

struct 
{
 char nombre[15];
 int stock_sucursal ;
} typedef Datos;


// venta de calzados 

struct 
{
 char modelo[15];
 char categoria [15];
 int stock_fabrica ;
 float precio ;
 Datos *sucursales ;
} typedef Producto ;

void imprimirDatos ( Producto *arre , int tam1 , int *tam2 );

int main( )
{
   system("cls");

   Datos sucursal1 = {"aguilares" , 10 };
   Datos sucursal2 = {"salta" , 10 };
   Datos sucursal3 = {"aguilares" , 10 };
   Datos sucursal4 = {"medonza" , 10 };

   Datos sucursal5 = {"lules" , 10 };
   Datos sucursal6 = {"las talitas" , 10 };
   Datos sucursal7 = {"chaco" , 10 };

   Datos arreglo1[]= {sucursal1, sucursal2,sucursal3,sucursal4} ;
   Datos arreglo2[]= {sucursal5, sucursal6,sucursal7} ;

   Datos *puntero1 = arreglo1 ;
   Datos *puntero2 = arreglo2 ;

  
  //-------> 


   Producto info[] = {
        {"Dione", "urbano", 450, 3, puntero1},
        {"California", "trekking", 845, 20, puntero2},
    };

//-----> tam2 info 

  int tam2[] = {4,3};
  int *puntero_tam2 =tam2 ;

    // Crear y asignar memoria para puntero_info y sus elementos
    Producto *puntero_info = (Producto *)malloc(2 * sizeof(Producto));

    for (int i = 0; i < 2; i++)
    {
        puntero_info[i] = info[i];  // Copiar la estructura Producto
        puntero_info[i].sucursales = (Datos *)malloc(info[i].stock_fabrica * sizeof(Datos));  // Asignar memoria para sucursales
        memcpy(puntero_info[i].sucursales, //puntero origen
               info[i].sucursales, // puntero destino
               info[i].stock_fabrica * sizeof(Datos));  // Tamaño.
    }

    // Hacer uso de puntero_info como sea necesario...

    // Liberar la memoria asignada
    for (int i = 0; i < 2; i++)
    {
        free(puntero_info[i].sucursales);
    }
   
    free (puntero_info);


  //-- -- > llamado a la funcion 

  imprimirDatos ( info , 2 , puntero_tam2);


 return 0;
}




void imprimirDatos ( Producto *arre , int tam1 , int *tam2 ) {

  puts ("******  DATOS *********");
   for (int i = 0; i < tam1 ; i++)
  {
     for (int j = 0; j < *tam2 ; j++)
     {
         
           printf("Sucursal: %s\n", arre[i].sucursales[j].nombre);
            printf("Stock Sucursal: %d\n", arre[i].sucursales[j].stock_sucursal);
            printf("\n");
         
     }

     tam2++;
  }
 
}