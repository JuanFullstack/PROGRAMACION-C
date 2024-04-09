#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define tam 100

struct {
    int dia;
    int mes;
    int anio;
} typedef fecha;

struct {
    char nombreProvedor[MAX];
    int telefono;   
} typedef datos;

struct {
    char nombreProducto[MAX];
    int precioUnitario ;
    int cantidadVendidaMes;
    datos Datosprovedor;
    fecha FechaInicioVenta ;
} typedef info;

info cargarDatos ();

int main()
{ system("cls");
    info productos ;
    //modificar precio unitario
    productos.precioUnitario=420;
    productos=cargarDatos ();
    mostrarDatos(productos);

    info * CATALOGO = (info*)malloc(tam*sizeof(info));
   
    return 0;
}


// NOTAR ES TIPO INFO !
info cargarDatos (){
 info productos ;
 printf("Ingrese Nombre del producto:");
 gets(productos.nombreProducto);
 printf("precio unitario : ");
 scanf("%d", &productos.precioUnitario);
 printf("Ingrese cantidad venta del mes : ");
 scanf("%d", &productos.cantidadVendidaMes);
 // es mas normal usar fflush si se tilda 
 fflush(stdin);
 printf("Ingrese nombre proveedor:");
 gets(productos.Datosprovedor.nombreProvedor);
 printf("Ingrese telefono: ");
 scanf("%d",&productos.Datosprovedor.telefono);
 //notar la carga para la fecha 
 printf("Fecha de venta (dd mm yyyy): ");
 scanf("%d %d %d",
&productos.FechaInicioVenta.dia,
&productos.FechaInicioVenta.mes,
&productos.FechaInicioVenta.anio
);
 
return productos ;

}


void  mostrarDatos(info productos){

 system("cls");
 printf("**********DATOS*********** \n\n");
 printf("Ingrese Nombre del producto: ");
 printf("%s",productos.nombreProducto);
 printf("\nprecio unitario : ");
 printf("%d\n", productos.precioUnitario);
 printf("Ingrese cantidad venta del mes : ");
 printf("%d\n", &productos.cantidadVendidaMes);
 printf("Ingrese nombre proveedor: ");
 printf("%s\n",productos.Datosprovedor.nombreProvedor);
 printf("\nIngrese telefono: ");
 printf("%d\n",productos.Datosprovedor.telefono);
 printf("Fecha de venta (dd mm yyyy): ");
 printf("%d/%d/ %d\n",
productos.FechaInicioVenta.dia,
productos.FechaInicioVenta.mes,
productos.FechaInicioVenta.anio
);

}