/* 
Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
interi positivi.
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

    printf("I numeri da 0 a %d sono : ", n);

    for (int i = 0; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n\n");
    return 0;
}