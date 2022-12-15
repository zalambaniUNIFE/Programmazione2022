#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCalorie.h"

void lista_vuota(Lista *pl){
    pl->n_elementi = 0;
}

void insCoda(Lista *pl, Record r){
    pl->dati[pl->n_elementi] = r;
    pl->n_elementi++;
}

float calorie100grammi(Lista l, char nome[]){
    for (int i=0; i<l.n_elementi; i++){
        if(strcmp (l.dati[i].nome, nome) == 0)
            return l.dati[i].calorie100grammi;
    }
}