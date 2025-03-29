/**
 * @brief Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
 * le ordina usando un algoritmo di ordinamento a scelta e scrive il risultato
 * sia a video che su un file il cui nome risiede in argv[1].
 *
 * Esempio:
 * $ ./a.out file.txt ciao a tutti
 * a
 * ciao
 * tutti
 *
 * $ cat file.txt
 * a
 * ciao
 * tutti
 *
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 *
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// system call
#include <fcntl.h>
#include <unistd.h>

void sortWord(char first[], char second[], char *result)
{
    result[0] = '\0';

    for (int i = 0; i < strlen(first); i++)
    {
        if (first[i] == second[i])
        {
            continue;
        }

        if (first[i] < second[i])
        {
            strcpy(result, first);
        }
        else
        {
            strcpy(result, second);
        }
    }
}

void bubbleSort(char *sort[], int l)
{
    char *tmp;

    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < l - i - 1; j++)
        {
            if (strcmp(sort[j], sort[j + 1]) > 0)
            {
                tmp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{

    char *words[argc - 2];

    for (int i = 2; i < argc; i++) {
        words[i - 2] = argv[i];
    }

    bubbleSort(words, argc - 2);

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0754);

    for (int i = 0; i < argc - 2; i++) {
        write(fd, words[i], strlen(words[i]));
        write(fd, "\n", 1);
    }

    close(fd);

    printf("\n\n");
    return 0;
}