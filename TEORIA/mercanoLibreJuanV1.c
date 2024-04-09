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


void CargarDatos (venta *arre , int tam1 );
void ImprimirDatos (venta *arre , int tam1  );

int main()
{
  system("cls");
  int tama1=1;

  venta *principal = (venta*)malloc(tama1*sizeof(venta));

  puts("***** CARGA DE DATOS *****");
 CargarDatos (principal , tama1 );

 system("cls");

 puts("***** DATOS IMPRESOS *****");
 ImprimirDatos (principal , tama1 );

 return 0;
}


  

void CargarDatos (venta *arre , int tam1  ){

 
  for (int i = 0; i < tam1; i++)
  {
    
     puts("Ingrese Marca:");
     gets(arre[i].marca);
     puts("Ingrese Categoria:");
     gets(arre[i].categoria);
     printf("Ingrese Stock ");
     scanf("%d",&arre[i].stock );
     
      arre[i].disponibles=(producto*)malloc(arre[i].stock*sizeof(producto));
      fflush(stdin);
      for (int j = 0; j < arre[i].stock; j++)
      {
          puts("Ingrese Modelo:");
          gets(arre[i].disponibles[j].modelo);
          printf("Ingrese Precio:");
          scanf("%f",&arre[i].disponibles[j].precio);
          fflush(stdin);
      }
  }
}



void ImprimirDatos (venta *arre , int tam1 ){

  for (int i = 0; i < tam1; i++)
  {

     printf("Marca :%s\n" , arre[i].marca);
     printf("Categoria :%s\n" , arre[i].categoria);
     printf("Stock :%d\n" , arre[i].stock);
     
      for (int j = 0; j < arre[i].stock; j++)
      {
        printf("Modelo :%s\n" , arre[i].disponibles[j].modelo);
        printf("Precio Modelo :%.2f\n" , arre[i].disponibles[j].precio);
          
      }
  }
}


