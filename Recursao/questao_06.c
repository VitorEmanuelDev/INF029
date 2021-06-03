/*6. Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule k n . Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
função.*/

#include<stdio.h>

int calcula(int k, int n);


int main(void){

	int k;
	int n;

	printf("Informe um número base k e um expoente n:\n");
	scanf("%d", &k);
	scanf("%d", &n);

	int resultado = calcula(k, n);

	printf("\n");
	printf("%d elevado a %d == %d", k, n, resultado);

	return 0;

}


int calcula(int k, int n){

	if(n > 0){

		return k * calcula(k, n - 1);

	}else{

		return 1;

	}

}

