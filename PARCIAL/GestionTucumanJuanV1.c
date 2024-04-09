#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DUDA!!! que pasa si me pide una condicion diferentes en donde deba analizar 
estructuras diferentes , debo recorrer el arreglo principial , si esta la condicion del arreglo principal
paso a analizar cada arreglo de las estructuras secundarias por separado ? */


/* es muy confuso en que punto hacer algo dinamico y a la vez inicilizar  CONFUNDE Y MUCHO */


struct 
{
  char apellido[20];
  char nombre[20];
  int matricula ;

} typedef Medico ;

struct 
{
  char apellido[20];
  char nombre[20];
  char dni[20];
  int edad;
  char TipoEcografia[20];
} typedef paciente ;

struct 
{
  char NombreObra[20];
  char Mes[20];
  int NumFactura;
  int importe;
  Medico *medicoDatos;
  paciente pacientesDatos[5];
} typedef obraSocial ;

void ImprimirMedico( obraSocial *arre ,  int tama , int id );
void analizar (obraSocial *arre  , int tam1 , int tam2 );

int main( )
{

 
   system("cls");

 

  Medico medico1={"Perez","Jose",2451};
  Medico medico2={"luz","maria",6481};
  Medico medico3={"lujan","mariela",25481};

  Medico medico4={"medina","marcelo",4671};
  Medico medico5={"dias","lourdez",5478};
  Medico medico6={"trigo","Janet",7895};

   


  Medico arreMedicos1[]={medico1,medico2,medico3};
  Medico arreMedicos2[]={medico4,medico5,medico6};

  paciente paciente1_1={ "luna" , "maria" , "203548" , 35 , "renal"};
  paciente paciente1_2={ "lima" , "jose" , "203548" , 27 , "tiroide"};
  paciente paciente1_3={ "mendes" , "david" , "203548" , 12 , "renal"};
  paciente paciente1_4={ "disme" , "sebastian" , "203548" , 35 , "renal"};
  paciente paciente1_5={ "zarate" , "claudio" , "203548" , 35 , "renal"};
 

  paciente paciente2_1={ "luna" , "maria" , "203548" , 35 , "renal"};
  paciente paciente2_2={ "lima" , "jose" , "203548" , 27 , "tiroide"};
  paciente paciente2_3={ "mendes" , "david" , "203548" , 12 , "renal"};
  paciente paciente2_4={ "disme" , "sebastian" , "203548" , 35 , "renal"};
  paciente paciente2_5={ "zarate" , "claudio" , "203548" , 35 , "renal"};
  
  paciente ArrePacientes1[]={paciente1_1,paciente1_2,paciente1_3,paciente1_4,paciente1_5};
  paciente ArrePacientes2[]={paciente2_1,paciente2_2,paciente2_3,paciente2_4,paciente2_5};


 //punteros de estructuras 
 
 Medico *PunterosMedico1= arreMedicos1;
 Medico *PunterosMedico2= arreMedicos2;
 paciente *PunterosPacientes1= ArrePacientes1;
 paciente *PunterosPacientes2= ArrePacientes2;

   // DE FORMA DINAMICA 

   // obraSocial Datos ;
   
  //  for (int i = 0; i < 5 ; i++)
  //  {
  //     Datos.medicoDatos=(Medico*)malloc(*sizeof(Medico));
  //  }

 //version estatica 

  obraSocial DatosObraSocial[]=
  {  { "San Bernardo" , "Diciembre" , 457121 , 47854,  PunterosMedico1 , PunterosPacientes1 ,
     "renal"},

     { "Asunt" , "Noviembre" , 4785 ,47885, PunterosMedico2 , PunterosPacientes2 ,
     "toroide"}

  };

int tam1=2;
int tam2=5;
  
analizar ( DatosObraSocial  ,  tam1 ,  tam2 );


  


 return 0;
}



void cargarDatos() {


}


  // char apellido[20];
  // char nombre[20];
  // int matricula ;


void ImprimirMedico( obraSocial *arre ,  int tama , int id ){

      for (int i = 0; i < tama; i++)
     {
       printf("MEDICO %d\n" , i+1 );
       printf( "Apellido: %s\n", arre[id].medicoDatos[i].apellido);
       printf( "Nombre: %s\n", arre[id].medicoDatos[i].nombre);
       printf( "Matricula: %d\n", arre[id].medicoDatos[i].matricula);
       printf("\n" );
         
     }
  
}


  // char apellido[20];
  // char nombre[20];
  // char dni[20];
  // int edad;
  // char TipoEcografia[20];


void ImprimirPaciente( obraSocial *arre  , int tam ,int id ){

   for (int i = 0; i < tam; i++)
     {
       printf("PACIENTE %d\n" , i+1 );
       printf( "Apellido: %s\n", arre[id].pacientesDatos[i].apellido);
       printf( "Nombre: %s\n", arre[id].pacientesDatos[i].nombre);
       printf( "dni: %s\n", arre[id].pacientesDatos[i].dni);
       printf( "edad: %d\n", arre[id].pacientesDatos[i].edad);
       printf( "Tipo Ecografia: %s\n", arre[id].pacientesDatos[i].TipoEcografia);
       printf("\n" );
         
     }
  
}

void analizar (obraSocial *arre  , int tam1 , int tam2 ){


  /*  DUDAS!   cuando recorro  el arreglo que tama debo tomar en cuenta el del arreglo del puntero
     pero si los arreglos de punteros tienen diferentes tama por ejemplo la obraOscial[0] tiene tama del
      arreglo pacientes 4  pero obraOscial[0] tiene un tama de 3 , como hago para que al recorrer todo
      adapte segun el arreglo
  
   */

  // los tamas los puedo dar directamente o los tengo que pedir ?

  for (int i = 0; i < tam1 ; i++)
  {

     if (strcmp(arre[i].Mes,"Noviembre")==0 && strcmp(arre[i].NombreObra,"Asunt")==0)
     {
       for (int j = 0; j < tam2; j++)
       {
           
          if ( strcmp(arre[i].pacientesDatos[j].TipoEcografia,"toroide")==0 )
          {
               
             for (int k = 0; k < tam2 ; k++)
             {
               printf( "Apellido: %s\n", arre[i].pacientesDatos[j].apellido);
              printf( "Nombre: %s\n", arre[i].pacientesDatos[j].nombre);
              printf( "dni: %s\n", arre[i].pacientesDatos[j].dni);
              printf( "edad: %d\n", arre[i].pacientesDatos[j].edad);
              printf( "Tipo Ecografia: %s\n", arre[i].pacientesDatos[j].TipoEcografia);
             }

             //DUDAS !! supongamos que me pida tambien que imprima los medicos con apellidos "medina"
             //tendria que crear una bandera 
             // el tam2 de donde lo saco del arreglo puntero ?
             
             


             

          }
         
       }
     
     }
     
  }

}


void ImprimirDatos(obraSocial *arre  , int tam , int id){

  for (int i = 0; i < tam; i++)
  {
      
  }

}