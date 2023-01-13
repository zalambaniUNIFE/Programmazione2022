#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Utente u)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = u;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista l, char numero[], int durataChiamata)
{
    while (l && strcmp(l->dato.numero, numero) != 0)
        l = l->next;
    if (l->dato.pianoTariffario == 'A')
        l->dato.credito -= 0.15 +  0.08 * (int)(durataChiamata / 60.0 + 1.0);
    else
        l->dato.credito -= 0.12 / 60.0 * (float) durataChiamata;
}

void stampa(Lista l)
{
    while (l != NULL)
    {
        printf("%s %.2f\n", l->dato.numero, l->dato.credito);
        l = l->next;
    }
}