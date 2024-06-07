// ****************************************************** MATTEO ZERBI ***************************************************** //

// Metodo PERSONALE per la risoluzione e il miglioramento del progetto.
// Struttura del progetto: (dall'alto verso il basso)
// - nella prima parte otterrai il codice sbagliato e sara'a reso tutto un commmento
// - nella seconda parte, troverai il codice giusto e migliorato 
// - nella terza parte otterai tutte le spiegazioni e le 'risposte' alle domande richieste nella traccia

// ***************************************************** PRIMA PARTE ******************************************************
/*
#include <stdio.h>

void menu ();
void moltiplica ();
void dividi ();
void ins_string();


int main () 

{
	char scelta = {'\0'};
	menu ();
	scanf ("%d", &scelta);

	switch (scelta)
	{
		case 'A':
		moltiplica();
		break;
		case 'B':
                dividi();
                break;
		case 'C':
                ins_string();
                break;
	}

return 0;

}


void menu ()
{
	printf ("Benvenuto, sono un assitente digitale, posso aiutarti a sbrigare alcuni compiti\n");
	printf ("Come posso aiutarti?\n");
	printf ("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\n");

}


void moltiplica ()
{
	short int  a,b = 0;
	printf ("Inserisci i due numeri da moltiplicare:");
	scanf ("%f", &a);
	scanf ("%d", &b);

	short int prodotto = a * b;

	printf ("Il prodotto tra %d e %d e': %d", a,b,prodotto);
}


void dividi ()
{
        int  a,b = 0;
        printf ("Inserisci il numeratore:");
        scanf ("%d", &a);
	printf ("Inserisci il denumeratore:");
        scanf ("%d", &b);

        int divisione = a % b;

        printf ("La divisione tra %d e %d e': %d", a,b,divisione);
}





void ins_string () 
{
	char stringa[10];
        printf ("Inserisci la stringa:");
        scanf ("%s", &stringa);
}
*/

// **************************************************** SECONDA PARTE *****************************************************

#include <stdio.h>

void menu();
void moltiplica();
void dividi();
void ins_string();

int main() {
    char scelta = '\0'; // tolto le parentesi graffe {} perche non servono 

    //ho gestito meglio l'identezione anche se facoltativo
    //Costruito un do while che forza l'utilizzo dei 3 caratteri, se viene scelto un'altro carattere, ripropone la domanda
    do {
        menu();
        scanf(" %c", &scelta); // Assicurati di includere uno spazio prima di %c per consumare eventuali newline lasciati da input precedenti
        // ho incluso uno spazio prima di %c per consumare eventuali newline lasciati da input precedenti (si fermerebbe il programma)
        // inoltre ho cambiato %d con %c perche non stiamo lavorando con int ma con char.

        switch(scelta) {
            case 'A':
                moltiplica();
                break;
            case 'B':
                dividi();
                break;
            case 'C':
                ins_string();
                break;
            case 'D':
                printf("\nUscita dal programma.\n");
                return 0;  // Uscita dal programma
            default:
                printf("\nScelta non valida. Riprova.\n");
                continue; // Ripresa del programma fino a quando non scegliera' la giusta lettera
        }
    } while (1); // crea un loop infinito


    return 0;
}

void menu() {
    printf("Benvenuto, sono un assistente digitale, posso aiutarti a sbrigare alcuni compiti\n");
    printf("Come posso aiutarti?\n");
    printf("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\nD >> Uscire dal programma\n");
}

void moltiplica() {
    short int a=0, b=0; // inizializiamo entrambi
    printf("Inserisci i due numeri da moltiplicare: ");
    scanf(" %hd %hd", &a, &b); //usiamo %hd perche sono 'short int' e rendiamo un tutt'uno lo scanf

    short int prodotto = a * b;
    printf("\nIl prodotto tra %d e %d e': %d\n", a, b, prodotto);
}

void dividi() {
    int a=0, b=0;
    printf("Inserisci il numeratore: ");
    scanf(" %d", &a);
    
    //Impediamo la divisione per zero
    do { //esegue il codice, e viene superato questo loop se e solo se, 'b != 0' !!!
        printf("Inserisci il denominatore (diverso da zero): ");
        scanf(" %d", &b);
        if (b == 0) {
            printf("Scegli un numero diverso da zero.\n");
        }
    } while (b == 0);
    int divisione = a/b;
    printf("\nLa divisione tra %d e %d e' uguale a: %d\n",a,b,divisione);
}

void ins_string() {
    char stringa[256]; // Aumentato la dimensione dell'array per evitare problemi di overflow
    printf("Inserisci la stringa: ");
    scanf(" %255[^\n]", stringa); // Legge fino a 99 caratteri o fino a un newline, evitando overflow del buffer
    printf("\nHai inserito: %s\n", stringa);
}


// ****************************************************** TERZA PARTE *******************************************************

/*
* 1) Cosa fa questo programma?
*
* Questo programma fa da assistente digitale, aiuta lo svolgimento di semplici operazioni matematiche, tramite input
* ed output con l'user.
* Inoltre semplifica l'aggiunta di una stringa.
*
* 2) Quali sono le casistiche non standard che il programma non gestisce?
*
* Ne ho individuate alcune:
* -Nella funzione 'menu' non si fa ricorso in caso venga scelto un carattere differente da 'A','B','C', se l'utente inserira'
*  un carattere differente, il programma si fermera e non fara' assolutamente nulla.
* -Nella funzione 'dividi' non c'e il controllo della divisione per zero, il che se l'utente sceglie 0 come denominatore
*  il programma dara' errore di 'runtime' (termina il programma inaspettatamente).
* -Nella funzione 'ins_string' non si e' tenuto conto dell'overflow da parte dell'input, cioe il sovraccarico in caso l'user
*  scriva una stringa piu' lunga di 10 caratteri; se viene eseguito, puo dare errori di memoria, puo' crasha il programma.
* -Inoltre ho pensato che il programma non debba finire una volta esguito uno dei 3 'metodi' pertanto ho costruito un ciclo do while che
*  faccia eseguire il programma fino a quando l'user scegliera' la lettera D per forzare l'uscita.
*  In poche parole aggiungo una quarta opzione per forzare l'uscita dal programma
*
* 3) Quali sono gli errori di sintassi e logici di questo programma:
*     (partendo dall'alto verso il basso)
*  1) Nella funzione main, lam definizione del carattere scelta, e' sbagliata:
*     char scelta = {'\0'}; e' un errore di sisntassi, le parentesi non servono, la versione aggiustata -->
*     --> char scelta = '\0' (che tra l'altro e' fondamentale per l'inizializzazione di un carattere)
*  2) Sempre nella funzione main, dentro allo 'scanf' c'e' un errore logico '%d' sbagliato perche' non sta lavorando con
*     gli interi ma con i caratteri, versione corretta --> scanf(" %c",&scelta)
*  3) Dentro allo switch ci sono vari errori sull'identazione, ma sono relativi, non danno errori dato che nel C, l'utilizzo delle
*     parentesi graffe {}, abbona l'identazione, ma per una buona condotta del codice, sistemarli rende piu' pulito e leggibile il
*     programma. 
*     Anche in altre zone ci sono altri problemi di identazione, le correggo senza specificarle uno ad uno, le sottointendo
*  4) Dentro alla funzione 'moltiplica' ci sono due errori:
*     -uno sull'inizializzazione delle varibili 'a' e 'b', il codice scritto cosi:
*      "short int a,b = 0;" inizializza solo la variabile b, mentre il giusto metodo per inizializzare entrambi e': -->
*      --> short int a=0,b=0;
*     -un'errore di logica nei 2 scanf, in particolare ne '%f' ne '%d' vanno bene perche' stiamo lavorando con gli 'short int' e quindi il
*      giusto "simbolo" e' '%hd', codice corretto per entrambi -->
*      --> "scanf (" %hd", &a);" e "scanf (" %hd", &b);"
*  5) nella funzione 'Divisione' abbiamo 2 errori di logica:
*     -uno nel commento "Inserisci il denominatore:" c'era scritto 'denumeratore'... che lingua e'? :)
*     -uno nella sisntassi della divisione tra a e b, c'era scritto a % b, quando invece l'operatore aritmentico giusto e' '/'
*      Codice corretto: -->   "int divisione = a / b;"
*  6) Infine nella Funzione 'ins_string', abbiamo anche qui un errore di logica nello 'scanf', c'era scritto "scanf (" %s", &stringa);" mentre 
*     '&' non ci vuole in questo caso perche' il nome dell'array di stringe e' gia' un indirizzo di memoria e non serve "richiamarlo", quindi
*     il codice corretto e' "scanf (" %s", stringa);"
*
* 4) Come risolverai il programma? 
*  1) Correzione degli errori di sisntassi e logici
*  2) Aggiunta pezzi di codici 'standard' per migliorare il programma
*   
*
*
*/