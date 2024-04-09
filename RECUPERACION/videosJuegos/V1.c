#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define MAX 15 




struct 
{
  char nombre[MAX];
  int edad ;
  int cantidad_partidas;
  char tipo_juego[MAX];
  int puntaje ;
  float transcurrido ;
 
} typedef datos;

void cargaDatos ( datos *arre , int tam1 );
void imprimirDatos(datos arre[], int numJugadores) ;
void ImprimirEdadTiempo ( datos *arre , int tam1) ;
void imprimirJugadorPuntaje (datos *arre , int tam1) ;

int main(  )
{

 system("cls");

 int numjug =0 ;

  printf("ingrese numero de jugadores \n");
  scanf("%d" , &numjug);

 datos *principal = (datos*)malloc(numjug*sizeof(datos));


 cargaDatos ( principal , numjug);
 imprimirJugadorPuntaje ( principal , numjug);



 return 0;
}



void cargaDatos ( datos *arre , int tam1 ) {

int ganadas =0;
int emparadas=0;
int perdidas =0 ;


char nombreX[][15]={"Pedro" , "Jose" , "Carlos" , "Matias" , "Lourdes" ,"Marcelo"};
char tipoJuegox[][15]={"Ajedres" , "Damas" , "Jenga" ,"Burako" , "Monopolio"};
int Victorias[] ={ 1 ,2 ,3 }; // 1 : gano , 2: empato , 3:perdio

srand(time(NULL));
for (int i = 0; i < tam1; i++)
{

  strcpy(arre[i].nombre ,nombreX[rand()%6] );
  arre[i].edad = (rand()% 13)+7 ;
  arre[i].cantidad_partidas= (rand()% 10 ) ; 
  strcpy( arre[i].tipo_juego ,tipoJuegox[rand() % 4] );
  arre[i].transcurrido= ((float)rand()/RAND_MAX)*(9.0) + 1.0 ;


   for (int j = 0; j < arre[i].cantidad_partidas; j++)
   {
         switch (Victorias[rand()%2])
      {
      case 1 : ganadas++;
      break;
      case 2 : emparadas++;
      break;
      case 3 : perdidas++;
      break;
      
      }
   }

    arre[i].puntaje  = ganadas*3 + emparadas*1 ;
 
}
   

}


void imprimirDatos(datos arre[], int numJugadores) {

    for (int i = 0; i < numJugadores; i++) {
        printf("Jugador %d:\n", i + 1);
        printf("Nombre: %s\n", arre[i].nombre);
        printf("Edad: %d\n", arre[i].edad);
        printf("Cantidad de partidas: %d\n", arre[i].cantidad_partidas);
        printf("Tipo de juego: %s\n", arre[i].tipo_juego);
        printf("Puntaje: %d\n", arre[i].puntaje);
        printf("Tiempo transcurrido: %.2f\n", arre[i].transcurrido);
        printf("\n");
    }
}


void imprimirJugadorPuntaje (datos *arre , int tam1) {
int Seleccion =0 ;
int mayorPuntaje=0 ;
int posicion=0 ; 
int totalJugadores =0 ;

char tipoJuegox[][15]={"Ajedres" , "Damas" , "Jenga" ,"Burako" , "Monopolio"};

 printf("Seleccione un opcion\n");
 printf("1- Ajedres\n");
 printf("2-Damas\n");
 printf("3-Jenga\n");
 printf("4-Burako\n");
 printf("5-Monopolio\n");
 scanf("%d" , &Seleccion);

for (int  i = 0; i < tam1; i++)
{

     if(  strcmp(arre[i].tipo_juego , tipoJuegox[Seleccion-1])==0   )
     {
 
      totalJugadores++;
      if(  arre[i].puntaje > mayorPuntaje ) 
      {
        mayorPuntaje = arre[i].puntaje ;
        posicion = i ;
        
      }
 
 
     }

}

if ( totalJugadores !=0  )
{
   system("cls");
   printf( " Juego : %s\n" , tipoJuegox[Seleccion-1]  );
   printf( " Total de jugadores : %d\n" , totalJugadores );
   printf( " Puntaje mas Alto : %d\n" , mayorPuntaje );
   printf( " Puntaje Nombre : %s\n" , arre[posicion] );
}else {

  system("cls");
  printf( "No hay jugadores en esa categoria \n"  );

}






}


void ImprimirEdadTiempo ( datos *arre , int tam1) 
{

  int TiempoTrancuridoInfantil =0 ;
  int infantil=0;
  int posiInfantil=0 ;
  int TiempoTrancuridoJubenil =0 ;
  int Jubenil=0 ;
  int posiJubenil=0 ;
  int TiempoTrancuridoMayor =0 ;
  int mayor = 0 ;
  int posiMayor=0 ;



  for (int i = 0; i < tam1 ; i++)
  {
    
    if (arre[i].edad <=12)
    {

      infantil++;

      if (arre[i].transcurrido >= TiempoTrancuridoInfantil) 
      {
        TiempoTrancuridoInfantil = arre[i].transcurrido ;
        posiInfantil=i ;
      }
    

    }else if (arre[i].edad >= 13 && arre[i].edad <=17 ) 
    {
    
      Jubenil++;

      if (arre[i].transcurrido >= TiempoTrancuridoJubenil) 
      {
        TiempoTrancuridoJubenil = arre[i].transcurrido ;
        posiJubenil=i ;
      }
             
    }else if (arre[i].edad >= 18) 
    {
      mayor++;
      if (arre[i].transcurrido >= TiempoTrancuridoMayor) 
      {
        TiempoTrancuridoMayor = arre[i].transcurrido ;
        posiMayor = i ;
      }
      
    }
  
  }


    printf ("**** Tabla posiciones ******* \n");

    printf ("CATEGORIA INFANTIL  \n");
    printf ("Total Participantes : %d \n" , infantil);
    printf ("Mayor tiempo Trancusrido: %d Horas\n" , TiempoTrancuridoInfantil);
    printf ("Nombre participante: %s \n" , arre[posiInfantil].nombre);
    printf ("\n" );
    printf ("CATEGORIA JUBENIL  \n");
    printf ("Total Participantes : %d \n" , Jubenil);
    printf ("Mayor tiempo Trancusrido: %d Horas \n" , TiempoTrancuridoJubenil);
    printf ("Nombre participante: %s \n" , arre[posiJubenil].nombre);
    printf ("\n" );
    printf ("CATEGORIA MAYOR   \n");
    printf ("Total Participantes : %d \n" , mayor);
    printf ("Mayor tiempo Trancusrido: %d Horas \n" , TiempoTrancuridoMayor);
    printf ("Nombre participante: %s \n" , arre[posiMayor].nombre);


}


