#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  FILE *file;
  int pid, num[5];

  for (int i = 0; i < 5; i++) {
    printf("inserisci un numero: ");
    scanf("%d", &num[i]);
  }
  
  file = fopen("file.txt", "w");

  for (int i = 0; i < 5; i++) {
    fprintf(file, "%d ", num[i]);
  }

  fclose(file);

  if ((pid = fork()) < 0) {
    printf("Errore nella generazione del figlio");
    exit(1);
  }
  
  if (pid == 0) {
    FILE *f;

    f = fopen("file.txt", "r");
    
    char c;
    while ((c = fgetc(f)) != EOF) {
      printf("%c", c);
    }
    
    fclose(f);
  }
  
  wait(&pid);


  printf("\n\n");
  return 0;
}
