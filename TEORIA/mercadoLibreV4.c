#include<stdio.h>
#include<stdlib.h>
#define MAX  20

struct{
     char modelo[MAX]; 
     float precio;
} typedef producto;


struct{
    char marca[MAX]; 
    char categoria[MAX];
    int stock;
    producto *disponibles ;
} typedef venta;


void mostrarProductos(venta producto[2] , int cart);

int main( )
{
    //--> consulto el tamaño arreglo principal
    int cantArt;
    printf("Ingrese la cantidad de articulos ha cargar: ");
    scanf("%d", &cantArt);

    //--> reservo segun ese tamaño el arreglo principal
    //--> *articulo se lo crea y define en main 
    venta *articulo = (venta *)malloc(cantArt * sizeof(venta));

     //--> codigo para tomar los datos 
    for (int j = 0; j < cantArt; j++) 
    {
        printf("Ingrese la marca del producto: "); 
        gets(articulo[j].marca);
        printf("Ingrese la categoria del producto: ");
        gets(articulo[j].categoria);
        printf("Ingrese el stock: ");
        //poner  & al los scanf 
        scanf("%d", &articulo[j].stock);

          //--> se hace una reservacion en tiempo de ejecucion de los arreglos secundarios 
        fflush(stdin);

         //--> no se crea un nuevo puntero , se usa el que ya esta en la estructura
         //-->la estructura principal tiene 1 puntero y si existe un arreglo con cantArt estructuras principales 
         //--> se creara un puntero por cada elemento del arreglo articulo osea igual cantArt 

        articulo[j].disponibles = (producto *)malloc(articulo[j].stock * sizeof(producto));

        //--> imprimir todos los articulos 
        for (int i = 0; i < articulo[j].stock; i++)
        {
            printf("Ingrese el modelo del producto: ");
            gets(articulo[j].disponibles[i].modelo);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &articulo[j].disponibles[i].precio); 
            fflush(stdin);
        }
    }

    mostrarProductos(articulo, cantArt);// dentro de la función libera el puntero de productos

    
    free(articulo); // Libera el puntero de ventas

    return 0;
}


void mostrarProductos(venta producto[2] , int cart)
{
    puts("***************MERCADERIA************");

    for (int j = 0; j < 2; j++)
    {    
        //--> imprimo primero lo que es solo de la estructura principal 
        printf("MARCA: %s\n", producto[j].marca);
        printf("Categoría: %s\n", producto[j].categoria); 
        printf("STOCK: %d\n", producto[j].stock);

        //--> imprimo despues lo que es solo de la estructura secundaria 
        printf("---------PRODUCTOS DISPONIBLES-------");
        for (int i = 0; i < producto[j].stock; i++)
        {
            printf("Modelo: %s\n", producto[j].disponibles[i].modelo); 
            printf("Precio: %.2f\n", producto[j].disponibles[i].precio);
            puts("***************************************");
            //--> libero la informacion 
            free(producto[j].disponibles);
        }
    }
 }