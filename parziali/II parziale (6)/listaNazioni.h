typedef struct{
    char nazione[20];
    int Ori;
    int Argenti;
    int Bronzi;
}Nazione;

typedef struct nodo{
    Nazione dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

void nuovaLista (Lista* pl);
void aggiorna (Lista *pl, char nomeNazione[], int posizione);
void stampa(Lista l);