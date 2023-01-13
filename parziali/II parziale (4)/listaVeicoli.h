typedef struct accesso{
    char targa[8];
    float durata;
}Accesso;

typedef struct veicolo{
    char targa[8];
    int n_accessi;
}Veicolo;

typedef struct nodo{
    Veicolo dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

void nuovaLista (Lista *pl);
void insTesta(Lista *pl, Veicolo v);
void aggiorna (Lista *pl, char targa[]);
float importoDovuto(int n_accessi);
void stampa (Lista l);