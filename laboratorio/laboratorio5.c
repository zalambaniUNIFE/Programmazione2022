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

int main(){
    printf ("Inserisci frase: ");
    maiuscolo();
}