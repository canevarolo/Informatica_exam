/* Si scriva un programma che legga da un file, il cui nome è introdotto da
 * tastiera, alcune informazioni ferroviarie. Per ciascuna linea, il file contiene
 * le seguenti informazioni (ciascuno dei campi non superi i 20 caratteri di
 * lunghezza e sia privo di spazi)
 * <stazione_partenza><ora_partenza><stazione_arrivo><ora_arrivo>
 * Il programma riceve poi da tastiera il nome di una città: il programma
 * calcoli e stampi il numero di treni in arrivo ed il numero di treni in
 * partenza da tale città (se inclusa nell’elenco)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 20

int main ()
{
  FILE *f;
  int  ora_partenza,
       ora_arrivo,
       treni_in_partenza = 0,
       treni_in_arrivo = 0;
  char datafile[MAX_STR_SIZE + 1],
       partenza[MAX_STR_SIZE + 1],
       arrivo[MAX_STR_SIZE + 1],
       city[MAX_STR_SIZE + 1];

  printf ("Inserire il nome del file dati: ");
  scanf ("%s", datafile);

  printf ("Inserire la citta' di partenza o arrivo: ");
  scanf ("%s", city);

  f = fopen (datafile, "r");
  if (f == NULL)
    {
      fprintf (stderr, "Errore nell'apertura del file dati \"%s\"\n", datafile);
      return 1;
    }
  else
    {
      while (fscanf (f, "%s%d%s%d", partenza, &ora_partenza, arrivo,
             &ora_arrivo) != EOF) {
        if (!strcmp(partenza, city))
          treni_in_partenza++;
        if (!strcmp(arrivo, city))
          treni_in_arrivo++;
      }
    }

  printf ("Treni in partenza da %s: %d\n", city, treni_in_partenza);
  printf ("Treni in arrivo a %s: %d\n", city, treni_in_arrivo);

  fclose (f);
  return 0;
}
