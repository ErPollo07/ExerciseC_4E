/* 
Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero. 
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int a, b;
    double res;

    do {
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        // Check if the division is possible
        if (a != 0 && b != 0) {
            if (a > b) {
                res = (double)b / (double)a;
            } else {
                res = (double)a / (double)b;
            }

            printf("Il rapporto e': %f\n", res);
        } else {
            printf("Il rapporto non e' stato possibile.\n");
        }
    } while (a != 0 && b != 0);

    
    return 0;
}
