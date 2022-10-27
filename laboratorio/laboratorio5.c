#include <stdio.h>

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

int main(){
    float n;
    double sin=0;
    printf ("Calcola sin ");
    scanf ("%f", &n);
    for (int i=0; i<10; i++){
        sin+= (pot(-1, i)* pot(n, 2*i+1))/fact(2*i+1)*1.0;
    }
    printf ("sin: %5.3lf\n", sin);
    return 0;
}