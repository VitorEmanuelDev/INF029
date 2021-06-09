/*19. O hiperfatorial de um número N, escrito H(n), é definido por
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
hiperfatorial desse número.*/

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int hiper(int valor);
int potencia(int valor);

int main(void){

    int valor;

    printf("Informe um valor");
    scanf("%d", &valor);

    printf("hiper fatorial de %d = %d", valor, hiper(valor));

    return 0;
}

int potencia(int valor){

	return valor * valor;

}

int hiper(int valor){

    if(valor == 1)
        return 1;

    return potencia(valor) * hiper(valor - 1);
}

