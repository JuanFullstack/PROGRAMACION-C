/*Sistema de Gestión de Consultas Veterinarias "Mascotas Saludables"

La clínica veterinaria "Mascotas Saludables" se especializa en brindar servicios de atención médica a animales de compañía y trabaja con diferentes dueños de mascotas. Para facilitar la facturación de los servicios prestados por los veterinarios, la clínica desea implementar un sistema de registro. A continuación se detallan los datos relevantes y los informes específicos que se necesitan:
a. Datos:
i. Dueño de mascota (Nombre, apellido, número de cliente)
¡i. Mes de consulta
iii. Número de factura
iv. Importe en pesos
v. Veterinario (Apellido, nombre, matrícula)
vi. Mascotas (Nombre, especie, raza, edad, motivo de la consulta: vacunación, desparasitación, revisión general)
b. Informes:
i. Módulo para listar todas las mascotas que hayan tenido una consulta por vacunación en el mes de diciembre con el dueño de mascota registrado bajo el nombre "Asunt".
¡i. Módulo que muestre la cantidad de mascotas mayores de 5 años atendidas en el mes de diciembre.
Nota: Para cargar las mascotas de cada dueño, considere un valor fijo de 3 mascotas para todos los casos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de estructuras
typedef struct {
    char nombre[50];
    char especie[50];
    char raza[50];
    int edad;
    char motivoConsulta[20];
} Mascota;

typedef struct {
    char nombreCliente[50];
    char apellidoCliente[50];
    int numCliente;
    char mesConsulta[20];
    int numFactura;
    float importe;
    char nombreVeterinario[50];
    Mascota mascotas[3];  // Cambiado a un array estático en lugar de utilizar malloc
} Consulta;

// Prototipos de funciones
void listarVacunacionesPorCliente(Consulta* consultas, int numConsultas, const char* nombreCliente, const char* mes);
void contarMascotasMayores(Consulta* consultas, int numConsultas, const char* mes, int edadLimite);

int main() {
    // Ejemplo de uso
    int numConsultas = 5;

    // Array de consultas en lugar de malloc
    Consulta consultas[5];

    // Cargar datos de ejemplo
    for (int i = 0; i < numConsultas; ++i) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", consultas[i].nombreCliente);

        printf("Ingrese el apellido del cliente: ");
        scanf("%s", consultas[i].apellidoCliente);

        consultas[i].numCliente = i + 1;

        printf("Ingrese el mes de la consulta: ");
        scanf("%s", consultas[i].mesConsulta);

        consultas[i].numFactura = i + 1;
        consultas[i].importe = 50.0 * (i + 1);

        printf("Ingrese el nombre del veterinario: ");
        scanf("%s", consultas[i].nombreVeterinario);

        // Cargar datos de mascotas
        for (int j = 0; j < 3; ++j) {
            printf("Ingrese el nombre de la mascota: ");
            scanf("%s", consultas[i].mascotas[j].nombre);

            printf("Ingrese la especie de la mascota: ");
            scanf("%s", consultas[i].mascotas[j].especie);

            printf("Ingrese la raza de la mascota: ");
            scanf("%s", consultas[i].mascotas[j].raza);

            printf("Ingrese la edad de la mascota: ");
            scanf("%d", &consultas[i].mascotas[j].edad);

            printf("Ingrese el motivo de la consulta para la mascota: ");
            scanf("%s", consultas[i].mascotas[j].motivoConsulta);
        }
    }

    // Llamadas a funciones
    listarVacunacionesPorCliente(consultas, numConsultas, "Dueño", "Diciembre");
    contarMascotasMayores(consultas, numConsultas, "Diciembre", 5);

    return 0;
}

// Implementación de funciones
void listarVacunacionesPorCliente(Consulta* consultas, int numConsultas, const char* nombreCliente, const char* mes) {
    printf("Mascotas que tuvieron una consulta por vacunación en el mes de %s con el dueño %s:\n", mes, nombreCliente);

    for (int i = 0; i < numConsultas; ++i) {
        if (strcmp(consultas[i].nombreCliente, nombreCliente) == 0 && strcmp(consultas[i].mesConsulta, mes) == 0) {
            for (int j = 0; j < 3; ++j) {
                if (strcmp(consultas[i].mascotas[j].motivoConsulta, "Vacunacion") == 0) {
                    printf("Factura %d - Mascota: %s\n", consultas[i].numFactura, consultas[i].mascotas[j].nombre);
                }
            }
        }
    }
    printf("\n");
}

void contarMascotasMayores(Consulta* consultas, int numConsultas, const char* mes, int edadLimite) {
    printf("Cantidad de mascotas mayores de %d atendidas en el mes de %s:\n", edadLimite, mes);

    int totalMascotasMayores = 0;
    for (int i = 0; i < numConsultas; ++i) {
        if (strcmp(consultas[i].mesConsulta, mes) == 0) {
            for (int j = 0; j < 3; ++j) {
                if (consultas[i].mascotas[j].edad > edadLimite) {
                    totalMascotasMayores++;
                }
            }
        }
    }
    printf("Total: %d\n", totalMascotasMayores);
}
