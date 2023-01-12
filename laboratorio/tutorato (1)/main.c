#include <stdio.h>
#include <stdlib.h>
#include "listaPazienti.h"

int main(int argc, char* argv[]){
    FILE *f;
    Lista l;
    Record r;
    if (argc < 2){
        printf ("Sintassi: ./%s rilevazioni.dat\n", argv[0]);
        exit(1);
    }
    nuovaLista(&l);
    f = fopen(argv[1], "rb");
    if (f == NULL){
        printf ("Errore nell'apertura del file %s", argv[1]);
        exit (2);
    }
    while (fread(&r, sizeof(Record), 1, f)){
        aggiorna(&l, r);
    }
    fclose(f);
    //parte 2:
    eliminaValori(&l);
    stampa (l);
    return 0;
}