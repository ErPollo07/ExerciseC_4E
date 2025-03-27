/**
 * @brief Scrivere un programma concorrente che realizzi il seguente comando:
 *
 * cat file.txt | wc
 *
 * il processo p2 deve rimandare l'output di wc al padre, il quale lo scriverà
 * su un file chiamato wc.txt
 *
 * il nome del file "file.txt" deve essere passato come argomento in argv[1]
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

int main(int argc, char *argv[])
{

    int p1p2[2], p2p0[2], pid;

    pipe(p1p2);
    pid = fork();

    if (pid == 0) {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], (char *)0);

        return -1;
    }

    pipe(p2p0);

    pid = fork();

    if (pid == 0) {
        // Comunuicazione tra p1 e p2
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        // Coumunicazione tra p2 e il padre
        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/wc", "wc", (char *)0);

        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);

    close(p2p0[1]);
    close(0);
    dup(p2p0[0]);
    close(p2p0[0]);

    int nRead;
    int fd = open("wc.txt", O_CREAT | O_WRONLY, 0777);
    char buff;

    while ((nRead = read(0, &buff, sizeof(buff))) > 0) {
        printf("%c", buff);
        write(fd, &buff, nRead);
    }

    close(fd);

    printf("\n\n");
    return 0;
}