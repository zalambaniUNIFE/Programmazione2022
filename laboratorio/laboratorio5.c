#include <stdio.h>

int PI (int n){
    int c = 0, count = 0;
    for (int k=2; k<=n; k++){
        c = 0;
        for (int i=2; i<k-1; i++){
            if (k%i == 0)
                c++;
        }
        if (c == 0)
            count++;
    }
    return count;
}

int main(){
    int n;
    printf ("Inserisci un numero >= 1: ");
    scanf ("%d", &n);
    printf ("Π(%d) = %d\n", n, PI(n));
    return 0;
}