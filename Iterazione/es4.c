/* 
Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri pari minori o uguali a N.
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

    printf("I numeri dispari minori o uguali a %d sono : ", n);

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n\n");
    return 0;
} 