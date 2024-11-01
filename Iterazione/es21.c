/* 
Dato un numero intero positivo N verificare se N è un numero primo.
*/

#include <stdio.h>

int isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {

    int n;

    printf("Inserisci n: ");
    scanf("%d", &n);

    if (isPrime(n)) {
        printf("Il numero e' primo.");
    } else {
        printf("Il numero non e' primo.");
    }

    printf("\n\n");
    return 0;
} 