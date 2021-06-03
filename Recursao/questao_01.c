//1. Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

#include <stdio.h>
#include <stdlib.h>

int fatorial(int numero);

int main(void){

    int numero;

    puts("Informe um número");
    scanf("%d", &numero);

    printf("O fatorial de %d é %d\n", numero, fatorial(numero));

    return 0;
}

int fatorial(int numero){

    if(numero == 1)
        return 1;

    return numero * fatorial(numero - 1);
}

