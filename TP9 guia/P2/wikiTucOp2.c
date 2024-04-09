#include <stdio.h>
#include <string.h>



// Definición de la estructura para los artículos

struct {
    int dia ;
    int mes ;
    int anio;
} typedef Fecha;



struct {
    char Nombre[30];
    char Apellido[30];
} typedef controlador;


struct {
    char nombre[30];
    char destinatarios[20];
    char nivel[20];
    char cursos[50];
    char area[50];
    char descripcion[200];
    controlador datos;
    
    Fecha control ;
    char estado[20];
} typedef Articulo;




void cargarArticulos( Articulo *arre , int can_producto ) ;
void mostrarArticulos( Articulo *arre , int can_product);


int main() {

   system("cls");
   int num_producto=0 ;
   

    printf("\ncuantos productos va a ingresar :\n");
    scanf("%d" , &num_producto);


    Articulo *info = (Articulo*)malloc(num_producto*sizeof(Articulo));
    

     cargarArticulos(info , num_producto);
     printf("***** Mostrando todos los articulos: ******\n");
     mostrarArticulos(info , num_producto);

   //PUNTO DE NIVEL HABILITACION CURSOS 
// inical nada 
// primario 1 , 2 3  grado
// secunadario 4 , 5 , 7 
// supeior 7 , 8  9  


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
void cargarArticulos( Articulo *arre , int can_producto ) {

      char Destinatariox[][20]= {"Alumnos", "Docentes", "Directivos"};
      char Nivelx[][20]={"Inicial", "Primario", "Secundario", "Superior"};
      char Cursosx[][20]={"1 grado" ,"2 grado" , "3 grado" };
      char Areax[][20]={"Lengua", "Matematica", "Ciencias Naturales", "Ciencias Sociales","Robotica", "Teatro",
"Musica"};
     char estadosx[][20]={"Cargado", "controlado", "publicado"};
     int seleccion;
  



        for (int i = 0; i < can_producto; i++)
        {
            puts("ingrese nombre del articulo");
            fflush(stdin);
            gets(arre[i].nombre);

            puts("ingrese destinatario : 1: Alumnos, 2: Docentes, 3: Directivos");
            scanf("%d" ,&seleccion);
            strcpy(arre[i].destinatarios, Destinatariox[seleccion - 1]);
            
            puts("ingrese nivel : 1:Inicial, 2:Primario, 3:Secundario, 4: Superior");
            scanf("%d" ,&seleccion);
            strcpy(arre[i].nivel, Nivelx[seleccion - 1]);
      
            puts("ingrese curso:");
            fflush(stdin);
            gets( arre[i].cursos);

            puts("ingrese area : 1:Lengua, 2:Matematica, 3:Ciencias 4:Naturales ,");
            puts("5: Ciencias Sociales,6:Robotica, 7:Teatro,8: Musica");
            scanf("%d" ,&seleccion);
            strcpy(arre[i].area, Areax[seleccion - 1]);
           
            puts("ingrese descripcion ");
            fflush(stdin);
            gets( arre[i].descripcion);

            puts("ingrese su nombre ");
            gets( arre[i].datos.Nombre);

             puts("ingrese su apellido ");
            gets( arre[i].datos.Apellido);

            puts("ingrese su fecha ");
            scanf("%d %d %d" ,  &arre->control.dia , &arre->control.mes ,&arre->control.anio);

            puts("ingrese su estado: 1 : Cargado, 2 :controlado, 3:publicado ");
            scanf("%d" ,&seleccion);
            strcpy(arre[i].estado, estadosx[seleccion - 1]);

        }
        

}

// Módulo para mostrar un arreglo completo de artículos
void mostrarArticulos( Articulo *arre , int can_product) {
    for (int i = 0; i < can_product; i++) 
    {
       
        printf("Nombre: %s\n", arre[i].nombre);
        printf("Destinatarios: %s\n", arre[i].destinatarios);
        printf("Nivel: %s\n", arre[i].nivel);
        printf("Cursos/Anios: %s\n", arre[i].cursos);
        printf("Area: %s\n", arre[i].area);
        printf("Descripcion: %s\n", arre[i].descripcion);
        printf("Controlador: %s %s\n", arre[i].datos.Nombre , arre[i].datos.Apellido);
        printf("Fecha de control: %d / %d / %d \n", arre->control.dia , arre->control.mes ,arre->control.anio);
        printf("Estado: %s\n\n", arre[i].estado);
        
    }
}

// // Módulo para listar los artículos de robótica destinados a docentes
// void listarArticulosRoboticaDocentes(Articulo *arre , int can_product) {
//     for (int i = 0; i < can_product; i++) {
//         if (strcmp(arre[i].area, "Robotica") == 0 && strcmp(arre[i].destinatarios, "docentes") == 0) {
//             printf("Nombre: %s\n", arre[i].nombre);
//         }
//     }
// }

// // Módulo para listar los artículos controlados
// void listarArticulosControlados(Articulo *arre , int can_product) {
//     for (int i = 0; i < can_product; i++) {
//         if (strcmp(arre[i].estado, "controlado") == 0) {
//             printf("Nombre: %s\n", arre[i].nombre);
//         }
//     }
// }

// // Módulo para listar los artículos de nivel primario destinados a alumnos de 5° grado
// void listarArticulosPrimarioAlumnos5to(Articulo *arre , int can_product) {
//     for (int i = 0; i < can_product; i++) {
//         if (strcmp(arre[i].nivel, "Primario") == 0 && strcmp(arre[i].destinatarios, "Alumnos") == 0 &&
//             strstr(arre[i].cursos, "5° grado") != NULL) {
//             printf("Nombre: %s\n", arre[i].nombre);
//         }
//     }
// }

// // Módulo para mostrar la cantidad de artículos según el área ingresada como dato
// void mostrarCantidadPorArea(Articulo *arre , int can_product) {
//  char area[20];

//   printf("ingrese el area ");
//   gets(area);

//     int cantidad = 0;
//     for (int i = 0; i < can_product; i++) {
//         if (strcmp(arre[i].area, area) == 0) {
//             cantidad++;
//         }
//     }
//     printf("Cantidad de artículos en el área %s: %d\n", area, cantidad);
// }

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


