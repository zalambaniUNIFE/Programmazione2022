#include <stdio.h>

void maiuscolo(){
    char c;
    while(c!='\n'){
        scanf ("%c", &c);
        if (c>96 && c<122)
            printf("%c", c-32);
        else
            printf ("%c", c);
    }
}

void radice(){
    float n, x=1;
    scanf ("%f", &n);
    for (int i=0; i<10; i++){
        x = (x+n/x)/2.0;
    }
    printf ("radice approssimata: %5.3f\n", x);
}

float pot(float n, float esp){
    float pot=1;
    for (int i=0; i<esp; i++)
        pot*=n;
    return pot;
}

long long int fact(int n){
    long long int fact=1;
    for (int i=2; i<n+1; i++)
        fact*=i;
    return fact;
}

void Taylor(){
    float n;
    double sin=0;
    printf ("Calcola sin ");
    scanf ("%f", &n);
    for (int i=0; i<10; i++){
        sin+= (pot(-1, i)* pot(n, 2*i+1))/fact(2*i+1)*1.0;
    }
    printf ("sin: %5.3lf\n", sin);
}

int main(){
    //maiuscolo();
    radice();
    //Taylor();
    return 0;
}