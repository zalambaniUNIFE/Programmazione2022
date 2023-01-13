typedef struct{
    int giorno;
    int mese;
    float ore;
    char attivita [30];
}Record;

/*typedef struct{
    int giorno;
    int mese;
    float contaOre;
}Giornate;*/

typedef struct nodo{
    Record dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista *pl);
void aggiorna (Lista *pl, Record a);
void stampa (Lista l);