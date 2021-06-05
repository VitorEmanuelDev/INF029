/* 16. A função fatorial duplo é definida como o produto de todos os números naturais
ímpares de 1 até algum número natural ímpar N.
Assim, o fatorial duplo de 5 é
5!! = 1 * 3 * 5 = 15
Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o
fatorial duplo desse número.*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(void){

    int n;

    puts("Informe um número");
    scanf("%d", &n);

    printf("%d!! = %d", n, fatorial(n));

    return 0;
}

int fatorial(int n){

    if(n == 1)
        return 1;

    if(n % 2 != 0)
        return n * fatorial(n - 1);

    return fatorial(n - 1);
}

