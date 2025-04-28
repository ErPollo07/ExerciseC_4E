#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
  FILE *origine, *dst;
  unsigned char buffer[BUFFER_DIM];
  int n;

  if (argc != 3)
  {
    printf("Errore nell'inserimento degli argomenti.");
    exit(-1);
  }

  // Apertura del file di origine
  origine = fopen(argv[1], "r");

  if (origine == NULL)
  {
    printf("Errore apertura file di origine.");
    exit(-1);
  }
  else
  {
    // apertura del file di destinazione
    dst = fopen(argv[2], "w");

    if (dst == NULL)
    {
      printf("Errore apertura file di origine.");
      exit(-1);
    } else {
      // se tutto va a buon file (gli else si possono togliere)
      
      while (!feof(origine)) {
        n = fread(buffer, 1, BUFFER_DIM, origine); // dove, dim di ogni carattere, dim da prelevare, *file
        if (n > 0) {
          fwrite(buffer, 1, n, dst);
        }
      }
    }
  }
  
  // r+ lettura e scrittura
  // w+ scrittura e lettura
  // a+ lettura e scrittura in append

  // per i file binari
  // rb+
  // wb+
  // ab+

  fclose(origine);
  fclose(dst);

  printf("\n\n");
  return 0;
}