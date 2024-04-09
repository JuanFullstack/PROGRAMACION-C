#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void funcionMayor (int *arre , int tama1 , int *mayor);

int main(   )
{
 
 system("cls");
 srand(time(NULL));
 int cantidad=0;
 int num_mayor=0;
 int *p_num_mayor=&num_mayor;

 printf("ingrese cantidad : ");
 scanf("%d", &cantidad);

 
 int *aletorios=(int*)malloc(cantidad*sizeof(int));
 
system("cls");

puts("*****Analisis *****");
funcionMayor(aletorios,cantidad,p_num_mayor);




 return 0;
}



void funcionMayor (int *arre , int tama1 , int *mayor){

int posicion ;

  for (int i = 0; i < tama1; i++)
  {
  
    *arre =rand()%99 ;
    

    if(i==0  ) {
    
    printf("[ %d , " , *arre );
    
    }else if (i!= (tama1-1)) {
    
    printf(" %d , " , *arre );
    }else {
    
     printf(" %d ] " , *arre );
    
    }
    

    if( *arre > *mayor){
    
     *mayor = *arre;
     posicion=i;
     
    
    }
    
    arre++;
  }
 printf(" \n" );
 printf(" mayor valor : %d  " , *mayor);

  


}