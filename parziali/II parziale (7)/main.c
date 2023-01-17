#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEsami.h"

int main(int argc, char* argv[]){
    FILE* fb;
    FILE *ft;
    Lista l;
    Record r;
    char materia[50];
    int CFU, somma = 0, tot = 0;
    if (argc < 3){
        printf ("Sintassi: %s esami.dat CFU.txt\n", argv[0]);
        exit(1);
    }
    nuovaLista(&l);
    fb = fopen(argv[1], "rb");
    if (fb == NULL){
        printf ("Errore nell'aperture del file %s\n", argv[1]);
        exit(2);
    }
    while (fread(&r, sizeof(Record), 1, fb)){
        aggiorna(&l, r);
    }
    fclose(fb);
    ft = fopen(argv[2], "rt");
    if (ft == NULL){
        printf ("Errore nell'aperture del file %s\n", argv[2]);
        exit(3);
    }
    while (fscanf(ft, "%s%i", materia, &CFU) == 2){
        somma += somma_ponderata(l, materia, CFU);
        if (somma_ponderata(l, materia, CFU) != 0){
            tot += CFU;
        }
    }
    stampa(l);
    printf ("Media ponderata: %.2f\n", (float)somma/tot);
    return 0;
}