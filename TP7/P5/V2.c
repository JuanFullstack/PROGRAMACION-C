#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void cargarTiros(int *puntos , int tiros);
float calcularGanancia(int *puntos , int tiros );

int main( )
{

 system("cls");
 int tirosx;

 printf("ingrese Cantidad tiros:  \n");
 scanf("%d",&tirosx);

 int *puntos = (int*)malloc(tirosx*sizeof(int));
 cargarTiros(puntos,tirosx);
 calcularGanancia(puntos,tirosx);



 return 0;
}



void   cargarTiros(int *puntos , int tiros)
{
  
   for (int i = 0; i < tiros; i++)
   {
      puntos[i]=( rand()% 9 )+1 ;

    
   }

}

float calcularGanancia(int *puntos , int tiros  )
{
  int totalGanancia =0 ;
  int totalPierdida=0;

  for (int i = 0; i < tiros; i++)
  {
   
       switch (puntos[i])
      {
      case  10 : totalGanancia+=1000;
                 totalPierdida+=350;
      break;
      case   9 : totalGanancia+=850;
                 totalPierdida+=350;
      break;
      case   8 : totalGanancia+=350;
                 totalPierdida+=350;
      break;
      case  7  : totalGanancia+=300;
                 totalPierdida+=350;
      break;
      case  1  : 
      case  2  : totalPierdida+=100;
                 totalPierdida+=350;
      break;

      default : totalPierdida+=350;
      break;

      }


  }

  printf("Gasto : %d "  , (tiros*350) );
  printf("Total ganancia : %d "  ,totalGanancia );
  printf("Total perdida : %d "  ,totalPierdida );
  printf("saldo : %d "  ,totalGanancia - totalPierdida );


}


