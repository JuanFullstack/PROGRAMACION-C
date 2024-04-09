#include<stdio.h>
#include<stdlib.h>
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

void cargarDatos (venta *arre , int tam1);
 void imprimirDatos (venta *arre , int tama);

int main( )
{  
    system("cls");
    int tama=1;
  
  venta *datosGral = (venta*)malloc(tama*sizeof(venta));

  puts("****** CARGA DE DATOS  *******");
  cargarDatos (datosGral , tama);

  system("cls");
  puts("****** impresion de datos  *******");
  imprimirDatos (datosGral , tama);
  
  free(datosGral);

 return 0;
}


  

    void cargarDatos (venta *arre , int tam1){
    
      char MarcaX[][20]={"Samsung" , "Lg" ,"Motorola" , "Apple"};
      char categoriax[][20]={"Celular", "Notebook" , "Tablet"};
      char Modelox[][20]={"S9" ,"S20 plus" ,"S22 ultra"};
      int Seleccion;

    for (int i = 0; i < tam1; i++)
    {
       puts("ingrese Marca : 1:Samsung  2:Lg  3:Motorola  4:Apple" );
       scanf("%d", &Seleccion);
       strcpy(arre[i].marca , MarcaX[Seleccion-1]);
       puts("ingrese Categoria: 1: Celular  2: Notebook  3: Tablet ");
        scanf("%d", &Seleccion);
       strcpy(arre[i].categoria , categoriax[Seleccion-1]);
       printf("ingrese Stock");
       scanf("%d", &arre[i].stock);

       fflush(stdin);
       arre[i].disponibles=(producto*)malloc(arre[i].stock*sizeof(producto));
       for (int j = 0; j < arre[i].stock ; j++)
       {
          puts("ingrese Modelo : 1:S9   2:S20 plus   3: S22 ultra ");
          scanf("%d", &Seleccion);
          strcpy(arre[i].disponibles[j].modelo , Modelox[Seleccion-1]);
          printf("ingrese Precio");
          scanf("%f", &arre[i].disponibles->precio);
          fflush(stdin);
       }
       

    }
    
    }


  // char marca[MAX]; 
    // char categoria[MAX];
    // int stock;
    // producto *disponibles ;


    //  char modelo[MAX]; 
    //  float precio;


    void imprimirDatos (venta *arre , int tama){
    
     for (int i = 0; i < tama; i++)
     {
          printf("Marca : %s\n" , arre[i].marca);
          printf("Categoria : %s\n" , arre[i].categoria);
          printf("Marca : %d\n" , arre[i].stock);
          for (int  j = 0; j < arre[i].stock; j++)
          {
             printf("Modelo : %s\n" , arre[i].disponibles[j].modelo);
             printf("Precio : %.2f\n" , arre[i].disponibles->precio);
          }

          free(arre[i].disponibles);
          
    
     }

    }