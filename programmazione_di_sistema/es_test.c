#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    int p1;
    int p1p0[2];
    int p;

    pipe(p1p0);
    p1 = fork();

    if (p1 == 0) {
        close(p1p0[0]); // chiudo il canale di 
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);

        char buff[20] = "123";

        write(1, &buff, sizeof(buff));

        exit(0);
    }

    close(p1p0[1]);
    close(0);
    dup(p1p0[0]);
    close(p1p0[0]);

    char buff[20];

    read(0, &buff, sizeof(buff));

    printf("IL messaggio del figlio e': %s", buff);


    printf("\n\n");
    return 0;
}