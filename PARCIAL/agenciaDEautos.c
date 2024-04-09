#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct 
{
  int anio;
  float kms ;
  float precios;

} typedef Producto;


struct 
{ char Codigo[20];
  char Marca[20];
  char Modelo[20];
  int stockMarca;
  int StockModelo;
  int Productos_disponibles;
  Producto *disponible;
} typedef Auto;


void listarMarca (Auto *arre , int tam1 , int tam2);

int main( )
{

  //  int anio;
  //  float kms ;
  // float precios;

    system("cls");
    Producto P1 = {2015,80000,2145};
    Producto P2 = {2022,230000,2145};
    Producto P3 = {2020,80000,2145};
    Producto P4 = {2001,40000,2145};
    Producto P5 = {2006,1000,2145};

    Producto P6 = {2015,90000,2145};
    Producto P7 = {2015,40000,2145};
    Producto P8 = {2015,100000,2145};
    Producto P9 = {2015,80000,2145};
    Producto P10= {2015,40000,2145};

    Producto P11 = {2015,90000,2145};
    Producto P12 = {2015,40000,2145};
    Producto P13 = {2015,80000,2145};
    Producto P14 = {2015,680000,2145};
    Producto P15= {2015,40000,2145};

   Producto arre1[] ={ P1,P2,P3,P4, P5} ;
   Producto arre2[] ={ P6,P7,P8,P9, P10} ;
   Producto arre3[] ={ P11,P12,P13,P14, P15} ;

  Producto *pArre1=arre1;
  Producto *pArre2=arre2;
  Producto *pArre3=arre3;

  
  Auto datos[]= 
  { {"H54D","Ford","flis",12 ,4 ,arre1},
    {"H54D","Ka","flis",12 ,4 ,arre2},
    {"H54D","renault","clio",12 ,4 ,arre3},
  
  };

 listarMarca (datos , 3 , 5);
 
 return 0;
}



void listarMarca (Auto *arre , int tam1 , int tam2){

 for (int i = 0; i < tam1; i++)
 {
     if ( strcmp(arre[i].Marca,"Ford")==0|| strcmp(arre[i].Marca,"Ka")==0 )
     {

       for (int j = 0; j < tam2; j++)
       {
         if( ( arre[i].disponible[j].kms==80000 ) )
         {
                     printf("Codigo : %s\n",arre[i].Codigo);
                     printf("Marca : %s\n",arre[i].Marca);
                     printf("Modelo : %s\n",arre[i].Modelo);
                     printf("StockMarca : %d\n",arre[i].stockMarca);
                     printf("StorckModelo : %d\n",arre[i].StockModelo);
                     printf("Kms : %d Kms\n",arre[i].disponible[j].kms);
                     printf("Anio : %d\n",arre[i].disponible[j].anio);
                     printf("Precio : $ %d\n",arre[i].disponible[j].precios);
                     printf("\n");
         
         }


       }
     }
  }
}