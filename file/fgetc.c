/*
Leggi il file numeri.txt composto da una sequenza di numeri separati da uno spazio.
Scrivi due file, pari.txt e dispari .txt, nei quali inserisci i numeri letti a seconda del loro valore pari o dispari.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  FILE *num, *pari, *dispari;
  int buff;

  // Apri il file dei numeri
  num = fopen("numeri.txt", "r");
  if (num == NULL)
  {
    printf("numeri.txt non trovato o non aperto correttamente.");
    return -1;
  }

  // Apri il file pari
  pari = fopen("pari.txt", "w");
  if (pari == NULL)
  {
    printf("numeri.txt non trovato o non aperto correttamente.");
    return -1;
  }

  // Apri il file dispari
  dispari = fopen("dispari.txt", "w");
  if (dispari == NULL)
  {
    printf("numeri.txt non trovato o non aperto correttamente.");
    return -1;
  }

  // Read char per char the file numeri.txt
  while ((buff = fgetc(num)) != EOF)
  {
    // controllo se il carattere e' uno spazio
    if (buff == 32)
    {
      continue;
    }

    // Posso fare questo controllo perche' nella tabella ascii i numeri pari hanno associato un numero pari
    if (buff % 2 == 0)
    {
      fputc(buff, pari);
      fputc(32, pari);
    }
    else
    {
      fputc(buff, dispari);
      fputc(32, dispari);
    }
  }

  printf("\n\n");
  return 0;
}