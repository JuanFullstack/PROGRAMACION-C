#include <stdio.h>
#include <string.h>



// Definición de la estructura para los artículos



typedef struct {
    char nombre[100];
    char destinatarios[20];
    char nivel[20];
    char cursos[50];
    char area[50];
    char descripcion[200];
    char controlador[50];
    char fecha_control[20];
    char estado[20];
} Articulo;

void cargarArticulos(Articulo *arre , int can_producto);
void mostrarArticulos( Articulo *arre , int can_product);


int main() {

   system("cls");
    int num_producto=0 ;

    printf("\ncuantos productos va a ingresar :\n");
    scanf("%d" , &num_producto);


    Articulo *info = (Articulo*)malloc(num_producto*sizeof(Articulo));


    

    // Pruebas de los módulos
    printf("Mostrando todos los artículos:\n");
   

    // printf("\nListando artículos de robótica destinados a docentes:\n");
    // listarArticulosRoboticaDocentes();

    // printf("\nListando artículos controlados:\n");
    // listarArticulosControlados();

    // printf("\nListando artículos de nivel primario destinados a alumnos de 5° grado:\n");
    // listarArticulosPrimarioAlumnos5to();

    // printf("\nMostrando cantidad de artículos por área:\n");
    // mostrarCantidadPorArea("Robótica");

    // printf("\nMostrando cantidad de artículos por nivel:\n");
    // mostrarCantidadPorNivel("Secundario");

    // printf("\nMostrando cantidad de artículos por área y nivel:\n");
    // mostrarCantidadPorAreaYNivel("Ciencias Sociales", "Primario");

    // // Prueba de modificación de estado de un artículo
    // modificarEstadoArticulo("Secundario", "Robótica", "Estudiantes", "publicado");
    // printf("\nEstado del artículo modificado:\n");
    // mostrarArticulos();

    return 0;
}








// Módulo para cargar un arreglo completo de artículos
void cargarArticulos( Articulo *arre , int can_producto) {

        for (int i = 0; i < can_producto; i++)
        {
            puts("ingrese nombre del articulo");
            gets(arre[i].nombre);
            puts("ingrese destinatario : 1: Alumnos, 2: Docentes, 3: Directivos");
            gets( arre[i].destinatarios);
            puts("ingrese nivel : Inicial, Primario, Secundario, Superior");
            gets( arre[i].nivel);
            puts("ingrese curso ");
            gets( arre[i].cursos);
            puts("ingrese area : Lengua, Matematica, Ciencias Naturales ,");
            puts(" Ciencias Sociales,Robotica, Teatro, Musica");
            gest(arre[i].area);
            puts("ingrese descripcion ");
            gets( arre[i].descripcion);
            puts("ingrese su nombre  ");
            gets( arre[i].controlador);
            puts("ingrese su fecha ");
            gets( arre[i].fecha_control);
            puts("ingrese su estado: Cargado, controlado, publicado ");
            printf("Estado: %s\n\n", arre[i].estado);

        }
        

}

// Módulo para mostrar un arreglo completo de artículos
void mostrarArticulos( Articulo *arre , int can_product) {
    for (int i = 0; i < can_product; i++) 
    {
       
        printf("Nombre: %s\n", arre[i].nombre);
        printf("Destinatarios: %s\n", arre[i].destinatarios);
        printf("Nivel: %s\n", arre[i].nivel);
        printf("Cursos/Años: %s\n", arre[i].cursos);
        printf("Área: %s\n", arre[i].area);
        printf("Descripción: %s\n", arre[i].descripcion);
        printf("Controlador: %s\n", arre[i].controlador);
        printf("Fecha de control: %s\n", arre[i].fecha_control);
        printf("Estado: %s\n\n", arre[i].estado);
        
    }
}

// Módulo para listar los artículos de robótica destinados a docentes
void listarArticulosRoboticaDocentes(Articulo *arre , int can_product) {
    for (int i = 0; i < can_product; i++) {
        if (strcmp(arre[i].area, "Robotica") == 0 && strcmp(arre[i].destinatarios, "docentes") == 0) {
            printf("Nombre: %s\n", arre[i].nombre);
        }
    }
}

// Módulo para listar los artículos controlados
void listarArticulosControlados(Articulo *arre , int can_product) {
    for (int i = 0; i < can_product; i++) {
        if (strcmp(arre[i].estado, "controlado") == 0) {
            printf("Nombre: %s\n", arre[i].nombre);
        }
    }
}

// Módulo para listar los artículos de nivel primario destinados a alumnos de 5° grado
void listarArticulosPrimarioAlumnos5to(Articulo *arre , int can_product) {
    for (int i = 0; i < can_product; i++) {
        if (strcmp(arre[i].nivel, "Primario") == 0 && strcmp(arre[i].destinatarios, "Alumnos") == 0 &&
            strstr(arre[i].cursos, "5° grado") != NULL) {
            printf("Nombre: %s\n", arre[i].nombre);
        }
    }
}

// Módulo para mostrar la cantidad de artículos según el área ingresada como dato
void mostrarCantidadPorArea(Articulo *arre , int can_product) {
 char area[20];

  printf("ingrese el area ");
  gets(area);

    int cantidad = 0;
    for (int i = 0; i < can_product; i++) {
        if (strcmp(arre[i].area, area) == 0) {
            cantidad++;
        }
    }
    printf("Cantidad de artículos en el área %s: %d\n", area, cantidad);
}

// // Módulo para mostrar la cantidad de artículos según el nivel ingresado como dato
// void mostrarCantidadPorNivel(char nivel[]) {
//     int cantidad = 0;
//     for (int i = 0; i < MAX_ARTICULOS; i++) {
//         if (strcmp(articulos[i].nivel, nivel) == 0) {
//             cantidad++;
//         }
//     }
//     printf("Cantidad de artículos en el nivel %s: %d\n", nivel, cantidad);
// }

// // Módulo para mostrar la cantidad de artículos según el área y el nivel ingresados como datos
// void mostrarCantidadPorAreaYNivel(char area[], char nivel[]) {
//     int cantidad = 0;
//     for (int i = 0; i < MAX_ARTICULOS; i++) {
//         if (strcmp(articulos[i].area, area) == 0 && strcmp(articulos[i].nivel, nivel) == 0) {
//             cantidad++;
//         }
//     }
//     printf("Cantidad de artículos en el área %s y nivel %s: %d\n", area, nivel, cantidad);
// }

// // Módulo para modificar el estado de un artículo
// void modificarEstadoArticulo(char nivel[], char area[], char destinatarios[], char nuevoEstado[]) {
//     for (int i = 0; i < MAX_ARTICULOS; i++) {
//         if (strcmp(articulos[i].nivel, nivel) == 0 && strcmp(articulos[i].area, area) == 0 &&
//             strcmp(articulos[i].destinatarios, destinatarios) == 0) {
//             strcpy(articulos[i].estado, nuevoEstado);
//         }
//     }
// }


