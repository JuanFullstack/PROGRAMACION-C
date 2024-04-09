#include <stdio.h>

int main(){
    char frase;
    int contadorDiptongo=0;

    printf("Ingresar la frase: ");
    scanf("%d", &frase);
    printf("\n");

    while (frase!='.')
    {
        while (frase!=' ' && frase !='.')
        {
            if (frase=='a' || frase=='e' || frase=='i' || frase=='o' || frase=='u' || frase=='A' || frase=='E' || frase=='I' || frase=='O' || frase=='U' )
            {
                scanf("%c", &frase);
                if (frase=='a' || frase=='e' || frase=='i' || frase=='o' || frase=='u' || frase=='A' || frase=='E' || frase=='I' || frase=='O' || frase=='U' ){
                    contadorDiptongo++;
                }
            }else{
               scanf("%c", &frase);
            }
        }
        if (frase!='.')
        {
            scanf("%c", &frase);
        }
    }

    printf("\nLa cantidad de palabras con diptongos es: %d\n", contadorDiptongo);

    return 0;
}