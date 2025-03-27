/**
 * @brief Scrivere un programma concorrente che realizzi il seguente comando:
 *
 * cat costituzione.txt | more
 * 
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 * 
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int p1p0[2];
    int pid;

    pid = fork();

    if (pid == 0)
    {
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pid = fork();

    if (pid == 0)
    {
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);
        execl("/bin/more", "more", (char *)0);
        return -1;
    }

    close(p1p0[1]);
    close(p1p0[0]);
    wait(&pid);
    wait(&pid);

    printf("\n\n");
    return 0;
} 
