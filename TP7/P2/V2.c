#include <stdio.h>
#include <stdlib.h>

void Imprimir ( int *arre , int tama1 );

int main()
{

   system("cls");

   int cantidad  ;

   printf("ingrese la Cantidad\n");
   scanf("%d", &cantidad);

   int *arreglo = (int*)malloc(cantidad*sizeof(int));

  printf("Ingrese los valores\n");

  for (int i = 0; i < cantidad; i++)
  {
     scanf("%d", &*(arreglo+i));
     
  }
  
  Imprimir(arreglo,cantidad);

 return 0;
}




void Imprimir ( int *arre , int tama1 ){
int sumax=0;
int posicion ;
system("cls");

printf("Arreglo original : \n");
for (int i = 0; i < tama1; i++)
{
    if(i==0 )
    {
       printf("[%d ," , *arre);
    }else if (i!=0 && i!=(tama1-1))
    {
       printf("%d ," , *arre);
    }else {
       printf("%d ]," , *arre);
    }

    if ((*arre + *(arre+1)) > sumax){

       sumax=(*arre + *(arre+1));
       posicion=i ;

    }

 arre++;


}
     arre -= tama1;

    printf("\n \n");
    printf("Nuevo arreglo\n");
    

    *arre    =*(arre + posicion);
    *(arre+1)=*(arre + posicion + 1 );
    *(arre+2)=posicion ;
    *(arre+3)=posicion + 1 ;
    *(arre+4)=sumax ;

    arre =(int*)realloc(arre, 5*sizeof(int));

    printf("[ %d , " ,  *arre);
    printf("  %d , " ,  *(arre+1));
    printf("  %d , " , *(arre+2));
    printf("  %d , " , *(arre+3) );
    printf("  %d ] , " , *(arre+4) );









}