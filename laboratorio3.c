#include <stdio.h>

int is1MCD(int n, int m){
    int c=0;
    for (int i=1; i<=n; i++){
        if (n%i==0 && m%i==0)
            c++;
    }
    if (c==1)
        return 1;
    else
        return 0;
}

void terne_pitagoriche(int ipotenusa){
    int a, b, c=0, m=1;
    printf ("Terne piatagoriche:\n");
    do{
        m++;
        for (int n=m-1; n<m; n++){
            if (is1MCD(n,m)){
                a=m*m-n*n;
                b=2*m*n;
                c=m*m+n*n;
                if (c>ipotenusa)
                    break; 
                printf ("%d %d %d \n", a, b, c);
            }
        }
    }while (c<=ipotenusa);
}

int main(){
    int n;
    printf ("Inserisci ipotenusa: ");
    scanf ("%d", &n);
    terne_pitagoriche(n);
    return 0;
}