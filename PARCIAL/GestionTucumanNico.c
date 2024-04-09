#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Estructuras

struct {
    char apellidoP[MAX];
    char nombreP[MAX];
    int dni;
    int edad;
    char tipoEco[MAX];
}typedef Paciente;

struct {
    char apellidoM[MAX];
    char nombreM[MAX];
    char matricula[MAX];
}typedef Medico;

struct {
    char obraSocial[MAX];
    char mes[MAX];
    int factura;
    float importe;
    Medico *infoMedico;
    Paciente *infoPaciente;
}typedef Datos;

//Funciones

void cargar(Datos *id, int cant, int *cantidadM, int *cantidadP);
void mostrar(Datos *id, int cant, int *cantidadM, int *cantidadP);
void listarPacientes1(Datos *id, int cant, int *cantidadM, int *cantidadP);
void listarPacientes2(Datos *id, int cant, int *cantidadM, int *cantidadP);
void liberarMemoria(Datos *id, int cant, int *cantidadM, int *cantidadP); 

int main(){

    Datos *misDatos;
    int cantidad, cantidadM, cantidadP;

    printf("\nCon cuantas obras sociales trabaja?: ");
    scanf("%d", &cantidad);

    misDatos = malloc(cantidad * sizeof(Datos));

    cargar(misDatos, cantidad, &cantidadM, &cantidadP);
    mostrar(misDatos, cantidad, &cantidadM, &cantidadP);
    listarPacientes1(misDatos, cantidad, &cantidadM, &cantidadP);
    listarPacientes2(misDatos, cantidad, &cantidadM, &cantidadP);
    liberarMemoria(misDatos, cantidad, &cantidadM, &cantidadP);

    return 0;
}

void cargar(Datos *id, int cant, int *cantidadM, int *cantidadP){

    for(int j = 0; j < cant; j++){

        printf("\nIngrese su obra social: ");
        fflush(stdin);
        gets(id->obraSocial);

        printf("\nIngrese el mes de facturacion(Enero, Febrero, etc): ");
        gets(id->mes);

        printf("\nIngrese el Nro de factura: ");
        fflush(stdin);
        scanf("%d", &id->factura);

        printf("\nIngrese el importe: $");
        scanf("%f", &id->importe);

        printf("\nCuantos medicos se encuentran trabajando?: ");
        scanf("%d", cantidadM);

        id->infoMedico = malloc(*cantidadM * sizeof(Medico));

        for(int i = 0; i < *cantidadM; i++){

            printf("\nIngrese apellido del medico: ");
            fflush(stdin);
            gets(id->infoMedico->apellidoM);

            printf("\nIngrese el nombre del medico: ");
            gets(id->infoMedico->nombreM);

            printf("\nIngrese la matricula del medico: ");
            gets(id->infoMedico->matricula);

            id->infoMedico++;

        }

        id->infoMedico -= *cantidadM;

        printf("\nIngrese la cantidad de pacientes que hubo: ");
        fflush(stdin);
        scanf("%d", cantidadP);

        id->infoPaciente = malloc(*cantidadP * sizeof(Paciente));

        for(int k = 0; k < *cantidadP; k++){

            int opcion;

            printf("\nIngrese apellido del paciente: ");
            fflush(stdin);
            gets(id->infoPaciente->apellidoP);

            printf("\nIngrese el nombre del paciente: ");
            gets(id->infoPaciente->nombreP);

            printf("\nIngrese DNI del paciente: ");
            fflush(stdin);
            scanf("%d", &id->infoPaciente->dni);

            printf("\nIngrese edad del paciente: ");
            scanf("%d", &id->infoPaciente->edad);

            do
            {
                printf("\nSeleccione el tipo de ecografia:\n");
                puts("1) Ginecologica");
                puts("2) Abdominal");
                puts("3) Renal");
                puts("4) Tiroidea");
                fflush(stdin);
                scanf("%d", &opcion);
            } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
            
            switch (opcion)
            {
            case 1:
                strcpy(id->infoPaciente->tipoEco, "Ginecologia");
                break;
            case 2:
                strcpy(id->infoPaciente->tipoEco, "Abdominal");
                break;
            case 3:
                strcpy(id->infoPaciente->tipoEco, "Renal");
                break;
            case 4:
                strcpy(id->infoPaciente->tipoEco, "Tiroidea");
                break;
            }

            id->infoPaciente++;


        }

        id->infoPaciente -= *cantidadP;

        id++;
    }

    id -= cant;
}

void mostrar(Datos *id, int cant, int *cantidadM, int *cantidadP){

    for(int i = 0; i < cant; i++){

        printf("\nObra social: %s", id->obraSocial);
        printf("\nMes de facturacion: %s", id->mes);
        printf("\nNro factura: %d", id->factura);
        printf("\nImporte: $%.2f", id->importe);
        
        for(int j = 0; j < *cantidadM; j++){

            printf("\n\n***** Informacion Medico %d *****\n", j+1);
            printf("\nApellido: %s", id->infoMedico->apellidoM);
            printf("\nNombre: %s", id->infoMedico->nombreM);
            printf("\nMatricula: %s", id->infoMedico->matricula);

            id->infoMedico++;

        }

        id->infoMedico -= *cantidadM;

        for(int k = 0; k < *cantidadP; k++){

            printf("\n\n***** Informacion Paciente %d *****\n", k + 1);
            printf("\nApellido: %s", id->infoPaciente->apellidoP);
            printf("\nNombre: %s", id->infoPaciente->nombreP);
            printf("\nDNI: %d", id->infoPaciente->dni);
            printf("\nEdad: %d", id->infoPaciente->edad);
            printf("\nTipo de ecografia: %s", id->infoPaciente->tipoEco);

            id->infoPaciente++;

        }

        id->infoPaciente -= *cantidadP;

        id++;

    }

    id -= cant;

}

void listarPacientes1(Datos *id, int cant, int *cantidadM, int *cantidadP){

    for(int i = 0; i < cant; i++){

        for(int j = 0; j < *cantidadM; j++){

            for(int k = 0; k < *cantidadP; k++){

                if(strcmp(id[i].infoPaciente[k].tipoEco, "Tiroidea") == 0 && strcmp(id[i].mes, "Noviembre") == 0 && strcmp(id[i].obraSocial, "Asunt") == 0){
                    
                    printf("\n\n***** Pacientes que realizaron una ecografia tiroidea en noviembre con obra social Asunt*****\n");
                    printf("\nObra social: %s", id[i].obraSocial);
                    printf("\nMes de facturacion: %s", id[i].mes);
                    printf("\nNro factura: %d", id[i].factura);
                    printf("\nImporte: $%.2f", id[i].importe);
                    printf("\nApellido medico: %s", id[i].infoMedico[j].apellidoM);
                    printf("\nNombre medico: %s", id[i].infoMedico[j].nombreM);
                    printf("\nMatricula: %s", id[i].infoMedico[j].matricula);
                    printf("\nApellido paciente: %s", id[i].infoPaciente[k].apellidoP);
                    printf("\nNombre paciente: %s", id[i].infoPaciente[k].nombreP);
                    printf("\nDNI paciente: %d", id[i].infoPaciente[k].dni);
                    printf("\nEdad paciente: %d", id[i].infoPaciente[k].edad);
                    printf("\nTipo de ecografia: %s", id[i].infoPaciente[k].tipoEco);
                }

            }

        }

    }

}

void listarPacientes2(Datos *id, int cant, int *cantidadM, int *cantidadP){

    for(int i = 0; i < cant; i++){

        for(int k = 0; k < *cantidadP; k++){

            if(id[i].infoPaciente[k].edad > 60 && strcmp(id[i].mes, "Noviembre") == 0){
                    
                printf("\n\n***** Pacientes mayores de 60 anios atendidos en noviembre*****\n");
                printf("\nApellido paciente: %s", id[i].infoPaciente[k].apellidoP);
                printf("\nNombre paciente: %s", id[i].infoPaciente[k].nombreP);
                printf("\nDNI paciente: %d", id[i].infoPaciente[k].dni);
                printf("\nEdad paciente: %d", id[i].infoPaciente[k].edad);
                printf("\nTipo de ecografia: %s", id[i].infoPaciente[k].tipoEco);
            }

        }

    }

}

void liberarMemoria(Datos *id, int cant, int *cantidadM, int *cantidadP){

    for(int i = 0; i < cant; i++){
        free(id[i].infoMedico);
        free(id[i].infoPaciente);
    }
    
    free(id);

}