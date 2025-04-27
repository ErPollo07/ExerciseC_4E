/**
 * @brief Il file f.txt contiene l'output della seguente chiamata:
 * $ traceroute google.com
 * 
 * Lo scopo del Traceroute è seguire il percorso di un pacchetto di dati dalla sua sorgente fino a destinazione. Per farlo dovrà registrare ogni singolo "salto" del pacchetto.
 * 
 * Sfruttando la programmazione concorrente si vuole realizzare un programma che legga il file, prelevi la prima delle tre colonne che mostra il tempo di risposta in nano secondi e calcoli quindi il tempo totale di richiesta.
 * 
 * Esempio di file:
 * 
 * $ cat f.txt 
 * traceroute to google.com (216.58.208.174), 30 hops max, 60 byte packets
 *  1  _gateway (192.168.2.1)  0.686 ms  0.732 ms  0.775 ms
 *  2  net-93-149-86-45.cust.vodafonedsl.it (93.149.86.45)  5.868 ms  5.947 ms  5.477 ms
 *  3  192.168.50.18 (192.168.50.18)  11.627 ms  14.028 ms  14.207 ms
 *  4  * * *
 *  5  * * *
 *  6  185.210.48.39 (185.210.48.39)  14.759 ms 185.210.48.38 (185.210.48.38)  12.411 ms  12.312 ms
 *  7  185.210.48.39 (185.210.48.39)  12.630 ms  12.715 ms  13.159 ms
 *  8  185.210.48.3 (185.210.48.3)  12.783 ms  14.649 ms  14.006 ms
 *  9  74.125.245.225 (74.125.245.225)  14.535 ms * 74.125.245.241 (74.125.245.241)  16.420 ms
 * 10  142.250.212.244 (142.250.212.244)  16.971 ms 72.14.234.75 (72.14.234.75)  12.953 ms 209.85.255.5 (209.85.255.5)  13.432 ms
 * 11  lhr25s09-in-f14.1e100.net (216.58.208.174)  12.783 ms  12.623 ms  12.129 ms
 * 
 * Come si può vedere dall'esempio la prima riga non è utile, e il primo tempo utile si trova nella quarta colonna. 
 * 
 * Note operative: 
 * p0 crea il processo p1 che chiama il comando cat e inoltra il suo output a p2
 * p2 estrapola la quarta colonna e la inoltra a p3
 * p3 chiama il comando tail -n +2 per escludere la prima riga, fatto cio inoltra l'output a p0
 * p0 somma tutti i tempi di accesso e al termine mostra il tempo totale che un pacchetto ha impiegato lungo il percorso
 * 
 * 
 * Osservazione importante:
 * Al fine di rendere l'esercizio facilmente testabile si è deciso di utilizzare il file f.txt in modo da avere un risultato riproducibile. Dopo aver testato il software si consiglia di sostituire al comando cat il comando traceroute in modo da realizzare un software il cui funzionamento è reale.
 * Esempio di utilizzo reale: $./a.out google.com
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

  int p1, p2, p3, p1p2[2], p2p3[2], p3p0[2];

  pipe(p1p2);

  p1 = fork();

  if (p1 == 0) {
    close(p1p2[READ]);
    close(WRITE);
    dup(p1p2[WRITE]);
    close(p1p2[WRITE]);

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    return -1;
  }

  pipe(p2p3);

  p2 = fork();

  if (p2 == 0) {
    // p1 -> p2
    close(p1p2[WRITE]);
    close(READ);
    dup(p1p2[READ]);
    close(p1p2[READ]);

    // p2 -> p3
    close(p2p3[READ]);
    close(WRITE);
    dup(p2p3[WRITE]);
    close(p2p3[WRITE]); 

    execl("/usr/bin/awk", "awk", "{print $4}", NULL);
    
    return -1;
  }

  close(p1p2[READ]);
  close(p1p2[WRITE]);

  pipe(p3p0);

  p3 = fork();

  if (p3 == 0) {
    // p2 -> p3
    close(p2p3[WRITE]);
    close(READ);
    dup(p2p3[READ]);
    close(p2p3[READ]);

    // p3 -> p0
    close(p3p0[READ]);
    close(WRITE);
    dup(p3p0[WRITE]);
    close(p3p0[WRITE]);

    execl("/usr/bin/tail", "tail", "-n", "+2", NULL);

    return -1;
  }

  // p2 -> p3
  close(p2p3[READ]);
  close(p2p3[WRITE]);

  // p3 -> p0
  close(p3p0[WRITE]);
  
  char val[100] = "", buff, *ptr;
  double time, tot = 0.0;

  while (read(p3p0[READ], &buff, sizeof(buff)) > 0) { 
    if (buff != '\n') {
      strncat(val, &buff, sizeof(buff));
      continue;
    }

    time = strtod(val, &ptr);
    tot += time;

    strcpy(val, "");

    printf("Tempo %.2f aggiunto al totale.\n", time);
  }

  close(p3p0[READ]);

  printf("Tempo totale %.2f.\n", tot);

  printf("\n\n");
  return 0;
}
