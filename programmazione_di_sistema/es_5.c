/**
 * @brief Un’applicazione multiprocesso in C deve presentare la seguente interfaccia:
 * controlloFatture nomeFileFatture 
 * dove nomeFileFatture è un nome assoluto di file.
 * 
 * A questo fine, l’addetto dell’azienda deve verificare, sul file passato 
 * come parametro, se un cliente ha ancora delle fatture in sospeso oppure se 
 * le ha pagate tutte.
 * 
 * Nel file passato come parametro sono memorizzate tutte le fatture, una per
 * ogni riga. Ogni riga è composta dal nome del cliente (un codice di 5 caratteri
 * alfanumerico che identifica univocamente ogni cliente), da un campo che 
 * contiene la stringa “pagato” per le fatture saldate oppure “insoluto”
 * per quelle ancora insolute, più altri campi con altre informazioni.
 * 
 * L’addetto dell’azienda inserisce a terminale il codice dei clienti (uno alla
 * volta) di cui vuole controllare lo stato dei pagamenti. Per ogni cliente
 * inserito, l’applicazione deve visualizzare il nome del cliente stesso e il
 * numero di fatture di tale cliente che risultano ancora da pagare.
 * 
 * Quando l’applicazione termina,a causa dell’inserimento della stringa “esci”,
 * il programma deve visualizzare il numero totale di richieste di servizio
 * eseguite fino a quel momento.
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

#define READ 0
#define WRITE 1

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Insufficente numero di argomenti.");
        exit(1);
    }

    char client[100];
    int fd = open(argv[1], O_RDONLY, 0777);
    int p1p0[2], pid, tot = 0;

    do {
        pipe(p1p0);

        printf("Inserisci codice cliente: ");
        scanf("%s", client);
        
        if (strcmp(client, "esci") == 0) {
            close(p1p0[READ]);
            close(p1p0[WRITE]);

            printf("Totale fatture non pagate dai clienti controllati: %d\n", tot);
            printf("Chiusura del programma.\n");
            break;
        }

        pid = fork();

        if (pid == 0) {
            close(p1p0[READ]);
            close(WRITE);
            dup(p1p0[WRITE]);
            close(p1p0[WRITE]);

            execl("/usr/bin/grep", "grep", "-c", strcat(client, " insoluto"), argv[1], (char *)0);

            return -1;
        }

        close(p1p0[WRITE]);

        char buff[1000];
        int nRead;

        read(p1p0[READ], buff, sizeof(buff));

        printf("Il cliente %s ha %d fatture da pagare.\n", client, atoi(buff));
        tot += atoi(buff);
    
    } while (strcmp(client, "esci") != 0);

    close(fd);

    printf("\n\n");
    return 0;
}