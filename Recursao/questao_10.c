/*10. Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>
#include <stdlib.h>

int contagem(int x, int y);

int main(void){

	int x, y;

		printf("Informe um dígito a ser procurado e um número:");
		scanf("%d", &y);
		scanf("%d", &x);

	    printf("O dígito %d ocorre %d vezes em %d", y, contagem(x, y), x);

	    return 0;

}


int contagem(int x, int y){

	if(x / 10 == 0){

		if(x % 10 == y)
			return 1;

		return 0;
	}

	if(x % 10 == y)
		return contagem(x / 10, y) + 1;

	return contagem(x / 10, y);

}

