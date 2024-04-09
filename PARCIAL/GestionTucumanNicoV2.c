#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define MAX2 20

struct{
    char apellidoM[MAX];
    char nombreM[MAX];
    char matricula[MAX2];
}typedef Medico;

struct{
    char apellidoP[MAX];
    char nombreP[MAX];
    char dni[MAX2];
    int edad;
    char tipoEco[MAX2];
}typedef Paciente;

struct{
    char obraSocial[MAX];
    char mesFacturacion[MAX2];
    int numeroFactura;
    float importe;
    Medico miMedico;
    Paciente *misPacientes;
}typedef Datos;

//Funciones

void listar(Datos id[]);
void mostrarSegun(Datos id[]);


int main(){

    Medico miMedico = {"Trigo", "Nicolas", "abc123def"};
    Medico miMedico2 = {"Velaztiqui", "Mauro", "abc12345def"};

    Paciente misPacientes[5] = {
        {"Lobo", "Mariana", "32587453", 28, "Ginecologia"},
        {"Lobo", "Fatima", "32587963", 25, "Renal"},
        {"Lobo", "Lourdes", "41526698", 36, "Tiroidea"},
        {"Blanca", "Ramiro", "32587425", 45, "Renal"},
        {"Juarez", "Matias", "45875942", 22, "Abdominal"}
    };

    Paciente *pPacientes = misPacientes;

    Paciente misPacientes2[5] = {
        {"Lobo", "Mariana", "32587453", 25, "Ginecologia"},
        {"Lobo", "Fatima", "32587963", 36, "Renal"},
        {"Lobo", "Lourdes", "41526698", 75, "Tiroidea"},
        {"Blanca", "Ramiro", "32587425", 74, "Renal"},
        {"Juarez", "Matias", "45875942", 29, "Abdominal"}
    };

    Paciente *pPacientes2 = misPacientes2;

    Datos misDatos[2] = {
        {"Asunt", "Noviembre", 254, 5000, miMedico, pPacientes},
        {"Assist Card", "Octubre", 125, 8000, miMedico2, pPacientes2}
    };

    listar(misDatos);
    mostrarSegun(misDatos);

    return 0;
}

void listar(Datos id[]){

    char buscarEco[MAX2];
    char buscarMes[MAX2];
    char buscarOS[MAX];

    printf("\nIngrese por el tipo de ecografia que desea buscar: ");
    fflush(stdin);
    gets(buscarEco);

    printf("\nIngrese el mes que se realizo la ecografia: ");
    gets(buscarMes);

    printf("\nIngrese con que obra social se realizo el estudio: ");
    gets(buscarOS);


    printf("\n\n**** Datos encontrados ****\n");
    for(int i = 0; i < 2; i++){
        if(strcmp(id[i].obraSocial, buscarOS) == 0 && strcmp(id[i].mesFacturacion, buscarMes) == 0){
            for(int k = 0; k < 5; k++){
                if(strcmp(id[i].misPacientes[k].tipoEco, buscarEco) == 0){
                    printf("\nApellido completo del paciente: %s %s", id[i].misPacientes[k].apellidoP, id[i].misPacientes[k].nombreP);
                    printf("\nDNI: %s", id[i].misPacientes[k].dni);
                    printf("\nEdad: %d\n", id[i].misPacientes[k].edad);
                }
            }
        }
    }
}

void mostrarSegun(Datos id[]){

    char buscarMes[MAX2];
    int buscarEdad2;
    int cantidadPacientesAtendidos = 0;

    printf("\nIngrese en el mes que fue atendido: ");
    gets(buscarMes);

    printf("\nIngrese hasta que edad quiere buscar: ");
    fflush(stdin);
    scanf("%d", &buscarEdad2);

    printf("\n\n**** Paciente/s atendidos ****\n");
    for(int i = 0; i < 2; i++){
        if(strcmp(id[i].mesFacturacion, buscarMes) == 0){
            for(int k = 0; k < 5; k++){
                if(id[i].misPacientes[k].edad <= buscarEdad2){
                    cantidadPacientesAtendidos++;
                    printf("\n-> %s %s", id[i].misPacientes[k].apellidoP, id[i].misPacientes[k].nombreP);
                }
            }
        }
    }
    printf("\nLa cantidad de pacientes menores a %d atendidos en %s fue de: %d", buscarEdad2, buscarMes, cantidadPacientesAtendidos);
}