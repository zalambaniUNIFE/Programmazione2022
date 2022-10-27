#include <math.h>
#include <stdio.h>

float media (float a, float x){
    return ((a + x)/2.0);
}

float radq (float a){
    float x = 1.0;
    while (fabsf(x * x - a) > 1e-5)
        x = media (x, a / x);
    return x;
}

int main(void) {
  float a, x;
  printf("Digita un numero: ");
  scanf("%f", &a);
  if (a < 0) {
    printf("%.2f e` negativo\n", a);
    return -1;
  }
  printf("La radice quadrata di %.2f e` circa %.4f\n", a, radq(a));
  return 0;
}