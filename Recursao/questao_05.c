//5. Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.

#include<stdio.h>

int soma(int numero);


int main(void){

	int numero;

	printf("Informe um número:\n");
	scanf("%d", &numero);

	int resultado = soma(numero);

	printf("\n");
	printf("%d", resultado);

	return 0;

}


int soma(int numero){

	if(numero > 0){

		return numero + soma(numero - 1);

	}else{

		return 0;

	}

}

