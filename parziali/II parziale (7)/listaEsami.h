typedef struct{
    int giorno;
    int mese;
    int anno;
    char nomeMateria [50];
    int voto;
}Record;

typedef struct{
    char nomeMateria [50];
    int giorno;
    int mese;
    int anno;
    int voto;
}Libretto;

typedef struct nodo{
    Libretto dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

void nuovaLista (Lista* pl);
void aggiorna(Lista *pl, Record r);
void stampa (Lista l);
int somma_ponderata (Lista l, char materia[], int CFU);