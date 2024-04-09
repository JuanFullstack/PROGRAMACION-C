#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main()
{
system("cls") ;

srand(time(NULL));


 prueba ( ) ;

 


 return 0;
}



void  prueba ( )
{

  for (int i = 0; i < 5; i++)
  {
    
    printf("( %d )  " , (rand() % 20 ) -10);
   

  }

}