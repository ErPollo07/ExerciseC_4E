/* 
Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.
*/

#include <stdio.h>
#include <math.h>

int main() {

    int a, b;
    double division, radice;

    do {
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        if (a > b && b != 0) {
            division = a / b;
        } else if (a != 0) {
            division = b / a;
        } else {
            printf("Il divisore non puo' essere 0.\n");
            break;
        }
        
        if (division >= 0) {
            radice = sqrt(division);
        } else {
            printf("Non poui fare una radice quadrata con un numero minore di 0");
            break;
        }

        printf("Radice: %f", radice);

    } while (1);

    printf("\n\n");
    return 0;
}