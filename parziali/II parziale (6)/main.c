#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaNazioni.h"

int main(int argc, char* argv[]){
    FILE* f;
    Lista l;
    char primo[20];
    char secondo[20];
    char terzo[20];
    if (argc < 2){
        printf ("Sintassi: %s risultati.txt\n", argv[1]);
        exit(1);
    }
    nuovaLista(&l);
    f = fopen(argv[1], "rt");
    if (f == NULL){
        printf ("Errore nell'apertura del file %s\n", argv[1]);
        exit(2);
    }
    while(fscanf(f, "%s%s%s", primo, secondo, terzo) == 3){
        aggiorna(&l, primo, 1);
        aggiorna(&l, secondo, 2);
        aggiorna(&l, terzo, 3);
    }
    fclose(f);
    stampa(l);
    return 0;
}