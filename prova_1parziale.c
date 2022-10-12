#include <stdio.h>

int cubo (){
    int n, s;
    scanf ("%d",&n);
    s = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<n; j++){
            s = s+n; 
        }
    }
    return s;
}

int main(){
    printf ("Cubo: %d\n", cubo());
    return 0;
}