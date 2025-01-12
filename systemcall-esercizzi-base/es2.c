/**
 * @brief Scrivere un programma in linguaggio C che scriva l'alfabeto su un file 
 * il cui nome deve essere letto da argv[1]
 * 
 * Esempio di utilizzo:
 * 
 * $ ./a.out /tmp/alfabeto
 * $ cat /tmp/alfabeto
 * abcdefghijklmnopqrstuvz
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

int main(int argc, char *argv[]) {

    char alfabeto[] = "abcdefghijklmnopqrstuvz";

    // open the file
    // if it doesn't exists create and write on it with permission
    // if the file already exists write on it, wtih permission
    int fd = open(argv[1], O_CREAT | O_WRONLY, 0754);

    // write on file
    write(fd, alfabeto, strlen(alfabeto));

    // close the file
    close(fd);

    printf("\n\n");
    return 0;
} 