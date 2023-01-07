typedef struct utente{
    char numero[11];
    char pianoTariffario;
    float credito;
}Utente;

typedef struct nodo{
    Utente dato;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Utente u);
void aggiorna(Lista l, char numero[], int durataChiamata);
void stampa (Lista l);