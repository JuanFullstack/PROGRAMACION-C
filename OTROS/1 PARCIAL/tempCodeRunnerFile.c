#include <stdio.h>


int main ()
{
    puts(" ************** comienzo programa  ********************** \n \n ");
 int x=3 , y ;
 float z;
 
  y = x + 3 ;
  printf("  y = x + 3 \n") ;
  printf(" suma entre 2 enteros :   %d \n \n ",y) ;

  y=3*x*x + 2*x+1 ;
  printf("  y=3*x*x + 2*x+1 \n") ;
  printf(" suma/producto entre 2 enteros :   %d \n \n ",y) ;

   z=x*0.3;
   printf("  z=x*0.3 \n") ;
   printf(" producto entre float-int : %f \n \n ",z) ;
   
   z=y/x;
   printf("  z=y/x  \n") ;
   printf(" division entre float-int-int :  %f \n \n",z) ;

  z=(float)y/x;
  printf("  z=y/x  \n") ;
   printf(" division entre float-float-int : %f \n \n",z) ;

return 0 ;
}