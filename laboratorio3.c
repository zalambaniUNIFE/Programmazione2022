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

void divisori_primi(int n){
    printf ("Divisori: ");
    for (int i=2; i<=n/2; i++){
        if (n%i==0 && isprimo(i))
            printf ("%d ", i);
    }
    printf ("\n");
}

int main(){
    int n;
    printf ("Inserisci un numero: ");
    scanf ("%d", &n);
    divisori_primi(n);
    return 0;
}