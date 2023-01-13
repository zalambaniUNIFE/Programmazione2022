#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaVeicoli.h"

void nuovaLista (Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Veicolo v){
    Nodo* aux = malloc(sizeof(Nodo));
    aux->dato = v;
    aux->next = *pl;
    *pl = aux; 
}

void aggiorna (Lista *pl, char targa[]){
    while (*pl && strcmp((*pl)->dato.targa, targa) != 0){
        pl = &(*pl)->next;
    }
    if (*pl == NULL){
        Veicolo v;
        strcpy(v.targa, targa);
        v.n_accessi = 0;
        insTesta(pl, v);
    }
    (*pl)->dato.n_accessi++;
}

float importoDovuto(int n_accessi){
    if (n_accessi <= 5)
        return n_accessi * 2.00;
    else if (n_accessi >= 6 && n_accessi <= 10)
        return n_accessi * 1.90;
    else if (n_accessi > 10)
        return n_accessi * 1.80;
}

void stampa (Lista l){
    while (l!=NULL){
        printf ("%s %.2f\n", l->dato.targa, importoDovuto(l->dato.n_accessi));
        l = l->next;
    }
}