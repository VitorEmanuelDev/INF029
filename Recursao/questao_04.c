///4. Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

#include<stdio.h>

int soma(int inteiros[], int atual, int tam, int total);

int main(void){

	int tam = 0;

	printf("Informe o tamanho do array:");
	scanf("%d", &tam);

	int inteiros[tam];

	printf("Informe os valores do array:\n");
	for(int i = 0; i < tam; i++){

		scanf("%d", &inteiros[i]);

	}

	int atual = 0;
	int total = 0;

	soma(inteiros, atual, tam, total);

	return 0;

}


int soma(int inteiros[], int atual, int tam, int total){

	if(atual == tam)
		return printf("Soma dos elementos do array = %d",total);

	total = total + inteiros[atual];

	atual++;

	soma(inteiros, atual, tam, total);


}

