#include <stdio.h>

void divisori(int n){
    printf ("Divisori: ");
    for (int i=1; i<=n; i++){
        if (n%i==0)
            printf ("%d ", i);
    }
    printf ("\n");
}

int main(){
    int n;
    printf ("Inserisci un numero: ");
    scanf ("%d", &n);
    divisori(n);
    return 0;
}