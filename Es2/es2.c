/*
Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma
*/

#include <stdio.h>

int main() {

    int a, b;
    int sum = 0, product;

    do {
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        if (a != 0 && b != 0) {
            product = a * b;
            sum += product;

            printf("Il prodotto e': %d\n", product);
        }
        
    } while (a != 0 && b != 0);

    printf("\n\tLa somma e': %d", sum);

    printf("\n\n");
    return 0;
}

    