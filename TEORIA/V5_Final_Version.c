#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void imprimirDatos ( venta *arre , int tama1 ) ;

int main()
{
   system("cls");

  //-->solicitud de tama principal
  
  int stock1 ;
  printf("ingrese el numero de ventas : \n");
  scanf("%d" ,&stock1 );

fflush(stdin);

//--> reserva dinamica
venta *Princial = (venta*)malloc(stock1*sizeof(venta));


puts("******** Carga  *********");
//--> toma de datos
for (int i = 0; i < stock1; i++)
{
   
   //--> datos principales
   puts("Ingrese la marca");
   gets(Princial[i].marca);

   puts("Ingrese la Categoria:  \n");
   gets(Princial[i].categoria);
   
   //--> stock vs punteros secundarios 
   printf("ingrese el stock de producto %d \n" , i + 1);
   scanf("%d" , &Princial[i].stock);

   fflush(stdin);
   //--> datos secundarios

   Princial[i].disponibles = (producto*)malloc(Princial[i].stock*(sizeof(producto)));

   for (int j = 0; j < Princial[i].stock; j++)
   {
       puts("Ingrese la modelo:  \n");
       gets(Princial[i].disponibles[j].modelo);

       printf("ingrese el precio : \n");
       scanf("%f" , &Princial[i].disponibles[j].precio);

       fflush(stdin);
   }
    
 
} 


puts("***** impresion *******");
imprimirDatos ( Princial , stock1 ) ;

 return 0;
}






void imprimirDatos ( venta *arre , int tama1 ) 
{
        for (int i = 0; i < tama1; i++)
        {
        
        //--> datos principales
        printf("la marca %d : %d \n", i + 1 , arre[i].marca);
        printf("Ingrese la Categoria: %s " , arre[i].categoria);
        printf(" stock producto  %d : %d \n" , i + 1 , arre[i].stock);
        
            for (int j = 0; j < arre[i].stock; j++)
            {   
                
                printf(" la modelo: %s \n", arre[i].disponibles[j].modelo);
                printf(" el precio %.2f: \n", arre[i].disponibles[j].precio );

            }

        }
}