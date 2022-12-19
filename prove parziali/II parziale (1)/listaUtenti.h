#define DIM 1000

typedef struct{
    char CodiceFiscale[17];
    int ingressi [3];
}Utenti;

typedef struct{
    Utenti dati[DIM];
    int n_elementi;
}Lista;

void listaVuota (Lista *pl);

void inserimento (Lista *pl, Utenti u);

void aggiorna(Lista *pl, char codicefiscale[], int attività);

void stampa (Lista l);