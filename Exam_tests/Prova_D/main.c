/* L'impiccato è un gioco di carta e matita per due giocatori.
Uno dei giocatori sceglie segretamente una parola; l'altro deve indovinarla.
Il giocatore che sceglie la parola disegna una riga tratteggiata, con un tratto per ogni lettera della parola.
L'altro tenta di indovinare la parola dichiarando una lettera a ogni turno.
Se la lettera compare nella parola, il giocatore che ha scelto la parola trascrive la lettera su tutti i trattini corrispondenti.
Se la lettera non è presente, il giocatore che ha scelto la parola traccia una linea del diagramma dell'impiccato.
Il gioco termina quando la parola viene indovinata, o viene completato il diagramma dell'impiccato.

Si vuole realizzare un programma che aiuti il giocatore che deve indovinare la parola segreta.
Tale programma riceve due parametri da linea di comando:
1) il nome di un file contenente un dizionario
2) l'attuale parola segreta con il carattere '_' (underscore) al posto delle lettere mancanti.

Il file contiene una parola per riga e non è noto il numero delle righe; le parole sono lunghe al massimo 35 caratteri
e non è possibile assumere alcun ordinamento nel suo contenuto (ovvero le parole NON sono in ordine alfabetico).

Il programma dovrà fornire un suggerimento:
1) estraendo dal dizionario prima parola compatibile in ordine alfabetico e stampandola a video
2) indicando quante altre possibili soluzioni potrebbero essere corrette considerato lo stato attuale
3) eventualmente rispondendo con "nessun suggerimento".
Esempio di dizionario:
limone leone lembo lontra lampo

#include <stdio.h>
#include <stdlib.h>
#define MAXPAROLA 35

int main(int argc, char *argv[2])
{
    int i=0;
    char parola[36];
    FILE *ifile;

    argv[1] = "dizionario.dat";
    ifile = fopen(argv[1], "r");
    if (ifile == NULL) {
        printf ("Errore nell'apertura del file\n");
        return EXIT_FAILURE;
    }
    printf ("Inserisci parola: \n");
    while (scanf("%c", &parola[i]) != ' ') {
        i++;
    };




    fclose (ifile);

    return 0;
} */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH	35

int is_compatible(char *pattern, char *word);

int main(int argc, char *argv[])
{
	char pattern[MAX_WORD_LENGTH +1];

	// check commandline
	if(argc != 3) {
		fprintf(stderr, "USAGE: %s dict_file pattern\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	strcpy(pattern, argv[2]);

	// Read & check dict
	FILE *dict = fopen(argv[1], "r");
	if(dict == NULL) {
		fprintf(stderr, "ERROR: Can't open dictionary file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char word[MAX_WORD_LENGTH +1];
	char best_word[MAX_WORD_LENGTH +1] = "";
	int num_alternatives = 0;
	while(fscanf(dict, "%s", word) != EOF) {
		if(is_compatible(pattern, word)) {
			num_alternatives += 1;
			if(best_word[0] == '\0' || strcmp(best_word, word) > 0) {
				strcpy(best_word, word);
			}
		}
	}
	fclose(dict);
	printf("%s - %d combinazioni\n", best_word, num_alternatives);

	// Check pattern
	return EXIT_SUCCESS;
}

int is_compatible(char *pattern, char *word)
{
	int flag = 1;
	if(strlen(pattern) != strlen(word)) {
		flag = 0;
	}
	for(int t = 0; pattern[t] != '\0'; ++t) {
		if(pattern[t] != word[t] && pattern[t] != '_') {
			flag = 0;
		}
	}
	return flag;
}
