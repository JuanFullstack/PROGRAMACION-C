#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 15

struct 
{
  char nombre_alumno[MAX];
  char curso[MAX];
  char nivel[MAX];
} typedef atencion;



struct 
{
  char nombre_sede[MAX];
  char tipo_atension[MAX] ;
  char nombre_docente[MAX];
  atencion *alumnos ;

} typedef sede ;



void CargarDatos (sede *arre , int tam1 , int *tam2) ;
void  imprimirTodo (sede *arre , int tam1 , int *tam2 ) ;
void imprimirNivel ( sede *arre , int tam1 , int  *tam2);
void ImprimirAtendidosx ( sede *arre , int tam1 , int  *tam2) ;

int main( )
{
  system("cls");
  int num_sedes ;
  printf("ingrese el numero de sedes : ");
  scanf("%d" ,&num_sedes );


 sede *Principal = (sede*)malloc(num_sedes*sizeof(sede));

 int tama2[10] ;

 for (int i = 0; i < num_sedes; i++)
 {
    tama2[i]=(rand()% 3)+2 ;
 }
 
 int *ptama2=tama2 ;


CargarDatos (Principal , num_sedes , ptama2);
ImprimirAtendidosx (Principal , num_sedes , ptama2);






 return 0;
}



void CargarDatos (sede *arre , int tam1 , int *tam2) 
{

    
     
     srand(time(NULL)) ;
     char sedex [][15]= {"yerba buenas"  , "capital" , "sur" };
     char Tipo_atensionx[][15]= {"Domicilio" ,"Hospital"};
     char Docentex[][25]= { "Profe Marcos Cruz"  ,"Profe Lucas trejo" ,  "Profe Lina Perez" };
   
     char Nombrex[][15]= { "Fernando" , "Cristian" , "Sebastian" , "carlos" , "hector" };
     char cursox[][15]= {"Primero" , "Segundo" , "tercero" , "cuarto" , "quinto"};
     char nivel[][15]={"primario","Secundario" , "Terciario", "eduacion superior "};

   for (int i = 0; i < tam1; i++)
   {

       strcpy(arre[i].nombre_sede , sedex[rand()%2]);
       strcpy(arre[i].tipo_atension , Tipo_atensionx[rand()%1]);
       strcpy(arre[i].nombre_docente , Docentex[rand()%2]);
       arre[i].alumnos = (atencion*)malloc((*tam2)*sizeof(atencion));


     for (int j = 0; j < *tam2; j++)
     {
        strcpy(arre[i].alumnos[j].nombre_alumno, Nombrex[rand()%4]);
        strcpy(arre[i].alumnos[j].curso, cursox[rand()%4]);
        strcpy(arre[i].alumnos[j].nivel , nivel[rand()%3]);
        
     }
     tam2++;
    
   }


}


void  imprimirTodo (sede *arre , int tam1 , int *tam2 ) {


  system("cls");

  for (int i = 0; i < tam1; i++)
  {
    printf("Sede : %s\n" , arre[i].nombre_sede );
    printf("Tipo Atencion  : %s\n" , arre[i].tipo_atension );
    printf("Nombre docente : %s\n" , arre[i].nombre_docente );

    for (int j = 0; j < *tam2; j++)
    {

          printf("Nombre Alumno : %s\n" , arre[i].alumnos[j].nombre_alumno );
          printf("Curso : %s\n" , arre[i].alumnos[j].curso );
          printf("Nivel : %s\n" , arre[i].alumnos[j].nivel);
    }
    printf("\n");
    tam2++;
  }
  

}

void imprimirNivel ( sede *arre , int tam1 , int  *tam2)
{
   for (int i = 0; i < tam1; i++)
   {

      for (int j = 0; j < *tam2; j++)
      {
        if
        (strcmp(arre[i].alumnos[j].curso , "Segundo")==0 &&
         strcmp(arre[i].alumnos[j].nivel , "primario")==0)
        {
        printf("Nombre Alumno : %s\n" , arre[i].alumnos[j].nombre_alumno );
        printf("Curso : %s\n" , arre[i].alumnos[j].curso );
        printf("Nivel : %s\n" , arre[i].alumnos[j].nivel);
        printf("\n");

        
        }

      }
      tam2++;
    
   }
   



}


//--> Datos atendidos 




void ImprimirAtendidosx ( sede *arre , int tam1 , int  *tam2) 
{
    int sede_yerba_buenas=0 ;
    int sede_capital=0 ;
    int sede_sur=0;
    int domicilio_yerba_buena=0;
    int domicilio_capital=0;
    int domicilio_sur=0;
    int Hospital_yerba_buena=0;
    int Hospital_capital=0;
    int Hospital_sur=0;



    for (int i = 0; i < tam1; i++)
    {
    
        if(  strcmp(arre[i].nombre_sede , "yerba buenas")==0  ) 
        {
            
            sede_yerba_buenas++;

            if ( strcmp(arre[i].tipo_atension , "Domicilio")==0  )
            {
                domicilio_yerba_buena++;
            }else if ( strcmp(arre[i].tipo_atension , "Hospital")==0  )
            {
                Hospital_yerba_buena++;
            }
            
        }
        

        if(  strcmp(arre[i].nombre_sede , "capital")==0  ) 
        {
        
            sede_capital++;
            
            if ( strcmp(arre[i].tipo_atension , "Domicilio")==0  )
            {
                domicilio_capital++;
            }else if ( strcmp(arre[i].tipo_atension , "Hospital")==0  )
            {
                Hospital_capital++;
            }
        
        }


        if(  strcmp(arre[i].nombre_sede , "sur")==0  ) 
        {
        
            sede_sur++;
            
            if ( strcmp(arre[i].tipo_atension , "Domicilio")==0  )
            {
                domicilio_sur++;
            }else if ( strcmp(arre[i].tipo_atension , "Hospital")==0  )
            {
                Hospital_sur++;
            }
        
        }
    
    }

 
 if(sede_yerba_buenas>sede_capital && sede_yerba_buenas>sede_sur) {
 
 
     printf("Total sede Yerba buenas  : %d\n" , sede_yerba_buenas );
     printf("Total Capital  : %d\n" , sede_capital );
     printf("Total sur  : %d\n" , sede_sur );

    printf("Mayor atencion : Yerba buenas \n" );
    printf("Atencion Domicilio : %d\n" , domicilio_yerba_buena );
    printf("Atencion Hospital : %d\n" , Hospital_yerba_buena );

    if ( Hospital_yerba_buena >  domicilio_yerba_buena) {
    
     printf("Mayor Tipo atencion en la sede : Hospital \n" );
    
    
    }else {
    
    printf("Mayor Tipo atencion en la sede : Domicilio \n" );
    
    }

    
 }else if (  sede_capital >sede_yerba_buenas && sede_yerba_buenas>sede_sur ){
 
     printf("Total sede Yerba buenas  : %d\n" , sede_yerba_buenas );
     printf("Total Capital  : %d\n" , sede_capital );
     printf("Total sur  : %d\n" , sede_sur );

    printf("conclusion : \n" );
    printf("Mayor atencion : Capital \n" );
    printf("Atencion Domicilio : %d\n" , domicilio_capital );
    printf("Atencion Hospital : %d\n" , Hospital_capital );

    if ( Hospital_capital >  domicilio_capital) {
    
     printf("conclusion : \n" );
     printf("Mayor Tipo atencion en la sede: Hospital \n" );
    
    
    }else {
    
    printf("Mayor Tipo atencion en la sede : Domicilio \n" );
    
    }
 
 
 }else if ( sede_capital >sede_yerba_buenas && sede_sur > sede_yerba_buenas )
 {
 
     printf("Total sede Yerba buenas  : %d\n" , sede_yerba_buenas );
     printf("Total Capital  : %d\n" , sede_capital );
     printf("Total sur  : %d\n" , sede_sur );

    printf("Mayor atencion : sur \n" );
    printf("Atencion Domicilio : %d\n" , domicilio_sur );
    printf("Atencion Hospital : %d\n" , Hospital_sur );

    if ( Hospital_sur >  domicilio_sur) {
    
     printf("Mayor Tipo atencion en la sede: Hospital \n" );
    
    
    }else {
    
    printf("Mayor Tipo atencion en la sede: Domicilio \n" );
    
    }
 
 
 }else {
 
     printf("Hay sedes con la misma cantidad atencion" );
     printf("Total sede Yerba buenas  : %d\n" , sede_yerba_buenas );
     printf("Total Capital  : %d\n" , sede_capital );
     printf("Total sur  : %d\n" , sede_sur );

 
 
 }


}






