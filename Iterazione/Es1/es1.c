/* 
Dato N un numero intero positivo, generare e visualizzare il numero 
successivo.
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

    printf("il numero successivo e' : %d", n + 1);

    printf("\n\n");
    return 0;
}