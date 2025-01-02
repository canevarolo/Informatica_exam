/* Si scriva un programma C che:
      - legga da tastiera (per righe o per colonne, a scelta) una matrice quadrata di dimensione uguale a 5 righe e 5 colonne
      - rintracci se tale matrice contiene delle sequenze di elementi adiacenti uguali a zero di lunghezza uguale o maggiore di 3
      - visualizzi l'indice di riga in cui tali sequenze si presentano. */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int main()
{
    int matrice[MAXSIZE][MAXSIZE];
    int i, k;
    FILE *fp;

    fp = fopen ("matrice.dat", "r");

    if (fp == NULL) {
        printf ("Errore nell'apertura del file\n");
        return -1;
    }

    for (i=0; i<MAXSIZE; i++) {
        for (k=0; k<MAXSIZE; k++) {
            fscanf (fp, "%d", &matrice[i][k]);
        }
    }

   /* for (i = 0; i < MAXSIZE; i++) {
        for (k = 0; k < MAXSIZE; k++) {
            printf ("Inserire numero intero: \n");
            scanf ("%d", &matrice[i][k]);
        }
    }   */

    for (i=0; i<MAXSIZE; i++) {
        for (k=0; k<MAXSIZE; k++) {
            if ((matrice[i][k] == 0) && (matrice[i][k+1] == 0) && (matrice[i][k+2] == 0))
                printf ("Una successione di zeri compare alla riga %d\n", i+1);
        }
    }


    return 0;
}
