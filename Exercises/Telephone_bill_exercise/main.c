/*  Si realizzi un programma per calcolare la bolletta telefonica degli utenti di un operatore di telefoniam mobile.
    I dati sono contenuti in una base di dati che consiste in un file di testo denominato "clienti.dat" in cui ogni riga
    descrive una telefonata nel seguente formato:
    <numero_telefonico> <data> <orainizio> <orafine> <numero_amico>
    Il numero telefonico è una stringa alfanumerica lunga al massimo 15 caratteri che indica il numero di telefono del chiamante,
    la data e una stringa nel formato GG/MM/YYYY, l’ora inizio e l’ora fine sono due stringhe di 8  caratteri nel formato HH:MM:SS
    e callcenter è un carattere che assume il valore ‘S’ nel caso la chiamata sia  verso un callcenter
    ‘N’ in caso contrario.
    Si assuma che le chiamate inizino e finiscano sempre nello stesso giorno, che il formato del file sia corretto e 
    che il numero di righe del file non sia noto a priori.
    La tariffa pagata per una chiamata dipende unicamente dall’ora d’inizio della stessa.
    La giornata è divisa in  quattro fasce orarie
    (fascia 1: 00:00:00 ­ 05:59:59; fascia 2: 06:00:00 ­ 11:59:59; fascia 3: 12:00:00 ­ 17:59:59;  fascia 4: 18:00:00 ­ 23:59:59).
    Il costo di una chiamata che inizia in fascia X sarà calcolato sulla base del costo della fascia X anche se a causa della sua 
    lunghezza la chiamata dovesse terminare nella fascia X+1.
    I costi  delle fasce sono contenuti in un file denominato ​ tariffe.txt​ .
    Il file è composto da 4 righe (una per ogni  fascia).
    Ogni riga contiene il costo per unità di 60 secondi di chiamata per la rispettiva fascia con la precisione 
    dei centesimi di euro. Nel caso di chiamata di un callcenter il costo della chiamata viene raddoppiato.
    Per  chiamate di durata non multipla di 60 secondi si arrotonda la durata per difetto.
    Ad esempio:
    Clienti.dat tariffe.txt
    3472222222 01/01/2011 10:10:12  10:11:10 S 0.23 
    3472222222 02/01/2011 15:10:12  16:11:20 N 0.51 
    3471111111 01/01/2011 11:10:12  11:21:10 N 0.65 
    3472222222 08/01/2011 21:20:12  22:13:09 N 0.12 
    3471111111 01/02/2011 11:15:00  11:15:10 N 
    3472222222 10/02/2011 21:20:12  22:11:10 N
    Il programma riceve sulla linea di comando il numero di telefono di un utente e un numero tra 1 e 12 indicante 
    un mese e deve stampare in output: 
    ● la bolletta da pagare nel mese,
    ● il numero di chiamate nel mese 
    ● La maggiorazione pagata a cause delle chiamate ai call center.
    Ad esempio:
    C:\> PROG.EXE 3472222222 1  Bolletta telefonica: 92.02 Euro  Numero di chiamate: 3 
    Maggiorazioni call center: 0.51 Euro */

#include <stdio.h>
#include <stdlib.h>

int Duratatelefonata(int orainizio, int minutoinizio, int secondoinizio, int orafine, int minutofine, int secondofine, int oredurata, int minutidurata, int secondidurata);

int main()
{
    int numerotelefonico, giorno, mese, anno, durata, fattore=0;
    int orainizio, minutoinizio, secondoinizio, orafine, minutofine, secondofine, oredurata=0, minutidurata=0, secondidurata=0;
    float costotelefonata = 0.00;
    char numeroamico;
    FILE *ifile;

    ifile = fopen ("clienti.dat", "r");
    if (ifile == NULL) {
        printf ("Errore di lettura del file\n");
        return EXIT_FAILURE;
    }

    while (!feof(ifile)) {
        fscanf (ifile, "%d %d/%d/%d %d:%d:%d %d:%d:%d %c", &numerotelefonico, &giorno, &mese, &anno, &orainizio, &minutoinizio, &secondoinizio,
            &orafine, &minutofine, &secondofine, &numeroamico);
    }


    printf ("La durata della chiamata è di %d secondi\n", secondidurata);


/*    durata = Duratatelefonata (orainizio, minutoinizio, secondoinizio, orafine, minutofine, secondofine, oredurata, minutidurata, secondidurata);

    fattore = durata / 30;
    if (durata%30 > 0) fattore++;
    if (numeroamico == 'S') {
        costotelefonata = 0.11*fattore;
    }
    else if (numeroamico == 'N') {
        costotelefonata = 0.23*fattore;
    }

    printf ("Il costo della telefonata è di %f euro\n", costotelefonata); */


    return 0;
}
/*
int Duratatelefonata(int orainizio, int minutoinizio, int secondoinizio, int orafine, int minutofine, int secondofine, int oredurata, int minutidurata, int secondidurata)
{
    if (orainizio != orafine) {
        oredurata = orafine - orainizio;
    }
    else oredurata = 0;
    if (oredurata < 0) {
        printf ("Valori impossibili\n");
        return EXIT_FAILURE;
    }

    if (minutoinizio != minutofine) {
        minutidurata = minutofine - minutoinizio;
    }
    else minutidurata = 0;

    if (secondoinizio != secondofine) {
        secondidurata = secondofine - secondoinizio;
    }
    else secondidurata = 0;

    secondidurata += minutidurata*60 + oredurata*3600;

    if (secondidurata < 0) {
        printf ("Valori impossibili\n");
        return EXIT_FAILURE;
    }
    else printf ("La durata della chiamata è di %d secondi\n", secondidurata);

    return secondidurata;
}
*/
