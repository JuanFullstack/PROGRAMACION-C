#include <stdio.h>
#define MAX 100

struct {
    int dia;
    int mes;
    int year;
} typedef fecha;

struct {
    char apellido[MAX];
    char nombre[MAX];
} typedef autor;

struct {
    char titulo[MAX];
    char editorial[MAX];
    int edicion;
    fecha fechaPublicacion;
    autor autor;
    long isbn;
    char categoria;
    int cantidadEjemplares;
} typedef libro;

libro cargarDatos();
void mostrarDatos(libro);

int main() {
    libro datosLibro;
    datosLibro = cargarDatos();
    mostrarDatos(datosLibro);
    return 0;
}

libro cargarDatos() {
    libro datosLibro;
    printf("Ingresar los datos del libro.\nTitulo: ");
    gets(datosLibro.titulo);
    printf("\nEditorial: ");
    gets(datosLibro.editorial);
    printf("\nEdicion: ");
    scanf("%d",&datosLibro.edicion);
    printf("\nFecha de publicacion (dd mm yyyy): ");
    scanf("%d %d %d",&datosLibro.fechaPublicacion.dia,&datosLibro.fechaPublicacion.mes,&datosLibro.fechaPublicacion.year);
    fflush(stdin);
    printf("\nNombre del autor: ");
    gets(datosLibro.autor.nombre);
    printf("\nApellido del autor: ");
    gets(datosLibro.autor.apellido);
    printf("\nISBN: ");
    scanf("%i",&datosLibro.isbn);
    fflush(stdin);
    printf("\nCategoria (Libro: L / Revista: R / Tesis: T): ");
    scanf("%c",&datosLibro.categoria);
    printf("\nCantidad de ejemplares: ");
    scanf("%d",&datosLibro.cantidadEjemplares);
    return datosLibro;
}

void mostrarDatos(libro datosLibro) {
    printf("\n\nLos datos del libro son:");
    printf("\nTitulo: ");
    puts(datosLibro.titulo);
    printf("\nEditorial: ");
    puts(datosLibro.editorial);
    printf("\nEdicion: %d",datosLibro.edicion);
    printf("\nFecha de publicacion: %d/%d/%d",
        datosLibro.fechaPublicacion.dia,datosLibro.fechaPublicacion.mes,datosLibro.fechaPublicacion.year);
    printf("\nNombre del autor: ");
    puts(datosLibro.autor.nombre);
    printf("\nApellido del autor: ");
    puts(datosLibro.autor.apellido);
    printf("\nISBN: %i",datosLibro.isbn);
    printf("\nCategoria: %c",datosLibro.categoria);
    printf("\nCantidad de ejemplares: %d",datosLibro.cantidadEjemplares);    
}