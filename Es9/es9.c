/* 
Progettare un algoritmo che risolva il seguente problema. Si richieda 
all’utente di inserire una serie di terne di dati numerici (A, B, C). 
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.
*/

#include <stdio.h>
#include <limits.h>

int main() {

    int a, b, c;
    int min = INT_MAX, max = 0;

    do {
        printf("Inserire a: ");
        scanf("%d", &a);
        printf("Inserire b: ");
        scanf("%d", &b);
        printf("Inserire c: ");
        scanf("%d", &c);

        if (a < b && b < c) {
            if (a < min) {
                min = a;
            }

            if (c > max) {
                max = c;
            }
        } else {
            printf("ATTENZIONE -> I valori sono sbagliati.\n");
        }
    } while (a > 0 && b > 0 && c > 0);

    printf("\n\tMin: %d\n\tMax: %d", min, max);

    printf("\n\n");
    return 0;
}
