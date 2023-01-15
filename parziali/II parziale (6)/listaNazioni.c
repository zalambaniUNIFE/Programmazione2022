#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaNazioni.h"

void nuovaLista (Lista* pl){
    *pl = NULL;
}

void insTesta (Lista* pl, Nazione n){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = n;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna (Lista *pl, char nomeNazione[], int posizione){
    while(*pl && strcmp((*pl)->dato.nazione, nomeNazione) != 0){
        pl = &(*pl)->next;
    }
    if (*pl == NULL){
        Nazione n;
        strcpy(n.nazione, nomeNazione);
        n.Ori = 0;
        n.Argenti = 0;
        n.Bronzi = 0;
        insTesta(pl, n);
    }
    if (posizione == 1)
        (*pl)->dato.Ori++;
    else if (posizione == 2)
        (*pl)->dato.Argenti++;
    else
        (*pl)->dato.Bronzi++;
}

int precede (Nazione n1, Nazione n2){
    return n1.Ori > n2.Ori ||
           (n1.Ori == n2.Ori && n1.Argenti > n2.Argenti) ||
           (n1.Argenti == n2.Argenti && n1.Bronzi > n2.Bronzi);
}

void ordina(Lista *pl, Nazione n){
    while (*pl != NULL && precede((*pl)->dato, n) > 0)
        pl = &(*pl)->next;
    insTesta(pl, n);
}

void stampa(Lista l){
    Lista lOrd;
    nuovaLista(&lOrd);
    while (l != NULL){
        ordina(&lOrd, l->dato);
        l = l->next;
    }
    while (lOrd != NULL){
        printf ("%s: %i ori, %i argenti, %i bronzi\n", lOrd->dato.nazione, lOrd->dato.Ori, lOrd->dato.Argenti, lOrd->dato.Bronzi);
        lOrd = lOrd->next;
    }
}