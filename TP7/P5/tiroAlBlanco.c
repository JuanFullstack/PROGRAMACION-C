#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para cargar los puntajes de los tiros
void cargarTiros(int *puntos, int tiros) {
    srand(time(NULL));
    for (int i = 0; i < tiros; i++) {
        puntos[i] = rand() % 10 + 1; // Números aleatorios del 1 al 10
    }
}

// Función que calcula cuánto ganó el jugador
float calcularGanancia(int *puntos, int tiros, float *perdida, float *totalPerdida, float *totalGanancia) {
    float ganancia = 0;
    float costoTiro = 350;
    
    for (int i = 0; i < tiros; i++) {
        switch (puntos[i]) {
            case 1:
            case 2:
                *perdida += 100;
                ganancia -= 100;
                break;
            case 7:
                *perdida += 50;
                ganancia += 300;
                break;
            case 8:
                *perdida += 50;
                ganancia += 350;
                break;
            case 9:
                *perdida += 50;
                ganancia += 850;
                break;
            case 10:
                *perdida += 50;
                ganancia += 1000;
                break;
            default:
                *perdida += costoTiro;
                ganancia -= costoTiro;
        }
    }

    *totalPerdida += *perdida;
    *totalGanancia += ganancia;

    return ganancia;
}

int main() {
    int numJugadores;
    int tiros;
    float totalPerdida = 0;
    float totalGanancia = 0;

    printf("Ingrese el número de jugadores: ");
    scanf("%d", &numJugadores);

    for (int jugador = 1; jugador <= numJugadores; jugador++) {
        printf("Jugador %d, ingrese la cantidad de tiros que desea realizar: ", jugador);
        scanf("%d", &tiros);

        int *puntos = (int *)malloc(tiros * sizeof(int));
     
     

        cargarTiros(puntos, tiros);

        float perdida = 0;
        float ganancia = calcularGanancia(puntos, tiros, &perdida, &totalPerdida, &totalGanancia);

        printf("Resumen para Jugador %d:\n", jugador);
        for (int i = 0; i < tiros; i++) {
            printf("Tiro %d: Puntuación %d\n", i + 1, puntos[i]);
        }
        printf("Gasto/Perdida: %.2f\n", perdida);
        printf("Ganancia: %.2f\n", ganancia);

        // Liberar la memoria asignada dinámicamente
        free(puntos);
    }

    printf("Resumen final:\n");
    printf("Monto total de gasto/perdida por los jugadores: %.2f\n", totalPerdida);
    printf("Monto total en ganancias: %.2f\n", totalGanancia);
    printf("Saldo final: %.2f\n", totalGanancia - totalPerdida);

    return 0;
}
