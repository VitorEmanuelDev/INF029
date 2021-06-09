/* 17. O fatorial quádruplo de um número N é dado por (2n)!/n!
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
fatorial quádruplo desse número.*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor);

int quadruplica(int valor);

int main(void){

    int valor;

    printf("Informe um valor");
    scanf("%d", &valor);

    printf("2(%d)! / %d! = %d", valor, valor, quadruplica(valor));

    return 0;
}

int quadruplica(int valor){

    return fatorial(valor * 2)/fatorial(valor);
}

int fatorial(int valor){

    if(valor == 1)
        return 1;

    return valor * fatorial(valor - 1);
}

