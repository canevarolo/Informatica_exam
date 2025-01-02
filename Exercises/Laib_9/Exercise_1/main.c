/* Una matrice di caratteri rappresenta in forma schematizzata una palude. La
palude è costituita da zone di fango, rappresentate dal carattere ‘.’, e da
zone pietrose, indicate dal carattere ‘*’. Le dimensioni della matrice
possono essere fissate a piacere, mediante dei #define, comunque non
superiori a 25 righe e 80 colonne.
Esempio di palude:
**.*.*....*
..*.*...**.
*.....*....
.*.*.*.*.*.
..*.*...*.*
Realizzare un programma che cerchi nella palude un percorso da sinistra a
destra, senza salti, costituito tutto da zone pietrose adiacenti. Si ipotizzi
che, adiacente a destra di un punto pietroso, ci possa essere al più un altro
punto pietroso (non ci sono diramazioni), sulla stessa riga, sulla riga in alto
o sulla riga in basso. Il programma deve visualizzare la sequenza righe in
cui ci sono le pietre del percorso trovato (le colonne sono implicite, ci
deve essere una pietra per ogni colonna), oppure avvertire che non esiste
un percorso. Per la prima versione del programma si utilizzi una matrice di
stringhe predefinita. Come approfondimento, la palude viene introdotta da
tastiera, e nella versione finale, si legge la palude da file. */

#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 12

int main()
{
    char palude[N][M], f;
    int i, k, j, n=0;

    f = fopen("palude.dat", "r");
    if (f == NULL) {
                        printf ("Non si riesce ad aprire il file correttamente");
                        return 1;
                    }
    if (palude[0][0] == '*')  for (i=1; i<N; i++) {
                                                        for (j=i-1; j<i+1; j++) {
                                                                                    scanf ("%c", palude[i][j]);
                                                                                    if (palude[i][j]=='.') n++;
                                                                                }
                                                        if (n<3) printf ("0");
                                                        if (n == 3) printf ("Percorso non valido");
                                                    }

    if (palude[0][0] == '.') for (i=1; i<N; i++) {
                                                    for (j=i-1; j<i+1; j++) {
                                                                                scanf ("%c", palude[i][j]);
                                                                                if (palude[i][j]=='.') n++;
                                                                                if (n<3) printf ("0 \n");
                                                                            }
                                                    if (n == 3) printf ("Percorso non valido");
                                                    }

    printf ("Percorso trovato!");

    return 0;
}
