#include <stdio.h>
#include <stdlib.h>
#include "listaGiornate.h"

int main (int argc, char* argv[]){
    FILE* f;
    Lista l;
    Record r;
    if (argc < 2){
        printf ("Sintassi: %s ore.dat\n", argv[0]);
        exit(1);
    }
    nuovaLista(&l);
    f = fopen(argv[1], "rb");
    if (f == NULL){
        printf ("Errore nell'apertura del file %s\n", argv[1]);
        exit(2);
    }
    while (fread(&r, sizeof(Record), 1, f)){
        aggiorna(&l, r);
    }
    fclose(f);
    stampa(l);
    return 0;
}