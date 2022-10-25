#include <stdio.h>

int cubo (int n){
    int s = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<n; j++){
            s = s+n; 
        }
    }
    return s;
}

int main(){
    int sequenza[100], M;
    printf ("Inserisci un numero tra 1 e 100: ");
    scanf("%d", &M);
    for (int i=1; i<=M; i++){
        sequenza[i] = cubo (i);
        printf ("%d ", sequenza [i]);
    }
    printf ("\n");
}