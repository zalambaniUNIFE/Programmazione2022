#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

void listaVuota (Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Cane c){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = c;
    aux->next = *pl;
    *pl = aux; 
}

void aggiorna(Lista *pl, Vaccino v){
    while (*pl && (*pl)->dato.chip != v.chip)
        pl = &(*pl)->next;
    if (*pl == NULL){
        Cane c;
        c.chip = v.chip;
        c.cimurro = 0;
        c.epatite = 0;
        c.parvovirosi = 0;
        insTesta(pl, c);
    }
    if (v.vaccino == 'C')
        (*pl)->dato.cimurro = 1;
    else if (v.vaccino == 'E')
        (*pl)->dato.epatite = 1;
    else
        (*pl)->dato.parvovirosi = 1;
}

void stampaMancanti(Lista l){
    while (l != NULL){
        printf ("%i: ", l->dato.chip);
        if (l->dato.cimurro == 0)
            printf ("cimurro ");
        if (l->dato.epatite == 0)
            printf ("epatite ");
        if (l->dato.parvovirosi == 0)
            printf ("parvovirosi");
        printf ("\n");
        l = l->next;
    }
}

int precede (Cane c1, Cane c2){
    return c1.cimurro + c1.epatite + c1.parvovirosi >
        c2.cimurro + c2.epatite + c2.parvovirosi ||
        c1.cimurro + c1.epatite + c1.parvovirosi ==
        c2.cimurro + c2.epatite + c2.parvovirosi &&
        c1.chip < c2.chip;
}

void insOrd (Lista *pl, Cane c){
    while (*pl && precede((*pl)->dato, c))
        pl = &(*pl)->next;
    insTesta(pl, c);
}

void stampaVaccini (Lista l){
    FILE *f;
    Lista lOrd;
    listaVuota(&lOrd);
    while (l != NULL){
        insOrd(&lOrd, l->dato);
        l = l->next;
    }
    f = fopen("vaccinati.txt", "wt");
    if (f == NULL){
        printf ("Errore nell'apertura del file vaccinati.txt\n");
        exit (3);
    }
    while (lOrd){
        fprintf(f,"%d (%d v.)\n", lOrd->dato.chip,
        lOrd->dato.cimurro + lOrd->dato.epatite + lOrd->dato.parvovirosi);
        lOrd = lOrd->next;
    }
    fclose(f);
}