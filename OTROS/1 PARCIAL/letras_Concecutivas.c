#include <stdio.h>


int es_vocal(char c); 

char letras ;
char anterior = 'l' ;
char vocalconsecutiva =0 ;
int vuelta = 0 ;

int main() {

printf("\n ingrese una frase con marca final : ");
scanf("%c",&letras);

 while (letras  !='.')
 {  
    vuelta++;
    if (es_vocal(anterior)==1&&es_vocal(letras)==1 )
    {
      vocalconsecutiva++;
    
    } 

  anterior=letras;
  scanf( "%c" , &letras);  
 }

 if (vocalconsecutiva > 0 )
    {
      printf(" \n se encontrarion %d  vocales consecutivas " ,vocalconsecutiva) ;
    
    } else 
    {
    
    printf(" \n no hay  vocales consecutivas en esta frase " ) ;
    
    }

}


int es_vocal(char c) {
    
int  esVocalBool ;

    return 

    (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
     c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    
    
     ;
}


// debo contemplar el esenario que el usuario ponga espacios o incluso mayusculas o esta bien resolver asi nomas ?