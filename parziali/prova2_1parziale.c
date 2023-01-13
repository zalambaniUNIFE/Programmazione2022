#include <stdio.h>

int MCD (int a, int b){
    int t, m;
    if (a<b){
        t=b;
        b=a;
        a=t;
    }
    else{
        m=1;
        for (int i=2; i<=a; i++){
            if (a%i==0){
                if (b%i==0)
                    m=i;
            }
        }
        return m;
    }
}

int main(){
    int array [10], M;
    scanf ("%d", &M);
    for (int i=1; i<=10; i++){
        array[i-1]=MCD(M,i);
    }
    for (int k=1; k<=10; k++){
        printf("MCD (%d, %d) = %d\n",M, k, array[k-1]);
    }
    return 0;
}