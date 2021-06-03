//3. Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

#include<stdio.h>

int inverte(int numero);

int inverso = 0;
int digito;

int main(void){

	int numero;
	int invertido;

	printf("Informe um número que deseja inverter:\n");
	scanf("%d", &numero);

	invertido = inverte(numero);

	printf("\n");
	printf("%d", invertido);

	return 0;

}


int inverte(int numero){

	if(numero){

		digito = numero % 10;//1 = 321 % 10
		inverso = inverso * 10 + digito;
		inverte(numero / 10);

	}else{

		return inverso;

	}

	return inverso;

}

