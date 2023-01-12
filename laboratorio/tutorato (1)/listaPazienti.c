#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPazienti.h"

void nuovaLista(Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Paziente p){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = p;
    aux->next = *pl;
    *pl = aux;
}

void elimTesta (Lista *pl){
    Nodo* aux = *pl;
    *pl = (*pl)->next;
    free (aux);
}

void aggiorna (Lista *pl, Record r){
    while (*pl && strcmp((*pl)->dato.codiceFiscale, r.codiceFiscale) != 0){
        pl = &(*pl)->next;
    }
    if (*pl == NULL){
        Paziente p;
        strcpy(p.codiceFiscale, r.codiceFiscale);
        p.numeroRilevazioni = 0;
        p.sumTemperatura = 0;
        p.sumSaturazione = 0;
        p.anomalia = 0;
        insTesta(pl, p);
    }
    (*pl)->dato.numeroRilevazioni++;
    (*pl)->dato.sumTemperatura += r.temperatura;
    (*pl)->dato.sumSaturazione += r.saturazione;
    if (r.temperatura > 37.5 || r.saturazione < 96)
        (*pl)->dato.anomalia = 1;
}

float media (float somma, int totale){
    return somma / (float)totale;
}

//parte2:
int annoNascita (char codicefiscale[]){
    return (codicefiscale[6] - 48) * 10 + (codicefiscale[7] - 48);
}

void eliminaValori (Lista *pl){
    while (*pl){
        if (annoNascita((*pl)->dato.codiceFiscale) >= 50 &&
           (*pl)->dato.anomalia == 0){
            elimTesta(pl);
            continue;
        }
        pl = &(*pl)->next;
    }
}

void stampa (Lista l){
    while (l!= NULL){
        printf ("%s %.1f %.1f\n", l->dato.codiceFiscale, media(l->dato.sumTemperatura, l->dato.numeroRilevazioni), 
        media(l->dato.sumSaturazione, l->dato.numeroRilevazioni));
        l = l->next;
    }
}