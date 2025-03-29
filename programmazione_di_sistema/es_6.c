/**
 * @brief Il file.txt rappresenta le fatture dell’ultimo mese della ditta ProgrammatoriHero srl
 * e contiene 3 campi: codice, “pagato” o “insoluto”, l’importo
 * 
 * Si vuole realizzare un programma concorrente in linguaggio C che mostri a video l'importo totale delle fatture emesse.
 *
 * Si usi la seguente procedura: 
 * Si generi un processo figlio P1 che legge il file e lo manda al processo P2 il quale
 * estrapola la terza colonna del file, e la manda al processo P0.
 * Il processo P0 riceve quindi tutti gli importi, ne calcola il totale e lo mostra a video. 
 * 
 * Note operative
 * Il processo P1 usi il comando cat per mostrare il contenuto del file e inviarlo a P2
 * Il processo P2 usi il comando: awk '{print $3}' per estrapolare la terza colonna
 * Il processo P2 deve inviare al processo P0 la terza colonna
 * Il processo P0 deve leggere in input tutti i valori e per ogni lettura deve incrementare la variabile accumulatore “totale”
 * 
 * Osservazione: 
 * strncat(strimporto, &buffer[0], sizeof(buffer[0]))
 * Aggiunge in coda alla stringa strimporto il carattere buffer[0] la cui dimensione è sizeof(buffer[0])
 * 
 * Osservazione:
 * char *ptr;
 * double x = strtod(strimporto, &ptr);
 * strtod converte la stringa strimporto in double. 
 * 
 * Osservazione:
 * strimporto[0] = '\0';
 * Pone in posizione 0 di una stringa il carattere terminatore, in questo modo si resetta a livello logico una stringa
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

    int p1, p2, p1p2[2], p2p0[2];

    pipe(p1p2);

    p1 = fork();

    if (p1 == 0) {
      close(p1p2[READ]);
      close(WRITE);
      dup(p1p2[WRITE]);
      close(p1p2[WRITE]);

      execl("/usr/bin/cat", "cat", argv[1], (char *)0);
      
      return -1;
    }

    pipe(p2p0);

    p2 = fork();

    if (p2 == 0) {
      // Comunicazione p1 -> p2
      close(p1p2[WRITE]);
      close(READ);
      dup(p1p2[READ]);
      close(p1p2[READ]);

      // Comunicazione p2 -> p0
      close(p2p0[READ]);
      close(WRITE);
      dup(p2p0[WRITE]);
      close(p2p0[WRITE]);

      execl("/usr/bin/awk", "awk", "{print $3}", (char *)0);

      return -1;
    }

    close(p1p2[READ]);
    close(p1p2[WRITE]);

    close(p2p0[WRITE]);

    int tot = 0, importo = 0; 
    char buff, strImp[10], *ptr;

    while (read(p2p0[READ], &buff, sizeof(buff)) > 0) {
      if (buff == '\n') {
        importo = strtod(strImp, &ptr);
        tot += importo;
        
        if (importo != 0) {
            printf("importo aggiunto al totale %d\n", importo);
        }

        strcpy(strImp, "");

        continue;
      }

      strncat(strImp, &buff, sizeof(buff));
    }

    printf("Totale: %d\n", tot);

    printf("\n\n");
    return 0;
}
