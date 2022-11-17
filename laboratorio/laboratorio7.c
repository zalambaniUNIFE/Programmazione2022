#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

float min(int DIM, float a[]){
    float min = 99999;
    for (int k=0; k<DIM; k++){
        if (abs(a[k]) < min){
            min = a[k];
        }
    }
    return min;
}

float max(int DIM, float a[]){
    float max = -999999;
    for (int k=0; k<DIM; k++){
        if (abs(a[k]) > max){
            max = a[k];
        }
    }
    return max;
}

float media(float DIM, float a[]){
    float s;
    for (int i=0; i<DIM; i++){
        s+=a[i];
    }
    return s/DIM;
}

float frequenza (int DIM, float a[] ){
    int c = 0; 
    float freq[DIM], max = -999999, moda;
    for (int i=DIM; i>0; i--){
        for (int k=0; k<DIM ; k++){
            if (a[i] == a[k]){
                c++;
            }
        }
        if (c > max){
            max = c;
            moda = a[i];
        }
        c = 0;
    }
    return moda;
}

void minimo(){
    float a[5];
    printf ("Inserisci 5 numeri reali: ");
    for (int i=0; i<5; i++){
        scanf("%f", &a[i]);
    }
    printf ("Il minimo in valore assoluto è: |%0.2f|\n", min(5, a));
}

void statistiche(){
    int i = 0;
    float a[N], n;
    do{
        scanf("%f", &n);
        if (n > 0){
            a[i] = n;
            i++;
        }
    }while (n > 0);
    printf ("Il massimo è: %0.2f\n", max(i-1, a));
    printf ("Il minimo è: %0.2f\n", min(i-1, a));
    printf ("La media è: %0.2f\n", media(i-1, a));
    printf ("La moda è: %0.2f\n", frequenza(i-1, a));
}

void contiene(){
    int i=0, k=0, c=0, j;
    char s1[N], s2[N];
    printf ("Inserisci due parole: ");
    scanf ("%s", s1);
    scanf ("%s", s2);
    while (s1[i] != '\0'){
        if (s1[i] == s2[0]){
            j = i;
            while (s2[k] != '\0'){
                if (s1[j]==s2[k]){
                    c++;
                    k++;
                }
                j++;
            }
        }
        i++;
    }
    if (c == strlen(s2))
        printf ("'%s' è contenuta in '%s'\n", s2, s1);
    else
        printf ("'%s' NON è contenuta in '%s'\n", s2, s1);
}

void link_meet(){
    char s[12];
    srand(time(NULL));
    for (int i=0; i<12; i++){
        if (i != 3 && i != 8){
            s[i] = (rand() % 26) + 97;
        }
        else
            s[i]='-';
    }
    printf ("\nNuova riunione: https://meet.google.com/%s\n", s);
}

int main(){
    //minimo();
    //statistiche();
    //contiene();
    link_meet();
    return 0;
}