#include <stdio.h>
#include <stdlib.h>

/*
Scrivi il codice sorgente diun programma che consente all'utente di inserire 5 numeri interi e
di salvarli in un file binario.
Successivamente, tali numeri dovranno essere letti dal file e visualizzati a schermo.
*/

int main(int argc, char *argv[]) {
  FILE *bin;

  if (argc != 6) {
    printf("Numero argomenti non valido");
    exit(1);
  }
  
  bin = fopen("file.bin", "wb");
  int num[5];
  
  for (int i = 0; i < 5; i++) {
    num[i] = atoi(argv[i + 1]);
  }

  fwrite(num, sizeof(int), 5, bin);

  fclose(bin);

  bin = fopen("file.bin", "rb");

  fread(num, sizeof(int), 5, bin);

  fclose(bin);
 
  for (int i = 0; i < 5; i++) {
    printf("%d " , num[i]);
  }
  
  printf("\n\n");
  return 0;
}
