/* 
Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    int a, b, num, sum = 0, i = 0;

    do {
        printf("Inserire a: ");
        scanf("%d", &a);
        printf("Inserire b: ");
        scanf("%d", &b);

        if (a > b) {
            printf("ATTENZIONE -> Devi inserire dei numeri tale per cui a < b sia vera.\n");
        }
    } while (a > b);

    do {
        printf("Inserire numero: ");
        scanf("%d", &num);

        // If the number is correct then
        // update the sum and the counter
        if (num >= a && num <= b) {
            sum += num;
            i++;
        }
    } while (num >= a && num <= b);

    // calculate and print avarage
    printf("\n\tLa media e': %f", (double)(sum / i));

    printf("\n\n");
    return 0;
}