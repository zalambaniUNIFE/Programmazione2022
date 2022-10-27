#include <stdio.h>

int giorno_giuliano(int G, int M, int A){
    int JD=0, N0, N1, N2, N3;
    N0 = (M-14)/12;
    N1 = (1461*(A+4800+N0))/4;
    N2 = (367*(M-2-12*N0))/12;
    N3 = (3*(A+4900+N0))/400;
    JD = N1 + N2 - N3 + G - 32075;
    return JD;
}

int main(){
    int G, M, A, JD=0, giorno;
    printf ("Inserisci giorno, mese, anno: ");
    scanf ("%d %d %d", &G, &M, &A);
    JD = giorno_giuliano(G, M, A);
    giorno = JD % 7;
    printf ("Era ");
    switch (giorno){
        case 0:
            printf ("lunedi'\n");
            break;
        case 1:
            printf ("martedi'\n");
            break;
        case 2:
            printf ("mercoledì'\n");
            break;
        case 3:
            printf ("giovedi'\n");
            break;
        case 4:
            printf ("venerdi'\n");
            break;
        case 5:
            printf ("sabato\n");
            break;
        case 6:
            printf ("domenica\n");
    }
    return 0;
}