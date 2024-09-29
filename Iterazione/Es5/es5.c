/* 
Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. 
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n1, n2;

    do {
        printf("Inserisci n1: ");
        scanf("%d", &n1);
        printf("Inserisci n2: ");
        scanf("%d", &n2);

        if (n1 > n2) {
            printf("Devi inserire n1 e n2 tale per cui n1 < n2 n\n");
        }

    } while (n1 > n2);

    printf("Questi sono i numeri da %d a %d : ", n1, n2);

    for (int i = n1; i <= n2; i++) {
        printf("%d ", i);
    }

    printf("\n\n");
    return 0;
} 