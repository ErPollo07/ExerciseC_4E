/*
Scrivi un programma che legge da argv[1] un numero intero positivo (N) e poi
disegna a terminale un quadrato vuoto composto di asterischi (‘*’)
con il lato lungo N:

Per N pari a 3 il programma stampa:

***
* *
***
Per N pari a 5 il programma stampa:

*****
*   *
*   *
*   *
*****
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        exit(1);
    }

    int lenght = atoi(argv[1]);

    for (int i = 0; i < lenght; i++)
    {
        if (i == 0 || i == lenght - 1)
        {
            for (int j = 0; j < lenght; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            printf("*");

            for (int j = 0; j < lenght - 2; j++)
            {
                printf(" ");
            }

            printf("*\n");
        }
    }

    printf("\n\n");
    return 0;
}