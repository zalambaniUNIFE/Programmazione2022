typedef struct record{
    char codiceFiscale[17];
    int oraRilevazione;
    float temperatura;
    float saturazione;
}Record;

typedef struct paziente{
    char codiceFiscale[17];
    int numeroRilevazioni;
    float sumTemperatura;
    float sumSaturazione;
    //parte 2:
    int anomalia;
}Paziente;

typedef struct nodo{
    Paziente dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Paziente p);
void elimTesta (Lista *pl);
void aggiorna (Lista *pl, Record r);
float media (float somma, int totale);
int annoNascita (char codicefiscale[]);
Lista*  ricerca (Lista *pl);
void eliminaValori (Lista *pl);
void stampa (Lista l);