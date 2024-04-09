#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define tama 30

struct {
    int dia;
    int mes;
    int year;
} typedef fecha;

struct {
    char apellido[MAX];
    char nombre[MAX];
    int dni ;
} typedef DatosGuia;

struct {
    char Destino[MAX];
    DatosGuia Guia;
    fecha salida;
    fecha regreso;
    int costoViaje;
    int cantidadHabitaciones;
    int *p_cantidadHabitaciones;
} typedef turismo;

void mostrar(int habi);

int main(int argc, char const *argv[])
{
   turismo info ;

   info.p_cantidadHabitaciones=&info.cantidadHabitaciones;
   //el sentido de esto es porque lo voy a usar en un for para varios clientes he ir redimencionando ?
   info.p_cantidadHabitaciones=(int*)malloc(tama*sizeof(int));
   cargar();
   Liberar(info.p_cantidadHabitaciones ,info.cantidadHabitaciones ) ;
   mostrar( info.cantidadHabitaciones);

    return 0;
}


turismo cargar(){
 turismo info ;
 printf("numero de habitacion:");
 scanf("%d" , &info.cantidadHabitaciones);

 return info;
}

void Liberar(int *habitaciones , int tam) {

habitaciones = (int*)realloc(habitaciones,(tam*sizeof(int)));

}


void mostrar(int habi){

printf("numero de habitacion:%d" , habi);

}