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

void mostrarProductos(venta producto[2]);

int main( )
{
    
venta articulo[2];
for (int j = 0; j < 2; j++)
{
    printf("Ingrese la marca del producto"); 
    gets(articulo[j].marca);
    printf("Ingrese la categoria del producto"); 
    gets(articulo[j].categoria);
    printf("Ingrese el stock:"); 
    scanf("%d", &articulo[j].stock);

    articulo[j].disponibles =(producto *) malloc(articulo[j].stock *(sizeof(producto)));

        fflush(stdin);
        for (int i = 0; i < articulo[j].stock; i++)
        {
            printf("Ingrese el modelo del producto: "); 
            gets(articulo[j].disponibles[i].modelo);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &articulo[j].disponibles[i].precio); 
            fflush(stdin);
        }
}
mostrarProductos(articulo);

    return 0;
}


void mostrarProductos(venta producto[2])
{
    puts("***************MERCADERIA************");
    for (int j = 0; j < 2; j++)
    {
        printf("MARCA: %s\n", producto[j].marca);
        printf("Categoría: %s\n", producto[j].categoria); 
        printf("STOCK: %d\n", producto[j].stock);

        printf("---------PRODUCTOS DISPONIBLES-------");
        for (int i = 0; i < producto[j].stock; i++)
        {
            printf("Modelo: %s\n", producto[j].disponibles[i].modelo); 
            printf("Precio: %.2f\n", producto[j].disponibles[i].precio);
            puts("***************************************");
            free(producto[j].disponibles);
        }
    }
 }