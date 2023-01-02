typedef struct{
    int chip;
    char vaccino;
}Vaccino;

typedef struct{
    int chip;
    int cimurro;
    int epatite; 
    int parvovirosi;
}Cane;

typedef struct nodo{
    Cane dato;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;

void listaVuota (Lista *pl);
void insTesta(Lista *pl, Cane c);
void aggiorna(Lista *pl, Vaccino v);
void stampaMancanti(Lista l);
void stampaVaccini (Lista l);
