/*11. A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros.*/

#include <stdio.h>
#include <stdlib.h>

int multiplica(int n1, int n2);

int main(void){

	int n1, n2;

	puts("Informe dois números que deseja multiplicar");
	scanf("%d", &n1);
	scanf("%d", &n2);

    printf("%d x %d = %d", n1, n2, multiplica(n1, n2));

    return 0;
}

int multiplica(int n1, int n2){

    if(n2 == 0)
        return 0;

    return multiplica(n1, n2 - 1) + n1;
}

