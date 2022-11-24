#include <stdio.h>

typedef struct{
    long int num;
    long int den;
}Frazione;

Frazione frazione(int n, int d){
    Frazione f;
    f.num = n;
    f.den = d;
    return f;
}

Frazione dividi (int a, int b){
    Frazione n;
    for (int i=2; i<b; i++){
        if (a%i == 0 && b%i == 0){
            a/=i;
            b/=i;
            i = 1;
        }
    }
    n.num = a;
    n.den = b;
    return n;
}

Frazione somma(int n1, int n2, int d1, int d2){
    Frazione s;
    if (d1 != d2){
        s.num = n1*d2 + n2*d1;
        s.den = d1*d2;
    }
    else{
        s.num = n1 + n2;
        s.den = d1;
    }
    return s;
}

Frazione sottrazione(int n1, int n2, int d1, int d2){
    Frazione s;
    if (d1 != d2){
        s.num = n1*d2 - n2*d1;
        s.den = d1*d2;
    }
    else{
        s.num = n1 - n2;
        s.den = d1;
    }
    return s;
}

Frazione moltiplicazione(int n1, int n2, int d1, int d2){
    Frazione s;
    s.num = n1 * n2;
    s.den = d1 * d2;
    return s;
}

Frazione divisione(int n1, int n2, int d1, int d2){
    Frazione s;
    s.num = n1 * d2;
    s.den = d1 * n2;
    return s;
}

int main(){
    Frazione a, b, n;
    int c, i=0, cont=0;
    char s[50];
    printf ("Inserisci l'operazione da eseguire tra frazioni positive: ");
    scanf ("%s", s);
    while (s[i]!='/'){
        if (cont == 0)
            a.num = s[i] - 48;
        else{
            a.num *= 10;
            a.num += (s[i] - 48); 
        }
        i++;
        cont++;
    }

    i++;
    cont = 0;

    while (s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!=':'){
        if (cont == 0)
            a.den = s[i] - 48;
        else{
            a.den *= 10;
            a.den += (s[i] - 48); 
        }
        i++;
        cont++;
    }

    i++;
    cont = 0;    

    while (s[i]!='/'){
        if (cont == 0)
            b.num = s[i] - 48;
        else{
            b.num *= 10;
            b.num += (s[i] - 48); 
        }
        i++;
        cont++;
    }

    i++;
    cont = 0;

    while (s[i]!='\0'){
        if (cont == 0)
            b.den = s[i] - 48;
        else{
            b.den *= 10;
            b.den += (s[i] - 48); 
        }
        i++;
        cont++;
    }

    i = 0;

    if (a.den == 0 || b.den == 0){
        printf ("Indefinito\n");
    }
    else{
        while (s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!=':'){
            if (s[i+1] == '+'){
                n = somma(a.num, b.num, a.den, b.den);
            }
            else if (s[i+1] == '-'){
                n = sottrazione(a.num, b.num, a.den, b.den);
            }
            else if (s[i+1] == '*'){
                n = moltiplicazione(a.num, b.num, a.den, b.den);
            }
            else
                n = divisione(a.num, b.num, a.den, b.den);
            i++;
        }
        
        if (n.den > n.num){
            n = dividi (n.num, n.den);
        }
        else{
            n = dividi (n.den, n.num);
            c = n.num;
            n.num = n.den;
            n.den = c;
        }
        printf ("Formato frazionario: %i/%i\n", n.num, n.den);
        printf ("Formato decimale: %f\n", n.num*1.0/n.den*1.0);
    }
    return 0;
}