#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaVeicoli.h"

#define N_ULTIME 3

int main(int argc, char* argv[]){
    FILE* f;
    Lista l;
    Accesso a;
    int i;
    char t[8];
    char ultimetarghe[N_ULTIME][8] = {""};
    if (argc < 2){
        printf ("Sintassi: ./%s accessi.dat\n", argv[0]);
        exit(1);
    }
    f = fopen(argv[1], "rb");
    if (f == NULL){
        printf ("Errore nell'apertura del file %s\n", argv[1]);
        exit(2);
    }
    nuovaLista(&l);
    while (fread(&a, sizeof(Accesso), 1, f)==1){
        aggiorna(&l, a.targa);
        strcpy(t, a.targa);
        i = 0;
        do{
            char temp[8];
            strcpy(temp, t);
            strcpy (t, ultimetarghe[i]);
            strcpy(ultimetarghe[i], temp);
            i++;
        }while (i < N_ULTIME && strcmp(t, ultimetarghe[0]) != 0);
    }
    fclose(f);
    stampa(l);
    f = fopen("ultimi3.txt", "wt");
    if (f == NULL){
        printf ("Errore nell'apertura del file ultimi3.txt\n");
        exit(3);
    }
    for (i=0; i<N_ULTIME; i++){
        fprintf(f,"%s\n", ultimetarghe[i]);
    }
    fclose(f);
    return 0;
}