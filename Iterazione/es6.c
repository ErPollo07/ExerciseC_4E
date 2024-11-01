/* 
Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n;

    do {
        printf("Inserisci n: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("il numero deve essere intero e positivo\n");
        }

    } while (n < 0);

    printf("Questi sono i numeri da %d a %d : ", -n, n);

    for (int i = -n; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n\n");
    return 0;
} 