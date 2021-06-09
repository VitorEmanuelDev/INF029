/*21. Os números tribonacci são definidos pela seguinte recursão
Faça uma função recursiv*/
#include<stdio.h>

int tribonacci(int numero);

int main(void){

	int numero;

	printf("Quantos termos deseja visualizar?");
	scanf("%d", &numero);

	int i = 0;

	for(i = 0; i < numero - 1; i++){

		printf("%d ", tribonacci(i + 1));

	}

	getchar();
	printf("\n");

	return 0;

}


int tribonacci(int numero){

	if (numero == 0 || numero == 1 || numero == 2)
	        return 0;
	if (numero == 3)
	        return 1;
	else
		return tribonacci(numero - 1) + tribonacci(numero - 2) + tribonacci(numero - 3);

}

