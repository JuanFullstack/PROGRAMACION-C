#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct 
{
 char nombre[15];
 int stock_sucursal ;
} typedef Datos;


// venta de calzados 

struct 
{
 char modelo[15];
 char categoria [15];
 int stock_fabrica ;
 float precio ;
 Datos *sucursales ;
 
} typedef Producto ;


void CargaDatos (Producto *arre , int tam1 );
void ImprimirDatos ( Producto *arre , int tam1 , int cate ) ;
void ControlDatos ( Producto *arre , int tam1  );

int main( )
{
  system("cls");
 int stockGral ;

 printf("ingrese el stock:  ");
 scanf("%d" , &stockGral);


  Producto *Principal = (Producto*)malloc(stockGral*sizeof(Producto));
  
  
CargaDatos (Principal , stockGral ) ;

int  category ;

printf("Seleccione una categoria\n");
printf("1- urbano \n");
printf("2- trekking \n");
printf("3- zapato \n");
printf("4- ojota \n");
scanf ("%d" ,&category);




 ControlDatos ( Principal , stockGral );

//ImprimirDatos ( Principal , stockGral ,category );



 return 0;
}




void CargaDatos (Producto *arre , int tam1 ) {

   char Modelox[][15] = { "Dione" , "California" , "Mirror " , "adidas" };
   char categoriax[][15] = { "urbano" , "trekking" , "zapato " , "ojota" };
   char surcusalesx[][15]= {"lules" , "mendoza" , "santiago" , "raco"};
 

     srand(time(NULL));

   for (int i = 0; i < tam1; i++)
   {
        strcpy(arre[i].modelo , Modelox[rand() % 3] );
        strcpy(arre[i].categoria , categoriax[rand() % 3] );
        arre[i].precio = rand() % 501 ;
        arre[i].stock_fabrica=( rand() %  4) + 6 ;

        arre[i].sucursales=(Datos*)malloc(arre[i].stock_fabrica*sizeof(Datos));

        for (int j = 0; j < arre[i].stock_fabrica; j++)
        {
            strcpy(arre[i].sucursales[j].nombre , surcusalesx[rand() % 3] );
            arre[i].sucursales[j].stock_sucursal= rand() % arre[i].stock_fabrica ;
            
        }
   }
   

}



void ImprimirDatos ( Producto *arre , int tam1 , int cate ) {

  system("cls");
  char categoriax[][15] = { "urbano" , "trekking" , "zapato " , "ojota" };

  puts("******* Impresion***********");
  for (int i = 0; i < tam1; i++)
   {
        
      if ( strcmp(arre[i].categoria, categoriax[cate-1])==0 )
      {
        printf("modelo: %s \n" ,arre[i].modelo );
        printf("categoria: %s \n" ,arre[i].categoria );
        printf("categoria: %.2f \n" ,arre[i].precio );
        printf("Stock Fabrica: %d \n" ,arre[i].stock_fabrica );

        puts(" -Surcursales- \n");
        for (int j = 0; j < arre[i].stock_fabrica; j++)
        {
           printf("Nombre sucursal %d : %s \n" , j + 1, arre[i].sucursales[j].nombre);
           printf("Stock sucursal : %d \n" ,arre[i].sucursales[j].stock_sucursal);
            
        }
        printf("\n");

      }

        
   }

}




void ControlDatos ( Producto *arre , int tam1  ) 
{

  system("cls");
  puts("******* control ***********");
    for (int i = 0; i < tam1; i++)
    {
            for (int j = 0; j < arre[i].stock_fabrica; j++)
            {
                if ( arre[i].sucursales[j].stock_sucursal  < 10 )
               {
                    int extra ;
                    printf(" %s stock fabrica  : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].stock_fabrica );
                    printf(" %s stock sucursal : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].sucursales[j].stock_sucursal );
                    printf("ingrese nuevo valor :   ");
                    scanf("%d", &extra );
                    int control = 1 ;

                    while (control)
                    {


                        if (arre[i].sucursales[j].stock_sucursal  < 10  && arre[i].stock_fabrica >=10 ) 
                        {
                        
                            arre[i].sucursales[j].stock_sucursal = arre[i].sucursales[j].stock_sucursal + extra  ;
                            arre[i].stock_fabrica  = arre[i].stock_fabrica - extra ;
                        
                        
                        }else 
                        {
                        
                                if ( arre[i].sucursales[j].stock_sucursal  > 10 && arre[i].stock_fabrica <= 10   )
                                {
                                
                                arre[i].sucursales[j].stock_sucursal = arre[i].sucursales[j].stock_sucursal - extra  ;
                                arre[i].stock_fabrica  = arre[i].stock_fabrica + extra ;
                                
                                
                                }
 
                         }


                        if ((arre[i].stock_fabrica - extra ) >= (arre[i].sucursales[j].stock_sucursal + extra )  )
                        {
                        
                            
                            control = 0 ;
                           printf(" %s stock fabrica Actulizado : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].stock_fabrica );
                           printf(" %s stock sucursal Actulizado : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].sucursales[j].stock_sucursal );
                        
                        }else 
                        {

                            system("cls");
                            printf("No cumple con los requisitos , ingrese nuevo valor ");
                            printf(" %s stock fabrica  : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].stock_fabrica );
                            printf(" %s stock sucursal : %d pares \n" , arre[i].sucursales[j].nombre ,arre[i].sucursales[j].stock_sucursal );
                            printf("---> :  ");
                            scanf("%d", &extra );

                        }

                    }

                        puts("----- control completado ");
                            
                        printf("\n");

                }

            
            }

    }
}