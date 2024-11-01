/**
 * @brief Popolare un array
 * 
 * Popolare un array di interi di dimensione 4, stamparne a video il
 * contenuto.
 * 
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 * 
 * @return La funzione restituisce 0.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int lenght = 4;
    int array[lenght];
    int indexArray = 0;

    while (indexArray != lenght) {
        printf("Inserisci il %d numero: ", indexArray+1);
        scanf("%d", &array[indexArray]);

        indexArray++;
    }

    printf("Contenuto dell'array: ");
    for (int i = 0; i < lenght; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\n");
    return 0;
} 