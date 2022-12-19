#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaUtenti.h"

void listaVuota (Lista *pl){
    pl->n_elementi = 0;
}

void inserimento (Lista *pl, Utenti u){
    pl->dati[pl->n_elementi] = u;
    pl->n_elementi++;
}

void aggiorna(Lista *pl, char codicefiscale[], int attività){
    int i=0;
    while (strcmp(pl->dati[i].CodiceFiscale, codicefiscale) != 0){
        i++;
    }
    if (pl->dati[i].ingressi[attività-1]!=0)
        pl->dati[i].ingressi[attività-1]-=1;
    else
        printf("Codice Fiscale %s, attività %i: Accesso negato\n", pl->dati[i].CodiceFiscale, attività);
}

void stampa (Lista l){
    for (int i=0; i<l.n_elementi; i++){
        printf ("%s: %i %i %i\n", l.dati[i].CodiceFiscale, l.dati[i].ingressi[0], l.dati[i].ingressi[1], l.dati[i].ingressi[2]);
    }
}