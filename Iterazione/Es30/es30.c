/* 
Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato 
di N2. 
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n1, n2;

    do {
        printf("Inserisci n1: ");
        scanf("%d", &n1);
    } while (n1 < 0);

    do {
        printf("Inserisci n2: ");
        scanf("%d", &n2);
    } while (n2 < 0);
    
    if (n1 == n2 * n2) {
        printf("n1 e' il quadrato di n2");
    } else {
        printf("n1 non e' il quadrato di n2");
    }

    printf("\n\n");
    return 0;
} 