#include <stdio.h>

float radice3(float y){
    float a=1.0, b=y, x;
    do{
        x = (a+b)/2.0;
        if (x*x*x > y)
            b = x;
        else
            a = x;
    }while ((b-a) > 1/100000.0);
    return x;
}

int main(){
    int c=0, j=0;
    float a[10], b[10];
    printf ("Inserisci 10 numeri reali: ");
    for (int i=0; i<10; i++){
        scanf ("%f", &a[i]);
    }
    for (int k=0; k<10; k++){
        if (a[k] > 1.0){
            b[c] = radice3(a[k]);
            c++;
        }
    }
    while (b[j]!='\0'){
        printf ("%1.3f ", b[j]);
        j++;
    }
    printf ("\n");
    return 0;
}