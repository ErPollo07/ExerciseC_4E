/* 
Progettare un algoritmo che risolve il seguente problema. Si desidera 
calcolare la somma delle radici quadrate di N valori numerici inseriti 
dall’utente, con N inserito in input. 
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).
*/

#include <stdio.h>
#include <math.h>

int main() {

    int N, a;
    double sum = 0;

    do { 
        printf("Inserisci N: ");
        scanf("%d", &N);

        if (N < 0) {
            printf("ATTENZIONE -> N deve essere positivo.");
        }
    } while (N < 0);
    
    for (int i = 0; i < N; i++) {
        printf("Inserisci a: ");
        scanf("%d", &a);

        // If the number don't permit performing the sqrt then
        // interrupt the program
        if (a < 0) {
            printf("\n\tHai inserito un numero non valido.");
            break;
        }

        sum += sqrt(a);
    }

    printf("\n\n\tLa somma delle radici quadrate e': %f\n", sum);

    printf("\n\n");
    return 0;
}