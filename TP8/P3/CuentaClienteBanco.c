#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
#define tama 30


struct {
    int dia;
    int mes;
    int year;
} typedef fecha;



struct CuentaClienteBanco
{ 
    char cbu[tama];
    float saldo;
    char movimientos[tama];
}typedef datosBanco;


struct 
{   char apellido[MAX];
    char nombre[MAX];
    char dni[tama] ;
    fecha nacimiento ;
    char contrasenia [MAX];
    datosBanco info ;
    int  *historial ;
    int disponible;
    DatosPersonal * SiguienteNodo ;
} typedef DatosPersonal;




void cambiarContrasenia ( DatosPersonal arre[] , int id );
float depositarMonto( DatosPersonal arre[] , int id);
float retirarDinero ( DatosPersonal arre[] , int id);
void consultaSaldo ( DatosPersonal arre[] , int id);
void mostrarhistorial ( DatosPersonal arre[] , int id , int tam , int disponible);
void historial2 ( DatosPersonal arre[] , int id , int tam , int diponible ,  int opera);

int main()
{ 
  system("cls");
  int continuar , operacion , id  , idReal;
  
  

  DatosPersonal Clientes[]={
        {"perez" , "jose" , "30456123", { 2 , 3 , 1974}, "casablanca", {"456123789" , 5000 , "cambio contrasenia"}},
        {"luna" , "maria" , "4561234", { 7 , 8 , 1475}, "perla1234", {"784562134" , 2000 , "consulta saldo"}},
        {"leon" , "pedro" , "30214578", { 7 , 8 , 1475}, "fuego4512", {"4756123" , 4000 , "cambio contrasenia"}},
   };

  DatosPersonal *Clientes2=(DatosPersonal*)malloc(tama*sizeof(DatosPersonal));

  

  
   //DEBO HACER UNO PARA CADA CLIENTE !!!!!
   // O HACERLO DENTRO DE LA FUNCION !!!!!
   Clientes->historial=(int*)malloc(tama*sizeof(int));




   Clientes->disponible=0;

   //iniciliazo a cero
     for (int i = 0; i < tama; i++) {
        Clientes->historial[i] = 0;
    }

  
   do
   {  
     
     printf("seleccione un cliente\n");
     printf("1: perez jose\n"); 
     printf("2: luna maria\n");
     printf("3: leon pedro\n");
     printf("0: SALIR\n"); 
     printf("-->  "); 
     scanf("%d" , &id);

     idReal=id-1 ;

     if (!id==0 )
     {
        
        printf("que operacion desea realizar?\n");
        printf("1 : Cambiar Contrasenia\n");
        printf("2 : Depositar un Monto\n");
        printf("3 : Retirar Dinero\n");
        printf("4 : Consultar Saldo\n");
        printf("5 : Mostrar Datos de la Cuenta\n");
        printf("6 : Mostrar Historial de Movimientos\n");
        printf("7 : Volver al menu clientes\n");
        scanf("%d" , &operacion);


      
  
         historial2 ( Clientes  , idReal , tama , Clientes->disponible , operacion );
         Clientes->disponible++;
        

            switch (operacion)
           {
            case 1 : cambiarContrasenia ( Clientes , idReal);
                      //arre[4]= cambiarcontrasenia22( )
            break;
            case 2 : Clientes[idReal].info.saldo = depositarMonto( Clientes, idReal);
                     printf("\nSu nuevo Saldo es :%.2f\n" , Clientes[idReal].info.saldo );
            break;
            case 3 : Clientes[idReal].info.saldo = retirarDinero( Clientes, idReal);
                     printf("\nSu nuevo Saldo es :%.2f\n" , Clientes[idReal].info.saldo );
            break;
            case 4 : consultaSaldo ( Clientes, idReal);
                     
            break;
        
            //   default:
            //     break;
           }


     
     }

       printf("desea realizar otras operacion ?\n");
       printf("1 : Si\n");
       printf("1 : No\n");
       fflush(stdin);
       scanf("%d",&continuar);

   } while (continuar!=0);

   mostrarhistorial ( Clientes, idReal , tama  , Clientes->disponible);
   
   printf("*************** Fin del programa  *****************");
   
    return 0;
}


void cambiarContrasenia ( DatosPersonal arre[] , int id ){
   
    printf("contrasenia actual : %s\n" ,arre[id].contrasenia );
    printf("ingrese la contrasenia nueva :");
    scanf("%s" , arre[id].contrasenia);
    printf("\nsu nueva contrasenia es :%s\n" , arre[id].contrasenia);

}




void historial2 ( DatosPersonal arre[] , int id , int tam , int disponible ,  int opera){
  
   //HACER UN ARREGLO POR CLIENTE 
  //arre[id].historial=(int*)malloc(tama*sizeof(int));

    if(disponible<tama){
    arre[id].historial[disponible]=opera;
    }else {
    
       realloc(arre[id].historial , tam*tam );
    }
         
}

//EJECUTAR AL FINAL DEL MAIN !!
void liberarMemoria ( DatosPersonal arre[] , int id , int tamGRAL , int disponible ,  int opera) {

//tamGRAL ES LA CANTIDAD DE ID QUE TIENE EN ESTE CASO 3 !!

   for (int i = 0; i < tamGRAL ; i++)
   {  
      //ANALIZAR BIENNN!!!
      //NO ES arre[id].historial[i] porque es un enetero,y free espera puntero 
      free(arre[i].historial);
   }
   
}




void mostrarhistorial ( DatosPersonal arre[] , int id , int tam , int disponible){
  int i = 0 , ultimaPosicion=0;

  printf("Historial: \n");
  for (i = 0; i < disponible; i++) {
    char info[tama];

   
  

    
      //FORMA CON ARISMETICA PUNTERO NO BORRAR !!!
      // OBSERVAR LA FORMA ANIDADA Y RESPETAR LOS PARENTECIS EN ESE ORDEN 
      //*((*(arre+i)).historial+i);

      



    switch (arre[id].historial[i]) {
      case 1:
        strcpy(info, "Cambiar Contrasenia");
        break;
      case 2:
        strcpy(info, "Depositar un Monto");
        break;
      case 3:
        strcpy(info, "Retirar Dinero");
        break;
      case 4:
        strcpy(info, "Consultar Saldo");
        break;
      case 5:
        strcpy(info, "Mostrar Datos de la Cuenta");
        break;
    }

    puts(info);
  }
}





float depositarMonto( DatosPersonal arre[] , int id){
    float monto =0 ;
    printf("Saldo Actual  : %.2f\n" ,arre[id].info.saldo );
    printf("cuanto desea ingresar :");
    scanf("%f", &monto );
     
     arre[id].info.saldo = arre[id].info.saldo  + monto  ;

    return arre[id].info.saldo ;
}


float retirarDinero ( DatosPersonal arre[] , int id){
    float monto =0 ;
    printf("Saldo Actual  : %.2f\n" ,arre[id].info.saldo );
    printf("cuanto desea ingresar :");
    scanf("%f", &monto );
     
     arre[id].info.saldo = arre[id].info.saldo - monto  ;

    return arre[id].info.saldo ;
}

void consultaSaldo ( DatosPersonal arre[] , int id){
    
    printf("Saldo Actual  : %.2f\n" ,arre[id].info.saldo );
    
     
}


void mostrarDatos ( DatosPersonal arre[] , int id){
    
    printf("Apellido : %S\n" ,arre[id].apellido );
    printf("Nombre : %S\n" ,arre[id].nombre );
    printf("Dni : %S\n" ,arre[id].dni );
    printf("fecha nacimiento : %d /%d /%d \n" ,arre[id].nacimiento.dia ,arre[id].nacimiento.mes,arre[id].nacimiento.year);
    
}