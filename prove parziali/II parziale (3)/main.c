#include <stdio.h>
#include <stdlib.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *fb;
    FILE *ft;
    Utente u;
    Lista l;
    char numero[11];
    int durataChiamata;
    if (argc > 3)
    {
        printf("Sintassi: ./%s utenti.dat chiamate.txt");
        exit(1);
    }
    nuovaLista(&l);
    fb = fopen(argv[1], "rb");
    if (fb == NULL)
    {
        printf("Errore di apertura del file %s", argv[1]);
        exit(2);
    }
    while (fread(&u, sizeof(Utente), 1, fb) == 1){
        insTesta(&l, u);
    }
    fclose(fb);
    ft = fopen(argv[2], "rt");
    if (ft == NULL)
    {
        printf("Errore di apertura del file %s", argv[2]);
        exit(3);
    }
    while (fscanf(ft, "%s%d", numero, &durataChiamata) == 2)
    {
        aggiorna(l, numero, durataChiamata);
    }
    fclose(ft);
    stampa(l);
    return 0;
}