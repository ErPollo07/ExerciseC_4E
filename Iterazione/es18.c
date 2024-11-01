/**
 * @brief Convertitore di secondi
 * 
 * Data una misura di tempo espressa in secondi S1, convertirla in ore H,
 * minuti M e secondi S.
 * Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
 * dal programma, 0h 27m 10s.
 * 
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 * 
 * @return La funzione restituisce 0.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int s, hour, minute, second;

    printf("Inserisci n1: ");
    scanf("%d", &s);

    while (s > 3600) {
        s -= 3600;
        hour++;
    }

    while (s > 60) {
        s -= 60;
        minute++;
    }

    second = s;

    printf("Tempo convertito: %d : %d : %d", hour, minute, second);

    printf("\n\n");
    return 0;
} 