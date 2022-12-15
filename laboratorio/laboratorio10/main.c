#include <stdio.h>
#include <stdlib.h>
#include "listaCalorie.h"

int main(int argc, char* argv[]){
    FILE* fb;
    FILE* ft;
    Lista l;
    Record r;
    char nome_alimento[31];
    float quantità;
    float calorieAlimento;
    float calorieTotali=0;
    if (argc != 3){
        printf ("Uso: %s file_binario file_testo\n", argv[0]);
        exit(1);
    }
    lista_vuota(&l);
    fb = fopen(argv[1], "rb");
    if (fb == NULL){
        printf ("Errore di apertura %s\n", argv[1]);
        exit(2);
    }
    while (fread (&r, sizeof(Record), 1, fb)==1)
        insCoda(&l, r);
    fclose(fb);

    ft = fopen(argv[2], "rt");
    if (ft == NULL){
        printf ("Errore di apertura %s\n", argv[2]);
        exit(3);
    }
    while (fscanf (ft, "%s%f", nome_alimento, &quantità)==2){
        calorieAlimento = calorie100grammi(l, nome_alimento)/100*quantità;
        calorieTotali+=calorieAlimento;
    }
    fclose(ft);
    printf ("Calorie totali: %.1f\n", calorieTotali);
    return 0;
}