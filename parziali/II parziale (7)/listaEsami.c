#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEsami.h"

void nuovaLista (Lista* pl){
    *pl = NULL;
}

void insTesta (Lista *pl, Libretto l){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = l;
    aux->next = *pl;
    *pl = aux;
}

int compara (Lista l, Record r){
    return (r.anno > l->dato.anno ||
           (r.anno == l->dato.anno && r.mese > l->dato.mese) ||
           (r.mese == l->dato.mese && r.giorno > l->dato.giorno)) ||
           l->dato.voto < 18 && r.voto >= 18;
}

void aggiorna(Lista *pl, Record r){
    while (*pl && strcmp((*pl)->dato.nomeMateria, r.nomeMateria) != 0)
        pl = &(*pl)->next;
    if (*pl == NULL){
        Libretto l;
        strcpy (l.nomeMateria, r.nomeMateria);
        l.giorno = r.giorno;
        l.mese = r.mese;
        l.anno = r.anno;
        l.voto = r.voto;
        insTesta(pl, l);
    }
    if (compara(*pl, r)){
        (*pl)->dato.giorno = r.giorno;
        (*pl)->dato.mese = r.mese;
        (*pl)->dato.anno = r.anno;
        (*pl)->dato.voto = r.voto;
    }
}

float media (Lista l){
    float somma, totale = 0.;
    while (l != NULL){
        if (l->dato.voto >= 18){
            somma += l->dato.voto;
            totale++;
        }
        l = l->next;
    }
    return somma/totale;
}

void stampa (Lista l){
    float m;
    m = media(l);
    while (l != NULL){
        if (l->dato.voto >= 18)
            printf ("%s %i/%i/%i %i\n", l->dato.nomeMateria, l->dato.giorno, l->dato.mese, l->dato.anno, l->dato.voto);
        l = l->next; 
    }
    printf ("Media aritmetica: %.2f\n", m);
}

int somma_ponderata (Lista l, char materia[], int CFU){
    while (strcmp(l->dato.nomeMateria, materia) != 0)
        l = l->next;
    if (l->dato.voto >= 18)
        return l->dato.voto * CFU;
    else
        return 0;
}