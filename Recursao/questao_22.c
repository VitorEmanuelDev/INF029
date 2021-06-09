/*22. Os números tetranacci iniciam com quatro termos pré-determinados e a partir daí
todos os demais números são obtidos pela soma dos quatro números anteriores. Os
primeiros números tetranacci são: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208...
Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
sequência de tetranacci.*/

#include<stdio.h>

int tetranacci(int numero);

int main(void){

	int numero;

	printf("Quantos termos deseja visualizar?");
	scanf("%d", &numero);

	int i = 0;

	for(i = 0; i < numero - 1; i++){

		printf("%d ", tetranacci(i + 1));

	}

	getchar();
	printf("\n");

	return 0;

}


int tetranacci(int numero){

	if (numero == 0 || numero == 1 || numero == 2 || numero == 3)
	        return 0;
	if (numero == 4)
	        return 1;
	else
		return tetranacci(numero - 1) + tetranacci(numero - 2) + tetranacci(numero - 3) + + tetranacci(numero - 4);

}

