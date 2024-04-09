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

void mostrarProductos(venta producto);
int main( )
{
    
    venta articulo;
    printf("Ingrese la marca del producto");
    gets(articulo.marca);
    printf("Ingrese la categoria del producto");
    gets(articulo.categoria);
    printf("Ingrese el stock:");
    scanf("%d", &articulo.stock);
    articulo.disponibles =(producto *) malloc(articulo.stock * (sizeof(producto)));
    fflush(stdin);

    for(int i = 0; i < articulo.stock; i++) 
    {
        printf("Ingrese el modelo del producto: "); 
        gets(articulo.disponibles[i].modelo);
        printf("Ingrese el precio del producto: "); 
        scanf("%f", &articulo.disponibles[i].precio);
    }

   mostrarProductos(articulo); 

   free(articulo.disponibles);//LIBERO LA MEMORIA SOLICITADA


    return 0;
}


void mostrarProductos(venta producto)
{ 

    puts("*****************MERCADERIA*****************");
    printf("----MARCA => %s \n", producto.marca);
    printf("Categoría: %s\n", producto.categoria);
    printf("----STOCK => %d \n", producto.stock);
    printf("----PRODUCTOS DISPONIBLES-----\n");
    
    for (int j = 0; j < producto.stock; j++)
    {
        printf("Modelo: %s\n", producto.disponibles[j].modelo);
        printf("Precio: %.2f \n", producto.disponibles[j].precio);
    }
}