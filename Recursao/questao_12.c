/*12.Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

void crescente(int n);

int main(void){

    int n;

    printf("Informe um número:");
    scanf("%d", &n);

    crescente(n);

    return 0;
}

void crescente(int n){

    if(n >= 0){

    	crescente(n - 1);
    	printf("%d ", n);

    }

}

