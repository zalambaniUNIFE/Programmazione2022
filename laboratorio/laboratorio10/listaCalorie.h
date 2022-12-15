#define DIM 1000

typedef struct{
    char nome[30];
    float calorie100grammi;
}Record;

typedef struct{
    Record dati [DIM];
    int n_elementi;
}Lista;

void lista_vuota(Lista *pl);

void insCoda(Lista *pl, Record r);

float calorie100grammi(Lista l, char nome[]);