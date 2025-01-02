/* Un’azienda che gestisce una “rete sociale” (in inglese: “socialnetwork”, come p.es. Facebook) ha bisogno di un
 programma che analizzi i dati dei suoi utenti al fine di identificare la redditività (attuale e potenziale) di ciascuno.
 Il programma riceve, da linea di comando, il nome di un file contenente i dati degli utenti relativi agli ultimi 30
 giorni; ogni riga del file è organizzata secondo il seguente formato:

 <codice_utente> <tempo_desktop> <tempo_mobile> <numero_click> <numero_post> <numero_share> <numero_like>

 I campi sono separati da spazi.
 Il <codice_utente> è un codice numerico di 12 cifre che identifica univocamente un determinato utente;
 il <tempo_desktop> è quanto tempo, misurato in minuti, l’utente ha passato sulla rete sociale accedendo da un computer desktop;
 <tempo_mobile> è l’analogo valore, sempre in minuti, ma relativo agli accessi da dispositivo mobile;
 <numero_click> corrisponde al numero di volte che l’utente ha cliccato un link presente nel suo “newsfeed”
 (ovvero, i contenuti che l’utente vede accedendoalservizio);
 <numero_post> corrisponde al numero di “post” effettuati dall’utente;
 <numero_share> corrisponde al numero di volte che l’utente ha condiviso dei contenuti;
 <numero_like> corrisponde al numero di “mi piace” espressi dall’utente.
 Tutti i tempi sono da intendersi numeri interi.
 Si facciano le seguenti ipotesi:
     ● il numero di righe del file non è noto a priori;
     ● il formato del file è da considerarsi corretto.

 La redditività di un utente è data dalla seguente formula:

 redditività = <tempo_desktop> + 1.5*<tempo_mobile> + 2.0*<numero_click> +1.8*<numero_post> + 1.5*<numero_share> + <numero_like>
 Scrivere un programma C che – leggendo una sola volta il file di input – implementi le seguenti funzionalità:

 ● Stampi su video i codici dei 2 utenti maggiormente redditizi, con relativo valore di redditività;
 ● Stampi su video i codici dei 2 utenti la cui redditività potrebbe maggiormente salire, ovvero, gli utenti col più elevato rapporto
  (<tempo_desktop> + <tempo_mobile>)/(<numero_click> + <numero_post> + <numero_share> + <numero_like>)
  (stampare anche il corrispondente rapporto). */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, codice_utente=0, tempo_desktop=0, tempo_mobile=0, numero_click=0, numero_post=0, numero_share=0, numero_like=0, righe=0;
    int codicemaxredditivita1=0, codicemaxredditivita2=0, codicemaxpromessa1=0, codicemaxpromessa2=0;
    float redditivita=0.00, maxredditivita1=0.00, maxredditivita2=0.00;
    float promessa=0.00, maxpromessa1=0.00, maxpromessa2=0.00;
    FILE *ifile;

    ifile = fopen ("socialnetwork.dat", "r");
    if (ifile == NULL) {
        printf ("Errore nell'apertura del file\n");
        return EXIT_FAILURE;
    }

    while (fscanf (ifile, "%d %d %d %d %d %d %d", &codice_utente, &tempo_desktop, &tempo_mobile, &numero_click, &numero_post, &numero_share, &numero_like)!= EOF) {
        redditivita = tempo_desktop + 1.5*tempo_mobile + 2.0*numero_click +1.8*numero_post + 1.5*numero_share + numero_like;
        printf ("La redditività è di %f\n", redditivita);
        promessa = (tempo_desktop + tempo_mobile) /(numero_click + numero_post + numero_share + numero_like);
        printf ("Le promesse valgono %f\n", promessa);

        if (redditivita > maxredditivita1) {
            maxredditivita1 = redditivita;
            codicemaxredditivita2 = codice_utente;
        }
        else if ((redditivita < maxredditivita1) && (redditivita > maxredditivita2)) {
            maxredditivita2 = redditivita;
            codicemaxredditivita2 = codice_utente;
        }

        if (promessa > maxpromessa1) {
            maxpromessa1 = promessa;
            codicemaxpromessa1 = codice_utente;
        }
        else if ((promessa < maxpromessa1) && (promessa > maxpromessa2)) {
            maxpromessa2 = promessa;
            codicemaxpromessa2 = codice_utente;
        }
    }

    printf ("I due utenti più redditizi attualmente sono: %d e %d\n", codicemaxredditivita1, codicemaxredditivita2);
    printf ("I due utenti più promettenti attualmente sono: %d e %d\n", codicemaxpromessa1, codicemaxpromessa2);

    fclose (ifile);

    return 0;
}
