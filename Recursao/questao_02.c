/*2. Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...*/

#include<stdio.h>

int fibonacci(int numero);

int main(void){

	int numero;

	printf("Quantos termos deseja visualizar?");
	scanf("%d", &numero);

	int i = 0;
	printf("%d ", i);

	for(i = 0; i < numero - 1; i++){

		printf("%d ", fibonacci(i + 1));

	}
        	
	getchar();
	printf("\n");

	return 0;

}


int fibonacci(int numero){

	if (numero <= 1)
		return numero;
	return fibonacci(numero - 1) + fibonacci(numero - 2);

}

