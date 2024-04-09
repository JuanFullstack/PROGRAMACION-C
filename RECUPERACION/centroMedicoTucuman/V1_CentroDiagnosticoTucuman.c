#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>




struct 
{ 
  char apellido[15];
  char nombre[15];
  int matricula ;
} typedef DatosM  ;

struct 
{
    char apellido[15];
    char nombre[15];
    char dni[15];
    int edad ;
    char Tipo_ecografia[15];
 } typedef DatosP ;

struct 
{ 
  char nombre_obraSocial[15];
  int mes_facturacion ;
  int num_facturacion ;
  DatosM medico ;
  DatosP *pacientes ;
} typedef DatosO ;

void imprimirInfo (DatosO *arre , int tama1 , int tama2);

int main( )
{

 system("cls");

  

     DatosM medicoinfo = { "perez" , "Jose" , 1245 } ;

     DatosP paciente1 = {"Gonzalez", "Jose", "123456789",15 ,"casa"};
     DatosP paciente2 = {"Rodriguez", "luis", "234567890",16, "abdominal"};
     DatosP paciente3 = {"Lopez", "Jose", "345678901", 17, "tiroide" };
     DatosP paciente4 = {"Martinez", "marcos", "456789012",20, "abdominal" };
     DatosP paciente5 = {"Perez", "Jose", "567890123", 15,"tiroide" };

     DatosP paciente6 = {"Gomez", "cesar", "678901234",16, "abdominal" };
     DatosP paciente7 = {"Fernandez", "Jose", "789012345",17, "tiroide" };
     DatosP paciente8 = {"Ramirez", "Jose", "890123456", 20,"ginecologia" };
     DatosP paciente9 = {"Sosa", "Jose", "901234567",22, "abdominal" };
     DatosP paciente10 = {"Alvarez", "Jose", "012345678",18, "tiroide" };
   
    DatosP Arreglo1[] = { paciente1,  paciente2, paciente3, paciente4, paciente5};
    DatosP Arreglo2[] = { paciente6,  paciente7, paciente8, paciente9, paciente10};


    // hay un general ??

     DatosP *puntero1 = Arreglo1 ;
     DatosP *puntero2 = Arreglo2 ;

  
    
 DatosO Obra_sociales[]= {
 {"Subcidio" , 10 , 1254 , medicoinfo , puntero1 },
 {"Asut" , 11 , 1254 , medicoinfo , puntero2 }

 };

  


 imprimirInfo ( Obra_sociales , 2 , 5 ) ;



 return 0;
}




void imprimirInfo (DatosO *arre , int tama1 , int tama2) 
{

   for (int i = 0; i < tama1; i++)
   {
      if ( strcmp(arre[i].nombre_obraSocial ,"Asut")==0 && arre[i].mes_facturacion==11 ) 
      {
      
         for (int j = 0; j < tama2; j++)
         {
               
            if (strcmp(arre[i].pacientes[j].Tipo_ecografia , "tiroide")==0)
            {
            
               puts(" ********* DATOS *********** ");
               printf("Apellido : %s \n" , arre[i].pacientes[j].apellido);
               printf("Nombre : %s \n" , arre[i].pacientes[j].nombre);  
               printf("DNI : %s \n" , arre[i].pacientes[j].dni);
               printf("edad : %d \n" , arre[i].pacientes[j].edad);
               printf("Tipo Ecografia : %s \n" , arre[i].pacientes[j].Tipo_ecografia);
               printf("\n");
         
            }            
         }
         
      } 
   }

}



