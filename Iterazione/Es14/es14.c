/* 
Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
ripetuta, il prodotto dei due numeri e visualizzarli.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n1, n2, sum;

    printf("Inserisci n1: ");
    scanf("%d", &n1);
    printf("Inserisci n2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        sum += n1;
    }

    printf("Il prodotto e': %d", sum);

    printf("\n\n");
    return 0;
} 