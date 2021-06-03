//3. Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

#include<stdio.h>

int inverte(int numero);

int main(void){

	int numero;

	printf("Informe um número que deseja inverter:\n");
	scanf("%d", &numero);

	inverte(numero);

	return 0;

}


int inverte(int numero){

	int temp;

	temp = numero % 10;

	printf("%d", temp);

	numero = numero / 10;

	if(numero > 0)
		return inverte(numero);
	return 0;


}

