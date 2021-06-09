/* 18. O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais
de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
superfatorial desse número.*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor);

int super(int valor);

int main(void){

    int valor;

    printf("Informe um valor");
    scanf("%d", &valor);

    printf("super fatorial de %d = %d\n", valor, super(valor));

    return 0;
}

int super(int valor){

    if(valor == 1)
        return 1;

    return fatorial(valor) * super(valor - 1);
}

int fatorial(int valor){

    if(valor == 1)
        return 1;

    return valor * fatorial(valor - 1);
}

