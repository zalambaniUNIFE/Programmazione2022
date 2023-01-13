#include <stdio.h>

void ordina (float a[], int DL){
    float c=0.0;
    for (int i=0; i<DL; i++){
        for (int j=DL-1; j>i; j--){
            if (a[j] < a[j-1]){
                c = a[j];
                a[j] = a[j-1];
                a[j-1] = c;
            }
        }
    }
}

int main(){
    float a[50];
    int i=0, k=0;
    do{
        scanf ("%f", &a[i]);
        i++;
    }while (a[i-1] > 0);

    ordina (a,i-1);

    for (k=0; k<i-1; k++){
        printf ("%3.2f ", a[k]);
    }

    printf ("\n");

    return 0;
}