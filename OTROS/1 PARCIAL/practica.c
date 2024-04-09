#include <stdio.h>


int main() 
{
       char miniscula , mayuscula ;
       puts("---------comienzo programa------------------");
       printf("\n introduce una letra minuscula  : ");
       scanf("%c" , &miniscula);
  

  mayuscula = miniscula - 32 ;

printf(" \n en minuscula : %c" , miniscula);
printf("\n en mayuscula : %c" , mayuscula);

 return 0 ;
}