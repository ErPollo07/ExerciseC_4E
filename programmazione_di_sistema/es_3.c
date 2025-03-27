/**
 * @brief Si scriva un’applicazione concorrente che presenti la seguente interfaccia:
 *
 * cercaStringhe FileIn
 *
 * dove FileIn è un nome assoluto di file.
 *
 * L’applicazione deve contare il numero di volte in cui un insieme di stringhe
 * che l’utente inserisce da terminale (una alla volta) compaiono all’interno
 * del file passato come parametro in argv[1].
 * Se in una riga del file una parola compare più volte, al fine del conteggio,
 * considerare solamente la prima occorrenza.
 * L’applicazione termina quando l’utente inserisce la stringa “fine”.
 * L’applicazione deve visualizzare il numero di volte in cui ogni stringa
 * compare nel file e anche, al termine dell’esecuzione, il numero totale di
 * stringhe trovate nel file.
 *
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 *
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char buffer[100] = "";
    int p1p0[2], pid;

    do
    {
        printf("Inserisci stringa da cercare: ");
        scanf("%s", buffer);

        if (strcmp(buffer, "fine") != 0)
        {
            pipe(p1p0);
            pid = fork();
            if (pid == 0)
            {
                close(p1p0[0]);
                close(1);
                dup(p1p0[1]);
                close(p1p0[1]);

                execl("/usr/bin/grep", "grep", "-c", buffer, argv[1], (char *)0);

                return -1;
            }

            close(p1p0[1]);

            char result[100];
            
            read(p1p0[0], result, sizeof(result));

            printf("Result for %s -> %s", buffer, result);
        }
    } while (strcmp(buffer, "fine") != 0);

    printf("\n\n");
    return 0;
}