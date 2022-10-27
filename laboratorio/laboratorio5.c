#include <stdio.h>

float potenza(float base, int esp) {
  float cont, prod = 1.0;
  if (esp > 0){
    for (cont = 0; cont < esp; cont++)
        prod *= base;
  }
  else{
    for (cont = 0; cont < -esp; cont++)
        prod *= base;
    prod = 1.0/prod;
  }
  return prod;
}

int main(){
    float b;
    int e;
    printf ("Inserisci base e esponente: ");
    scanf ("%f%d", &b, &e);
    printf ("%0.2f^%d = %0.4f\n", b, e, potenza (b,e));
    return 0;
}