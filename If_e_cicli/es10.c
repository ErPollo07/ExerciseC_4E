/* 
Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale 
le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. 
La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande 
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char type[20];
    double price = 0;
    int drinks = 0, resturant = 0;
    double avarageDrinks, avarageResturant;
    double sumDrinks = 0, sumResturant = 0;
    int counterResturant = 0, counterDrinks = 0;

    while (1) {
        printf("Inserici la tipologia: ");
        scanf("%s", &type);

        if (strcmp(type, "esci") == 0) 
            break;

        do {
            printf("Inserisci il prezzo: ");
            scanf("%lf", &price);
        } while (price <= 0);
        
        if (strcmp(type, "ristorante") == 0) {
            printf("r");

            sumResturant += price;
            counterResturant++;
        } else if (strcmp(type, "bevande") == 0) {
            printf("ds");

            sumDrinks += price;
            counterDrinks++;
        } else if (strcmp(type, "esci") != 0) {
            printf("Il tipo non esiste.\n");
        }
    }

    if (counterDrinks > counterResturant) {
        printf("Le bevande sono state vendute di piu'.\n");
    } else if (counterDrinks < counterResturant) {
        printf("Le ristorazioni sono state vendute di piu'.\n");
    } else {
        printf("Le vendite sono state uguali.\n");
    }

    if (counterDrinks > 0) {
        avarageDrinks = sumDrinks / (double)counterDrinks;
        printf("La media delle bevande e': %lf.\n", avarageDrinks);
    }

    if (counterResturant > 0) {
        avarageResturant = sumResturant / (double)counterResturant;
        printf("La media delle ristorazioni e': %lf.\n", avarageResturant);
    }

    printf("\n\n");
    return 0;
}