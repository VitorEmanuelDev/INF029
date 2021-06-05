/* 15. Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem decrescente.*/

#include <stdio.h>
#include <stdlib.h>

void decrescente(int n);

int main(void){

    int n;

    printf("Informe um número:");
    scanf("%d", &n);

    decrescente(n);

    return 0;
}

void decrescente(int n){

    if(n >= 0){

    	if(n % 2 == 0)
    		printf("%d ", n);

    	crescente(n - 1);

    }

}

