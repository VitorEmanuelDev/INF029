/*7. Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int inverte(float reais[], int esq, int dir);

int temp;

int main(void){

	float reais[TAM];

	srand((unsigned int)time(NULL));

	float a = 1.0;

	for(int i = 0; i < TAM; i++){

		reais[i] = ((float)rand()/(float)(TAM)) * a;

		//printf("\n%.2f ", reais[i]);
	}

	//printf("\n\n\n");

	inverte(reais, 0, TAM - 1);

	for(int i = 0; i < TAM; i++){

		printf("\n%.2f ", reais[i]);

	}

	return 0;

}


int inverte(float reais[], int esq, int dir){

	if(esq < dir){

		temp = reais[dir];
		reais[dir] = reais[esq];
		reais[esq] = temp;
		esq++;
		dir--;

		inverte(reais, esq, dir);

	}else{

		return 0;

	}

	return 0;

}
