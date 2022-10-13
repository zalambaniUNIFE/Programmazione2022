#include <stdio.h>

int isprimo(int n){
    int c=0;
    for (int i=2; i<=(n-1); i++){
        if (n%i==0)
            c++;
        
    }
    if (c==0)
        return 1;
    else
        return 0;
}

void fattorizzazione(int n){
    int i=2;
    printf ("Fattorizzazione: ");
    while (n!=1){
        if (n%i==0 && isprimo (i)){
            printf ("%d ", i);
            n/=i;
        }
        else
            i++;
    }
    printf ("\n");
}

int main(){
    int n;
    printf ("Inserisci un numero: ");
    scanf ("%d", &n);
    fattorizzazione(n);
    return 0;
}