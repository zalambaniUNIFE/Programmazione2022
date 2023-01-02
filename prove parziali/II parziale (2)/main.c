#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

int main(int argc, char *argv[]){
    FILE *f;
    Lista l;
    Vaccino v;
    if (argc < 2){
        printf ("Sintassi: ./%s file.dat", argv[0]);
        exit(1);
    }
    listaVuota(&l);
    f = fopen(argv[1], "rb");
    if (f == NULL){
        printf("Errore nell'apertura del file %s", argv[1]);
        exit (2);
    }
    while (fread(&v, sizeof(Vaccino), 1, f) == 1){
        aggiorna(&l, v);
    }
    fclose(f);
    stampaMancanti(l);
    stampaVaccini(l);
    return 0;
}