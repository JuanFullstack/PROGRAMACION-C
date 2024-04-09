#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un jugador
struct Jugador {
    char nombre[50];
    int edad;
    int partidasJugadas;
    char** juegos;
    int* puntos;
    float tiempoTranscurrido;
};

// Función para encontrar al jugador con el puntaje más alto en un juego específico
struct Jugador encontrarMejorJugador(struct Jugador* jugadores, int numJugadores, char* nombreJuego) {
    struct Jugador mejorJugador;
    mejorJugador.puntos = -1; // Inicializamos con un puntaje imposible de alcanzar

    for (int i = 0; i < numJugadores; i++) {
        for (int j = 0; j < jugadores[i].partidasJugadas; j++) {
            if (strcmp(jugadores[i].juegos[j], nombreJuego) == 0 && jugadores[i].puntos[j] > mejorJugador.puntos) {
                mejorJugador = jugadores[i];
            }
        }
    }

    return mejorJugador;
}

// Función para contar la cantidad de jugadores según su edad y tiempo transcurrido
void contarJugadoresPorEdadYTiempo(struct Jugador* jugadores, int numJugadores) {
    int contadorInfantil = 0;
    int contadorJuvenil = 0;
    int contadorMayor = 0;

    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].edad <= 12) {
            contadorInfantil++;
        } else if (jugadores[i].edad >= 13 && jugadores[i].edad <= 17) {
            contadorJuvenil++;
        } else {
            contadorMayor++;
        }
    }

    printf("Cantidad de jugadores Infantiles: %d\n", contadorInfantil);
    printf("Cantidad de jugadores Juveniles: %d\n", contadorJuvenil);
    printf("Cantidad de jugadores Mayores: %d\n", contadorMayor);
}

int main() {
    // Supongamos que tenemos un array de jugadores
    struct Jugador jugadores[] = {
        {"Jugador1", 15, 5, {"Ajedrez", "Damas", "Jenga", "Monopoly", "Pictionary"}, {2, 1, 3, 0, 2}, 10.5},
        {"Jugador2", 20, 3, {"Damas", "Jenga", "Monopoly"}, {1, 3, 0}, 8.2},
        // ... Puedes agregar más jugadores aquí
    };

    int numJugadores = sizeof(jugadores) / sizeof(struct Jugador);

    // Ejemplo de uso del primer módulo
    char nombreJuegoBuscado[50];
    printf("Ingrese el nombre del juego: ");
    scanf("%s", nombreJuegoBuscado);

    struct Jugador mejorJugador = encontrarMejorJugador(jugadores, numJugadores, nombreJuegoBuscado);

    if (mejorJugador.puntos != -1) {
        printf("El mejor jugador en %s es %s con %d puntos.\n", nombreJuegoBuscado, mejorJugador.nombre, mejorJugador.puntos);
    } else {
        printf("No se encontraron datos para el juego %s.\n", nombreJuegoBuscado);
    }

    // Ejemplo de uso del segundo módulo
    contarJugadoresPorEdadYTiempo(jugadores, numJugadores);

    return 0;
}