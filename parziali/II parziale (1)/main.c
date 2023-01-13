#include <stdio.h>
#include <stdlib.h>
#include "listaUtenti.h"

int main(int argc, char* argv[]){
    FILE *fb;
    FILE *ft;
    Lista l;
    Utenti u;
    char codicefiscale[17];
    int attività;
    if (argc != 3){
        printf ("Sintassi: %s file_binario file.txt\n", argv[0]);
        exit(1);
    }
    listaVuota(&l);
    for (int i=0; i<3; i++){
        u.ingressi[i]=4;
    }
    fb = fopen(argv[1], "rb");
    if (fb == NULL){
        printf ("Errore nell' apertura del file %s", argv[1]);
        exit(2);
    }
    while (fread(&u, 17, 1, fb)==1)
        inserimento(&l, u);
    fclose(fb);

    ft = fopen(argv[2], "rt");
    if (fb == NULL){
        printf ("Errore nell' apertura del file %s", argv[2]);
        exit(3);
    }
    while (fscanf(ft, "%s%i", codicefiscale, &attività)==2){
        aggiorna(&l, codicefiscale, attività);
    }
    fclose(ft);
    stampa (l);
    return 0;
}