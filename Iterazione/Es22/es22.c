/* 
Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
danno per somma il numero stesso. Non considerare la proprietà commutativa.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n;
    

    do {
        printf("Inserisci n: ");
        scanf("%d", &n);
    } while (n < 0);
    
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= n; j++) {
            if (i + j == n) {
                printf("%d + %d = %d\n", i, j, n);
            }
        }
    }

    printf("\n\n");
    return 0;
} 