/**
 * @brief Si scriva un programma in C che legge in input da argv[1] un carattere, quindi istanzi un processo figlio
 * il quale deve convertire il carattere in maiuscolo e terminare. Il padre attende la terminazione del processo figlio.
 * 
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 * 
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Devi inserire un carattere in minuscolo da convertire in maiuscolo.\n");
        exit(0);
    }

    // In this variable is contained the childprocess's pid
    int pid = fork();

    // child stuff
    if (pid == 0) {
        // convert the caracter
        char c = toupper(argv[1][0]);

        printf("Sono il processo figlio: Il carattere in maiuscolo e' %c.\n", c);
        sleep(1);
        exit(0);
    } else {
        // waiting for child
        wait(&pid);
    }

    printf("Mio figlio a finito");

    printf("\n\n");
    return 0;
} 