/* Si realizzi in C un programma per consultare un database sullo scarico/carico merci sulla banchina di
un porto.
La base dati consiste in un file di testo il cui nome viene passato come unico parametro sulla linea di
comando. Ogni riga del file descrive una merce nel formato:
<merce> <data> <peso>
La merce è una stringa lunga al massimo 20 caratteri che non contiene spazi, la data è una stringa nel
formato GG-MM-YYYY, il peso è espresso come un numero intero in chilogrammi, positivo nel
caso di operazione di carico o negativo nel caso di operazione di scarico. I dati sono separati da uno
spazio. Non si deve assumere nessun ordinamento per le righe, ed il numero di righe non è noto a
priori.
Ad esempio:
banane 22-01-2011 120
mele 01-03-2011 80
manghi 03-06-2011 -100
banane 01-02-2011 -100
manghi 15-01-2011 120
banane 20-01-2011 80
pere 01-01-2011 80
banane 22-01-2011 -80
Si desidera realizzare un programma per visualizzare alcune statistiche sulle operazioni effettuate. Il
programma riceve da tastiera il nome di una merce e deve visualizzare sullo schermo:
• I quintali totali caricati di quella merce, espressi con due cifre decimali
• La data dell’ultima operazione di carico effettuata per quella merce
• Il guadagno totale delle operazioni di carico per quella merce, sapendo che la tariffazione è di
10 ! per ogni operazione più 10 cent. al chilo.
Si assuma che il formato del file sia corretto.
Ad esempio:
C:\> PROG.EXE molo.dat
Inserire il nome della merce: banane
Quintali totali caricati di banane: 2,00
Data ultimo carico: 22-01-2011
Guadagno totale carico banane: ! 40,00 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 20

int main(int argc, char *argv[])
{
    int giorno, mese, anno, chilogrammi, chilogrammicaricati=0;
    int ultimogiorno, ultimomese, ultimoanno;
    float quintalicaricati=0.00, guadagno=0.00;
    char nomeprodotto[MAXCHAR], mercedesiderata[MAXCHAR];
    FILE *ifile;

    ifile = fopen("molo.dat", "r");
    if (ifile == NULL) {
        printf ("Errore nell'apertura del file\n");
        return EXIT_FAILURE;
    }
    if (argv =! 2) {
        printf("Numero di merci errato\n");
        return EXIT_FAILURE;
    }

    printf ("Inserire nome merce: \n");
    scanf ("%s", &mercedesiderata);
    while (fscanf(ifile, "%s %d-%d-%d %d", &nomeprodotto, &giorno, &mese, &anno, &chilogrammi) != EOF) {
        if (strcmp(nomeprodotto, mercedesiderata) == 0) {
            if (chilogrammi > 0) {
                chilogrammicaricati+=chilogrammi;
                quintalicaricati=chilogrammicaricati/100;
                guadagno = 10.00 + 10*quintalicaricati;
                }
            ultimogiorno=giorno;
            ultimomese=mese;
            ultimoanno=anno;
            }
    }

    printf ("Il numero di quintali caricati di %s è: %f\n", mercedesiderata, quintalicaricati);
    printf ("Data ultimo carico: %d-%d-%d\n", ultimogiorno, ultimomese, ultimoanno);
    printf ("Guadagno totale caricio banane: %f\n", guadagno);

    return 0;
}
