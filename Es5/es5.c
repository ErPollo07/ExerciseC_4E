/* 
Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati
*/

#include <stdio.h>

int main() {

    int a, b, c;
    int even = 0, odd = 0, null = 0;

    do {
        printf("Inserire a: ");
        scanf("%d", &a);
        printf("Inserire b: ");
        scanf("%d", &b);
        printf("Inserire c: ");
        scanf("%d", &c);

        if (a - b == 0) {
            null++;
        // If the module of the subtruction between 1 and b then
        // upgrade even
        } else if ((a - b) % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    } while (a + b < c);

    printf("\n\n\tEven : %d\n\tOdd : %d\n\tNull : %d\n", even, odd, null);

    printf("\n\n");
    return 0;
}